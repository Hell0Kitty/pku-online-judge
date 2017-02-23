#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;
typedef struct fun { double x, y, z, r; } rr;
fun a[105];
bool vis[105];
double len[105][105];
int cout, n;
int main() {
  int i, j;
  while (1) {
    cout = 0;
    double sum = 0;
    scanf("%d", &n);
    if (n == 0) break;
    for (i = 1; i <= n; i++) {
      scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z, &a[i].r);
      vis[i] = false;
    }
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        len[i][j] = len[j][i] =
            sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2) +
                 pow(a[i].z - a[j].z, 2)) -
            a[i].r - a[j].r;
    vis[1] = true;
    cout = 1;
    while (cout < n) {
      double Max = 100000000;
      int k;
      for (j = 2; j <= n; j++) {
        if (len[j][1] < Max && vis[j] == false) {
          Max = len[j][1];
          k = j;
        }
      }
      vis[k] = true;
      cout++;
      if (Max > 0) sum += Max;
      for (j = 2; j <= n; j++) {
        if (vis[j] == false && len[k][j] < len[j][1] && k != j) {
          len[j][1] = len[k][j];
        }
      }
    }
    printf("%0.3lf\n", sum);
  }
  return 0;
}
