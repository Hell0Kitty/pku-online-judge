#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int N, idx;
char G[25][25], vis[25];
int match[25];
map<string, int> mp, mpID;
map<int, int> mp_ret;
set<int> st;
set<int>::iterator it;

int path(int u) {
  for (int i = 1; i <= N; ++i) {
    if (G[u][i] || vis[i]) continue;
    vis[i] = 1;
    if (!match[i] || path(match[i])) {
      match[i] = u;
      return 1;
    }
  }
  return 0;
}

int query() {
  int ret = 0;
  memset(match, 0, sizeof(match));
  for (int i = 1; i <= N; ++i) {
    memset(vis, 0, sizeof(vis));
    ret += path(i);
  }
  return ret;
}

void output() {
  map<string, int>::iterator it1, it2;
  for (it1 = mp.begin(); it1 != mp.end(); ++it1) {
    if (mp_ret.count(it1->second)) {
      for (it2 = mpID.begin(); it2 != mpID.end(); ++it2) {
        if (it2->second == mp_ret[it1->second]) {
          cout << it1->first << ":" << it2->first << endl;
          break;
        }
      }
    } else {
      cout << it1->first << ":???" << endl;
    }
  }
}

int main() {
  int T;
  char name[25], op[5];
  while (scanf("%d", &N) != EOF) {
    idx = 1;
    mp.clear(), mpID.clear();
    st.clear(), mp_ret.clear();
    memset(G, 0, sizeof(G));
    for (int i = 1; i <= N; ++i) {
      scanf("%s", name);
      mpID[name] = i;  // 对字符串进行hash处理
    }
    while (scanf("%s", op), op[0] != 'Q') {
      if (op[0] == 'E') {  // 进来的人名
        scanf("%s", name);
        if (!mp.count(name)) {
          mp[name] = idx++;
        }
        st.insert(mp[name]);
      } else if (op[0] == 'M') {  // 发出去的是账户名
        scanf("%s", name);
        char in[25] = {0};
        for (it = st.begin(); it != st.end();
             ++it) {  // 在藏匿点的所有人都和这封邮件连边
          in[*it] = 1;
        }
        for (int i = 1; i <= N; ++i) {
          if (!in[i]) G[i][mpID[name]] = 1;  // 外面的人肯定与邮件无关
        }
      } else if (op[0] == 'L') {
        scanf("%s", name);
        it = st.find(mp[name]);
        st.erase(it);
      }
    }
    int Max = query(), t;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (G[i][j]) continue;
        G[i][j] = 1;
        t = query();
        G[i][j] = 0;
        if (t < Max) {
          mp_ret[i] = j;
          break;
        }
      }
    }
    output();
  }
  return 0;
}
