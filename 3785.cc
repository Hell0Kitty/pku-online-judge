#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctime>
#define MAXN 222
#define MAXM 6122222
#define INF 1000000001
using namespace std;
int n, c[1111];
char s[1111];
void get_next() {
  int pos1 = n - 1;
  while (pos1 > 0 && c[pos1] >= c[pos1 + 1]) pos1--;  //>变成了>=
  int pos2 = n;
  while (c[pos2] <= c[pos1]) pos2--;  //<变成了<=
  swap(c[pos2], c[pos1]);
  int l = pos1 + 1, r = n;
  while (l < r) {
    swap(c[l], c[r]);
    l++;
    r--;
  }
}
int main() {
  int T, cas;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &cas);
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
      c[i + 1] = s[i] - '0';
    }
    printf("%d ", cas);
    bool flag = 1;
    for (int i = 1; i < n; i++)
      if (c[i] < c[i + 1]) flag = 0;
    if (flag) {
      printf("BIGGEST\n");
      continue;
    }
    get_next();
    for (int i = 1; i <= n; i++) printf("%d", c[i]);
    printf("\n");
  }
  return 0;
}
