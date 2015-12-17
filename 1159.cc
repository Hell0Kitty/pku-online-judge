
#include <stdio.h>
char ch[5001];
short min[5000][5000] = {0};
inline int minnum(short a, short b) { return a > b ? b : a; }
int main() {
  short n;
  short i, j, k;
  scanf("%d", &n);
  scanf("%s", ch);
  for (i = n - 1; i >= 0; i--)
    for (j = i + 1; j < n; j++) {
      if (ch[i] == ch[j])
        min[i][j] = min[i + 1][j - 1];
      else
        min[i][j] = 1 + minnum(min[i + 1][j], min[i][j - 1]);
    }
  printf("%d\n", min[0][n - 1]);
  return 0;
}