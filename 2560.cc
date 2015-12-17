#include <stdio.h>
#include <math.h>
//  POJ 2560

const int INF = 2147483647;
const int N = 101;
typedef double value_type;
int n; // the length of g graph
value_type g[N][N], d[N], q[N]; // int or double
bool visit[N];
void prim() {
  int i, j, k, id = 0;

  value_type min, sum;

  for (i = 0; i < n; i++) // not forget to initial the visit array
    visit[i] = false;

  for (i = 0; i < n; i++)
    d[i] = g[0][i]; // initial the d array

  visit[0] = true; // vertex 0 is visited.

  for (i = 1; i < n; i++) // total edge is p-1
  {
    min = INF;

    for (j = 0; j < n; j++) // find next min
      if (visit[j] == 0 && d[j] != -1 && d[j] < min) {
        min = d[j];
        k = j;
      }

    visit[k] = 1; // visit k

    q[id++] = min; // add to mst

    for (j = 0; j < n; j++) // refresh d[j]
      if (visit[j] == 0 && g[k][j] > 0 && (d[j] == -1 || g[k][j] < d[j]))
        d[j] = g[k][j];
  }

  sum = 0;

  for (i = 0; i < n - 1; i++) //  the value of mst
    sum += q[i];

  printf("%.2lf\n", sum); //  answer
}

double x[N], y[N];

int main() {
  scanf("%d", &n);
  int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      g[i][j] = -1;
  for (i = 0; i < n; i++)
    scanf("%lf%lf", &x[i], &y[i]);
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      g[j][i] = g[i][j] =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  prim();
}
