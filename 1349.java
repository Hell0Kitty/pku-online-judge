import java.util.*;
import java.math.*;

public class Main {
	public static String s;
	public static int []p = new int [51];
	public static int []visit = new int [51];
	public static Vector res = new Vector();
	public static BigInteger []q = new BigInteger [51];
	public static int n;
	static void init()
	{
		q[0] = q[1] = BigInteger.ONE;
		int i;
		for (i = 2; i < 51; i++)
			 q[i] = q[i - 1].multiply(new BigInteger (i + ""));
	}
	static void parse()
	{
		int i, j, k, len;
		char ch;
		len = s.length();
		ch = s.charAt(2);
		if (ch >= '0' && ch <= '9')
		{
			n = (ch - '0') + 10 * (s.charAt(1) - '0');
			i = 5;
		}
		else
		{
			n = (s.charAt(1) - '0');
			i = 4;
		}
		k = j = 0;
		while (i < len)
		{
			ch = s.charAt(i);
			if (ch == ',' || ch == ')')
			{
				p[j++] = k;
				k = 0;
			}
			else
				k = k * 10 + (ch - '0');
			i++;
		}
	}
	static void deal()
	{
		BigInteger ans = BigInteger.ONE, temp;
		Arrays.fill(visit, 0);
		int i, j, count;
		for (i = 0; i < n; i++)
		{
			count = 0;
			for (j = 1; j < p[i]; j++)
				 if (visit[j] == 0)
					 count++;
			visit[p[i]] = 1;
			temp = BigInteger.ONE;
			temp = temp.multiply(new BigInteger (count + "")).multiply(q[n - i - 1]);
			ans = ans.add(temp);
		}
		res.addElement(ans);
	}
	static void input()
	{
		Scanner cin = new Scanner (System.in);
		while (cin.hasNext())
		{
			s = cin.nextLine();
			if (s.compareTo("-1") == 0)
				break;
			parse();
			deal();
		}
		int i, len = res.size();
		for (i = 0; i < len - 1; i++)
			 System.out.print(res.elementAt(i) + ",");
		System.out.println(res.elementAt(i));
	}
	public static void main (String []args)
	{
		init();
		input();
	}
}