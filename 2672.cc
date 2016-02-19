#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<vector<int> > VVI;
VVI vt;
const int maxn = 26;
int match[maxn];
bool vis[maxn + 1];
char buf[100];
bool dfs(int v) {
  if (vis[v]) return false;
  vis[v] = true;
  for (int i = 0; i < (int)vt[v].size(); i++) {
    if (vt[v][i] == 0) continue;
    int t = match[i];
    if (t == -1 || dfs(t)) {
      match[i] = v;
      return true;
    }
  }
  return false;
}
bool getX(VVI vec, vector<int>& ret) {
  vt = vec;
  ret = vector<int>(26, 0);
  if (vec.size() > 26) return false;
  memset(match, -1, sizeof(match));

  for (int i = 0; i < (int)vt.size(); i++) {
    memset(vis, false, sizeof(vis));
    if (!dfs(i)) return false;
  }

  for (int i = 0; i < 26; i++) {
    if (match[i] == -1)
      ret[i] = 1;
    else {
      memset(vis, false, sizeof(vis));
      int v = match[i];

      match[i] = 26;
      vis[26] = true;
      if (dfs(v)) {
        ret[i] = 1;
        match[i] = -1;
      } else
        match[i] = v;
    }
  }

  return true;
}
vector<int> getV() {
  vector<int> vec(26, 0);
  for (int i = 0; buf[i]; i++) {
    if (buf[i] >= 'A' && buf[i] <= 'Z') vec[buf[i] - 'A'] = 1;
  }

  return vec;
}
void change(vector<int>& vec, vector<int> vec2) {
  for (int i = 0; i < 26; i++) vec[i] = vec[i] & vec2[i];
}
int solve() {
  vector<VVI> vec;
  vec.push_back(VVI());
  if (!gets(buf)) return -1;

  vector<int> tmp;
  while (1) {
    gets(buf);
    if (strcmp(buf, "<") == 0) {
      vec.push_back(VVI());
    } else if (strcmp(buf, ">") == 0) {
      if (!getX(vec.back(), tmp)) return false;
      vec.pop_back();
      if (vec.size() == 0) return 1;
      change(vec.back().back(), tmp);
    } else {
      vec.back().push_back(getV());
    }
  }
  return 1;
}
int main() {
  int ans = solve();

  if (ans)
    printf("Got It!\n");
  else
    printf("No Solution\n");

  return 0;
}
