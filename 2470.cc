#include <stdio.h>

int a[100002];

int main() {
  int n;

  int i;
  while (scanf("%d", &n) && n != 0) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (i = 1; i <= n; i++)
      if (a[a[i]] != i) break;

    if (i >= n + 1)
      printf("ambiguous\n");

    else
      printf("not ambiguous\n");
  }

  return 0;
}