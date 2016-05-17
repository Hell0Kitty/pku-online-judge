#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 200000, MAX_R = MAX_N * 2;
int n, s[MAX_R + 1], sa[MAX_R + 1], rank[MAX_R + 1], height[MAX_R + 1],
    cnt[MAX_R + 1];
int t[MAX_R + 1], o[MAX_N + 1], m;

struct node_t {
  int v[2], p;
  bool operator==(const node_t &t) const {
    return v[0] == t.v[0] && v[1] == t.v[1];
  }
} nd[MAX_R + 1], tp[MAX_R + 1];

int find(int x) {
  int l = 1, r = m + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (o[mid] <= x)
      l = mid;
    else
      r = mid;
  }
  return l;
}

void ra(int b, int l) {
  for (int i = 1; i >= 0; i--) {
    memset(cnt, 0, sizeof(int) * (b + 1));
    for (int j = 1; j <= l; j++) cnt[nd[j].v[i]]++;
    for (int j = 1; j <= b; j++) cnt[j] += cnt[j - 1];
    for (int j = l; j >= 1; j--) tp[cnt[nd[j].v[i]]--] = nd[j];
    memcpy(nd, tp, sizeof(node_t) * (l + 1));
  }
  for (int i = 1, j = 1, k = 1; i <= l; i = j, k++)
    while (j <= l && nd[j] == nd[i]) rank[nd[j++].p] = k;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  memcpy(o + 1, s + 1, sizeof(int) * n);
  sort(o + 1, o + n + 1);
  m = unique(o + 1, o + n + 1) - (o + 1);
  for (int i = 1; i <= n; i++) s[i] = find(s[i]);

  memcpy(t + 1, s + 1, sizeof(int) * n);
  reverse(t + 1, t + n + 1);
  for (int i = 1; i <= n; i++) nd[i].v[0] = t[i], nd[i].v[1] = 0, nd[i].p = i;
  ra(m, n);
  for (int st = 1; st < n; st <<= 1) {
    for (int i = 1; i <= n; i++) {
      nd[i].v[0] = rank[i], nd[i].v[1] = i + st <= n ? rank[i + st] : 0;
      nd[i].p = i;
    }
    ra(n, n);
  }
  for (int i = 1; i <= n; i++) sa[rank[i]] = i;

  int fir = 1;
  while (sa[fir] <= 2) fir++;
  for (int i = sa[fir]; i <= n; i++) printf("%d\n", o[t[i]]);
  memset(t, 0, sizeof(t));
  int new_n = sa[fir] - 1;
  for (int i = 1; i <= new_n; i++) t[i] = s[i + n - sa[fir] + 1];
  reverse(t + 1, t + new_n + 1);
  for (int i = 1; i <= new_n; i++) t[i + new_n] = t[i];
  new_n *= 2;
  for (int i = 1; i <= new_n; i++)
    nd[i].v[0] = t[i], nd[i].v[1] = 0, nd[i].p = i;
  ra(m, new_n);
  for (int st = 1; st < new_n; st <<= 1) {
    for (int i = 1; i <= new_n; i++) {
      nd[i].v[0] = rank[i], nd[i].v[1] = i + st <= new_n ? rank[i + st] : 0;
      nd[i].p = i;
    }
    ra(new_n, new_n);
  }
  for (int i = 1; i <= new_n; i++) sa[rank[i]] = i;
  fir = 1;
  while (sa[fir] > new_n / 2 || sa[fir] == 1) fir++;
  for (int i = 0; i < new_n / 2; i++) printf("%d\n", o[t[sa[fir] + i]]);

  return 0;
}
