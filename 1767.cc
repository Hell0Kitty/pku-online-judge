#include <stdio.h>
bool opt[35];
int n, p, s, e, res;
int main() {
  scanf("%d", &n);
  while (n) {
    opt[p++] = n & 1;
    n >>= 1;
  }
  for (s = 0; s < p && !opt[s]; s++)
    ;
  for (e = s; e < p && opt[e]; e++)
    ;
  if (e == p) {
    opt[0] = opt[1] = 0;
    for (int i = 2; i < p; i++) opt[i] = (i & 1) ^ 1;
  } else {
    int cnt = e - s - 1;
    opt[e] = 1;
    for (int i = s; i < e; i++) opt[i] = 0;
    for (int i = 2; i < p && cnt; i++) {
      opt[i] = (i & 1) ^ 1;
      if (!opt[i]) cnt--;
    }
  }
  for (int i = p - 1; i >= 0; i--) res = (res << 1) | opt[i];
  printf("%d\n", res);
  return 0;
}