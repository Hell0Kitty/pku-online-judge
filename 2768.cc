#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;
template <class T>
void checkmin(T &t, T x) {
  if (x < t) t = x;
}
template <class T>
void checkmax(T &t, T x) {
  if (x > t) t = x;
}
template <class T>
void _checkmin(T &t, T x) {
  if (t == -1) t = x;
  if (x < t) t = x;
}
template <class T>
void _checkmax(T &t, T x) {
  if (t == -1) t = x;
  if (x > t) t = x;
}
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long lld;
#define foreach (it, v) \
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define DEBUG(a) cout << #a " = " << (a) << endl;
#define DEBUGARR(a, n)                               \
  for (int i = 0; i < (n); i++) {                    \
    cout << #a "[" << i << "] = " << (a)[i] << endl; \
  }
#define maxn 100000
#define oo 20000
int f[maxn][3], son[maxn][4], trup[maxn];
void calc(int now, int fa) {
  int L = -1, R = -1;

  if (trup[now]) {
    f[now][0] = oo, f[now][1] = 0;
    f[now][2] = 0;
    return;
  }
  for (int i = 1; i <= son[now][0]; i++)
    if (son[now][i] != fa) {
      if (L == -1)
        L = son[now][i];
      else
        R = son[now][i];
      calc(son[now][i], now);
    }
  if (L == -1) {
    f[now][0] = f[now][1] = 0;
    f[now][2] = 1;
  } else if (R == -1) {
    // one
    f[now][0] = f[L][0];
    f[now][1] = f[L][1];
    f[now][2] = f[L][2];
  } else {
    f[now][0] = f[L][0] + f[R][0];
    f[now][1] = min(f[L][0] + f[R][1], f[L][0] + f[R][2]);
    checkmin(f[now][1], min(f[R][0] + f[L][1], f[R][0] + f[L][2]));
    f[now][2] = min(f[now][1], f[now][0]) + 1;
    checkmin(f[now][2], f[L][2] + f[R][2]);
  }
}

int N, M;
int main() {
  int i, j, a;
  while (scanf("%d%d", &N, &M)) {
    if (N == 0 && M == 0) break;
    for (i = 1; i <= N; i++) {
      scanf("%d", &son[i][0]);
      for (j = 1; j <= son[i][0]; j++) scanf("%d", &son[i][j]);
      trup[i] = 0;
    }

    for (i = 0; i < M; i++) scanf("%d", &a), trup[a] = 1;

    calc(1, -1);
    printf("%d\n", f[1][2]);
  }
}
