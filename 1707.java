import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
public class Main 
{
	static class com
	{
		BigInteger a,b;//a/b...
		com add(com C)
		{
			com ret=new com();
			BigInteger lcm;
			lcm=b.multiply(C.b).divide(b.gcd(C.b));
			ret.b=lcm;
			ret.a=a.multiply(lcm.divide(b)).add(C.a.multiply(lcm.divide(C.b)));
			lcm=ret.b.gcd(ret.a);
			ret.a=ret.a.divide(lcm);
			ret.b=ret.b.divide(lcm);
			return ret;
		}
		com sub(com C)
		{
			com ret=new com();
			BigInteger lcm;
			lcm=b.multiply(C.b).divide(b.gcd(C.b));
			ret.b=lcm;
			ret.a=a.multiply(lcm.divide(b)).subtract((C.a.multiply(lcm.divide(C.b))));
			lcm=ret.b.gcd(ret.a);
			ret.a=ret.a.divide(lcm);
			ret.b=ret.b.divide(lcm);
			return ret;
		}
		void show()
		{
			System.out.println(a+" / "+b);
		}
	}
	static BigInteger s[][]=new BigInteger[105][105],fac[]=new BigInteger[105],dp[][]=new BigInteger[105][105];
	static com B[]=new com[105];
	static com buf[] = new com[105];
	static void mkstri()
	{
		int i,j;
		com tmp = new com();
		for (i = 0; i <105; ++i) B[i] = new com();
		for(i=1;i<105;++i)
			{
				dp[i][0]=dp[i][i]=BigInteger.ONE;
				for(j=1;j<i;++j)
					dp[i][j]=dp[i-1][j-1].add(dp[i-1][j]);
			}
		for(i=1;i<105;++i)
			s[i][i]=s[i][1]=BigInteger.ONE;
		for(i=2;i<105;++i)
			for(j=2;j<i;++j)
				s[i][j]=s[i-1][j-1].add(s[i-1][j].multiply(BigInteger.valueOf(j)));
		fac[0]=BigInteger.ONE;
		for(i=1;i<105;++i)fac[i]=fac[i-1].multiply(BigInteger.valueOf(i));
		B[0].a=B[0].b=BigInteger.ONE;
		for(i=1;i<105;++i)
		{
			B[i].a=BigInteger.ZERO;
			B[i].b=BigInteger.ONE;
			for(j=1;j<=i;++j)
			{
				tmp.a=fac[j].multiply(s[i][j]);
				tmp.b=BigInteger.valueOf(j+1);
				if((i+j)%2==0)
					B[i]=B[i].add(tmp);
				else
					B[i]=B[i].sub(tmp);
			}
		}
	}
	public static void main(String args[]) throws Exception {
		Scanner cin=new Scanner(System.in);
		mkstri();
		BigInteger ans,tmp,G;
		int k,i;
		for(i=0;i<105;++i)buf[i]=new com();
		while(cin.hasNext())
		{
			k=cin.nextInt();
			//k+1...
			ans=BigInteger.ONE;
			for(i=0;i<=k;++i)
				{
					buf[i].b=B[i].b.multiply(BigInteger.valueOf(k+1));
					buf[i].a=B[i].a.multiply(dp[k+1][i]);
					G=buf[i].a.gcd(buf[i].b);
					buf[i].a=buf[i].a.divide(G);
					buf[i].b=buf[i].b.divide(G);
					ans=ans.multiply(buf[i].b).divide(buf[i].b.gcd(ans));
				}
			System.out.print(ans);
			for(i=0;i<=k;++i)
				{
					G=ans.divide(buf[i].b);
					System.out.print(" "+buf[i].a.multiply(G));
				}
			System.out.println(" 0");
		}
    }
} 