#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1 << 30;
const double eps = 1e-6;
const int N = 100010;
char s[N], a[N], b[N], c[N];
bool vis[N][30];
int n, k, cnt[N];
void rev(char *s) {
  int l = 0, r = n - 1;
  for (; l < r; l++, r--) swap(s[l], s[r]);
}
void read() {
  memset(vis, 0, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  while (k--) {
    scanf("%s", s);
    rev(s);
    for (int i = 0; i < n; ++i) vis[i][s[i] - 'a'] = 1;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 26; ++j)
      if (!vis[i][j]) cnt[i]++;
}
int ctoint(int idx, char c) {
  c = c - 'a';
  int res = 0;
  for (int i = 0; i < c; ++i)
    if (!vis[idx][i]) res++;
  return res;
}
char inttoc(int idx, int x) {
  int i;
  for (i = 0;; i++)
    if (!vis[idx][i] && (x--) == 0) break;
  return i + 'a';
}
void run() {
  read();
  scanf("%s%s", a, b);
  rev(a);
  rev(b);
  int rem = 0, tmp;
  for (int i = 0; i < n; ++i) {
    tmp = rem + ctoint(i, a[i]) + ctoint(i, b[i]);
    c[i] = tmp % cnt[i];
    rem = tmp / cnt[i];
  }
  for (int i = 0; i < n; ++i) c[i] = inttoc(i, c[i]);
  for (int i = n - 1; i >= 0; --i) putchar(c[i]);
  puts("");
}

int main() {
  while (scanf("%d%d", &n, &k) != EOF) run();
  return 0;
}
