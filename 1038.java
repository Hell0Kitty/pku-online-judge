import java.util.*;

public class Main {
	static Scanner in = new Scanner(System.in);
	static int[] p = new int[12];
	static {
		p[0] = 1;
		for(int i=1; i!=p.length; ++i)
			p[i] = 3*p[i-1];
	}
	static int get(int s, int i) {
		return s/p[i]%3;
	}
	static int set(int s, int i, int v) {
		return s+(v-get(s, i))*p[i];
	}
	public static void main(String[] args) {
		int t = in.nextInt();
		while(t-->0) {
			int n = in.nextInt();
			int m = in.nextInt();
			if(m>10) while(true);
			boolean[][] map = new boolean[n+1][m+1];
			for(int i=0; i<=n; ++i) map[i][m] = true;
			for(int j=0; j<=m; ++j) map[n][j] = true;
			int k = in.nextInt();
			while(k-->0) map[in.nextInt()-1][in.nextInt()-1] = true;
			int[][] dp = new int[m+1][p[m]];
			dp[0][p[m]-1]=1;
			for(int i=0; i!=n; ++i) {
				for(int j=0; j!=m; ++j) {
					for(int s=0, _s; s!=p[m]; ++s) {
						int x = dp[j][s];
						if(x==0)continue;
						int l = get(s, j);
						_s = set(s, j, Math.min(2, l+1));
						dp[j+1][_s] = Math.max(dp[j+1][_s], x);
						int r = get(s, j+1);
						if(l!=2||r!=2) continue;
						if(map[i+0][j+0]) continue;
						if(map[i+0][j+1]) continue;
						if(map[i+1][j+0]) continue;
						if(map[i+1][j+1]) continue;
						if(!map[i+2][j]&&!map[i+2][j+1]) {
							_s = set(set(s, j, 0), j+1, 0);
							if(j+2>m)while(true);
							dp[j+2][_s] = Math.max(dp[j+2][_s], x+1);
						}
						if(get(s, j+2)==2&&!map[i][j+2]&&!map[i+1][j+2]) {
							_s = set(set(set(s, j, 1), j+1, 1), j+2, 1);
							if(j+3>m)while(true);
							dp[j+3][_s] = Math.max(dp[j+3][_s], x+1);
						}
					}
				}
				int[] tmp = dp[m];
				for(int j=m; j>=1; --j)
					Arrays.fill(dp[j] = dp[j-1], 0);
				dp[0] = tmp;
			}
			int ans = 0;
			for(int s=0; s!=p[m]; ++s)
				ans = Math.max(ans, dp[0][s]);
			System.out.println(ans-1);
		}
	}
}
