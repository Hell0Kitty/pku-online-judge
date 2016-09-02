#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long val_t;
const char split[] = "#";
const int MAX_L = 100000, MAX_N = MAX_L * 2 + 1;
char a[MAX_L + 2], b[MAX_L + 2], c[MAX_N + 2];
int m, sza, szb, n, sa[MAX_N + 1], rank[MAX_N + 1], height[MAX_N + 1],
    cnt[MAX_N + 1];
val_t ans;
int tcnt[MAX_N + 1];

struct node_t {
  int v[2], p;
  bool operator==(const node_t &t) const {
    return v[0] == t.v[0] && v[1] == t.v[1];
  }
} nd[MAX_N + 1], tp[MAX_N + 1];

struct mono_stack_t {
  val_t v[MAX_N + 1][4];
  int stop;
  mono_stack_t() { stop = 0; }
  void clear() { stop = 0; }
  void push(int p, int x) {
    while (stop && x <= v[stop][0]) stop--;
    stop++;
    v[stop][0] = x, v[stop][1] = p;
    v[stop][2] = v[stop - 1][2] + (val_t)(tcnt[p] - tcnt[v[stop - 1][1]]) * x;
    v[stop][3] = v[stop - 1][3] + (val_t)(p - v[stop - 1][1]) * x;
  }
  val_t ask(bool t) {
    if (t)
      return v[stop][2];
    else
      return v[stop][3] - v[stop][2];
  }
} st;

void ra(int b) {
  for (int i = 1; i >= 0; i--) {
    memset(cnt, 0, sizeof(int) * (b + 1));
    for (int j = 1; j <= n; j++) cnt[nd[j].v[i]]++;
    for (int j = 1; j <= b; j++) cnt[j] += cnt[j - 1];
    for (int j = n; j >= 1; j--) tp[cnt[nd[j].v[i]]--] = nd[j];
    memcpy(nd, tp, sizeof(node_t) * (n + 1));
  }
  for (int i = 1, j = 1, k = 1; i <= n; i = j, k++)
    while (j <= n && nd[j] == nd[i]) rank[nd[j++].p] = k;
}

int main() {
  while (scanf("%d", &m) != EOF && m) {
    scanf("%s%s", a + 1, b + 1);
    sza = strlen(a + 1), szb = strlen(b + 1);
    strcpy(c + 1, a + 1);
    strcat(c + 1, split);
    strcat(c + 1, b + 1);
    n = strlen(c + 1);
    for (int i = 1; i <= n; i++) {
      nd[i].v[0] = c[i], nd[i].v[1] = 0;
      nd[i].p = i;
    }
    ra(255);
    for (int s = 1; s < n; s <<= 1) {
      for (int i = 1; i <= n; i++) {
        nd[i].v[0] = rank[i], nd[i].v[1] = i + s <= n ? rank[i + s] : 0;
        nd[i].p = i;
      }
      ra(n);
    }
    for (int i = 1; i <= n; i++) sa[rank[i]] = i;
    for (int i = 1, j, k = 0; i <= n; height[rank[i++]] = k)
      for (k ? k-- : 0, j = sa[rank[i] - 1]; c[i + k] == c[j + k]; k++)
        ;

    ans = 0LL;
    for (int i = 1; i <= n;) {
      int j = i;
      while (j + 1 <= n && height[j + 1] >= m) j++;

      tcnt[0] = 0;
      for (int k = i, p = 0; k <= j; k++, p++)
        tcnt[p + 1] = tcnt[p] + (sa[k] > sza + 1);
      st.clear();
      for (int k = i + 1, p = 0; k <= j; k++) {
        st.push(++p, height[k] - m + 1);
        if (sa[k] <= sza)
          ans += st.ask(1);
        else
          ans += st.ask(0);
      }

      i = j + 1;
    }

    printf("%lld\n", ans);
  }
  return 0;
}
