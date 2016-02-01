#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls id << 1, l, mid
#define rs id << 1 | 1, mid + 1, r
#define CLR(x) memset(x, 0, sizeof x)
#define MEM(x) memset(x, 0x3f, sizeof x)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i >= b; i--)
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
set<string> s;
char a[5][5];
int d[3] = {0, 1, -1};
void dfs(int x, int y, string cur, int k) {
  if (k == 5) {
    s.insert(cur);
    return;
  }
  rep(i, 0, 3) rep(j, 0, 3) {
    if ((i == 0 && j == 0) || (i && j)) continue;
    int nx = x + d[i], ny = y + d[j];
    if (nx > 4 || nx < 0 || ny < 0 || ny > 4) continue;
    dfs(nx, ny, cur + a[nx][ny], k + 1);
  }
}
int main() {
  rep(i, 0, 5) rep(j, 0, 5) cin >> a[i][j];
  rep(i, 0, 5) rep(j, 0, 5) {
    string t;
    t += a[i][j];
    dfs(i, j, t, 0);
  }
  cout << s.size() << endl;
  return 0;
}
