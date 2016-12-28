#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int equ, var;
int x[55];
int a[55][55];
int nofree_num;
void debug() {
  for (int i = 0; i < equ; i++) {
    for (int j = 0; j <= var; j++) printf("%d ", a[i][j]);
    puts("");
  }
  puts("");
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
int dfs(int p, int q)  // 从矩阵下方向上枚举每个x[i]∈{0,1,2}
// 看等式是否成立，当成立时跳上上一行继续枚举，
// 如果当前行无解则返回0
{
  int i, j;
  if (p == -1) return 1;
  for (i = 0; i < 3; i++) {
    int tep = a[p][var];
    for (j = p + 1; j < var; j++)
      tep = (tep % q - (x[j] * a[p][j]) % q + q) % q;
    if ((i * a[p][p]) % q == tep) {
      x[p] = i;
      return dfs(p - 1, q);
    }
  }
  return 0;
}
int gauss(int p) {
  int i, j, k;
  int row, col;
  for (row = 0, col = 0; row < equ && col < var; row++, col++) {
    int maxr = row;
    for (i = row + 1; i < equ; i++)
      if (abs(a[i][col]) > abs(a[maxr][col])) maxr = i;
    if (a[maxr][col] == 0) {
      row--;
      continue;
    }
    for (i = 0; i <= var; i++) swap(a[row][i], a[maxr][i]);
    for (i = row + 1; i < equ; i++) {
      if (a[i][col]) {
        int LCM = lcm(abs(a[row][col]), abs(a[i][col]));
        int ta = LCM / abs(a[row][col]);
        int tb = LCM / abs(a[i][col]);
        if (a[i][col] * a[row][col] < 0) ta = -ta;
        for (j = col; j <= var; j++)
          a[i][j] = ((a[i][j] * tb) % p - (a[row][j] * ta) % p + p) % p;
      }
    }
  }
  for (i = row; i < equ; i++)
    if (a[i][var]) return 0;
  for (i = 0; i < equ; i++) {
    if (a[i][i] == 0) {
      for (j = i + 1; j < var; j++)
        if (a[i][j]) break;
      if (j == var) break;
      for (k = 0; k < equ; k++) swap(a[k][i], a[k][j]);
    }
  }
  nofree_num = row;
  return dfs(var - 1, p);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int q, n;
    int A[55];
    int i, k;
    cin >> q >> n;
    equ = var = n;
    for (i = 0; i < n; i++) cin >> A[i];
    memset(a, 0, sizeof(a));
    for (k = 0; k < n; k++) {
      for (i = 0; i <= k; i++) a[k][k - i] = A[i];
      for (i = k + 1; i <= n - 1; i++) a[k][n + k - i] = A[i];
    }
    a[0][var] = 1;
    puts(gauss(q) ? "A solution can be found" : "No solution");
  }
}
