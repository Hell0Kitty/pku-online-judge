import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(true)
		{
			int n = in.nextInt();
			int m = in.nextInt();
			int m1 = m;
			BigInteger sum1 = new BigInteger("1");
			BigInteger sum2 = new BigInteger("1");
			BigDecimal a;
			if(n == 0 && m == 0)
				break;
			if(m > n/2)
			{
				m = n - m;
			}
			for(int i = 0; i<m; i++)
			{
				sum1 = sum1.multiply(new BigInteger(String.valueOf(n-i))); 
			}
			for(int i = 0; i<m; i++)
			{
				sum2 = sum2.multiply(new BigInteger(String.valueOf(i+1)));
			}
			System.out.println(n + " things taken " + m1 +" at a time is " 
					+ sum1.divide(sum2) +" exactly.");
		}
	}

}
