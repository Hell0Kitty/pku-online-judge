#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
int r, c;
char map[30][30];
int num[30], po[30][2];
bool vis[30][30];
bool in(int x, int y) {
  return (x >= 1 && x <= r && y >= 1 && y <= c && map[x][y] != 'X');
}
bool dfs(int x, int y) {
  if (map[x][y] == 'G') return true;
  vis[x][y] = true;
  if (isupper(map[x][y]) && num[map[x][y] - 'A'] != 0) return false;
  if (islower(map[x][y])) num[map[x][y] - 'a']--, map[x][y] = '.';
  bool flag = false;
  if (in(x + 1, y) && !vis[x + 1][y]) flag = flag || dfs(x + 1, y);
  if (in(x - 1, y) && !vis[x - 1][y]) flag = flag || dfs(x - 1, y);
  if (in(x, y + 1) && !vis[x][y + 1]) flag = flag || dfs(x, y + 1);
  if (in(x, y - 1) && !vis[x][y - 1]) flag = flag || dfs(x, y - 1);
  return flag;
}
int main() {
  while (scanf("%d%d", &r, &c), (r || c)) {
    memset(num, -1, sizeof(num));
    memset(vis, false, sizeof(vis));
    int x, y;
    for (int i = 1; i <= r; i++) {
      scanf("%s", map[i] + 1);
      for (int j = 1; j <= c; j++) {
        char ch = map[i][j];
        if (isalpha(ch)) {
          if (islower(ch)) {
            if (num[ch - 'a'] == -1)
              num[ch - 'a'] = 1;
            else
              num[ch - 'a']++;
          } else if (ch <= 'E') {
            po[ch - 'A'][0] = i;
            po[ch - 'A'][1] = j;
            if (num[ch - 'A'] == -1) num[ch - 'A'] = 0;
          } else if (ch == 'S') {
            x = i;
            y = j;
            map[i][j] = '.';
          }
        }
      }
    }
    if (dfs(x, y)) {
      printf("YES\n");
      continue;
    }
    while (1) {
      bool flag = false;
      for (int i = 0; i < 5; i++) {
        if (num[i] == 0) {
          x = po[i][0];
          y = po[i][1];
          if (!vis[x][y]) continue;
          num[i]--;
          flag = true;
          map[x][y] = '.';
          break;
        }
      }
      if (!flag) {
        printf("NO\n");
        break;
      } else if (dfs(x, y)) {
        printf("YES\n");
        break;
      }
    }
  }
  return 0;
}
