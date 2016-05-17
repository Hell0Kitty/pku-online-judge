#include <iostream>
using namespace std;
int cake[11], pos[41];  //题目限制的是蛋糕的最大变长为10,且需分割的最大边长为40
int m, k;

bool DFS(int a) {
  int i, min_pos = 41, lie = 0, j, t;
  if (a == k)  //如果遍历到放入的数目和要求的数目相同即完成目标
    return true;
  for (i = 1; i <= m; i++)
    if (pos[i] < min_pos) {
      min_pos = pos[i];  //找到了在竖直方向上用去的最短行数
      lie = i;
    }
  for (i = 10; i >= 1; i--) {
    if (cake[i] && min_pos + i <= m &&
        lie + i - 1 <= m) {  //可以放入边长为I的正方形
      for (j = lie; j <= lie + i - 1; j++)
        if (pos[j] > min_pos)  //该空隙的宽度大于等于i
          break;
      if (j > lie + i - 1) {
        cake[i]--;  //这个就是典型的DFS算法的了
        for (t = lie; t <= lie + i - 1; t++) pos[t] = pos[t] + i;
        if (DFS(a + 1)) return true;  // I GET THE WA HERE
        cake[i]++;                    //回溯部分的算法
        for (t = lie; t <= lie + i - 1; t++) pos[t] = pos[t] - i;
      }
    }
  }
  return false;
}

int main() {
  int n, sum_cake, ori_cake, i, s;
  scanf("%d", &n);
  while (n--) {
    memset(cake, 0, sizeof(cake));
    memset(pos, 0, sizeof(pos));
    scanf("%d%d", &m, &k);
    sum_cake = 0;
    ori_cake = m * m;
    for (i = 1; i <= k; i++) {
      scanf("%d", &s);
      cake[s]++;
      sum_cake = sum_cake + s * s;
    }
    // printf("sum_cake==%d,ori_cake==%d\n",sum_cake,ori_cake);
    if (sum_cake != ori_cake)
      printf("HUTUTU!\n");
    else if (DFS(0))
      printf("KHOOOOB!\n");
    else
      printf("HUTUTU!\n");
  }
  return 0;
}
