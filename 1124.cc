#include <iostream>
#include <map>
#include <string.h>
#include <memory>
#include <stdio.h>
#include <limits.h>
#define MAX_N 20
#define QSIZE 500
using namespace std;

char graph[MAX_N + 1][MAX_N + 1];  //记录输入的图
double res[MAX_N + 1][MAX_N + 1];  //记录最终的结果，即每个街道的load值
int pre[MAX_N + 1][MAX_N + 1][2];  //记录每个结点前驱的坐标
int vTime
    [MAX_N + 1]
    [MAX_N +
     1];                //记录在找一对entrance和exit之间最短路径时，路径上每个点出现的次数，用于计算每个点需要分到的load值
int pos[MAX_N + 1][2];  //记录每个entrance/exit的坐标，index是：当前字符 - 'A'
bool v[MAX_N + 1][MAX_N +
                  1];  // DFS时标识这个点是否被访问过，访问时置1，回溯时置0

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  //遍历的四个方向

map<string, int> load;  //记录输入里每个entrance/exit对的load总和，对于AB 2 BA
// 1，要把BA转换成AB，所以最终是AB 3
map<string, int>::iterator itr;

int rowN, colN, srcR, srcC, destR, destC, pathNum,
    minLen;  //计算时用到的相关变量

string temp;

//判断当前点是否可走
bool inRange(int curR, int curC) {
  char type = graph[curR][curC];
  //是否在坐标轴内
  bool t1 = (curR >= 1 && curR <= rowN && curC >= 1 && curC <= colN);
  //是否是终点或者是街道，否则不可走
  bool t2 = ((curR == destR && curC == destC) || type == '.');
  return t1 && t2;
}
void dfs(int curR, int curC, int len) {
  int d, nextR, nextC, tR, tC;
  if (curR == destR && curC == destC) {
    //超过了当前最短的，直接忽略掉
    if (len > minLen) return;
    //新的路径更短
    else if (len < minLen) {
      //重置数据
      memset(vTime, 0, sizeof(vTime));
      pathNum = 1;
    }
    //路径长度和最优的相等，则路径数增加1
    else
      pathNum++;
    minLen = len;

    //遍历路径，为每个节点的load比重加1
    nextR = pre[curR][curC][0];
    nextC = pre[curR][curC][1];
    while (!(nextR == srcR && nextC == srcC)) {
      vTime[nextR][nextC]++;
      tR = pre[nextR][nextC][0];
      tC = pre[nextR][nextC][1];
      nextR = tR, nextC = tC;
    }
    return;
  }
  //剪枝
  if (len >= minLen) return;

  //遍历四个方向
  for (d = 0; d < 4; d++) {
    nextR = curR + dir[d][0], nextC = curC + dir[d][1];
    //判断是否可走
    if (v[nextR][nextC] || !inRange(nextR, nextC)) continue;
    v[nextR][nextC] = true;
    pre[nextR][nextC][0] = curR, pre[nextR][nextC][1] = curC;
    //继续走
    dfs(nextR, nextC, len + 1);
    //回溯
    v[nextR][nextC] = false;
  }
}

//利用DFS遍历所有的entrance/exit对找出所有的最短路径，并按照比例对相同的最短路径上的几点进行load均分
void travel() {
  int lVal, i, j;
  for (itr = load.begin(); itr != load.end(); itr++) {
    //相关初始化
    temp = itr->first;
    lVal = itr->second;
    srcR = pos[temp[0] - 'A'][0], srcC = pos[temp[0] - 'A'][1];
    destR = pos[temp[1] - 'A'][0], destC = pos[temp[1] - 'A'][1];
    memset(v, 0, sizeof(v));
    memset(vTime, 0, sizeof(vTime));
    pre[srcR][srcC][0] = -1;
    v[srcR][srcC] = true;
    pathNum = 0;
    minLen = INT_MAX;

    //遍历
    dfs(srcR, srcC, 0);

    //按照各点的比重均分
    for (i = 1; i <= rowN; i++) {
      for (j = 1; j <= colN; j++)
        res[i][j] += ((double)vTime[i][j] / pathNum) * lVal;
    }
  }
}
int main() {
  int i, j, l;
  char c;
  //输入格式化
  cin >> colN >> rowN;
  for (i = 1; i <= rowN; i++)
    for (j = 1; j <= colN; j++) {
      cin >> c;
      graph[i][j] = c;
      if (c >= 'A' && c <= 'O') {
        pos[c - 'A'][0] = i;
        pos[c - 'A'][1] = j;
      }
    }
  while (cin >> temp >> l && temp != "XX") {
    if (temp[0] > temp[1]) {
      c = temp[0];
      temp[0] = temp[1];
      temp[1] = c;
    }
    itr = load.find(temp);
    if (itr == load.end())
      load[temp] = l;
    else
      load[temp] += l;
  }
  //遍历
  travel();
  //输出结果
  for (i = 1; i <= rowN; i++) {
    for (j = 1; j <= colN; j++) {
      //保留小数点后两位，进行四舍五入
      double temp = res[i][j];
      int t = temp * 1000 + 5;
      t = t / 10 * 10;
      temp = (double)t / 1000;
      printf("%7.2f", temp);
    }
    printf("\n");
  }
  return 0;
}
