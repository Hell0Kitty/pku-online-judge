#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int ran[1005], id, top;
int getnext() { return ran[id++]; }
int pos[10], to[105], flag[105];
bool res[105];
int main() {
  int x, y;
  top = 0;
  while (scanf("%d", &x), ran[top] = x) top++;
  int n;
  while (scanf("%d", &n), n) {
    id = 0;
    memset(to, 0, sizeof(to));
    memset(flag, 0, sizeof(flag));
    memset(pos, 0, sizeof(pos));
    memset(res, false, sizeof(res));
    while (scanf("%d%d", &x, &y), (x || y)) to[x] = y;
    while (scanf("%d", &x), x)
      if (x < 0)
        flag[-x] = -1;
      else
        flag[x] = 1;
    int p = 0, d;
    while (1) {
      p++;
      if (p == n + 1) p = 1;
      if (res[p]) {
        res[p] = false;
        continue;
      }
      d = getnext();
      int t = pos[p] + d;
      if (t > 100) continue;
      if (to[t])
        pos[p] = t = to[t];
      else
        pos[p] = t;
      if (t == 100) {
        printf("%d\n", p);
        break;
      }
      if (flag[t] < 0)
        res[p] = true;
      else if (flag[t] > 0)
        p--;
    }
  }
  return 0;
}
