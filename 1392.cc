#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1 << 16;
int n, m, k, top, len, cnt[maxn], ans[maxn];
void DFS(int v) {
  while (cnt[v] < 2) {
    int w = (v << 1) + cnt[v];
    cnt[v]++;
    DFS(w & m);
    ans[len++] = w;
  }
}
int main() {
  while (scanf("%d%d", &n, &k) && (n + k)) {
    top = len = 0;
    memset(cnt, 0, sizeof(cnt));
    m = (1 << (n - 1)) - 1;
    DFS(0);
    while (k--) len--;
    printf("%d\n", ans[--len]);
  }
  return 0;
}
