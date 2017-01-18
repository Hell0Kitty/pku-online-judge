#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 15
#define maxl 25

int n;
char gene[maxn][maxl];
int cost[maxn][maxn];
int f[maxn];

void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", gene[i]);
}

int cal(char *st1, char *st2) {
  int len1 = strlen(st1);
  int len2 = strlen(st2);
  for (int i = len1 - len2; i < len1; i++) {
    bool ok = true;
    for (int j = i; j < len1; j++)
      if (st1[j] != st2[j - i]) {
        ok = false;
        break;
      }
    if (ok) return len2 + i - len1;
  }
  return len2;
}

void make() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cost[i][j] = cal(gene[i], gene[j]);
}

void work() {
  for (int i = 0; i < n; i++) f[i] = i;
  int ans = 0x3f3f3f3f;
  do {
    int temp = strlen(gene[f[0]]);
    for (int i = 0; i < n - 1; i++) temp += cost[f[i]][f[i + 1]];
    ans = min(ans, temp);
  } while (next_permutation(f, f + n));
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    make();
    work();
  }
  return 0;
}
