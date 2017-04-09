#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char file[102][102][65];
struct data {
  char s[70];
  bool operator<(const data &ne) const { return strcmp(s, ne.s) < 0; }
} po[102];
int main() {
  int n, r, c, mlen;
  while (scanf("%d", &n) != EOF) {
    memset(file, '\0', sizeof(file));
    mlen = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", po[i].s);
      mlen = max(mlen, (int)strlen(po[i].s));
    }
    sort(po, po + n);
    c = (60 - mlen) / (mlen + 2) + 1;
    r = n / c + (n % c != 0);
    int nu = 0;
    for (int i = 0; i < c && nu < n; i++)
      for (int j = 0; j < r && nu < n; j++) strcpy(file[j][i], po[nu++].s);
    puts("------------------------------------------------------------");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (file[i][j][0] != '\0') printf("%s", file[i][j]);
        int k = strlen(file[i][j]);
        while (k < mlen) putchar(' '), k++;
        if (j == c - 1)
          printf("\n");
        else
          printf("  ");
      }
    }
  }
  return 0;
}
