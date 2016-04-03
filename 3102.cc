#include <cstdio>
#include <cstring>
#include <cmath>

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

const int MAXN = 205;
const double eps = 1e-6;
const double DINF = 1e20;

int x[MAXN], y[MAXN];
double w[MAXN][MAXN];

int main() {
  int N;
  while (~scanf("%d", &N)) {
    for (int i = 1; i <= N; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= N; j++) w[i][j] = DINF;
    int a, b;
    for (int i = 1; i <= N; i++) {
      scanf("%d%d", &a, &b);
      w[a][b] = w[b][a] = sqrt(0.0 + (x[a] - x[b]) * (x[a] - x[b]) +
                               (y[a] - y[b]) * (y[a] - y[b]));
    }
    // floyd
    for (int k = 0; k <= N; k++)
      for (int i = 0; i <= N; i++)
        if (w[i][k] + eps < DINF)
          for (int j = 0; j <= N; j++)
            if (w[i][j] > w[i][k] + w[k][j]) w[i][j] = w[i][k] + w[k][j];
    double Max = 0;
    for (int i = 0; i <= N; i++)
      for (int j = i + 1; j <= N; j++) {
        bool ok = true;
        // check whether online
        for (int k = 0; k <= N; k++)
          if (k != i && k != j &&
              (x[i] - x[k]) * (y[j] - y[k]) == (x[j] - x[k]) * (y[i] - y[k]) &&
              x[k] <= max(x[i], x[j]) && x[k] >= min(x[i], x[j]) &&
              y[k] <= max(y[i], y[j]) && y[k] >= min(y[i], y[j])) {
            ok = false;
            break;
          }
        if (ok) {
          double tmp = w[i][j] - sqrt(0.0 + (x[i] - x[j]) * (x[i] - x[j]) +
                                      (y[i] - y[j]) * (y[i] - y[j]));
          if (tmp > Max + eps) {
            Max = tmp;
            a = i, b = j;
          }
        }
      }
    if (Max < eps)
      puts("-1");
    else
      printf("%d %d\n", a, b);
  }
  return 0;
}
