
#include <iostream>
#include <queue>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, target_row, target_index;
int dir[][2] = {{1, 0}, {0, 1}};  //下 右
struct node {
  char box[10];
  int num;
};

char Encode(int r, int v, int d, int len) {
  char a = v;
  a |= (r << 3);
  a |= ((len - 2) << 6);
  a |= (d << 7);
  return (a);
}

// 0表示下  1表示右
inline int GetDir(char a) { return ((a & (1 << 7)) ? 1 : 0); }

inline int GetLen(char a) { return ((a & (1 << 6)) ? 3 : 2); }

inline int GetRow(char a) { return ((a >> 3) & 7); }

inline int GetVec(char a) { return (a & 7); }

int GetValue(node& a) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (GetDir(a.box[i]) == 0)  // 竖直方向
    {
      res = res * 6 + GetRow(a.box[i]);
    } else {
      res = res * 6 + GetVec(a.box[i]);
    }
  }
  return (res);
}

void exact(node& a, char lab[][6]) {
  int r, v, d, len;
  memset(lab, 0, sizeof(char) * 36);
  for (int i = 0; i < n; ++i) {
    r = GetRow(a.box[i]);
    v = GetVec(a.box[i]);
    d = GetDir(a.box[i]);
    len = GetLen(a.box[i]);
    for (int j = 0; j < len; ++j) {
      lab[r][v] = 'a' + i;
      r += dir[d][0];
      v += dir[d][1];
    }
  }
}

int IsSuceed(node& a, char lab[][6]) {
  int i = GetVec(a.box[target_index]) + GetLen(a.box[target_index]);
  for (; i < 6; ++i) {
    if (lab[target_row][i]) {
      return (0);
    }
  }
  return (1);
}

int bfs(node a) {
  set<int> visit;
  visit.insert(GetValue(a));

  queue<node> q;
  q.push(a);
  node nd1, nd2;
  char lab[6][6];

  int i, j;
  int r, v, d, len, r1, v1, value;
  while (q.empty() == 0) {
    nd1 = q.front();
    q.pop();
    exact(nd1, lab);

    if (IsSuceed(nd1, lab)) {
      return (nd1.num + 1);
    }

    for (i = 0; i < n; ++i) {
      nd2 = nd1;
      nd2.num += 1;
      r = GetRow(nd2.box[i]);
      v = GetVec(nd2.box[i]);
      d = GetDir(nd2.box[i]);
      len = GetLen(nd2.box[i]);

      //正向
      r1 = (d ? 0 : len) + r;
      v1 = (d ? len : 0) + v;
      for (j = 1; j <= 6; ++j) {
        if (r1 >= 6 || v1 >= 6 || lab[r1][v1]) break;

        nd2.box[i] = Encode(r + j * dir[d][0], v + j * dir[d][1], d, len);

        r1 += dir[d][0];
        v1 += dir[d][1];

        value = GetValue(nd2);
        if (visit.find(value) == visit.end()) {
          visit.insert(value);
          q.push(nd2);
        }
      }

      //反向
      nd2 = nd1;
      nd2.num += 1;
      for (j = 0; j < 6; ++j) {
        r -= dir[d][0];
        v -= dir[d][1];

        if (r < 0 || v < 0 || lab[r][v]) break;

        nd2.box[i] = Encode(r, v, d, len);

        value = GetValue(nd2);
        if (visit.find(value) == visit.end()) {
          visit.insert(value);
          q.push(nd2);
        }
      }
    }
  }
  return (-1);
}

int main() {
  node nd;
  int i, j, t, cnt = 0;
  int sr_index[10], sv_index[10], er_index[10], ev_index[10];
  int d, len;
  char vehicles[10][10];
  while (cin >> n) {
    if (n == 0) break;
    ++cnt;
    memset(sr_index, -1, sizeof(sr_index));
    memset(sv_index, -1, sizeof(sv_index));
    for (i = 0; i < 6; ++i) {
      cin >> vehicles[i];
      for (j = 0; j < 6; ++j) {
        if (vehicles[i][j] == '.') continue;

        if (vehicles[i][j] == 'x') {
          if (sr_index[n - 1] == -1 && sv_index[n - 1] == -1) {
            sr_index[n - 1] = i;
            sv_index[n - 1] = j;
          } else {
            er_index[n - 1] = i;
            ev_index[n - 1] = j;
          }
        } else {
          t = vehicles[i][j] - 'a';
          if (sr_index[t] == -1 && sv_index[t] == -1) {
            sr_index[t] = i;
            sv_index[t] = j;
          } else {
            er_index[t] = i;
            ev_index[t] = j;
          }
        }
      }
    }

    target_index = n - 1;
    target_row = sr_index[target_index];

    for (i = 0; i < n; ++i) {
      if (sr_index[i] == er_index[i]) {
        d = 1;
        len = ev_index[i] - sv_index[i] + 1;
      } else {
        d = 0;
        len = er_index[i] - sr_index[i] + 1;
      }
      nd.box[i] = Encode(sr_index[i], sv_index[i], d, len);
    }

    for (j = GetVec(nd.box[target_index]) + GetLen(nd.box[target_index]); j < 6;
         ++j) {
      if (vehicles[target_row][j] != '.' &&
          GetDir(nd.box[vehicles[target_row][j] - 'a']) == 1) {
        printf("You are trapped in scenario #%d.\n", cnt);
        break;
      }
    }

    if (j < 6) continue;

    nd.num = 0;
    int res = bfs(nd);
    if (res == -1) {
      printf("You are trapped in scenario #%d.\n", cnt);
    } else {
      printf("Scenario #%d requires %d moves.\n", cnt, res);
    }
  }
  return (0);
}
