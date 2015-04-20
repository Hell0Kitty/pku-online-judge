#include "stdio.h"
#include "string.h"
#define N 100001
int n, m;
int mark[N];
void fun() {
  int i;
  int ans;
  memset(mark, 0, sizeof(mark));
  ans = 0;
  mark[0] = 1;
  for (i = 0; i < m; i++) {
    ans = (ans + n) % m;
    if (mark[ans] == 1) break;
    mark[ans] = 1;
  }
  for (i = 0; i < m; i++)
    if (mark[i] != 1) break;
  if (i >= m)
    printf("%10d%10d%s\n", n, m, "    Good Choice");
  else
    printf("%10d%10d%s\n", n, m, "    Bad Choice");
  printf("\n");
}

int main() {
  while (scanf("%d%d", &n, &m) != -1) fun();
  return 0;
}
