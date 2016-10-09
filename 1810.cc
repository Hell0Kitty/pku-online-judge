#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX = 1200;
const double eps = 1e-8;
int dp[MAX][MAX];
int ret, x, y;

int main() {
	int T, k, m, n, ref;
	double xx, yy;

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &k, &n, &m);
		ret = 0;
		memset(dp, 0, sizeof(dp));
		while (k--) {
			scanf("%lf%lf", &xx, &yy);
			dp[(int) (xx + eps)][(int) (yy + eps)]++;
		}
		for (int i = 1; i <= n; i++) {
			dp[0][i] += dp[0][i - 1];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j)
					dp[i][j] += dp[i - 1][j] - dp[i - 1][j - 1] + dp[i][j - 1];
				else
					dp[i][j] += dp[i - 1][j];
			}
		}
		for (int i = 0; i + m <= n; i++) {
			for (int j = 0; j + m <= n; j++) {
				if (i && j) {
					ref = dp[i - 1][j - 1] + dp[i + m - 1][j + m - 1] - dp[i
							- 1][j + m - 1] - dp[i + m - 1][j - 1];
				} else if (i) {
					ref = dp[i + m - 1][j + m - 1] - dp[i - 1][j + m - 1];
				} else if (j) {
					ref = dp[i + m - 1][j + m - 1] - dp[i + m - 1][j - 1];
				} else {
					ref = dp[i + m - 1][j + m - 1];
				}

				if (ret <= ref) {
					ret = ref;
					x = i;
					y = j;
				}
			}
		}
		printf("%d %d\n", x, y);
	}

	return 0;
}



