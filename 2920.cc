#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 300 + 5;
struct Node {
  int r, c;
  Node(int r, int c) : r(r), c(c) {}
};
int dr[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[] = {0, 0, -1, 1, -1, -1, 1, 1};
char map[maxn][maxn];
int n, m;
bool mine(int r, int c) {
  for (int d = 0; d < 8; d++) {
    int nr = r + dr[d], nc = c + dc[d];
    if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && map[nr][nc] == '*')
      return true;
  }
  return false;
}
void BFS(int mr, int mc) {
  queue<Node> Q;
  if (mine(mr, mc))
    map[mr][mc] = '#';
  else
    map[mr][mc] = '.';
  if (map[mr][mc] == '.') Q.push(Node(mr, mc));
  while (!Q.empty()) {
    Node node = Q.front();
    Q.pop();
    int r = node.r, c = node.c;
    for (int d = 0; d < 8; d++) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && map[nr][nc] == '?') {
        if (mine(nr, nc))
          map[nr][nc] = '#';
        else
          map[nr][nc] = '.';
        if (map[nr][nc] == '.') Q.push(Node(nr, nc));
      }
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) map[i][j] = '?';
    while (m--) {
      int r, c;
      scanf("%d%d", &r, &c);
      map[r][c] = '*';
    }
    BFS((n + 1) / 2, (n + 1) / 2);
    printf("Scenario #%d:\n", kase);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) printf("%c", map[i][j]);
      printf("\n");
    }
    puts("");
  }
  return 0;
}
