#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double mat[200][2][2];
void update(int ID) {
  memset(mat[ID], 0, sizeof(mat[ID]));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        mat[ID][i][j] += mat[ID - 1][i][k] * mat[ID - 1][k][j];
}
int mine[20];
int main() {
  int n;
  double p;
  while (scanf("%d%lf", &n, &p) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d", mine + i);
    sort(mine, mine + n);
    mat[0][0][0] = p;
    mat[0][0][1] = 1.0;
    mat[0][1][0] = 1.0 - p;
    mat[0][1][1] = 0;
    for (int i = 1; i < 200; i++) update(i);
    double ans = 1;
    int lx = 1, len, k;
    for (int i = 0; i < n; i++) {
      len = mine[i] - lx;
      double x[2], y[2];
      x[0] = 1.0;
      x[1] = 0.0;
      k = 0;
      while (len > 0) {
        if (len & 1) {
          y[0] = x[0] * mat[k][0][0] + x[1] * mat[k][1][0];
          y[1] = x[0] * mat[k][0][1] + x[1] * mat[k][1][1];
          x[0] = y[0];
          x[1] = y[1];
        }
        len >>= 1;
        k++;
      }
      ans *= (1 - x[0]);
      lx = mine[i] + 1;
    }
    printf("%.7lf\n", ans);
  }
  return 0;
}
