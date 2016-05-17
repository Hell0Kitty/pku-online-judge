#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 1000
int max(int a, int b) { return a > b ? a : b; }
int n;
bool vis[27];
char str[30];
struct bign {
  int num[MAX];
  int len;
  void init() {
    memset(num, 0, sizeof(num));
    len = 1;
  }
  void print() {
    int i;
    for (i = MAX - 1; i >= 0; i--) {
      if (num[i]) break;
    }
    if (i == -1) {
      printf("0\n");
    } else {
      for (; i >= 0; i--) {
        printf("%d", num[i]);
      }
      printf("\n");
    }
  }
};
bign add(bign a, bign b) {
  bign c;
  c.init();
  c.len = max(a.len, b.len);
  int i;
  for (i = 0; i < c.len; i++) {
    c.num[i] += a.num[i] + b.num[i];
    if (c.num[i] >= 10) {
      c.num[i + 1] += c.num[i] / 10;
      c.num[i] %= 10;
      if (i + 2 > c.len) c.len = i + 2;
    }
  }
  return c;
}
bign multi(bign a, bign b) {
  bign c;
  c.init();
  int i, j;
  c.len = a.len + b.len;
  for (i = 0; i < a.len; i++) {
    for (j = 0; j < b.len; j++) {
      c.num[i + j] += a.num[i] * b.num[j];
    }
  }
  for (i = 0; i < c.len - 1; i++) {
    if (c.num[i] >= 10) {
      c.num[i + 1] += c.num[i] / 10;
      c.num[i] %= 10;
    }
  }
  return c;
}

void solve() {
  memset(vis, 0, sizeof(vis));
  bign sum;
  sum.init();
  int i, j;
  for (i = 0; i < n; i++) {
    int id = str[i] - 'A' + 1;
    int ct = 0;
    for (j = 1; j < id; j++) {
      if (!vis[j]) ct++;
    }
    bign tp;
    tp.init();
    tp.num[0] = ct;
    int d = n - 1 - i;
    int r = 25 - i;
    while (d--) {
      bign tp1;
      tp1.init();
      tp1.num[0] = r--;
      tp = multi(tp, tp1);
    }
    sum = add(sum, tp);
    vis[id] = 1;
  }
  sum.print();
}
int main() {
  while (scanf("%d", &n)) {
    if (n == 0) break;
    getchar();
    scanf("%s", &str);
    solve();
  }
}
