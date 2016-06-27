#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef __int64 lld;
vector<lld> lu, res;
int tot;
void dfs(lld num, int de) {
  if (de == 12) return;
  lu.push_back(num);
  dfs(num * 10 + 4, de + 1);
  dfs(num * 10 + 7, de + 1);
}
void dfs1(int x, lld num) {
  for (int i = x; i < lu.size(); i++) {
    if (1e12 / num < lu[i]) return;
    res.push_back(num * lu[i]);
    dfs1(i, num * lu[i]);
  }
}
void init() {
  lu.clear();
  res.clear();
  dfs(4, 0);
  dfs(7, 0);
  sort(lu.begin(), lu.end());
  dfs1(0, 1);
  sort(res.begin(), res.end());
  tot = unique(res.begin(), res.end()) - res.begin();
}
int main() {
  init();
  int t;
  lld a, b;
  scanf("%d", &t);
  while (t--) {
    scanf("%I64d%I64d", &a, &b);
    int l = lower_bound(res.begin(), res.begin() + tot, a) - res.begin();
    int r = upper_bound(res.begin(), res.begin() + tot, b) - res.begin();
    printf("%d\n", r - l);
  }
}
