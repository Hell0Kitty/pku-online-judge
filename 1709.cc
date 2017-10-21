#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int NUM = 105;
const int INF = 0x3fffffff;

struct Point {
  int color;            //该点的颜色
  int cnt;              //该店的出度
  int to[1005];         //记录从该点出发的有向边
  int edgecolor[1005];  //记录有向边的颜色
  void Get(int v, int color) {
    to[cnt] = v;
    edgecolor[cnt++] = color;
  }
} point[NUM];

int N, L, K, Q, ans;
bool visit[NUM][NUM];

struct Step  //记录每一步
    {
  int first, second, cnt;  //第一个棋子,第二个棋子,步数
  Step(int _f, int _s, int _c) {
    first = _f;
    second = _s;
    cnt = _c;
  }
  ~Step() {}
};

queue<Step> q;

bool Bfs() {
  Step temp(L, K, 0);
  visit[L][K] = true;
  q.push(temp);
  bool flag = false;  //标记是否找到

  while (!q.empty()) {
    temp = q.front();
    q.pop();
    if (temp.first == Q || temp.second == Q) {
      flag = true;
      if (temp.cnt < ans) ans = temp.cnt;
      break;
    }
    int i;
    Point curf = point[temp.first];
    Point curs = point[temp.second];
    for (i = 0; i < curf.cnt; i++)
      if (visit[curf.to[i]][temp.second] == false &&
          curf.to[i] != temp.second && curf.edgecolor[i] == curs.color) {
        visit[curf.to[i]][temp.second] = true;
        Step temp2(curf.to[i], temp.second, temp.cnt + 1);
        q.push(temp2);
      }
    for (i = 0; i < curs.cnt; i++)
      if (visit[temp.first][curs.to[i]] == false && curs.to[i] != temp.first &&
          curs.edgecolor[i] == curf.color) {
        visit[temp.first][curs.to[i]] = true;
        Step temp2(temp.first, curs.to[i], temp.cnt + 1);
        q.push(temp2);
      }
  }
  return flag;
}

void Init()  //初始化
{
  ans = INF;
  memset(point, 0, sizeof(point));
  memset(visit, false, sizeof(visit));
  while (!q.empty()) q.pop();
}

int main() {
  while (~scanf("%d%d%d%d", &N, &L, &K, &Q)) {
    int i, T;
    Init();
    for (i = 1; i <= N; i++) scanf("%d", &point[i].color);
    scanf("%d", &T);
    int u, v, color;
    for (i = 1; i <= T; i++) {
      scanf("%d%d%d", &u, &v, &color);
      point[u].Get(v, color);
    }
    if (Bfs())
      printf("YES\n%d\n", ans);
    else
      printf("NO\n");
  }
  return 0;
}
