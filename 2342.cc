#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Long;
typedef double DD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<Long, Long> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

const int INF = 2000000000;
const int MOD = 1000000007;

#define sf scanf
#define pf printf
#define mem(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPI(i, a, b, c) for (int i = a; i <= b; i += c)
#define REPR(i, a, b) for (int i = b; i >= a; --i)
#define REPRD(i, a, b, c) for (int i = b; i >= a; i -= c)
#define REPB(i, a) for (int i = a;; i++)
#define REPRB(i, a) for (int i = a;; i--)
#define mp(a, b) make_pair(a, b)
#define fs first
#define sc second
#define SZ(s) ((int)s.size())
#define PI 3.141592653589793
#define VS vector<string>
#define VI vector<int>
#define VD vector<DD>
#define VL vector<Long>
#define VVL vector<VL>
#define lim 6001
#define tlim (1 << ((int)ceil(log2(lim)) + 1))
#define unq(vec)                       \
  stable_sort(vec.begin(), vec.end()); \
  vec.resize(distance(vec.begin(), unique(vec.begin(), vec.end())));
#define BE(a) a.begin(), a.end()
#define rev(a) reverse(BE(a))
#define sorta(a) stable_sort(BE(a))
#define sortc(a, comp) sort(BE(a), comp)

VVI G;
int DP[lim][2], ind[lim];
void DFS(int par, int c) {
  REP(i, 0, (SZ(G[c]) - 1)) {
    int v = G[c][i];
    if (v == par) continue;
    DFS(c, v);
    DP[c][0] += max(DP[v][0], DP[v][1]);
    DP[c][1] += DP[v][0];
  }
  return;
}
int main(int argc, const char **argv) {
  int N, L, K, root;
  while (~sf("%d", &N)) {
    REP(i, 1, N) sf("%d", &DP[i][1]), DP[i][0] = 0;
    G = VVI(N + 1, VI(0));
    mem(ind, 0);
    while (~sf("%d %d", &L, &K) and (L + K)) {
      G[K].pb(L);
      ind[L]++;
    }
    REP(i, 1, N) if (!ind[i]) {
      root = i;
      break;
    }
    DFS(0, root);
    pf("%d\n", max(DP[root][0], DP[root][1]));
  }
  return 0;
}
