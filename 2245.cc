#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 20
int p[MAXN];
void print(int *a, int m) {
  int i, cnt;
  for (i = 0; i < m - 1; i++) {
    cnt = a[i];
    cout << p[cnt] << ' ';
  }
  cnt = a[m - 1];
  cout << p[cnt] << endl;
}

void GenComb(int *a, int n, int m) {
  int i, j, t;
  print(a, m);
  for (j = m - 1; j >= 0; j--)
    if (a[j] < n - m + j + 1) break;
  t = a[j];
  for (i = 0; i <= m - j - 1; i++) a[j + i] = t + i + 1;
}
void GenAllComb(int *a, int n, int m) {
  int index;
  for (index = 0; index < m; index++) a[index] = index + 1;
  index = 0;
  while (index <= n - m) {
    GenComb(a, n, m);
    if (a[0] > index + 1) index++;
  }
}
int main() {
  int n, m = 6, a[MAXN], i;
  int first = 0;
  while (cin >> n, n) {
    if (first) cout << endl;
    first = 1;
    for (i = 1; i <= n; i++) cin >> p[i];
    GenAllComb(a, n, m);
  }
  return 0;
}
