import java.util.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	static int pp;
	static int[] p = new int[30000];
	static int[] w = new int[30000];
	static boolean[] q = new boolean[35000];

	static void init() {
		int i;
		for (i = 2; i * i < 35000; i++) {
			if (q[i])
				continue;
			p[pp++] = i;
			for (int j = i * i; j < 35000; j += i)
				q[j] = true;
		}
		for (; i < 32768; i++)
			if (!q[i])
				p[pp++] = i;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
		Scanner in = new Scanner(System.in);
		String s;
		while (true) {
			s = in.nextLine();
			if (s.equals("0"))
				break;
			StringTokenizer aa = new StringTokenizer(s);
			BigInteger k = BigInteger.ONE;
			int a1, a2;
			while (aa.hasMoreTokens()) {
				a1 = Integer.parseInt(aa.nextToken());
				a2 = Integer.parseInt(aa.nextToken());
				for (int i = 0; i < a2; i++)
					k = k.multiply(BigInteger.valueOf(a1));
			}
			k=k.subtract(BigInteger.ONE);
			for (int i = pp - 1; i >= 0; --i) {
				w[i] = 0;
				while (k.mod(BigInteger.valueOf(p[i])).equals(BigInteger.ZERO)) {
					w[i]++;
					k = k.divide(BigInteger.valueOf(p[i]));
				}
				if (w[i] > 0)
					if (k.equals(BigInteger.ONE)) {
						System.out.println(p[i] + " " + w[i]);
						break;
					} else
						System.out.print(p[i] + " " + w[i] + " ");
			}
		}
	}

}
