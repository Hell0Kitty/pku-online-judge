#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

const int maxn = 100000 + 5;
const double inf = 1000000 + 5;
int n, k;
struct jew {
  int id;
  int v, w;
  double key;
  void cal(double x) { key = v - x * w; }
  bool operator<(const jew& a) const { return key > a.key; }
} j[maxn];

bool c(double x) {
  for (int i = 1; i <= n; i++) {
    j[i].cal(x);
  }
  sort(j + 1, j + n + 1);
  double tmp = 0;
  for (int i = 1; i <= k; i++) tmp += j[i].key;
  return tmp >= 0;
}

int main() {
  while (cin >> n >> k) {
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &j[i].v, &j[i].w);
      j[i].id = i;
    }
    double l = 0, r = inf;
    for (int i = 0; i < 100; i++) {
      double mid = (l + r) / 2;
      if (c(mid))
        l = mid;
      else
        r = mid;
    }
    for (int i = 1; i <= k; i++) {
      if (i - 1)
        printf(" %d", j[i].id);
      else
        printf("%d", j[i].id);
    }
    cout << endl;
  }
}
