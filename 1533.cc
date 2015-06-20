
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
#define pb push_back
#define all(c) c.begin(), c.end()
#define start(side) s[id[side]][p[side]]
#define end(side, len) s[id[side]][p[side] + len]
// 13C
#define DBG 1
#define sz(c) ((int)(c).size())
#define forl(i, a, b) for (int i = (a); i < (b); ++i)
#define forle(i, a, b) for (int i = (a); i <= (b); ++i)
#define forg(i, a, b) for (int i = (a); i > (b); --i)
#define forge(i, a, b) for (int i = (a); i >= (b); --i)
#define forlc(i, a, b) for (int i##_b = (b), i = (a); i < i##_b; ++i)
#define forlec(i, a, b) for (int i##_b = (b), i = (a); i <= i##_b; ++i)
#define forgc(i, a, b) for (int i##_b = (b), i = (a); i > i##_b; --i)
#define forgec(i, a, b) for (int i##_b = (b), i = (a); i >= i##_b; --i)
#define forall(i, v) forl(i, 0, sz(v))
#define forallc(i, v) forlc(i, 0, sz(v))
#define forlla(i, v) forge(i, sz(v) - 1, 0)
#define forls(i, n, a, b) for (int i = a; i != b; i = n[i])
#define rep(n) for (int repp = 0; repp < (n); ++repp)
#define repc(n) for (int repp_b = (n), repp = 0; repp < repp_b; ++repp)
#define rst(a, v) memset(a, v, sizeof a)
#define cpy(a, b) memcpy(a, b, sizeof a)
#define rstn(a, v, n) memset(a, v, (n) * sizeof((a)[0]))
#define cpyn(a, b, n) memcpy(a, b, (n) * sizeof((a)[0]))
#define ast(b)                   \
  if (DBG && !(b)) {             \
    printf("%d!!|\n", __LINE__); \
    while (1) getchar();         \
  }
#define dout DBG &&cout << __LINE__ << ">>| "
#define pr(x) #x "=" << (x) << " | "
#define mk(x) DBG &&cout << __LINE__ << "**| " #x << endl
#define pra(arr, a, b)                                         \
  if (DBG) {                                                   \
    dout << #arr "[] | ";                                      \
    forlec(i, a, b) cout << "[" << i << "]=" << arr[i] << " |" \
                         << ((i - (a) + 1) % 13 ? " " : "\n"); \
    if (((b) - (a) + 1) % 13) puts("");                        \
  }
#define rd(type, x) \
  type x;           \
  cin >> x
inline int rdi() {
  int d;
  scanf("%d", &d);
  return d;
}
inline char rdc() {
  scanf(" ");
  return getchar();
}
inline string rds() {
  rd(string, s);
  return s;
}
inline double rddb() {
  double d;
  scanf("%lf", &d);
  return d;
}
template <class T>
inline bool updateMin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool updateMax(T &a, T b) {
  return a < b ? a = b, true : false;
}

const int N = 128, M = 1024, S = 16384, h = N - 1, t = N - 2;

int L[N], R[N];
int len, ans[S];
int n, m, cnt[N], has[N][N];
int ne, head[N], vex[M], nxt[M];

void link(int l, int r) { R[l] = r, L[r] = l; }
void init_list() {
  int pre = h;
  forl(i, 0, n) if (cnt[i]) link(pre, i), pre = i;
  link(pre, t);
}
void del(int i) { L[R[i]] = L[i], R[L[i]] = R[i]; }
void ins(int i) { L[R[i]] = i, R[L[i]] = i; }

void add_edge(int u, int v) {
  ++ne;
  vex[ne] = v;
  nxt[ne] = head[u];
  head[u] = ne;
}

bool possible() {
  forl(i, 0, n) if (head[i] && !cnt[i]) return false;
  forle(i, 1, ne) if (!cnt[vex[i]]) return false;
  return true;
}

bool valid(int r) {
  if (cnt[r]) return true;
  forls(i, nxt, head[r], 0) if (!has[vex[i]][r]) return false;
  return true;
}

void add_has(int dep) { forl(i, 0, dep)++ has[ans[i]][ans[dep]]; }
void del_has(int dep) { forl(i, 0, dep)-- has[ans[i]][ans[dep]]; }
bool dfs(int dep) {
  if (dep == len) return true;
  forls(i, R, R[h], t) {
    ans[dep] = i;
    if (add_has(dep), --cnt[i] == 0) del(i);
    if (valid(i) && dfs(dep + 1)) return true;
    if (del_has(dep), ++cnt[i] == 1) ins(i);
  }
  return false;
}

int main() {
  while (scanf("%d %d", &n, &m) == 2 && m) {
    rst(has, false);
    rst(head, 0), ne = 0;
    forl(i, 0, n) cnt[i] = rdi();
    init_list(), len = accumulate(cnt, cnt + n, 0);
    rep(m) {
      int l, r;
      scanf("%d %d", &l, &r);
      add_edge(r, l);
    }
    if (possible() && dfs(0))
      forl(i, 0, len) printf("%d%c", ans[i], i < len - 1 ? ' ' : '\n');
    else
      puts("Impossible!");
  }
  return 0;
}