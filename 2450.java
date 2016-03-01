import java.util.*;
import java.math.*;

public class Main {
  static int gcd(int a,int b)
  {
	int c;
	while( (a%=b) != 0 )
	{
         c=b;
	  b=a;
	  a=c;
	}
	return b;
   }

  static int a,b,c,d,n,m,p,q;
  static int t[] = new int[100001];

  static BigInteger comb(int a,int b)
 {
   int i,j,g,k,last;
   if( b > a/2 )
     b = a - b;
   last = b;

   for(i=0;i< b;i++)
   {
	t[i]=a-i;
   }

   for(i=2;i<=b;i++)
   {
	k=i;
	for(j=0;j< b/*last*/&&k>1;j++)
	if(t[j]>1)
	{
         g=gcd(t[j],k);
	  t[j]/=g;
	  k/=g;
	}
    }

    BigInteger ans = BigInteger.valueOf(1);
    int temp=1;
    for(i=0;i< last;i++)
	if(t[i]>1)
	{
	  temp*=t[i];
	  if(temp>=10000)
	  {
	    ans=ans.multiply( BigInteger.valueOf(temp) );
	    temp=1;
	   }
	}

    ans=ans.multiply( BigInteger.valueOf(temp) );
    return ans;
   }

   static void doit()
   {
     int x1,x2,n1,m1,n2,m2,temp1,temp2, temp;
     boolean key;
     BigInteger ans = BigInteger.valueOf( 0 );
     if( (int)(((n-p)/a)< ((m-q)/b)?((n-p)/a):((m-q)/b)) >
	(int)(((n-p)/c)< ((m-q)/d)?((n-p)/c):((m-q)/d)) )
     {
	temp = a; a = c; c = temp;
	temp = b; b = d; d = temp;
     }

    for( x1=0 ; (n1=n-a*x1)>=0 && (m1=m-b*x1)>=0 ; x1++ )
    {
	temp1=(n1>p) ? (n1-p+c-1)/c : 0;
	temp2=(m1>q) ? (m1-q+d-1)/d : 0;
	x2 = temp1>temp2 ? temp1 : temp2 ;
	n2 = n1-c*x2; m2 = m1-d*x2;
	while( n2>p&&m2>q )
         System.out.println( "error" );

	key = true;
	while( n2>=0 && m2>=0 && key )
	{
	   key = false;
	   if( x1 != 0 && ( n2 + a > p || m2 + b > q ) ) {
		ans = ans.add( comb( x1+x2-1, x1-1 ) );
		key = true;
	   }

	 if( x2 != 0 && ( n2 + c > p || m2 + d > q ) ) {
	   ans = ans.add( comb( x1+x2-1, x2-1 ) );
	   key = true;
	}

	n2 -= c;
	m2 -= d;
	x2++;
    }
   }

   System.out.println( ans );
	//ans.output('\n');
  }

  public static void main( String [] str )
  {
	int cas;
	Scanner cin = new Scanner( System.in );
	cas = cin.nextInt();
	while( cas-- != 0 )
	{
        n = cin.nextInt();
	 m = cin.nextInt();
	 p = cin.nextInt();
	 q = cin.nextInt();
	 a = cin.nextInt();
	 b = cin.nextInt();
	 c = cin.nextInt();
	 d = cin.nextInt();
	doit();
	}
	return;
  }
}

