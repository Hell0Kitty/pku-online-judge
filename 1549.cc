#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf = 1 << 28;
int b[8];
char input[12][10];
int brac[12][10];
int ans[15];
int mark[15];
int state
    [4500][8]
    [8];  //在第一维压缩记录状态，用到哪个镯子就把相应位置1，得到的整数即是第一维的索引
// state[k][i][j] 表示k状态镯子链最左色为i，最右色为j的cost是多少
int mi[12];
int n;
int Min;

//计算整数key里面有多少个1
int ones(int key) {
  int c = 0;
  while (key) {
    key &= (key - 1);
    c++;
  }
  return c;
}

int main() {
  mi[0] = 1;
  for (int i = 1; i <= 11; ++i) mi[i] = mi[i - 1] << 1;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < 8; i++) scanf("%d", &b[i]);

    for (int i = 0; i < n; i++) {
      scanf("%s", input[i]);
      for (int j = 0; j < 8; j++) brac[i][j] = input[i][j] - 'A';
    }

    memset(state, -1, sizeof(state));

    //初始状态，只有一个
    for (int i = 0; i < 8; i++) {
      int l = brac[0][(i + 4) % 8], r = brac[0][i];
      state[mi[0]][l][r] = 0;
    }

    int tot = mi[n] - 1;  // tot为二进制下全1的n位
    for (int i = 1; i < n; i++)
      for (int x = 1; x <= tot; x++)
        if (ones(x) == i)  //枚举i个镯子的压缩状态
        {
          for (int q = 0; q < 8; q++)
            for (int p = 0; p < 8; p++)  //这两个循环枚举左右色
              if (state[x][q][p] != -1)  //前状态存在
              {
                for (int s = 0; s < n; s++)
                  if ((mi[s] & x) == 0)  //枚举还没插入的镯子
                  {
                    for (int k = 0; k < 8; k++) {
                      int l = brac[s][(k + 4) % 8];
                      int r = brac[s][k];
                      if (p == l)  //插在右端
                      {
                        if (i == n - 1 && q != r) continue;
                        if (state[mi[s] + x][q][r] == -1 ||
                            state[x][q][p] + b[p] < state[mi[s] + x][q][r])
                          state[mi[s] + x][q][r] = state[x][q][p] + b[p];
                      }
                      if (q == r)  //插在左端
                      {
                        if (i == n - 1 && l != p) continue;
                        if (state[mi[s] + x][l][p] == -1 ||
                            state[x][q][p] + b[q] < state[mi[s] + x][l][p])
                          state[mi[s] + x][l][p] = state[x][q][p] + b[q];
                      }
                    }
                  }
              }
        }

    int Min = inf;
    for (int i = 0; i < 8; i++)
      if (state[tot][i][i] !=
          -1)  //因为镯子要成环形，最后的状态要满足头尾颜色也相等
        Min = min(Min, state[tot][i][i] + b[i]);  //加上头尾对接的颜色值

    if (Min == inf)
      printf("impossible\n");
    else
      printf("%d\n", Min);
  }

  return 0;
}
