#include <set>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int map[4][10];
struct TNode {
  int id[5], cnt, step, later[40];
  string lf;
} st;
string str;
set<string> ans;
queue<TNode> qu;
void init() {
  int i, j, k, i1, j1;
  bool tmp;
  str = "";
  for (i = k = 0; i < 4; i++) {
    str += i + 1 + '0';
    str += '1';
    map[i][0] = (i + 1) * 10 + 1;
    for (j = 1; j < 8; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] % 10 == 1)
        map[i][j] = 0, st.id[k++] = i * 8 + j, str += "00";
      else
        str += map[i][j] / 10 + '0', str += map[i][j] % 10 + '0';
    }
  }
  st.lf = str, st.cnt = 0;
  str = "";
  for (i = 1; i <= 4; i++) {
    for (j = 1; j <= 7; j++) str += i + '0', str += j + '0';
    str += "00";
  }
  st.step = 0;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 8; j++) {
      if (map[i][j] == 0) continue;
      for (i1 = 0, tmp = 0; i1 < 4; i1++) {
        for (j1 = 0; j1 < 8; j1++) {
          if (map[i1][j1] == map[i][j] + 1) {
            st.later[i * 8 + j] = i1 * 8 + j1, tmp = 1;
            break;
          }
        }
        if (tmp) break;
      }
    }
}
int bfs() {
  int i, j, k, mid;
  TNode tmp1, tmp2;
  ans.clear();
  ans.insert(st.lf);
  while (!qu.empty()) qu.pop();
  qu.push(st);
  while (!qu.empty()) {
    tmp1 = qu.front();
    qu.pop();
    if (str == tmp1.lf) return tmp1.cnt;
    for (i = 0; i < 4; i++) {
      tmp2 = tmp1;
      tmp2.cnt = tmp1.cnt + 1;
      k = tmp1.id[i];
      if (tmp1.lf[2 * k - 1] == '7' || tmp1.lf[2 * k - 1] == '0') continue;
      j = tmp2.later[k - 1];
      tmp2.lf[2 * k] = tmp2.lf[2 * j];
      tmp2.lf[2 * k + 1] = tmp2.lf[2 * j + 1];
      tmp2.lf[2 * j] = tmp2.lf[2 * j + 1] = '0';
      tmp2.id[i] = j;
      tmp2.later[k - 1] = k;
      tmp2.later[k] = tmp2.later[j];
      if (ans.count(tmp2.lf))
        continue;
      else {
        ans.insert(tmp2.lf);
        qu.push(tmp2);
      }
    }
  }
  return -1;
}
int main() {
  scanf("%d", &n);
  while (n--) {
    init();
    printf("%d\n", bfs());
  }
  return 0;
}
