#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
#define NN 101000

struct node {
  int a, b;
  bool operator<(const node &y) const { return b > y.b; }
} a[NN], w[NN], tn;

bool cmp(const node &a, const node &b) { return a.a < b.a; }

int main() {
  int n, m, i, tot, p;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].a, &a[i].b);
  }
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &w[i].a, &w[i].b);
  }
  multiset<node> st;
  multiset<node>::iterator it;
  sort(a + 1, a + n + 1, cmp);
  sort(w + 1, w + m + 1, cmp);

  tot = 0;
  p = 1;
  long long ans = 0;
  for (i = 1; i <= m; ++i) {
    while (p <= n && a[p].a <= w[i].a) {
      st.insert(a[p]);
      ++p;
    }
    it = st.lower_bound(w[i]);
    if (it != st.end()) {
      st.erase(it);
      tot++;
      ans += w[i].a;
    }
    if (tot == n) break;
  }

  if (tot == n)
    printf("%I64d\n", ans);
  else
    printf("-1\n");
  return 0;
}
