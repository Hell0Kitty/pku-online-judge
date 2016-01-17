#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int maxn = 10;
char l[maxn], m[maxn], r[maxn];
int have[maxn], ans[maxn];
__int64 ll, mm, rr, cnt;
int num;

void put(char *s) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (have[s[i] - 'A'] == -1) {
      have[s[i] - 'A'] = num++;
    }
  }
  return;
}

__int64 judge(char *s) {
  __int64 res = 0;
  int len = strlen(s);
  if (len == 1 && ans[have[s[0] - 'A']] == 0) return 0;
  for (int i = 0; s[i] != '\0'; i++) {
    __int64 tmp = ans[have[s[i] - 'A']];
    if (i == 0 && tmp == 0) return -1;
    res *= 10;
    res += tmp;
  }
  return res;
}

void check() {
  ll = judge(l);
  if (ll == -1) return;
  mm = judge(m);
  if (mm == -1) return;
  rr = judge(r);
  if (rr == -1) return;
  if (ll + mm == rr) cnt++;
  if (ll - mm == rr) cnt++;
  if (ll * mm == rr) cnt++;
  if (mm != 0 && (ll % mm) == 0 && ll / mm == rr) cnt++;
  return;
}

void dfs(int pos, int st) {
  if (pos == num) {
    check();
    return;
  }
  for (int i = 0; i <= 9; i++) {
    if ((st & (1 << i)) == 0) {
      ans[pos] = i;
      dfs(pos + 1, st | (1 << i));
    }
  }
  return;
}

void solve() {
  memset(have, -1, sizeof(have));
  scanf("%s %s %s", l, m, r);
  num = cnt = 0;
  put(l), put(m), put(r);
  dfs(0, 0);
  printf("%I64d\n", cnt);
  return;
}

int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    solve();
  }
  return 0;
}
