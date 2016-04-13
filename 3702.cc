#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define clr(a, b) (memset(a, b, sizeof(a)))
#define rep(i, a) for (int i = 0; i < (int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

bool vis[33][33][33][33];
int a[4], b[4];
char s1[33], s2[33];
bool ans;

void dfs(int n0, int n1, int n2, int n3) {
  if (ans == true) return;
  if (vis[n0][n1][n2][n3] == true) return;
  if (n0 < 0 || n1 < 0 || n2 < 0 || n3 < 0) return;
  if (n0 == b[0] && n1 == b[1] && n2 == b[2] && n3 == b[3]) {
    ans = true;
    return;
  }

  vis[n0][n1][n2][n3] = true;
  dfs(n0 - 1, n1 + 1, n2 - 1, n3 + 1);
  dfs(n0 + 1, n1 - 1, n2 + 1, n3 - 1);

  dfs(n0 - 1, n1 - 1, n2 + 1, n3);
  dfs(n0, n1 - 1, n2 - 1, n3 + 1);
  dfs(n0 + 1, n1, n2 - 1, n3 - 1);
  dfs(n0 - 1, n1 + 1, n2, n3 - 1);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    clr(a, 0), clr(b, 0), clr(vis, false);
    scanf("%s%s", s1, s2);
    int c1 = 0, c2 = 0;
    for (int i = 0; i < 30; i++) {
      if (s1[i] == '*') a[i % 4]++, c1++;
      if (s2[i] == '*') b[i % 4]++, c2++;
    }
    if (c1 < c2) {
      puts("NO");
      continue;
    }

    ans = false;
    dfs(a[0], a[1], a[2], a[3]);
    if (ans)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
