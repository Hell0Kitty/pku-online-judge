#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105
#define maxm 100005

bool f[maxm];
int used[maxm], num[maxn], value[maxn];
int n, m;

void input() {
  for (int i = 0; i < n; i++) scanf("%d", &value[i]);
  for (int i = 0; i < n; i++) scanf("%d", &num[i]);
}

void work() {
  memset(f, 0, sizeof(f));
  f[0] = true;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    memset(used, 0, sizeof(used));
    for (int j = value[i]; j <= m; j++)
      if (!f[j] && f[j - value[i]] && used[j - value[i]] < num[i]) {
        f[j] = true;
        used[j] = used[j - value[i]] + 1;
        sum++;
      }
  }
  printf("%d\n", sum);
}

int main() {
  while (scanf("%d%d", &n, &m), n | m) {
    input();
    work();
  }
  return 0;
}