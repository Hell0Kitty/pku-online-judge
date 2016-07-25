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
#define foreach \
  (it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define DEBUG(a) cout << #a " = " << (a) << endl;
#define DEBUGARR(a, n)                               \
  for (int i = 0; i < (n); i++) {                    \
    cout << #a "[" << i << "] = " << (a)[i] << endl; \
  }

const long long INF = 9e17;
int cnt;

int n, m;
int a[5];
long long Pow[63][55][55];
long long now[55];
long long init[55];
long long tmp[55];
int pos[5][10];

void mul(lld ret[55][55], lld a[55][55], lld b[55][55]) {
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < cnt; j++) {
      ret[i][j] = 0;
      for (int k = 0; k < cnt; k++) {
        if (b[k][j] && a[i][k] > INF / b[k][j]) {
          ret[i][j] = INF;
          break;
        } else if (ret[i][j] + a[i][k] * b[k][j] > INF) {
          ret[i][j] = INF;
          break;
        } else {
          ret[i][j] += a[i][k] * b[k][j];
        }
      }
    }
  }
}

void _mul(lld ret[55], lld a[55], lld b[55][55]) {
  for (int j = 0; j < cnt; j++) {
    ret[j] = 0;
    for (int k = 0; k < cnt; k++) {
      if (b[k][j] && a[k] > INF / b[k][j]) {
        ret[j] = INF;
        break;
      } else if (ret[j] + a[k] * b[k][j] > INF) {
        ret[j] = INF;
        break;
      } else {
        ret[j] += a[k] * b[k][j];
      }
    }
  }
}

bool tooBig(long long ans) {
  for (int j = 0; j < m; j++) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += tmp[pos[i][j]];
      if (sum >= ans) return 1;
    }
  }
  return 0;
}
int clzll(lld x) {
  for (int i = 62; i >= 0; --i)
    if (x & 1ll << i) return i;
}
long long gao(long long ans) {
  if (ans == 1) return a[0] - 1;
  memcpy(now, init, sizeof(now));
  long long ret = 0;
  for (int i = clzll(ans * 100ll); i >= 0; i--) {
    _mul(tmp, now, Pow[i]);
    if (!tooBig(ans)) {
      ret |= 1LL << i;
      for (int i = 0; i < cnt; i++) now[i] = tmp[i];
    }
  }
  return ret;
}

int main() {
  int tcc = 0;
  while (scanf("%d", &n) && n) {
    printf("Set %d\n", ++tcc);
    int g = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      g = __gcd(g, a[i]);
    }
    m = 0;
    for (int i = 0; i < n; ++i) m = max(m, a[i] /= g);
    sort(a, a + n);
    cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        pos[i][j] = cnt++;
      }
    }
    memset(Pow[0], 0, sizeof(Pow[0]));
    memset(now, 0, sizeof(now));
    now[pos[0][m - 1]] = 1;
    memcpy(init, now, sizeof(init));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j + 1 < m; j++) {
        Pow[0][pos[i][j + 1]][pos[i][j]] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        Pow[0][pos[j][m - a[i]]][pos[i][m - 1]] = 1;
      }
    }
    for (int i = 1; i < 63; i++) {
      mul(Pow[i], Pow[i - 1], Pow[i - 1]);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      long long x;
      cin >> x;
      long long ret = gao(x);
      if (ret > 100 * x) {
        puts("no candy for you");
      } else {
        cout << (ret + 1) * g << "\n";
      }
    }
  }
}
