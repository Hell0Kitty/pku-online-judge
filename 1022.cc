#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, q[1000], inq[1000], con[1000][9], move[1000][9],
    sta[9];  //实际上这些1000是多余的，一开始为了保险这样写了。其实只要比100稍大就行了
// move[i][j]记录第i个方块在8个方向上分别比第1个方块多了几个单位
// sta[i]记录每个方向上离第1个方块最远的距离

map<int, int> pos;  // pos[o]保存号码为o的方块所在的输入时的次序i
//由于序号的大小范围并没有给出，所有用map是一个偷懒的办法

bool solve() {
  int head = 0, tail = 0;
  // bfs
  inq[q[++tail] = 1] = 1;
  while (head < tail) {
    int now = q[++head];
    for (int i = 1; i <= 8; i++) {
      int next = pos[con[now][i]];  //取出now的这位邻居的读入时的序号
      if (con[now][i] && pos[con[next][((i + 1) ^ 1) - 1]] != now)
        return false;  //判断这位next对应的这维上的反方向的邻居是否是now，如果不是，说明输入不合法
      if (con[now][i] && !inq[pos[con[now][i]]]) {
        inq[q[++tail] = next] = 1;
        for (int j = 1; j <= 8; j++)
          move[next][j] = move[now][j];  //用now更新next的move
        move[next][i] = move[now][i] + 1;  // next比now在i方向上多一个单位
      }
    }
  }

  for (int i = 1; i <= n; i++)
    if (!inq[i])
      return false;  //判断是否是不合法情形2：如果此时还有点未入队，说明它在另一个连通块里，则为不合法情形2
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;

    pos.clear();
    pos[0] = 0;  //其实这句话不写也可以
    for (int i = 1; i <= n; i++) {
      int o;
      scanf("%d", &o);
      pos[o] = i;                     //号码为o的方块是第i个输入的
      for (int j = 1; j <= 8; j++) {  //读入四个维上共八个方向的邻居
        int t;
        scanf("%d", &t);
        con[i][j] = t;
      }
    }

    memset(inq, 0, sizeof inq);
    memset(move, 0, sizeof move);

    if (!solve()) {
      puts("Inconsistent");
      continue;
    }

    memset(sta, 0, sizeof sta);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 8; j++) {
        if (move[i][j] > sta[j])
          sta[j] = move[i][j];  //找出各个方向上的最大值，存入move
      }
    }

    cout
        << (sta[1] + sta[2] + 1) * (sta[3] + sta[4] + 1) *
               (sta[5] + sta[6] + 1) * (sta[7] + sta[8] + 1)
        << endl;  //同一维上相反的方向上的sta值要相加，这是显然的。并且由于第1个方块也算1个单位，所以都要加1
  }

  return 0;
}
