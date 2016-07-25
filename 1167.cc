#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, tot[70], top, ans;
struct Data {
  int start, ti, num;
  bool operator<(const Data &ne) const { return num > ne.num; }
  Data() {}
  Data(int _st, int _ti, int _num) {
    start = _st, ti = _ti;
    num = _num;
  }
} bus[1000];
bool check(int i, int t) {
  for (; i < 60; i += t)
    if (tot[i] <= 0) return false;
  return true;
}
void dfs(int k, int cnt) {
  if (n == 0) {
    ans = cnt;
    return;
  }
  for (; k < top; k++) {
    if (cnt + n / bus[k].num >= ans) return;
    if (check(bus[k].start, bus[k].ti)) {
      for (int i = bus[k].start, ti = bus[k].ti; i < 60; i += ti) tot[i]--, n--;
      dfs(k, cnt + 1);
      for (int i = bus[k].start, ti = bus[k].ti; i < 60; i += ti) tot[i]++, n++;
    }
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(tot, 0, sizeof(tot));
    for (int tp, i = 0; i < n; i++) scanf("%d", &tp), tot[tp]++;
    top = 0;
    for (int i = 0; i <= 29; i++)
      if (tot[i])
        for (int j = i + 1; i + j < 60; j++)
          if (check(i, j)) bus[top++] = Data(i, j, (59 - i) / j + 1);
    sort(bus, bus + top);
    ans = 17;
    dfs(0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
