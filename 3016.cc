#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}

const int N = 1005;

int c[2][N][N];
int f[15][N];
int a[N], b[N];
int n, m;

int mid[N], size[N], l[N], r[N], h[N], g[N];

void merge(int &x, int &y) {
  if (b[x] < b[y]) swap(x, y);
  if (y == 0) return;
  merge(r[x], y);
  swap(l[x], r[x]);
}

int cal(int i) { return h[i] - 2 * g[i] + (2 - (size[i] & 1)) * b[mid[i]]; }

void work(int i, int gxx) {
  int ed = 0;
  int cost = 0;
  for (int j = i; j <= n; ++j) {
    ++ed;
    mid[ed] = j;
    size[ed] = 1;
    l[j] = r[j] = 0;
    h[ed] = g[ed] = b[j];
    while (ed > 1 && b[mid[ed]] < b[mid[ed - 1]]) {
      cost -= cal(ed);
      --ed;
      cost -= cal(ed);
      merge(mid[ed], mid[ed + 1]);
      size[ed] += size[ed + 1];
      h[ed] += h[ed + 1];
      g[ed] += g[ed + 1];
      if (size[ed] & 1) {
        merge(l[mid[ed]], r[mid[ed]]);
        g[ed] -= b[mid[ed]];
        mid[ed] = l[mid[ed]];
      }
      cost += cal(ed);
    }
    c[gxx][i][j] = cost;
  }
}

int main() {
#ifdef LOCAL_TEST
  freopen("c.in", "r", stdin);
//		freopen("c.out","w",stdout);
#endif
  b[0] = -lim;
  while (1) {
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      b[i] = a[i] - i;
    }
    for (int i = 1; i <= n; ++i) work(i, 0);
    for (int i = 1; i <= n; ++i) b[i] = -a[i] - i;
    for (int i = 1; i <= n; ++i) work(i, 1);
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; ++j) c[0][i][j] = min(c[0][i][j], c[1][i][j]);
    for (int i = 0; i <= m; ++i)
      for (int j = 1; j <= n; ++j) f[i][j] = lim;
    f[0][0] = 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        for (int k = 1; k <= j; ++k)
          f[i][j] = min(f[i][j], f[i - 1][k - 1] + c[0][k][j]);
    cout << f[m][n] << endl;
  }
  return 0;
}
