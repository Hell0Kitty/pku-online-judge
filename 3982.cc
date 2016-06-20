#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add(char a[], char b[], char back[]) {
  int i, j, k, up, x, y, z, l;
  char *c;
  if (strlen(a) > strlen(b))
    l = strlen(a) + 2;
  else
    l = strlen(b) + 2;
  c = (char *)malloc(l * sizeof(char));
  i = strlen(a) - 1;
  j = strlen(b) - 1;
  k = 0;
  up = 0;
  while (j >= 0 || i >= 0) {
    if (i < 0)
      x = '0';
    else
      x = a[i];
    if (j < 0)
      y = '0';
    else
      y = b[j];
    z = x - '0' + y - '0';
    if (up) z++;
    if (z > 9) {
      up = 1;
      z %= 10;
    } else
      up = 0;
    c[k++] = z + '0';
    i--;
    j--;
  }
  if (up) c[k++] = '1';
  i = 0;
  c[k] = '\0';
  for (k -= 1; k >= 0; k--) back[i++] = c[k];
  back[i] = '\0';
}

int main() {
  char a[1000], b[1000], c[1000], sum[1000];
  int m, i;
  while (~scanf("%s%s%s", a, b, c)) {
    add(a, b, sum);
    add(c, sum, sum);
    int n = 5;
    for (i = 1; i <= 24; i++) {
      add(b, c, a);
      add(sum, a, a);
      add(c, sum, b);
      add(b, a, b);
      add(sum, a, c);
      add(b, c, c);
      add(a, b, sum);
      add(c, sum, sum);
    }
    printf("%s\n", sum);
  }
  return 0;
}
