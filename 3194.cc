#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
using namespace std;
int n, sum, b[102][102];
char a[102][102];
void dfs(int x, int y, char c) {
  if (a[x][y] == '*' || a[x][y] != c) return;
  sum++;
  a[x][y] = '*';
  dfs(x, y + 1, c);
  dfs(x, y - 1, c);
  dfs(x + 1, y, c);
  dfs(x - 1, y, c);
}
int main() {
  while (cin >> n && n) {
    int i, j, x, y, flag = 0;
    sum = 0;
    mem(a, '*');
    mem(b, 0);
    for (i = 1; i < n; i++)
      for (j = 0; j < n; j++) {
        cin >> x >> y;
        a[x][y] = i;
        b[x][y] = 1;
      }
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (!b[i][j]) a[i][j] = n;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (a[i][j] != '*') {
          sum = 0;
          dfs(i, j, a[i][j]);
          if (sum != n) {
            cout << "wrong" << endl;
            flag = 1;
            break;
          }
        }
      }
      if (flag) break;
    }
    if (!flag) cout << "good" << endl;
  }
  return 0;
}
