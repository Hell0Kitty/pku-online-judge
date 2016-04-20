#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps = 1e-8, pi = acos(-1.0);
int cl(double z) { return ceil(z - eps); }
int flr(double z) { return floor(z + eps); }
long long cll(double z) { return ceil(z - eps); }
long long flrl(double z) { return floor(z + eps); }
int dblcmp(double d) { return (d < -eps) ? -1 : (d > eps); }
const int inf = 999999999;
const long long infl = 999999999999999999LL;
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define ctz __builtin_ctz
#define popcount __builtin_popcount
#define gch c = getchar()
#define clr(z, w) memset(z, w, sizeof(z))
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define MII map<int, int>
#define MLL map<long long, long long>

#define REP(z, a, b) for (int z = (a); z <= (b); z++)
#define RREP(z, a, b) for (int z = (a); z >= (b); z--)
#define FREP(z, a, b, f)           \
  for (int z = (a); z <= (b); z++) \
    if (f)
#define CREP(p, z) for (char *p = (z); *p; p++)
#define VREP(z, t) \
  for (vector<t>::iterator it = (z).begin(); it != (z).end(); ++it)
#define MREP(z, t1, t2) \
  for (map<t1, t2>::iterator it = (z).begin(); it != (z).end(); it++)
#define FOR_WORD_IN_LINE   \
  gets(buf);               \
  string line = buf, word; \
  istringstream in(line);  \
  while (in >> word)

#define RDS(z) scanf("%s", z)
#define RDL(z) scanf("%lld", &z)
#define RD1(z) scanf("%d", &z)
#define RD2(z, o) scanf("%d%d", &z, &o)
#define RD3(z, o, v) scanf("%d%d%d", &z, &o, &v)

#define PTS(z) printf("%s\n", z)
#define PTL(z) printf("%lld\n", z)
#define PT1(z) printf("%d\n", z)
#define PT2(z, o) printf("%d %d\n", z, o)
#define PT3(z, o, v) printf("%d %d %d\n", z, o, v)
#define PTA(arr, a, b) REP(z, a, b) printf("%d%c", arr[z], " \n"[z == b])
#define PTAL(arr, a, b) REP(z, a, b) printf("%lld%c", arr[z], " \n"[z == b])

#define FMT(z, w)            \
  do {                       \
    REP(o, 1, w) putchar(z); \
  } while (0)
#define DBG(z)                        \
  do {                                \
    printf("---------------DEBUG: "); \
    cout << z << endl;                \
  } while (0)
#define FDBG(z, f)                               \
  do {                                           \
    if (flag) printf("---------------FDEBUG: "); \
    cout << z << endl;                           \
  } while (0)
#define JDBG(z, j)                       \
  do {                                   \
    static int w = 0;                    \
    if (++w % j == 0) {                  \
      printf("---------------JDEBUG: "); \
      cout << z << endl;                 \
    }                                    \
  } while (0)

template <class T>
inline void checkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline bool fcheckmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
template <class T>
inline bool fcheckmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <class T>
inline double dist(T a, T b) {
  return sqrt(a * 1.0 * a + b * 1.0 * b);
}

//=======================================================================================

///#define
/// U_Set//-----------------------------------------------------------------------
#ifdef U_Set
const int max_set = 100005;
int pos[max_set];
int getfather(int i) {
  return (pos[i] == i) ? i : (pos[i] = getfather(pos[i]));
}
void combine(int i, int j) {
  int I = getfather(i), J = getfather(j);
  if (I != J) pos[I] = J;
}
#endif

///#define
/// Trie//------------------------------------------------------------------------
#ifdef Trie
struct tnode {
  tnode *x[26];
  int id;
};
struct trie {
  tnode pool[255 * 1005];
  tnode *root;
  int top, wd;
  void nn(tnode *&ptr) {
    if (ptr) return;
    memset(&pool[++top], 0, sizeof(tnode));
    ptr = &pool[top];
  }
  void init() {
    root = 0;
    top = wd = 0;
    nn(root);
  }
  trie() { init(); }
  int insert(char *s) {
    tnode *p = root;
    for (; *s; s++) {
      int i = *s - 'a';
      nn(p->x[i]);
      p = p->x[i];
    }
    return p->id ? p->id : (p->id = ++wd);
  }
};
trie X;
#endif

///#define
/// TreeDP//----------------------------------------------------------------------
#ifdef TreeDP
struct node {
  int id;
  node *x;
};
struct tree {
  node pool[maxn * 3];
  int tot;
  void init(int n) {
    tot = n + 1;
    REP(i, 0, n) pool[i].x = 0;
  }
  node *nn(int id, node *x) {
    node *p = &pool[tot++];
    p->id = id;
    p->x = x;
    return p;
  }
  void push(int a, int b) { pool[a].x = nn(b, pool[a].x); }
};
tree T;
void dfs(Tree &t, int p, int f) {
  for (node *s = t.pool[p].x; s; s = s->x)
    if (s->id != f) {
      dfs(t, s->id, p);
    }
}
void solve() {
  int n, a, b;
  RD1(n);
  T.init(n);
  REP(i, 1, n - 1) {
    RD2(a, b);
    T.push(a, b);
  }
}
#endif

