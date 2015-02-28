#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
int a[1000][2];
int h[1000][2];
int n, k;
int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  for (int o = 0; o < t; o++) {
    scanf("%d%d", &k, &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i][0]);
    for (int i = 0; i < n; i++) {
      a[i][1] = 99999;
      for (int j = i + 1; j < n; j++)
        if (a[i][0] == a[j][0]) {
          a[i][1] = j;
          break;
        }
    }
    int m = 0;
    int p;
    for (int i = 0; i < n && m < k; i++) {
      int u = 0, v = 0;
      for (int j = 0; j < m; j++) {
        if (h[j][0] == a[i][0]) {
          h[j][1] = a[i][1];
          u = 1;
        }
      }
      if (u == 0) {
        h[m][0] = a[i][0];
        h[m][1] = a[i][1];
        m++;
      }
      p = i;
    }
    for (int i = p + 1; i < n; i++) {
      int u = 0, v = 0, e = 1;
      for (int j = 0; j < k; j++) {
        if (a[i][0] == h[j][0]) {
          v = j;
          e = 0;
          break;
        }
        if (h[j][1] > u) {
          u = h[j][1];
          v = j;
        }
      }

      h[v][0] = a[i][0];
      h[v][1] = a[i][1];
      m += e;
    }
    cout << m << endl;
  }
  return 0;
}
