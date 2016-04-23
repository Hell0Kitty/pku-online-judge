#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100005;
char s[N];
int n, sa[N], height[N], rank[N], tmp[N], top[N];
void makesa() {
  int i, j, len, na;
  na = max(256, n);
  memset(top, 0, sizeof(top));
  for (i = 0; i < n; i++) top[rank[i] = (s[i] & 0xff)]++;
  for (i = 1; i < na; i++) top[i] += top[i - 1];
  for (int i = 0; i < n; i++) sa[--top[rank[i]]] = i;
  for (len = 1; len < n; len <<= 1) {
    for (i = 0; i < n; i++) {
      j = sa[i] - len;
      if (j < 0) j += n;
      tmp[top[rank[j]]++] = j;
    }
    sa[tmp[top[0] = 0]] = j = 0;
    for (i = 1; i < n; i++) {
      if (rank[tmp[i]] != rank[tmp[i - 1]] ||
          rank[tmp[i] + len] != rank[tmp[i - 1] + len])
        top[++j] = i;
      sa[tmp[i]] = j;
    }
    memcpy(rank, sa, sizeof(int) * n);
    memcpy(sa, tmp, sizeof(int) * n);
    if (j >= n - 1) break;
  }
}
void lcp() {
  int i, j, k;
  for (j = rank[height[i = k = 0] = 0]; i < n - 1; i++, k++) {
    while (k >= 0 && s[i] != s[sa[j - 1] + k])
      height[j] = k--, j = rank[sa[j] + 1];
  }
}
int st[40][N];
void initrmq() {
  int i, j, k, sk;
  for (i = 0; i < n; i++) st[0][i] = height[i];
  for (i = 1, k = 2; k < n; i++, k <<= 1) {
    for (j = 0, sk = (k >> 1); j < n; j++, sk++) {
      st[i][j] = st[i - 1][j];
      if (sk < n && st[i][j] > st[i - 1][sk]) {
        st[i][j] = st[i - 1][sk];
      }
    }
  }
}
int lg[N];
int query(int x, int y) {
  if (x > y) swap(x, y);
  x++;
  int b = lg[y - x + 1];
  return min(st[b][x], st[b][y - (1 << b) + 1]);
}
struct data {
  int len, r, pos;
  data() {}
  data(int _len, int _r, int _pos) {
    len = _len;
    r = _r;
    pos = _pos;
  }
  bool operator<(const data &ne) const {
    if (r != ne.r) return r < ne.r;
    return rank[pos] > rank[ne.pos];
  }
};
int main() {
  int ca = 0;
  lg[0] = -1;
  for (int i = 1; i < N; i++) {
    lg[i] = (i & (i - 1)) ? lg[i - 1] : (lg[i - 1] + 1);
  }
  while (gets(s), strcmp(s, "#") != 0) {
    n = strlen(s) + 1;
    makesa();
    lcp();
    initrmq();
    int a, b;
    data ans(1, 1, 0);
    for (int ll = 1; ll < n; ll++) {
      for (int i = 0; i + ll < n; i += ll) {
        int t, r, k = query(rank[i], rank[i + ll]);
        r = k / ll + 1;
        t = i - ll + k % ll;
        if (t >= 0 && k % ll != 0 && query(rank[t], rank[t + ll]) >= k) {
          r++;
          while (t >= 0 && t > i - ll && query(rank[t], rank[t + ll]) >= k) {
            data tp(ll, r, t);
            if (ans < tp) ans = tp;
            t--;
          }
        } else {
          data tp(ll, r, i);
          if (ans < tp) ans = tp;
        }
      }
    }
    s[ans.pos + ans.len * ans.r] = '\0';
    printf("Case %d: %s\n", ++ca, s + ans.pos);
  }
  return 0;
}
