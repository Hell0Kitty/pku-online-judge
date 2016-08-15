#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;  // 0WRB, 1WBR, 2RWB, 3RBW, 4BRW, 5BWR

int base[] = {1, 6, 36, 216, 1296, 7776, 46656, 279936, 1679616};
int state[6][4] = {{2, 2, 4, 4},
                   {5, 5, 3, 3},
                   {0, 0, 5, 5},
                   {4, 4, 1, 1},
                   {3, 3, 0, 0},
                   {1, 1, 2, 2}};
char hash1[1680000][9];
char hash2[1680000][9];
char b[10];
struct node {
  int s[9];
  int dis;
  int space;
  int value;
} st;
queue<node> q;
int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};  //下，上，右，左，和前面相反

inline bool isok(int &x, int &y) { return x >= 0 && x < 3 && y >= 0 && y < 3; }
inline int cal(node &t)  //计算初始的hash值
{
  int value = 0;
  int top = 0;
  for (int i = 0; i < 9; i++) {
    if (i == t.space) continue;
    value += t.s[i] * base[top++];
  }
  return value;
}
int cal(node &t, node &f, int d)  //因为每次移动只会改变几个hash值，所以可以特判
{
  if (d == 2) {
    t.value -= f.s[t.space] * base[f.space];
    t.value += t.s[f.space] * base[f.space];
    return t.value;
  } else if (d == 3) {
    t.value -= f.s[t.space] * base[t.space];
    t.value += t.s[f.space] * base[t.space];
    return t.value;
  } else if (d == 0) {
    for (int i = f.space; i <= f.space + 2; i++) {
      t.value -= f.s[i + 1] * base[i];
      t.value += t.s[i] * base[i];
    }
    return t.value;
  } else if (d == 1) {
    for (int i = t.space; i <= t.space + 2; i++) {
      t.value -= f.s[i] * base[i];
      t.value += t.s[i + 1] * base[i];
    }
    return t.value;
  }
}
bool bfs(node st) {
  node t1, t2, f;
  queue<node> Q;
  st.dis = 0;
  Q.push(st);
  t2.dis = 0;
  int k;
  int k1 = 1, kk1 = 0, k2 = 256, kk2 = 0;
  while (!Q.empty() && !q.empty()) {
    while (k1--) {
      st = Q.front();
      Q.pop();
      if (st.dis + 1 + t2.dis > 30) {
        printf("-1\n");
        return false;
      }
      for (int d = 0; d < 4; d++) {
        t1 = st;
        int sx = t1.space / 3;
        int sy = t1.space % 3;
        int nx = sx + dir[d][0];
        int ny = sy + dir[d][1];
        if (isok(nx, ny)) {
          t1.space = nx * 3 + ny;
          t1.s[sx * 3 + sy] = state[t1.s[nx * 3 + ny]][d];
          t1.s[nx * 3 + ny] = 6;
          t1.dis = st.dis + 1;
          t1.value = cal(t1, st, d);
          if (hash1[t1.value][t1.space]) continue;
          if (hash2[t1.value][t1.space]) {
            printf("%d\n", t1.dis + t2.dis);
            return true;
          }

          hash1[t1.value][t1.space] = t1.dis;
          Q.push(t1);
          kk1++;
        }
      }
    }
    k1 = kk1;
    kk1 = 0;
    while (k2--) {
      f = q.front();
      if (f.dis == 9) break;
      q.pop();
      for (int d = 0; d < 4; d++) {
        t2 = f;
        int sx = t2.space / 3;
        int sy = t2.space % 3;
        int nx = sx + dir[d][0];
        int ny = sy + dir[d][1];
        t2.dis = f.dis + 1;
        if (isok(nx, ny)) {
          t2.space = nx * 3 + ny;
          t2.s[sx * 3 + sy] = state[t2.s[nx * 3 + ny]][d];
          t2.s[nx * 3 + ny] = 6;
          t2.value = cal(t2, f, d);
          if (hash2[t2.value][t2.space]) continue;
          if (hash1[t2.value][t2.space]) {
            printf("%d\n", t2.dis + st.dis + 1);
            return true;
          }
          hash2[t2.value][t2.space] = t2.dis;
          q.push(t2);
          kk2++;
        }
      }
    }
    t1.dis = f.dis + 1;
    k2 = kk2;
    kk2 = 0;
  }
  printf("-1\n");
}
void dfs(node &end, int k) {
  if (k == 9) {
    end.dis = 0;
    end.value = cal(end);
    q.push(end);
    hash2[end.value][end.space] = 1;
    return;
  }
  if (b[k] == 'W') {
    end.s[k] = 0;
    dfs(end, k + 1);
    end.s[k] = 1;
    dfs(end, k + 1);
  } else if (b[k] == 'R') {
    end.s[k] = 2;
    dfs(end, k + 1);
    end.s[k] = 3;
    dfs(end, k + 1);
  } else if (b[k] == 'B') {
    end.s[k] = 4;
    dfs(end, k + 1);
    end.s[k] = 5;
    dfs(end, k + 1);
  } else {
    end.s[k] = 6;
    dfs(end, k + 1);
  }
}
int main() {
  int x, y;
  char a;
  node end;
  while (scanf("%d%d", &y, &x) != EOF) {
    if (!x && !y) break;
    while (!q.empty()) q.pop();
    memset(hash1, 0, sizeof(hash1));
    memset(hash2, 0, sizeof(hash2));

    x--;
    y--;
    for (int i = 0; i < 9; i++) {
      if (x == i / 3 && y == i % 3) {
        st.s[i] = 6;
        st.space = i;
      } else
        st.s[i] = 0;
    }
    for (int i = 0; i < 9; i++) {
      scanf(" %c", &a);
      if (a == 'E') end.space = i;
      b[i] = a;
    }
    dfs(end, 0);  //得到所有的终点状态，全部加入队列。

    int k;  //一开始就是答案
    st.value = cal(st);
    hash1[st.value][st.space] = -1;
    if (hash2[st.value][st.space]) {
      printf("0\n");
      continue;
    }
    bfs(st);
  }
  return 0;
}
