nclude<iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define N 250
    using namespace std;
int n, m, lin[N], count;  // lin[i]:第i个stall相连的cow
bool map[N][N], used[N];
bool search(int a) {  //判断是否能构成新的增广序列的函数
  for (int j = 1; j <= m; j++)
    if (map[a][j] && !used[j]) {             //连通 没有用过
      used[j] = 1;                           //标记
      if (lin[j] == -1 || search(lin[j])) {  //无奶牛与之配对 或 构成增广序列
        lin[j] = a;  //记录该j产奶屋对应的奶牛序号a
        return true;
      }
    }
  return false;
}
int main() {
  int si, temp;
  while (scanf("%d %d", &n, &m) != EOF) {
    count = 0;
    memset(map, false, sizeof(map));
    memset(lin, -1, sizeof(lin));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &si);
      for (int j = 1; j <= si; j++) {
        scanf("%d", &temp);
        map[i][temp] = true;
      }
    }
    //匈牙利算法
    for (int i = 1; i <= n; i++) {
      memset(used, false, sizeof(used));  //每次对循环中的used进行初始化
      if (search(i)) count++;
    }
    printf("%d\n", count);
  }
  return 0;
}
