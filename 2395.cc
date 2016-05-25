#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int father[2010], r[2010];
struct road {
  int one, another;
  int dis;
  bool operator<(const road& a) const { return dis < a.dis; }
} v[10010];
int findfa(int x) {
  return x == father[x] ? x : (father[x] = findfa(father[x]));
}
int m, n;
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < m; ++i)
      scanf("%d%d%d", &v[i].one, &v[i].another, &v[i].dis);
    for (int i = 1; i < n; ++i) {
      r[i] = 1;
      father[i] = i;
    }
    sort(v, v + m);
    int cnt = 0;
    int ans = -1;
    for (int i = 0; i < m && cnt < n - 1; ++i) {
      road temp = v[i];
      int fa = findfa(temp.another), fo = findfa(temp.one);
      if (fa != fo) {
        ++cnt;
        if (r[temp.another] > r[temp.one]) {
          r[temp.another] += r[temp.one];
          father[fo] = fa;
        } else {
          r[temp.one] += r[temp.another];
          father[fa] = fo;
        }
        ans = max(ans, temp.dis);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
