#include <stdio.h>
#define SIZE 100010
#define MAX 0x7fffffff

int f1[SIZE] = {0};
int f2[SIZE] = {0};
int a[SIZE];

int main() {
  int i, j, n, k;
  int pos, min, temp;
  char ch;
  scanf("%d%d", &n, &k);

  min = MAX;
  for (i = 1; i <= n; i++) {
    scanf("%c", &ch);
    if (ch == '\n') {
      i--;
    } else if (ch == '*') {
      a[i] = -1;
    } else {
      a[i] = ch - '0';
      f2[i] = f2[i - 1] + a[i];
      f1[i] = f1[i - 1] + 1;
      /* 更新最优解 */
      if (f1[i] >= k) {
        temp = f2[i] - f2[i - k];
        if (temp < min) {
          min = temp;
          pos = i - k + 1;
        }
      }
    }
  }

  if (min == MAX) {
    printf("0\n");
  } else {
    printf("%d\n", pos);
  }
  return 0;
}