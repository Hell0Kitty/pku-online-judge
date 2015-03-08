
#include <iostream>
#include <cstdio>
using namespace std;

int father[100000 + 10];
int _rank[100000 + 10];
void Make_Set(int n) {
  int i;
  for (i = 1; i <= n; i++) {
    father[i] = i;
    _rank[i] = 1;
  }
}

int Find_Set(int a) {
  if (a == father[a])
    return a;
  else {
    int temp = father[a];
    father[a] = Find_Set(father[a]);
    _rank[a] = (_rank[temp] + _rank[a] + 1) % 2;
  }
  return father[a];
}

void Union_Set(int a, int b) {
  int fa, fb;
  fa = Find_Set(a);
  fb = Find_Set(b);
  if (fa != fb) {
    father[fa] = fb;
    _rank[fa] = (_rank[a] + _rank[b]) % 2;  // fa结点以下的结点的_rank不需要改
  }
}

int main() {
  int T, N, M;
  char ch;
  int a, b, fa, fb;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &M);
    Make_Set(N);
    int i;
    for (i = 1; i <= M; i++) {
      getchar();
      scanf("%c%d%d", &ch, &a, &b);
      if (ch == 'A') {
        if (Find_Set(a) == Find_Set(b)) {
          if ((_rank[a] + _rank[b]) % 2 == 0) {
            printf("In the same gang.\n");
          } else
            printf("In different gangs.\n");
        } else {
          printf("Not sure yet.\n");
        }

      } else {
        Union_Set(a, b);
      }
    }
  }
  return 0;
}