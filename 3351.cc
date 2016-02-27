#include <algorithm>
using namespace std;

const int INF = 12345678;
const int N = 1010;
const int P = 12;

int n, p;
int v[N][P];
int win[N][N];
int dp[N][N];

int Max(int a, int b) { return a > b ? a : b; }
void input() {
  scanf("%d", &n);
  scanf("%d", &p);
  int i, j, k;
  memset(v[0], 0, sizeof(v[0]));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= p; j++) {
      scanf("%d", &k);
      v[i][j] = v[i - 1][j] + k;
    }
}
void init() {
  int i, j, k, vote;
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++) {
      vote = v[j][1] - v[i - 1][1];
      for (k = 2; k <= p; k++)
        if (v[j][k] - v[i - 1][k] >= vote) break;
      if (k > p)
        win[i][j] = 1;
      else
        win[i][j] = -1;
    }
}
int solve() {
  init();

  int i, j, k, t;
  int list[N], top, mx;
  dp[0][0] = 0;
  for (j = 1; j <= n; j++) {
    top = 0;
    mx = -INF;
    for (i = j; i <= n; i++) {
      if (dp[i - 1][j - 1] > mx) {
        mx = dp[i - 1][j - 1];
        list[0] = i - 1;
        top = 1;
      } else if (dp[i - 1][j - 1] == mx)
        list[top++] = i - 1;
      for (t = 0; t < top - 1; t++)
        if (win[list[t] + 1][i] == 1) break;
      dp[i][j] = mx + win[list[t] + 1][i];
    }
  }

  int ans;
  for (ans = n; ans >= 1; ans--)
    if (dp[n][ans] > 0) return n - ans;
  return -1;
}
int main() {
  input();
  printf("%d\n", solve());
  return 0;
}
