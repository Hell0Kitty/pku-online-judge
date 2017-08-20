#include <stdio.h>
#include <string.h>

char st[40], num[40], *base;
int lenb;
long long f[40], ans;

int minx(int x, int y) { return (x < y) ? x : y; }

int cmp(int l, int r) {
  int i;

  for (i = l; i < r; ++i) num[i - l] = st[i];
  num[r - l] = '\0';
  return strcmp(num, base);
}

void count(int x) {
  int i, j, k;

  for (i = x - 1; i >= 0; --i)
    if (st[i] != '0') {
      k = minx(i + lenb, x);
      for (j = i + 1; j <= k; ++j)
        if (j - i < lenb || j - i == lenb && cmp(i, j) < 0) f[i] += f[j];
    } else
      f[i] += f[i + 1];
}

int main() {
  int i, j;

  while (scanf("%s", st), st[0] != '#') {
    if (st[0] == '0') {
      printf((st[1] == '\0' || st[1] == '0' || st[1] == '1' && st[2] == '\0')
                 ? "The code %s is invalid.\n"
                 : "The code %s can represent 1 numbers.\n",
             st);
      continue;
    }
    ans = 0;
    for (i = (int)strlen(st) - 1, j = 1; i; --i, ++j)
      if (st[i] != '0') {
        memset(f, 0, sizeof(f));
        f[i] = 1;
        base = st + i;
        lenb = j;
        count(i);
        ans += f[0];
      }
    (ans) ? printf("The code %s can represent %lld numbers.\n", st, ans)
          : printf("The code %s is invalid.\n", st);
  }
  return 0;
}
