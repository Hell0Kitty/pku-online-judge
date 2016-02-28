import java.util.Random;
import java.util.Scanner;
//http://en.wikipedia.org/wiki/Pollard's_rho_algorithm
public class Main{
   static int MAX_COUNT = 6;
   static long allFactor[ ]=new long [65];
   static int nFactor;
   static Random rn=new Random();
	
   static long  fMultiModular(   long a,   long b,   long  n)
	{
		long back = 0, temp = a % n;
	    while ( b > 0 )
	    {
	        if ( (b & 0x1)==1 )
	        {
	            if ( (back = back + temp) > n )
				 back -= n;
			}//modres=back
	        if ( (temp <<= 1) > n )
			temp -= n;//temp=a^(xx)

	        b >>= 1;
	    }
	    return back;
	}

      static long   GCD(long    a , long  b)
	{
		  
			int z = 0;
			while(b != 0 && a != 0)
			{
				while((a & 1) == 0 && (b & 1) == 0)
				{
					z++;
					a >>= 1;
					b >>= 1;
				}
				while((a & 1) == 0)
				{
					a >>= 1;
				}
				while((b & 1) == 0)
				{
					b >>= 1;
				}
				if(a > b)
				{
					a -= b;
				}
				else
				{
					b -= a;
				}
			}//while
			if(b == 0)
			{
				return a << z;
			}
			return b << z;
	}



static long modular_exp( long  a, long b, long n)
{
	long d=1, dTemp=(a % n);
    while ( b > 0 )
    {
        if ( (b & 0x1)==1 )
            d = fMultiModular(d, dTemp, n);
        dTemp = fMultiModular(dTemp, dTemp, n);
        b >>= 1;
    }
    return d;
}

static boolean fWitNess(long  a, long  n, int t, long  u)
{
	long x, y = 0;
 x = modular_exp(a, u, n);
 while ( t-- >0)
 {
  y = fMultiModular(x, x, n);
  if ( y == 1 && x != 1 && x != n-1 )
   return true; //must not
  x = y;
 }
 return y != 1;
}


static boolean  miller_rabin(long n, int count) 
{
    if ( n == 1 )
        return false;
    if ( n == 2 )
	return true;
 
  long  a, u;    
    int t=0; 
    for (u = n-1; !((u & 0x1)==1); u>>=1)
  ++t;//2's power
    for (int i = 1; i <= count; ++i)
    {
        a = rand() % (n-1) + 1;
        if ( fWitNess(a, n, t, u) )
		 return false;
    }
    return true;
}

static long  pollard_rho(long c, long num)
{
    int i=(1), k=(2);
   long x = rand() % num;
   long y = x, comDiv;
    do
    {
        ++i;
        if ( (x = fMultiModular(x, x, num) - c) < 0 )
   x += num;
        if ( x == y )
            break;
        comDiv = GCD((y-x+num)%num, num);
        if ( comDiv > 1 && comDiv < num )
            return comDiv;
        if ( i == k )
        {
            y = x;
            k <<= 1;
        }
    }while ( true );
    return num;
}

static void fFindFactor(long num)
{
    if ( miller_rabin(num, MAX_COUNT) == true )
    {
    allFactor[++nFactor] = num; 
 // printf("%I64d ",num);
        return;
    }
    long factor;
    do
    {
        factor = pollard_rho(rand()%(num-1) + 1, num);
    }while ( factor >= num );

    fFindFactor(factor);
    fFindFactor(num/factor);
}

 static long rand()
 {
	 long temp=rn.nextLong();
	 if(temp<0)
		 temp+=Long.MAX_VALUE;
	 return 
	temp;
 }

 public static void main(String args[])
 {
		int t, i;
		Scanner cin = new Scanner(System.in);
		long test_num, min;
		t = cin.nextInt();
		while (t-- > 0) {
			test_num = cin.nextLong();
			//BigInteger testprime = new BigInteger(Long.toString(test_num));
			// if(testprime.isProbablePrime(20))
			if (miller_rabin(test_num, 20))				
				System.out.println("Prime");
			else {
				min = test_num;
				nFactor = 0;
				fFindFactor(test_num);
				for (i = 1; i <= nFactor; i++) {
					if (allFactor[i] < min)
						min = allFactor[i];
				}
				System.out.println(min);
			}
		}
	}
}