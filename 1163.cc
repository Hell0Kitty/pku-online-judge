
#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define maxBound 105
int n;
int triangle[maxBound][maxBound];
int sum[maxBound][maxBound];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      scanf("%d", &triangle[i][j]);
    }
  }
  memset(sum, 0, sizeof(sum));
  sum[1][1] = triangle[1][1];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (j == 1)
        sum[i][j] = sum[i - 1][j] + triangle[i][j];
      else if (j == i)
        sum[i][j] = sum[i - 1][j - 1] + triangle[i][j];
      else {
        sum[i][j] = max(triangle[i][j] + sum[i - 1][j - 1],
                        triangle[i][j] + sum[i - 1][j]);
      }
    }
  }
  int maxValue = -1;
  for (int i = 1; i <= n; i++) {
    if (maxValue < sum[n][i]) {
      maxValue = sum[n][i];
    }
  }
  printf("%d\n", maxValue);

  return 0;
}