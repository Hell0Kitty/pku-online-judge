#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool has[100][100];
int map[100][100], n, m;
char mapstr[100][100][100];
int GetNum(char *str) {
  int ans = 0;
  for (int i = 0; i < strlen(str); i++) ans = ans * 10 + str[i] - '0';
  return ans;
}
int GetY(char *str) {
  if (strlen(str) == 1) return str[0] - 'A' + 1;
  if (strlen(str) == 2) return (str[0] - 'A' + 1) * 26 + str[1] - 'A' + 1;
  if (strlen(str) == 3)
    return (str[0] - 'A' + 1) * 676 + (str[1] - 'A' + 1) * 26 + str[2] - 'A' +
           1;
}
int DFS(int x, int y) {
  if (has[x][y]) return map[x][y];
  int ans = 0, itx = 0, ity = 0, len = strlen(mapstr[x][y]);
  for (int i = 1; i < len; i++) {
    char ita[100], cou = 0;
    itx = ity = 0;
    while (mapstr[x][y][i] >= 'A') {
      ita[cou] = mapstr[x][y][i];
      cou++;
      i++;
    }
    ita[cou] = '\0';
    ity = GetY(ita);
    while (mapstr[x][y][i] != '+' && i < len) {
      itx = itx * 10 + mapstr[x][y][i] - '0';
      cou++;
      i++;
    }
    ans += DFS(itx, ity);
  }
  return ans;
}
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    memset(has, 0, sizeof(has));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        char str[50];
        scanf("%s", str);
        if (str[0] != '=') {
          map[i][j] = GetNum(str);
          has[i][j] = 1;
        } else
          strcpy(mapstr[i][j], str);
      }
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (has[i][j]) continue;
        map[i][j] = DFS(i, j);
        has[i][j] = 1;
      }
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (j != n)
          printf("%d ", map[i][j]);
        else
          printf("%d\n", map[i][j]);
      }
  }
  return 0;
}
