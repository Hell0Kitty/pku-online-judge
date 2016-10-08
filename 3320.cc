#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
using namespace std;
const int maxn = 1e6 + 1000;
int n, a[maxn], ans;
set<int> s;
map<int, int> f;
int main() {
  while (scanf("%d", &n) != EOF) {
    s.clear();
    f.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      s.insert(a[i]);
    }
    int cnt = s.size(), pre = 0, last = 0, now = 0;
    ans = n;
    while (1) {
      while (last < n && now < cnt) {
        if (!f[a[last]]) now++;
        f[a[last++]]++;
      }
      while (f[a[pre]] > 1) f[a[pre++]]--;
      if (now == cnt) {
        ans = min(ans, last - pre);
        f[a[pre++]]--;
        now--;
      }
      if (last == n) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
