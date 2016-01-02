#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include <queue>
#include <deque>
#include <iomanip>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define keyTree (ch[ch[root][1]][0])
const int maxn = 1001111;
const int mask = 32767;
const int INF = (mask << 15) | mask;
int q[maxn], front, rear;
int dp[maxn];
bool can[maxn];
struct node {
  int l, r;
  node() {}
  node(int l, int r) : l(l), r(r) {}
} f[1111];
void solve(int N, int L, int A, int B) {
  int i, j;
  for (i = 0; i < N; ++i) {
    if (f[i].r - f[i].l > B) {
      puts("-1");
      return;
    }
  }
  memset(can, true, sizeof(can));
  for (i = 0; i < N; ++i) {
    for (j = f[i].l + 1; j < f[i].r; ++j) can[j] = false;
  }
  front = rear = 0;
  dp[0] = 0;
  for (i = 2; i <= L; i += 2) {
    dp[i] = INF;
    j = i - A;
    if (j < 0) continue;
    if (can[j] && dp[j] < INF) {
      while (front < rear && dp[q[rear - 1]] >= dp[j]) --rear;
      q[rear++] = j;
    }
    if (can[i]) {
      while (front < rear && i - q[front] > B) ++front;
      if (front < rear) dp[i] = dp[q[front]] + 1;
    }
  }
  if (dp[L] == INF)
    puts("-1");
  else
    printf("%d\n", dp[L]);
}
int main() {
  int N, L, A, B, i, l, r;
  scanf("%d%d%d%d", &N, &L, &A, &B);
  for (i = 0; i < N; ++i) {
    scanf("%d%d", &l, &r);
    f[i] = node(l, r);
  }
  solve(N, L, A << 1, B << 1);
  return 0;
}
