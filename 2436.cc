#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#define MAXN 1111
using namespace std;
int cow[MAXN], vis[MAXN], N, D, K, ans;
void dfs(int idx, int cnt, int sum) {
  if (cnt == K) {
    int num = 0;
    for (int i = 0; i < N; i++)
      if (cow[i] == (cow[i] & sum)) num++;
    ans = max(ans, num);
    return;
  }
  for (int i = idx; i < D; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      dfs(i + 1, cnt + 1, sum | (1 << i));
      vis[i] = 0;
    }
  }
}
int main() {
  int tmp, kind;
  while (~scanf("%d%d%d", &N, &D, &K)) {
    memset(cow, 0, sizeof(cow));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; i++) {
      scanf("%d", &tmp);
      for (int j = 0; j < tmp; j++) {
        scanf("%d", &kind);
        cow[i] |= (1 << (kind - 1));
      }
    }
    ans = 0;
    dfs(0, 0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
