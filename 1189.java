import java.util.*;

public class Main {
	static final Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		int n = in.nextInt();
		int m = in.nextInt();
		in.nextLine();
		long[][] a = new long[n+1][];
		a[0] = new long[]{1l<<n};
		for(int i=1; i<=n; ++i)
			a[i] = new long[i+1];
		for(int i=1; i<=n; ++i) {
			boolean[] flag = new boolean[i+1];
			String s = in.nextLine();
			for(int k=0, j=0; j<s.length(); ++j)
				switch(s.charAt(j)) {
					case '*': flag[k] = true;
					case '.': ++k;
				}
			for(int j=i-1; j>=0; --j) {
				if(flag[j]) {
					a[i][j] = a[i][j]+a[i-1][j]/2;
					a[i][j+1] = a[i][j+1]+a[i-1][j]/2;
				} else a[i+1][j+1] = a[i-1][j];
			}
		}
		long num = a[n][m];
		long den = a[0][0];
		while((num&1)==0&&(den&1)==0) {
			num /= 2;
			den /= 2;
		}
		System.out.println(num+"/"+den);
	}
}
