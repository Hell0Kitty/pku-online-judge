#include <stdio.h>
#include <string.h>

char a[1010];
char b[1010];
int t[1010][1010], A, B;

int main() {
  int i, j;
  while (scanf("%d%s%d%s", &A, a, &B, b) != EOF) {
    memset(t, 0, sizeof(t));
    for (i = 0; i <= A; i++) t[i][0] = i;
    for (j = 0; j <= B; j++) t[0][j] = j;

    for (i = 1; i <= A; i++)
      for (j = 1; j <= B; j++) {
        if (a[i - 1] == b[j - 1])
          t[i][j] = t[i - 1][j - 1];
        else {
          t[i][j] = t[i - 1][j] + 1 < t[i - 1][j - 1] + 1 ? t[i - 1][j] + 1
                                                          : t[i - 1][j - 1] + 1;
          t[i][j] = t[i][j] < t[i][j - 1] + 1 ? t[i][j] : t[i][j - 1] + 1;
        }
      }
    printf("%d\n", t[A][B]);
  }
  return 0;
}