///#define
/// MEM_String//------------------------------------------------------------------
#ifdef MEM_String
struct memstring {
  char mpool[200005];
  char *mptr[100005];
  int mtop, mcount;
  void init() { mtop = mcount = 0; }
  char *getstring(int id) { return mptr[id]; }
  void insert(char *w) {
    strcpy(mpool + mtop, w);
    mptr[++mcount] = mpool + mtop;
    mtop += strlen(w) + 1;
  }
};
#endif

///#define
/// Directions//------------------------------------------------------------------
#ifdef Directions
//     ==GRID=={O,R,L,D,U}    ==AXIS=={O,U,D,R,L}
const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, 1, -1, 0, 0};
#endif

///#define
/// Hashing//---------------------------------------------------------------------
#ifdef Hashing
int table[1000005], tsize;  ///[0,tsize)
void init_table() {
  sort(table, table + tsize);
  tsize = unique(table, table + tsize) - table;
}
int get_index(int key) {
  return lower_bound(table, table + tsize, key) - table;
}
#endif

///#define
/// Primes//---------------------------------------------------------------------
#ifdef Primes
const int size = 10000005;
bool notp[size];
int pr[size / 10], pn;  // int minfac[size];
void getprime() {
  int i, j;
  notp[0] = notp[1] = 1;
  for (i = 2; i < size; i++) {
    if (!notp[i]) { /*minfac[i]=pn;*/
      pr[pn++] = i;
    }
    for (j = 0; j < pn; j++) {
      int x = pr[j] * i;
      if (x >= size) break;
      notp[x] = 1; /*minfac[x]=j;*/
      if (i % pr[j] == 0) break;
    }
  }
}
#endif

#ifdef BIT
#define lowbit(z) (z & (-z))
#define TYPE int
TYPE c[100005];
int size;
void change(TYPE *c, int i, TYPE d) {
  for (; i <= size; i += lowbit(i)) c[i] += d;
}
TYPE getsum(TYPE *c, int i) {
  TYPE s = 0;
  for (; i > 0; i -= lowbit(i)) s += c[i];
  return s;
}
#endif

#define INIT_GRAPH(z, a, b)                  \
  do {                                       \
    REP(i, a, b) REP(j, a, b) z[i][j] = inf; \
    REP(i, a, b) z[i][i] = 0;                \
  } while (0)
#define MCASE            \
  do {                   \
    int _;               \
    scanf("%d", &_);     \
    while (_--) solve(); \
  } while (0)
#define SCASE \
  do {        \
    solve();  \
  } while (0)
#define pl p << 1
#define pr p << 1 | 1
inline int pinput() {
  int S = 0, gch;
  while (!isdigit(c)) gch;
  while (isdigit(c)) {
    S = S * 10 + c - 48;
    gch;
  }
  return S;
}
#define LL long long

char buf[1000005];
int a[1005];

int dp1[1005][1005];
int dp2[1005][1005];
void solve() {
  int n, k;
  while (RD2(n, k), n) {
    REP(i, 1, n) RD1(a[i]);
    if (n == k) {
      puts("Yes");
      continue;
    }
    REP(i, 0, n) REP(j, 0, n) { dp1[i][j] = dp2[i][j] = -inf; }
    dp1[1][1] = a[1];
    dp2[1][0] = 0;
    REP(i, 2, n) {
      dp2[i][0] = 0;
      REP(j, 1, i) {
        dp1[i][j] =
            max(max(dp1[i - 1][j - 1], dp2[i - 1][j - 1]), dp1[i - 1][j]) +
            a[i];
        dp2[i][j] = max(dp1[i - 1][j], dp2[i - 1][j]);
      }
    }
    if (dp1[n][k] == dp2[n][k]) {
      puts("No");
      continue;
    }
    int ans = max(dp1[n][k], dp2[n][k]);
    int i = n;
    int j = k;
    bool dup = false;
    int must1 = false;
    while (i > 1 && j > 0) {
      int dp;
      if (must1 || dp1[i][j] > dp2[i][j]) {
        must1 = 0;
        dp = dp1[i][j] - a[i];
        int cnt = (dp1[i - 1][j - 1] == dp) + (dp2[i - 1][j - 1] == dp) +
                  (dp1[i - 1][j] == dp);
        if (cnt == 0)
          while (1)
            ;
        if (cnt != 1) {
          dup = true;
          break;
        }
        if (dp1[i - 1][j] == dp) {
          i--;
          must1 = 1;
        } else {
          i--;
          j--;
        }
        continue;
      } else if (dp1[i][j] < dp2[i][j]) {
        dp = dp2[i][j];
        int cnt = (dp1[i - 1][j] == dp) + (dp2[i - 1][j] == dp);
        if (cnt == 0)
          while (1)
            ;
        if (cnt != 1) {
          dup = true;
          break;
        }
        i--;
        continue;
      } else {
        dup = true;
        break;
      }
    }
    if (dup)
      puts("No");
    else
      puts("Yes");
  }
}

int main() { SCASE; }
