#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

const int size = 26;

int value[size];  //第i种邮票面值value[i]
int pv;  // value[]指针
int time[size];  //标记第i种邮票被分配过的次数

bool flag;      //标记是否已经出现过解
bool flag_tie;  //标记是否为tie
int solve[6];  // solve[0]:邮票张数  solve[5]:邮票种数
               // solve[1..4]:持有的邮票面值，0表示不持有
int BestSolve[6];  //最优解

void dfs(int need, int num, int type,
         int pre);  // need:总面值 num:邮票张数  type:邮票种数
int max4(int* s);              //返回s[1..4] 4个数中的最大值
void best(int num, int type);  //更新最优解

int main(void) {
  while (true) {
    pv = 0;
    int type[size] = {0};  //面值为i的邮票的种数type[i]

    int tmp;
    while (true) {
      if (scanf("%d", &tmp) == EOF) exit(0);
      if (tmp == 0) break;

      if (type[tmp] < 5)  //剪枝，同面额的邮票种类超过5，则按5计算
      {
        type[tmp]++;
        value[pv++] = tmp;
      }
    }
    sort(value, value + pv);  //要使分配的邮票的种类尽可能多
    //只需在搜索前把邮票面值升序排序，从最小面额开始搜索

    int need;  //顾客需求
    while (cin >> need && need) {
      flag = false;
      flag_tie = false;
      memset(solve, 0, sizeof(solve));
      memset(BestSolve, 0, sizeof(BestSolve));
      memset(time, 0, sizeof(time));

      /*Search*/

      dfs(need, 0, 0, 0);

      /*Output*/

      cout << need;
      if (BestSolve[0] == 0)
        cout << " ---- none" << endl;
      else {
        cout << " (" << BestSolve[5] << "):";

        if (flag_tie)
          cout << " tie" << endl;
        else {
          sort(BestSolve + 1, BestSolve + 5);
          for (int i = 1; i <= 4; i++) {
            if (BestSolve[i] == 0) continue;
            cout << ' ' << BestSolve[i];
          }
          cout << endl;
        }
      }
    }
  }
  return 0;
}

void dfs(int need, int num, int type,
         int pre)  // need:总面值 num:邮票张数  type:邮票种数
{
  if (num == 5)  //剪枝，顾客持有邮票张数不超过4
    return;

  if (need == 0) {
    if (!flag) {
      if (type == BestSolve[5])  //最优解的种类type相同
      {
        if (num == BestSolve[0])  //最优解的张数num相同
        {
          int Maxs = max4(solve);  // solve的最大面值
          int MaxBs = max4(BestSolve);  // BestSolve的最大面值

          if (Maxs == MaxBs)  //存在多个最优解
            flag_tie = true;
          else if (Maxs >
                   MaxBs)  //种类、张数都相同的情况下，最大面值较大的解优先
          {
            flag_tie = false;
            best(num, type);
          }
        } else if (num < BestSolve[0])  //种类相同情况下，张数少的解优先
        {
          flag_tie = false;
          best(num, type);
        }
      } else if (type > BestSolve[5])  //种类多的解优先
      {
        flag_tie = false;
        best(num, type);
      }
    } else {
      flag = true;
      best(num, type);
    }

    return;
  }

  for (int i = pre; i < pv;
       i++)  // i=pre 剪枝，不重复搜索比当前面值小的邮票，同时避免错误的tie
  {
    if (need >= value[i]) {
      solve[num + 1] = value[i];

      if (time[i] != 0) {
        time[i]++;
        dfs(need - value[i], num + 1, type, i);
      } else {
        time[i]++;
        dfs(need - value[i], num + 1, type + 1, i);
      }

      solve[num + 1] = 0;  //回溯
      time[i]--;
    } else
      return;  // value已排序
  }

  return;
}

int max4(int* s)  //返回s[1..4] 4个数中的最大值
{
  int a = s[1] > s[2] ? s[1] : s[2];
  int b = s[3] > s[4] ? s[3] : s[4];

  return a > b ? a : b;
}

void best(int num, int type)  //更新最优解
{
  BestSolve[0] = num;
  BestSolve[5] = type;

  for (int k = 1; k <= 4; k++) BestSolve[k] = solve[k];
  return;
}
