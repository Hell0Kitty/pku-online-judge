#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nMax 1005

int cow[105];
bool map[nMax][nMax];
bool flag[nMax];
int K, N;
int pastures[nMax];
void dfs(int now) {
  flag[now] = true;
  pastures[now]++;
  for (int i = 1; i <= N; ++i) {
    if (!flag[i] && map[now][i]) {
      dfs(i);
    }
  }
}
int main() {
  int M;
  while (scanf("%d %d %d", &K, &N, &M) != EOF) {
    memset(map, false, sizeof(map));
    memset(pastures, 0, sizeof(pastures));  //多少牛能到此牧草地
    for (int i = 1; i <= K; ++i) {
      scanf("%d", &cow[i]);  //第i头牛所在的牧草地
    }
    int u, v;
    for (int i = 0; i < M; ++i) {
      scanf("%d %d", &u, &v);
      map[u][v] = true;  //牧草地u到v有路
    }
    for (int i = 1; i <= K; ++i) {
      memset(flag, false, sizeof(flag));  //每次dfs是否走过i
      dfs(cow[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
      if (pastures[i] == K)  //如果牧草地K头牛都能到，则++
      {
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
