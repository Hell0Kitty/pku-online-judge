#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

#define MEM(a, x) memset(a, x, sizeof a)
#define eps 1e-8
#define MOD 10009
#define MAXN 10010
#define MAXM 100010
#define INF 99999999
#define ll __int64

using namespace std;

int Read() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}

void Print(int a) {
  if (a > 9) Print(a / 10);
  putchar(a % 10 + '0');
}

int total, n, farey[4000000][2], all;
void makefarey(int x1, int y1, int x2, int y2) {
  if (x1 + x2 > n || y1 + y2 > n) return;
  makefarey(x1, y1, x1 + x2, y1 + y2);
  total++;
  farey[total][0] = x1 + x2;
  farey[total][1] = y1 + y2;
  makefarey(x1 + x2, y1 + y2, x2, y2);
}

int main() {
  int q;
  while (scanf("%d%d", &n, &q) != EOF) {
    if (n == 1) {
      while (q--) {
        int k;
        scanf("%d", &k);
        if (k == 1)
          printf("0/1\n");
        else if (k == 2)
          printf("1/1\n");
        else
          puts("No Solution");
      }
      continue;
    }
    total = 1;
    farey[1][0] = 0;
    farey[1][1] = 1;
    makefarey(0, 1, 1, 2);
    farey[total + 1][0] = 1;
    farey[total + 1][1] = 2;
    all = total * 2 + 1;
    while (q--) {
      int k;
      scanf("%d", &k);
      if (k > all)
        puts("No Solution");
      else if (k <= total + 1)
        printf("%d/%d\n", farey[k][0], farey[k][1]);
      else
        printf("%d/%d\n", farey[all - k + 1][1] - farey[all - k + 1][0],
               farey[all - k + 1][1]);
    }
  }
  return 0;
}
