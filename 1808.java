import java.io.*;
import java.util.*;
import java.math.*;
public class Main 
{
	public static long mod(long a,long b,long c)
	{
		long ret=1%c;
		while(b!=0)
		{
			if((b&0x1)!=0)
				ret=ret*a%c;
			a=a*a%c;
			b>>=1;
		}
		return ret;
	}
	public static void main(String args[]) throws Exception {
	
		int idx=0;
		Scanner cin=new Scanner(System.in);
		long a,p;
		int t;
		t=cin.nextInt();
		while(t!=0)
		{
			--t;
			a=cin.nextLong();
			p=cin.nextLong();
			a%=p;
			if(a<0)a+=p;
			++idx;
			System.out.println("Scenario #"+idx+":");
			if(mod(a,(p-1)/2,p)==1)
				System.out.println("1");
			else
				System.out.println("-1");
			System.out.println();
		}
	}
}