#include <stdio.h>
#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int m, s[101], i;
    int ji = 0, ou = 0;
    scanf("%d", &m);
    if (m % 2) {
      for (i = 1; i <= m; i++) scanf("%d", &s[i]);
      printf("YES\n");
    } else {
      for (i = 1; i <= m; i++) {
        scanf("%d", &s[i]);
        if (!s[i] && i % 2) ji++;
        if (!s[i] && !(i % 2)) ou++;
      }
      if (abs(ji - ou) < 2)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
