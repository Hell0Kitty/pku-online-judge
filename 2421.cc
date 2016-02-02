#include <stdio.h>
#define MAX 1000000
int map[105][105];
int lowcost[105];
int N;
void Prim(int map[][105], int n) {
  int i, j, k, road = 0;
  int min;
  for (i = 2; i <= N; i++) lowcost[i] = map[1][i];
  for (i = 2; i <= N; i++) {
    min = lowcost[i];
    k = i;
    for (j = 2; j <= N; j++)
      if (min > lowcost[j]) {
        min = lowcost[j];
        k = j;
      }
    road += min;
    lowcost[k] = MAX;
    for (j = 2; j <= N; j++) {
      if ((map[k][j] < lowcost[j]) && (lowcost[j] < MAX)) {
        lowcost[j] = map[k][j];
      }
    }
  }
  printf("%d\n", road);
}
int main() {
  int n, i, j;
  while (scanf("%d", &N) != EOF) {
    for (i = 1; i <= N; i++)
      for (j = 1; j <= N; j++) scanf("%d", &map[i][j]);
    scanf("%d", &n);
    while (n--) {
      scanf("%d%d", &i, &j);
      map[i][j] = map[j][i] = 0;
    }
    Prim(map, N);
  }
  return 0;
}
