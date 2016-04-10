#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u >> 1;
template <class T>
bool get_max(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
bool get_min(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}

const int maxn = 1000 + 100;

int CS, a[12][maxn], x[maxn];
int n, ans, equ, var;
struct node {
  int year, w[12];
} vec[maxn];

bool cmp(node a, node b) { return a.year < b.year; }
void init() {
  int t[12];
  scanf("%d", &n);
  for (int i = 1; i <= 11; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= 11; i++) scanf("%d", &vec[n + 1].w[i]);
  for (int i = 1; i <= 11; i++) {
    vec[n + 1].w[i] -= t[i];
    vec[n + 1].w[i] = (vec[n + 1].w[i] + 11) % 11;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 11; j++) {
      scanf("%d", &vec[i].w[j]);
      vec[i].w[j] = (vec[i].w[j] + 11) % 11;
    }
    scanf("%d", &vec[i].year);
  }
}
bool eliminate() {
  int k, ta, tb, max_r, col, gcd;
  col = 1;
  for (k = 1; k <= equ && col <= var; k++, col++) {
    max_r = k;
    for (int i = k + 1; i <= equ; i++) {
      if (abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
    }
    if (max_r != k) {
      for (int j = k; j <= var + 1; j++) swap(a[k][j], a[max_r][j]);
    }
    if (a[k][col] == 0) {
      k--;
      continue;
    }
    for (int i = k + 1; i <= equ; i++) {
      if (a[i][col] != 0) {
        gcd = __gcd(abs(a[i][col]), abs(a[k][col]));
        ta = a[k][col] / gcd;
        tb = a[i][col] / gcd;
        if (a[i][col] * a[k][col] < 0) tb = -tb;
        for (int j = col; j <= var + 1; j++) {
          a[i][j] = ((a[i][j] * ta) % 11 - (a[k][j] * tb) % 11 + 11) % 11;
        }
      }
    }
  }
  for (int i = k; i <= equ; i++) {
    if (a[i][col] % 11 != 0) return false;
  }
  return true;
}
int backsub() {
  int k = min(11, n);
  for (int i = 1; i <= 11; i++) {
    for (int j = 1; j <= n + 1; j++) printf("%d ", a[i][j]);
    printf("\n");
  }
  printf("\n");
  while (k > 0 && a[k][n] == 0) {
    if (a[k][n + 1] != 0) return -1;
    k--;
  }
  if (k < n) return n - k;
  return 0;
}
bool solve(int nth) {
  for (int i = 1; i <= nth; i++)
    for (int j = 1; j <= 11; j++) a[j][i] = vec[i].w[j];
  for (int i = 1; i <= 11; i++) a[i][nth + 1] = vec[n + 1].w[i];
  equ = 11;
  var = nth;
  bool flag = eliminate();
  return flag;
}

int main() {
  scanf("%d", &CS);
  while (CS--) {
    init();
    sort(vec + 1, vec + n + 1, cmp);
    ans = -1;
    int l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (solve(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    if (ans == -1)
      puts("unreachable");
    else
      printf("%d\n", vec[ans].year);
  }
  return 0;
}
