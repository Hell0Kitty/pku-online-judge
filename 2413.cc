#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
using namespace std;
struct NODE {
  char dig[150];
} nod[1005];
char a[150], b[150];
void rever(char a[]) {
  int la = strlen(a);
  for (int i = 0; i < la / 2; i++) swap(a[i], a[la - 1 - i]);
}
int _strcmp(char a[], char b[]) {
  int la = strlen(a), lb = strlen(b), i;
  if (la != lb) return la < lb ? -1 : 1;
  for (i = la - 1; i >= 0; i--) {
    if (a[i] != b[i]) return a[i] > b[i] ? 1 : -1;
  }
  return 0;
}
int main() {
  strcpy(nod[1].dig, "1");
  strcpy(nod[2].dig, "2");
  int i = 3, j, cnt, t1, t2;
  for (;; i++) {
    int len1 = strlen(nod[i - 2].dig);
    int len2 = strlen(nod[i - 1].dig);
    cnt = 0;
    for (j = 0; j < len1 || j < len2; j++) {
      t1 = 0;
      t2 = 0;
      if (j < len1) t1 = nod[i - 2].dig[j] - '0';
      if (j < len2) t2 = nod[i - 1].dig[j] - '0';
      nod[i].dig[j] = (t1 + t2 + cnt) % 10 + '0';
      cnt = (t1 + t2 + cnt) / 10;
    }
    if (cnt != 0) nod[i].dig[j++] = cnt + '0';
    nod[i].dig[j] = '\0';
    if (j > 100) break;
  }
  int tot = i;
  while (scanf("%s", a) != EOF) {
    scanf("%s", b);
    if (a[0] == '0' && b[0] == '0') break;
    cnt = 0;
    rever(a);
    rever(b);
    for (i = 0; i < tot; i++) {
      if (_strcmp(a, nod[i].dig) > 0) continue;
      if (_strcmp(b, nod[i].dig) < 0) break;
      cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
