#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;

#define MAXN 2510
#define ID(r, c) ((r)*C + (c))
#define INRG(r, c) (0 <= (r) && (r) < R && 0 <= (c) && (c) < C)

int dr[12] = {-1, -2, -2, -1, 1, 2, 2, 1, -1, 0, 1, 0};
int dc[12] = {-2, -1, 1, 2, 2, 1, -1, -2, 0, 1, 0, -1};
int reservdir[12] = {4, 5, 6, 7, 0, 1, 2, 3, 10, 11, 8, 9};
int noname[12] = {0x001, 0x002, 0x004, 0x008, 0x010, 0x020,
                  0x040, 0x080, 0x100, 0x200, 0x400, 0x800};

int hall[51][51];
int R, C;
int m1to2[MAXN];
int m2to1[MAXN];
bool visited[MAXN];
bool isTreasure[MAXN];
vector<int> conn[MAXN];

bool FindPath(int nn) {
  int i;
  int v;
  for (i = conn[nn].size() - 1; i >= 0; i--) {
    v = conn[nn][i];
    if (visited[v]) continue;
    visited[v] = true;
    if (m2to1[v] == -1 || FindPath(m2to1[v])) {
      m1to2[nn] = v;
      m2to1[v] = nn;
      return true;
    }
  }

  return false;
}

int solve() {
  int res = 0;
  int gridCount = R * C;
  memset(m1to2, -1, sizeof(m1to2));
  memset(m2to1, -1, sizeof(m2to1));
  for (int i = 0; i < gridCount; i++) {
    if (!isTreasure[i]) continue;

    if (m1to2[i] == -1) {
      memset(visited, 0, sizeof(visited));
      res += FindPath(i);
    }
  }

  return res;
}

void makeMap() {
  memset(isTreasure, false, sizeof(isTreasure));

  int i, k;
  for (i = R * C - 1; i >= 0; i--) conn[i].resize(0);

  int v, id, dir;
  int r, c;
  for (i = 0; i < R; i++) {
    for (k = 0; k < C; k++) {
      if ((i + k) & 1) continue;

      v = hall[i][k];
      if (v == -1) continue;

      id = ID(i, k);
      isTreasure[id] = true;
      for (dir = 0; dir < 12; dir++) {
        r = i + dr[dir];
        c = k + dc[dir];
        if (!INRG(r, c) || hall[r][c] == -1) continue;

        if (v & noname[dir]) {
          conn[id].push_back(ID(r, c));
        } else if (hall[r][c] & noname[reservdir[dir]]) {
          conn[id].push_back(ID(r, c));
        }
      }
    }
  }
}

int main() {
  int kase = 0;
  while (scanf("%d %d", &R, &C), R > 0 && C > 0) {
    int i, k;
    for (i = 0; i < R; i++)
      for (k = 0; k < C; k++) scanf("%d", &hall[i][k]);

    makeMap();
    printf("%d. %d\n", ++kase, solve());
  }

  return 0;
}
