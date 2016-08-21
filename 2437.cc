#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
struct Road {
  int s;
  int e;
} road[MAXN];

bool cmp(Road x, Road y) { return x.s < y.s; }

int main() {
  int n, l;
  while (scanf("%d%d", &n, &l) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d%d", &road[i].s, &road[i].e);
    sort(road, road + n, cmp);
    int ans = 0;
    int cnt = (road[0].e - road[0].s - 1) / l + 1;
    ans += cnt;
    int pl = road[0].s + cnt * l;
    for (int i = 1; i < n; i++) {
      if (pl >= road[i].e) continue;
      if (pl < road[i].s) pl = road[i].s;
      cnt = (road[i].e - pl - 1) / l + 1;
      ans += cnt;
      pl += cnt * l;
    }
    printf("%d\n", ans);
  }
  return 0;
}
