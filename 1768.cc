#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#define eps 1e-6
#define INF 0x1f1f1f1f
#define PI acos(-1.0)
#define ll __int64
#define lson l, m, (rt << 1)
#define rson m + 1, r, (rt << 1) | 1
using namespace std;

bool vis[16][1 << 15], vv[32];  //映射后只有这么多的寄存器能影响
int map1[32];                   //将状态映射过来
char save[16][10];              //保存命令
int can1[16], can2[16], n, m, ans, ss;  //参数
vector<int> jz;
vector<int> hav[32];
int bin[40];  //将每一个寄存器对应的值保存下来

int cal(char* a)  //返回该命令的参数个数
{
  if (!strcmp(a, "NOT") || !strcmp(a, "RANDOM") || !strcmp(a, "JMP")) return 1;
  if (!strcmp(a, "STOP")) return 0;
  return 2;
}

void dfs(int cur) {
  for (int i = 0; i < hav[cur].size(); i++) {
    if (vv[hav[cur][i]]) continue;
    // printf("cur:%d->%d\n",cur,hav[cur][i]);
    vv[hav[cur][i]] = true;
    map1[hav[cur][i]] = m;
    m++;
    dfs(hav[cur][i]);
  }
  return;
}

void Dfs(int sta, int i, int ss) {
  if (i >= n) return;
  if (vis[i][sta]) return;
  ss++;
  vis[i][sta] = true;
  int T = sta;

  if (!strcmp(*(save + i), "AND")) {
    int a = map1[can1[i]], b = map1[can2[i]];  //取出对应的离散化的位置
    if (a == -1 || b == -1)  //遇到无效状态，直接跳过
    {
      Dfs(sta, i + 1, ss);
      vis[i][sta] = false;  //从前往后就不用回溯，因为后面的情况一定比当前坏
      return;
    }
    int tt = sta;
    int aa = (tt >> a) & 1, bb = (tt >> b) & 1;  //取出两寄存器的数
    if (aa & bb)  //运算，并把结果加进去
      tt = tt | bin[a];
    else
      tt = tt - (aa << a);
    Dfs(tt, i + 1, ss);
  } else if (!strcmp(*(save + i), "OR")) {
    int a = map1[can1[i]], b = map1[can2[i]];  //取出对应的离散化的位置
    if (a == -1 || b == -1) {
      Dfs(sta, i + 1, ss);
      vis[i][sta] = false;
      return;
    }
    int tt = sta;
    int aa = (tt >> a) & 1, bb = (tt >> b) & 1;
    if (aa | bb)
      tt = tt | bin[a];
    else
      tt = tt - (aa << a);
    Dfs(tt, i + 1, ss);
  } else if (!strcmp(*(save + i), "XOR")) {
    int a = map1[can1[i]], b = map1[can2[i]];  //取出对应的离散化的位置
    if (a == -1 || b == -1) {
      Dfs(sta, i + 1, ss);
      vis[i][sta] = false;
      return;
    }
    int tt = sta;
    int aa = (tt >> a) & 1, bb = (tt >> b) & 1;
    if (aa ^ bb)
      tt = tt | bin[a];
    else
      tt = tt - (aa << a);
    Dfs(tt, i + 1, ss);
  } else if (!strcmp(*(save + i), "NOT")) {
    int a = map1[can1[i]];
    if (a == -1) {
      Dfs(sta, i + 1, ss);
      vis[i][sta] = false;
      return;
    }
    sta = sta ^ bin[a];  //取反
    Dfs(sta, i + 1, ss);
  } else if (!strcmp(*(save + i), "MOV")) {
    int a = map1[can1[i]], b = map1[can2[i]];
    if (a == -1 || b == -1) {
      Dfs(sta, i + 1, ss);
      vis[i][sta] = false;
      return;
    }
    int aa = (sta >> b) & 1;
    if (aa)
      sta = sta | bin[a];
    else
      sta = sta & ((bin[m] - 1) - bin[a]);  //把第a个寄存器清零
    Dfs(sta, i + 1, ss);
  } else if (!strcmp(*(save + i), "SET")) {
    int a = map1[can1[i]], b = can2[i];
    if (a == -1) {
      Dfs(sta, i + 1, ss);
      vis[i][sta] = false;
      return;
    }
    if (b)
      sta = sta | (1 << a);
    else
      sta = sta & ((bin[m] - 1) - bin[a]);
    Dfs(sta, i + 1, ss);
  } else if (!strcmp(*(save + i), "JMP")) {
    int a = can1[i];
    Dfs(sta, a, ss);
  } else if (!strcmp(*(save + i), "JZ")) {
    int a = can1[i], b = map1[can2[i]];
    int bb = (sta >> b) & 1;  //一定是影响寄存器
    if (!bb) {
      Dfs(sta, a, ss);
      vis[i][sta] = false;
      return;
    }
    Dfs(sta, i + 1, ss);
  } else if (!strcmp(*(save + i), "STOP")) {
    if (ss < ans) ans = ss;
  } else if (!strcmp(*(save + i), "RANDOM")) {
    int a = map1[can1[i]];
    if (a == -1) {
      Dfs(sta, i + 1, ss);
      vis[i][sta] = false;
      return;
    }
    Dfs(sta | bin[a], i + 1, ss);                 //置1
    Dfs(sta & (bin[m] - 1 - bin[a]), i + 1, ss);  //置0
  }
  vis[i][T] = false;
}
int main() {
  for (int i = 0; i <= 35; i++) bin[i] = (1 << i);
  while (scanf("%d", &n) != EOF) {
    memset(map1, -1, sizeof(map1));
    memset(vv, false, sizeof(vv));

    jz.clear();
    for (int i = 0; i < 32; i++) hav[i].clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", save + i);
      int t = cal(*(save + i));
      if (t == 1)
        scanf("%d", &can1[i]);
      else if (t == 2) {
        scanf("%d%d", &can1[i], &can2[i]);
        if (!strcmp(*(save + i), "JZ")) {
          jz.push_back(can2[i]);  //从这点开始扫描有影响的状态
          continue;
        }
        if (strcmp(*(save + i), "SET"))  // set命令不影响
          hav[can1[i]].push_back(can2[i]);  //寄存器2能影响寄存器1
      }
    }
    m = 0;
    for (int i = 0; i < jz.size(); i++) {
      if (!vv[jz[i]]) {
        map1[jz[i]] = m;
        m++;
        vv[jz[i]] = true;
        dfs(jz[i]);
      }
    }
    ans = INF;

    memset(vis, false, sizeof(vis));
    for (int i = 0; i <= bin[m] - 1; i++) Dfs(i, 0, 0);  //这样写不用回溯
    if (ans == INF)
      printf("HANGS\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
