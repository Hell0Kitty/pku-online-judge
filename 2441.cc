#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define pb(a) push(a)
#define INF 0x1f1f1f1f
#define lson idx << 1, l, mid
#define rson idx << 1 | 1, mid + 1, r
#define PI 3.1415926535898
template <class T>
T min(const T& a, const T& b, const T& c) {
  return min(min(a, b), min(a, c));
}
template <class T>
T max(const T& a, const T& b, const T& c) {
  return max(max(a, b), max(a, c));
}

int getch() {
  int ch;
  while ((ch = getchar()) != EOF) {
    if (ch != ' ' && ch != '\n') return ch;
  }
  return EOF;
}

int dp[1 << 20];
int like[22][22];
int n, m;
int f() {
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int st = (1 << m) - 1; st >= 0; st--)
      if (dp[st] != 0) {
        for (int j = 0; j < m; j++)
          if (like[i][j] && !((1 << j) & st)) {
            dp[st | (1 << j)] += dp[st];
          }

        dp[st] = 0;
      }
  }
  int ans = 0;
  for (int st = 0; st < (1 << m); st++)
    if (dp[st] != -1) ans += dp[st];
  return ans;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(like, 0, sizeof(like));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      int p;
      scanf("%d", &p);
      for (int j = 1; j <= p; j++) {
        int x;
        scanf("%d", &x);
        like[i][x - 1] = 1;
      }
    }
    int res = f();
    printf("%d\n", res);
  }
  return 0;
}
