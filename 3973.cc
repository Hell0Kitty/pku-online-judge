#include <string.h>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int playernum, gamenum;
bool visited[210];
vector<vector<int> > games;
int match[210];
int dfs(int x) {
  for (int i = 0; i < games[x].size(); i++)
    if (!visited[games[x][i]]) {
      visited[games[x][i]] = true;
      int k = match[games[x][i]];
      if (k == -1 || dfs(k)) {
        match[games[x][i]] = x;
        return true;
      }
    }
  return false;
}
int find() {
  memset(match, -1, sizeof(match));
  int res = 0;
  for (int i = 0; i < gamenum; ++i) {
    memset(visited, false, sizeof(visited));
    res += dfs(i);
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  vector<int> v;
  for (int l = 1; l <= t; l++) {
    cin >> playernum >> gamenum;
    games.clear();
    for (int i = 0; i < gamenum; ++i) {
      v.clear();
      int p;
      cin >> p;
      for (int j = 0, g; j < p; ++j) {
        cin >> g;
        v.push_back(g - 1);
      }
      games.push_back(v);
    }
    printf("Case %d: %d\n", l, playernum + gamenum - find());
  }
  return 0;
}
