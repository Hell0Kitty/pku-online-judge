#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory>
#include <string>
using namespace std;
#define MAXN 3000 + 1
#define MAX 10
#define oo 2147483647
int n, q;
int po[6][10];
char map[MAXN][MAXN];
char a[MAX][MAX];
int v[MAX][2];
void work(int q, int x1, int y1, bool col) {
  int i, j;
  if (!col) {
    for (i = x1; i < x1 + po[n][q]; i++)
      for (j = y1; j < y1 + po[n][q]; j++) map[i][j] = ' ';
  } else {
    if (q == 1) {
      for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) map[x1 + i][y1 + j] = a[i][j];
    } else if (v[q][0] == -1) {
      for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          work(q - 1, x1 + i * po[n][q - 1], y1 + j * po[n][q - 1],
               a[i][j] != ' ');
      v[q][0] = x1;
      v[q][1] = y1;
    } else {
      for (i = 0; i < po[n][q]; i++)
        for (j = 0; j < po[n][q]; j++)
          map[x1 + i][y1 + j] = map[v[q][0] + i][v[q][1] + j];
    }
  }
}
int main() {
  int i, j;
  po[3][0] = po[4][0] = po[5][0] = 1;
  for (i = 3; i <= 5; i++)
    for (j = 1; j < 10; j++) po[i][j] = po[i][j - 1] * i;
  while (cin >> n && n) {
    memset(v, 255, sizeof(v));
    getchar();
    for (i = 0; i < n; i++) gets(a[i]);
    cin >> q;
    work(q, 0, 0, true);
    for (i = 0; i < po[n][q]; i++) {
      map[i][po[n][q]] = 0;
      puts(map[i]);
    }
  }
  return 0;
}
