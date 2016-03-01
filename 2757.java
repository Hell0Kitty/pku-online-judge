//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
 public static void main(String args[]) throws Exception {

	Scanner cin=new Scanner(System.in);
	BigInteger n;
	long b;
	while(cin.hasNext())
	{
		n=cin.nextBigInteger();
		b=cin.nextLong();
		if(n.compareTo(BigInteger.ZERO)<=0)
		{
			System.out.println("0");
			continue;
		}
		BigInteger ans;
		ans=n.multiply(n.add(BigInteger.ONE)).divide(BigInteger.valueOf(2));
		ans=ans.multiply(BigInteger.valueOf(b));
		//how many [0..b-1]
		BigInteger cnt=n.divide(BigInteger.valueOf(b));
		ans=ans.add(BigInteger.valueOf(b*(b-1)/2).multiply(cnt));
		cnt=cnt.multiply(BigInteger.valueOf(b));
		while(cnt.compareTo(n)<=0)
		{
			BigInteger tmp=BigInteger.ZERO,tsum=cnt;
			while(tsum.compareTo(BigInteger.ZERO)>0)
			{
				tmp=tmp.add(tsum.mod(BigInteger.valueOf(b)));
				tsum=tsum.divide(BigInteger.valueOf(b));
			}
             tmp=(BigInteger.valueOf(b).subtract(tmp.mod(BigInteger.valueOf(b)))).mod(BigInteger.valueOf(b));
			cnt=cnt.add(BigInteger.ONE);
			ans=ans.add(tmp);
		}
		System.out.println(ans);
	}
  }
}

