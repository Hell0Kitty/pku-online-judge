#include <stdio.h>
#include <string.h>
const int N = 20;

char g[N][5][5];
int n, m[N][2], flag, vis[5][5], t, sum;

void init() {
  flag = sum = 0;
  memset(vis, 0, sizeof(vis));
  t++;
}

void dfs(int cur) {    // cur表示当前
  if (cur == n + 1) {  //如果但前 == n+1则返回结果为真
    flag = 1;
    for (int i = 0; i < 4; i++) {  //打印结果
      for (int j = 0; j < 4; j++) printf("%d", vis[i][j]);
      printf("\n");
    }
    return;
  }
  if (flag)  // flag == true剪枝
    return;
  for (int i = 0; i <= 4 - m[cur][0]; i++) {    //行
    for (int j = 0; j <= 4 - m[cur][1]; j++) {  //列
      int flag1 = 1;                            //标记没有被覆盖
      for (int p = 0; p < m[cur][0]; p++) {     //行
        for (int q = 0; q < m[cur][1]; q++)     //列
          if (flag1 && !vis[i + p][j + q] && g[cur][p][q] == '1')
            vis[i + p][j + q] = cur;
          else if (flag1 && g[cur][p][q] == '0')
            continue;
          else
            flag1 = 0;
      }
      if (flag1) dfs(cur + 1);
      for (int p = 0; p < 4; p++)
        for (int q = 0; q < 4; q++)
          if (vis[p][q] == cur) vis[p][q] = 0;
    }
  }
}

int main() {
  while (scanf("%d", &n) && n) {  //输入n个方块
    init();
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &m[i][0], &m[i][1]);  //输入行和列
      getchar();
      for (int j = 0; j < m[i][0]; j++) {  //统计
        for (int k = 0; k < m[i][1]; k++) {
          scanf("%c", &g[i][j][k]);  //第i个的图
          sum += g[i][j][k] - '0';
        }
        getchar();
      }
    }
    if (t != 1) printf("\n");
    if (sum == 16)  //如果sum == 16 dfs
      dfs(1);
    if (!flag) printf("No solution possible\n");
  }
  return 0;
}
