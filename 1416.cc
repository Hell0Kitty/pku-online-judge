#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define M 6

int d[M], tar, val, len, num[M][M];
bool flag;

struct PathCell {
  int l, r;
} pre[M][M], ans;  //记录路径
void convert(char tmp[]) {
  int i;
  for (i = 0; tmp[i] != '\0'; i++) d[i] = tmp[i] - '0';
  len = i;
}

void preprocess()  //预处理，求出剪断后的所有可能整数
{
  int i, j, k;

  for (i = 0; i < len; i++) {
    for (j = i; j < len; j++) {
      k = i;
      while (k <= j) {
        num[i][j] = num[i][j] * 10 + d[k];
        k++;
      }
    }
  }
}

bool dfs(int id, int now, int last) {
  if (id >= len) {
    if (now > val && now <= tar) {
      val = now;
      ans.l = last;
      ans.r =
          id -
          1;  //当获得最优值时，ans记录最后的情况，用于输出路径，flag更新为false，表明目前只有一种方式取得最优值
      flag = false;
      return true;  //返回true，表明找到最优值
    } else if (now == val)
      flag = true;  // flag为true表示当前最优值可通过多种方式获得
    return false;
  }

  bool mark = false;
  for (int i = 1; i <= len - id; i++) {
    int cur = id + i - 1;
    if (dfs(id + i, now + num[id][cur],
            id)) {  //返回值为true时(即找到当前最优指时)记录路径
      pre[id][cur].l = last;
      pre[id][cur].r = id - 1;
      mark = true;
    }
  }
  return mark;
}

void output(int l, int r)  //递归输出路径
{
  if (l < 0 && r < 0) return;
  output(pre[l][r].l, pre[l][r].r);
  printf("%d ", num[l][r]);
}

int main() {
  char tmp[10];

  while (scanf("%d %s", &tar, tmp)) {
    if (!tar && tmp[0] == '0') break;
    memset(num, 0, sizeof(num));
    convert(tmp);
    preprocess();

    flag = false;
    val = -1;
    dfs(0, 0, -1);
    if (flag) {
      printf("rejected\n");
      continue;
    }
    if (val == -1)
      printf("error\n");
    else {
      printf("%d ", val);
      output(ans.l, ans.r);
      printf("\n");
    }
  }
  return 0;
}
