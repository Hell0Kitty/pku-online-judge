#include <stdio.h>
#include <string.h>
#include <math.h>
#define POW (int) pow(10.0, (len - i - 1) * 1.0)

int main() {
  int s[10] = {0,     9,      81,      729,      6561,
               59049, 531441, 4782969, 43046721, 387420489};
  char num[20];
  int len, i, ans, m;
  while (scanf("%s", num) != EOF) {
    if (strcmp(num, "0") == 0) break;
    ans = m = 0;
    len = strlen(num);
    for (i = 0; i < len; i++) m = m * 10 + num[i] - '0';
    for (i = 0; i < len - 1; i++) {
      if (num[i] > '4') num[i] = num[i] - 1;
      ans += s[len - i - 1] * (num[i] - '0');
    }
    if (num[i] >= '4') num[i]--;
    ans += (num[i] - '0');
    printf("%d: %d\n", m, ans);
  }

  return 0;
}
