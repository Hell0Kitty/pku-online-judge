#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct {
  int h;
  int c;
  int a;
} node;

node block[405];

bool cmp(node b1, node b2) { return b1.a < b2.a; }

int ans = 0, k, i, j, countn[40005], dp[40005];

int main() {
  scanf("%d", &k);
  for (i = 1; i <= k; i++) {
    scanf("%d%d%d", &block[i].h, &block[i].a, &block[i].c);
  }
  sort(block + 1, block + k + 1, cmp);
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (i = 1; i <= k; i++) {
    memset(countn, 0, sizeof(countn));
    for (j = block[i].h; j <= block[i].a; j++) {
      if (!dp[j] && dp[j - block[i].h] && countn[j - block[i].h] < block[i].c) {
        dp[j] = 1;
        countn[j] = countn[j - block[i].h] + 1;
        if (ans < j) ans = j;
      }
    }
  }
  printf("%d", ans);
}
