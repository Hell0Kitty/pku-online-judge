#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <limits>
using namespace std;
typedef long long ll;
const int inf = 1000000000;
const double pi = acos(-1.0);
#define eps (1e-15)
#define clr clear
#define PB push_back
#define SZ(x) ((int)(x).size())
#define MP make_pair
#define X first
#define Y second
#define PII pair<int, int>
#define VI vector<int>
#define VD vector<double>
#define VS vector<string> dd
#define FORD(i, b, c) for (int(i) = (b); (i) >= c; (i)--)
#define REPD(i, c) FORD(i, c, 0)
#define FOR(i, b, c) for (int i = (b); i < (c); i++)
#define REP(i, c) FOR(i, 0, c)
#define PQ priority_queue
#define L(x) ((x) << 1)
#define R(x) ((x) << 1 | 1)
#ifdef DBG
#define see(x) \
  (cerr << "[Line : " << __LINE__ << "] : " << #x << "=" << x << endl)
#define se(x) cerr << x << " "
#else
#define see(x)  //
#define se(x)   //
#endif

#define maxn 500010
int n, m;
int first[maxn], next[maxn], E[maxn], M, C[maxn];
int down[maxn], flag[maxn], in[maxn];
void _insert(int a, int b, int c) {
  in[a]++;
  M++;
  next[M] = first[a];
  first[a] = M;
  E[M] = b;
  C[M] = c;
}

void insert(int a, int b, int c) {
  _insert(a, b, c);
  _insert(b, a, c);
}

void init() {
  memset(first, -1, sizeof(first));
  M = 0;
}

void dfs(int u, int f) {
  int i, e, j;
  int v, res = 0;
  for (e = first[u]; e != -1; e = next[e]) {
    v = E[e];
    if (!flag[v]) {
      flag[v] = 1;
      dfs(v, C[e]);
      if (in[v] == 1) {
        down[u] += C[e];
      } else {
        down[u] += min(C[e], down[v]);
      }
      flag[v] = 0;
    }
  }
}

int ans = 0;
void dfs2(int u, int f) {
  int i, e, j, v, res = 0;

  for (e = first[u]; e != -1; e = next[e]) {
    v = E[e];
    if (!flag[v]) {
      flag[v] = 1;
      ans = max(ans, f + down[u]);
      int tp = down[u] + f - C[e];
      if (tp == 0) tp = C[e];
      dfs2(v, min(tp, C[e]));
      flag[v] = 0;
    }
  }
  if (in[u] == 1) {
    ans = max(ans, f);
  }
}
int main() {
  int i, j, k, t;
  scanf("%d", &t);
  while (t--) {
    memset(in, 0, sizeof(in));
    memset(flag, 0, sizeof(flag));
    init();
    int a, b, c;
    scanf("%d", &n);
    for (i = 0; i < n - 1; i++) {
      scanf("%d%d%d", &a, &b, &c);
      insert(a, b, c);
    }

    memset(down, 0, sizeof(down));
    flag[1] = 1;
    dfs(1, 0);

    ans = 0;
    dfs2(1, 0);
    printf("%d\n", ans);
  }
}
