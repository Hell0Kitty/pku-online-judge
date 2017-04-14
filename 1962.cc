#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 30000;
int fa[N], dist[N];
int Find(int x) {
  if (x == fa[x])
    return x;
  else {
    int fx = Find(fa[x]);
    dist[x] = (dist[x] + dist[fa[x]]);  //%1000;
    return fa[x] = fx;
  }
}
void makeset(int x, int y) {
  int fx = Find(x), fy = Find(y);
  if (fx == fy)
    return;
  else {
    fa[fx] = x;
    dist[fx] = dist[x];
    fa[x] = y;
    dist[x] = abs(y - x) % 1000;
  }
}
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      fa[i] = i;
      dist[i] = 0;
    }
    char s[2];
    while (scanf("%s", s), s[0] != 'O') {
      if (s[0] == 'E') {
        scanf("%d", &x);
        Find(x);
        printf("%d\n", dist[x]);
      } else {
        scanf("%d%d", &x, &y);
        makeset(x, y);
      }
    }
  }
  return 0;
}
