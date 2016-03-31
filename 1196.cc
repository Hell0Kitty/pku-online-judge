#include <cstdio>
#include <cstring>
using namespace std;
int f[6][6][6][6][6];
char op[9], s[33], out[33];
int i, j, n, tmp;
bool ok(int x, int t) { return (!out[x] || out[x] == t + 'A'); }
int dfs(int a, int b, int c, int d, int e, int t) {
  if (t >= 25) return 1;
  int &tmp = f[a][b][c][d][e];
  if (tmp) return tmp;
  if (a < 5 && ok(a, t)) tmp += dfs(a + 1, b, c, d, e, t + 1);
  if (b < a && ok(b + 5, t)) tmp += dfs(a, b + 1, c, d, e, t + 1);
  if (c < b && ok(c + 10, t)) tmp += dfs(a, b, c + 1, d, e, t + 1);
  if (d < c && ok(d + 15, t)) tmp += dfs(a, b, c, d + 1, e, t + 1);
  if (e < d && ok(e + 20, t)) tmp += dfs(a, b, c, d, e + 1, t + 1);
  return tmp;
}
int main() {
  while (~scanf("%s", op)) {
    if (op[0] == 'N') {
      scanf("%d", &n);
      for (i = 0; i < 25; ++i)
        for (out[i] = 'A'; 1; ++out[i]) {
          memset(f, 0, sizeof(f));
          tmp = dfs(0, 0, 0, 0, 0, 0);
          if (tmp >= n) break;
          n -= tmp;
        }
      puts(out);
    }
    if (op[0] == 'W') {
      scanf("%s", s);
      for (n = i = 0; i < 25; ++i)
        for (out[i] = 'A'; out[i] < s[i]; ++out[i]) {
          memset(f, 0, sizeof(f));
          n += dfs(0, 0, 0, 0, 0, 0);
        }
      printf("%d\n", n + 1);
    }
  }
  return 0;
}
