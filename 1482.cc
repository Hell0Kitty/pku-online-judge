#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Pragram {
  int time;
  char start[21], end[21];
};

struct Node {
  int t, state;
  bool operator<(const Node A) const { return t > A.t; }
};

Pragram P[101];
int n, m, flag, ans;
int vis[1148576];

// k 表示第k个补丁、state表示当前状态、&val 表示补丁后状态
bool Check(int k, int state, int &val) {
  int i, cnt0 = 0, cnt1 = 0;
  for (i = 0; i < n; i++) {
    if (P[k].start[i] != '0') {
      if (P[k].start[i] == '+') {
        if ((state & (1 << i))) return false;
      } else {
        if ((state & (1 << i)) == 0) return false;
      }
    }
  }
  val = 0;
  for (i = 0; i < n; i++) {
    if (P[k].end[i] == '0') {
      if (state & (1 << i)) {
        val ^= (1 << i);
      }
    } else if (P[k].end[i] == '-') {
      val ^= (1 << i);
    }
  }
  return true;
}

//+ 表示为0、-表示为1
void BFS(int ca) {
  int i;
  flag = 0, ans = 10000000;  //初始化标示变量
  priority_queue<Node> Q;
  Node tmp;
  tmp.state = 0;
  tmp.t = 0;
  Q.push(tmp);
  vis[0] = 1;
  while (!Q.empty()) {
    tmp = Q.top();
    Q.pop();
    if (tmp.t > ans) break;
    if (tmp.state == ((1 << n) - 1))  //终止状态
    {
      cout << "Product " << ca << endl;
      cout << "Fastest sequence takes " << tmp.t << " seconds." << endl
           << endl;
      return;
    }
    for (i = 0; i < m; i++) {
      int Estate;
      if (Check(i, tmp.state, Estate)) {
        if (!vis[Estate]) {
          Node N;
          N.state = Estate;
          N.t = tmp.t + P[i].time;
          Q.push(N);
          vis[Estate] = N.t;
        } else if (vis[Estate] > (tmp.t + P[i].time)) {
          Node N;
          N.state = Estate;
          N.t = tmp.t + P[i].time;
          Q.push(N);
          vis[Estate] = N.t;
        }
      }
    }
  }
  if (!flag) {
    cout << "Product " << ca << endl;
    cout << "Bugs cannot be fixed." << endl
         << endl;
  } else {
    cout << "Product " << ca << endl;
    cout << "Fastest sequence takes " << ans << " seconds." << endl
         << endl;
  }
}

int main() {
  int i, ca = 1;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < m; i++) {
      cin >> P[i].time >> P[i].start >> P[i].end;
    }
    BFS(ca++);
  }
  return 0;
}
