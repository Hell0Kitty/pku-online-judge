#include <iostream>
using namespace std;

typedef class {
 public:
  int row;
  char col;
} location;

int p, q;
bool chess['Z' + 1][27];

int x, y;                         //返回值
void path(int i, int j, int num)  // ij为骑士当前在棋盘的位置
{                                 // num为骑士即将要跳到的位置序号
  switch (num) {
    case 1: {
      x = i - 1;
      y = j - 2;
      break;
    }  //注意这个尝试跳的顺序不能错
    case 2: {
      x = i + 1;
      y = j - 2;
      break;
    }  //因为题目要求是字典序lexicographically输出
    case 3: {
      x = i - 2;
      y = j - 1;
      break;
    }  //这个顺序错了，必定WA
    case 4: {
      x = i + 2;
      y = j - 1;
      break;
    }
    case 5: {
      x = i - 2;
      y = j + 1;
      break;
    }
    case 6: {
      x = i + 2;
      y = j + 1;
      break;
    }
    case 7: {
      x = i - 1;
      y = j + 2;
      break;
    }
    case 8: {
      x = i + 1;
      y = j + 2;
      break;
    }
  }
  return;
}

bool DFS(location *way, int i, int j, int step) {
  chess[i][j] = true;
  way[step].row = i;
  way[step].col = j;
  if (step == way[0].row) return true;

  for (int k = 1; k <= 8; k++)  //骑士从当前位置尝试跳到其他位置
  {
    path(i, j, k);
    int ii = x, jj = y;
    if (!chess[ii][jj] && ii >= 1 && ii <= p && jj >= 'A' && jj <= 'A' + q - 1)
      if (DFS(way, ii, jj, step + 1)) return true;
  }

  chess[i][j] = false;  //能执行到这步，说明前面跳的8步都不符合要求
  return false;  //即当前位置是错误位置，擦除记录返回上一步
}

int main(void) {
  int test;
  cin >> test;
  int t = 1;
  while (t <= test) {
    /*Initial*/

    memset(chess, false, sizeof(chess));

    cin >> p >> q;
    if (p == 1 && q == 1)  //范围缩窄，不要也能AC
    {
      cout << "Scenario #" << t++ << ':' << endl;
      cout << "A1" << endl
           << endl;
      continue;
    }
    if (p * q > 26 || p >= 9 || q >= 9 || p <= 2 ||
        q <= 2)  //范围缩窄，不要也能AC
    {
      cout << "Scenario #" << t++ << ':' << endl;
      cout << "impossible" << endl
           << endl;
      continue;
    }

    location *way = new location[p * q + 1];  //记录走过的位置坐标
    way[0].row = p * q;  //记录总步数(棋盘总格子数)

    /*DFS*/

    bool flag = false;
    for (int j = 'A'; j <= 'A' + q - 1; j++) {
      for (int i = 1; i <= p; i++)
        if (DFS(way, i, j, 1)) {
          cout << "Scenario #" << t++ << ':' << endl;

          for (int k = 1; k <= way[0].row; k++)
            cout << way[k].col << way[k].row;
          cout << endl
               << endl;
          flag = true;
          break;
        }
      if (flag) break;
    }

    if (!flag) {
      cout << "Scenario #" << t++ << ':' << endl;
      cout << "impossible" << endl
           << endl;
    }
  }
  return 0;
}