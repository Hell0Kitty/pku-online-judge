#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> v[25005];

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) scanf("%d%d", &v[i].first, &v[i].second);
  sort(v, v + n);
  int from = 1, to = 0, cnt = 1;
  for (int i = 0; i < n; ++i) {
    if (v[i].first > from) {
      ++cnt;
      from = to + 1;
    }
    if (v[i].first <= from) {
      to = max(to, v[i].second);
      if (to >= t) break;
    } else
      break;
  }
  printf("%d\n", to < t ? -1 : cnt);
  return 0;
}
