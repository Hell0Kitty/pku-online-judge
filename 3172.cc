#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1002;
int n, m, res;
__int64 val[maxn], num[maxn];
void dfs(int idx, __int64 sum) {
  if (sum > m) return;
  if (idx <= 0) {
    if (res < sum) res = sum;
    return;
  }
  if (num[idx] + sum <= res) {
    return;
  }
  if (sum > res) res = sum;
  dfs(idx - 1, sum + val[idx]);
  dfs(idx - 1, sum);
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    int i, j, k = 0;
    res = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &j);
      if (j <= m) val[++k] = j;
    }
    for (i = 1; i <= k; i++) {
      num[i] = num[i - 1] + val[i];
    }
    dfs(k, 0);
    printf("%d\n", res);
  }
  return 0;
}
