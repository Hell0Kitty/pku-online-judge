#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
struct word {
  char s[200];
} a[50001];
int n;
char b[200];
bool cmp(struct word x, struct word y) { return strcmp(x.s, y.s) < 0; }
bool gao(char *x) {
  int l = 0, r = n - 1, mid;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (strcmp(x, a[mid].s) < 0)
      r = mid - 1;
    else if (strcmp(x, a[mid].s) > 0)
      l = mid + 1;
    else
      return true;
  }
  return false;
}
int main() {
  int m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", a[i].s);
  sort(a, a + n, cmp);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int flag = 0;
    while (scanf("%s", b) && strcmp(b, "-1") != 0) {
      if (!gao(b)) {
        if (flag == 0) {
          flag = 1;
          printf("Email %d is not spelled correctly.\n", i + 1);
        }
        printf("%s\n", b);
      }
    }
    if (!flag) printf("Email %d is spelled correctly.\n", i + 1);
  }
  printf("End of Output\n");
  return 0;
}
