//* @author: Yeming Hu"cslittleye@gmail.com"
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
	long n,k;
	while(sc.hasNext())
	{
	    n = sc.nextLong();
	    k = sc.nextLong();
	    long sum;
	    if(n<=k)
	    {
	        sum = sumMod(k,n);
	    }else
	    {
	        sum = sumMod(k,k);
		sum += (n-k)*k;
	    }

	    System.out.println(sum);
	}
    }

    static long sumMod(long k, long n)
    {
        long sum = 0;
	long d = k/n;
	long t1 = n;
	long t2 = k/(d+1);
	while(k/d - t2 > 10)
	{
	    long s = k%t1;
	    long e = k%(t2+1);
	    sum += (s+e)*(t1-t2)/2;
	    d++;
	    t1 = t2;
	    t2 = k/(d+1);
	}

	for(long i=2;i<=t1;i++)
	{
	    sum += k%i;
	}

	return sum;
    }
}

