#include <iostream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <vector>

#define MAXW 10

using namespace std;

bitset<MAXW + 1> g[MAXW + 1];
char dp_w[MAXW + 1][MAXW + 1];
vector<pair<char, char> > cov;
vector<char> to_cov[MAXW + 1][MAXW + 1];
bool vis_cov[MAXW * MAXW];
bool cp_vis_cov[MAXW * MAXW];

int w, h;
int hval;
int bound;
int stp;

inline int min(int a, int b) { return a < b ? a : b; }

int h_val(void) {
  int i, j, k;
  int lft;

  memcpy(cp_vis_cov, vis_cov, sizeof(vis_cov));

  lft = 0;
  for (i = 1; i <= h; i++)
    for (j = 1; j <= w; j++)
      if (g[i][j]) {
        for (k = 0; k < to_cov[i][j].size(); k++)
          if (cp_vis_cov[to_cov[i][j][k]]) goto _h_val_CONT_;

        lft++;
        for (k = 0; k < to_cov[i][j].size(); k++)
          cp_vis_cov[to_cov[i][j][k]] = true;

      _h_val_CONT_:
        continue;
      }

  return lft;
}

int dfs(int x, int y) {
  int k;
  int tmp_bound;
  int ret_bound;

  if (!hval) return -1;
  if (hval + stp > bound) return hval + stp;

  if (y > w) {
    y = 1;
    x++;
  }

  if (!g[x][y]) return dfs(x, y + 1);
  for (k = 0; k < to_cov[x][y].size(); k++)
    if (vis_cov[to_cov[x][y][k]]) return dfs(x, y + 1);

  ret_bound = INT_MAX;
  for (k = 0; k < to_cov[x][y].size(); k++) {
    vis_cov[to_cov[x][y][k]] = true;
    hval = h_val();
    stp++;
    if ((tmp_bound = dfs(x, y + 1)) == -1) return -1;
    stp--;
    vis_cov[to_cov[x][y][k]] = false;

    ret_bound = min(ret_bound, tmp_bound);
  }

  return ret_bound;
}

int main() {
  int i, j, k;
  int x, y;
  int bit;

  while (scanf("%d%d", &w, &h), w) {
    memset(vis_cov, 0, sizeof(vis_cov));

    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++) {
        scanf("%d", &bit);
        g[i][j] = bit;
      }

    cov.clear();
    for (i = 1; i <= w; i++) dp_w[h][i] = g[h][i];
    for (i = 1; i <= h; i++) dp_w[i][w] = g[i][w];
    for (i = h - 1; i > 0; i--)
      for (j = w - 1; j > 0; j--)
        dp_w[i][j] = !g[i][j] ? 0 : 1 + min(min(dp_w[i + 1][j], dp_w[i][j + 1]),
                                            dp_w[i + 1][j + 1]);

    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++)
        if (g[i][j]) {
          for (x = 1; x <= i; x++)
            for (y = 1; y <= j; y++) {
              if (x == i && y == j) continue;
              if (x + dp_w[x][y] >= i + dp_w[i][j] &&
                  y + dp_w[x][y] >= j + dp_w[i][j])
                goto _CONT_;
            }

          cov.push_back(make_pair(i, j));
        _CONT_:
          continue;
        }

    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++)
        if (g[i][j]) {
          to_cov[i][j].clear();
          for (k = 0; k < cov.size(); k++) {
            x = cov[k].first;
            y = cov[k].second;

            if (x <= i && y <= j && x + dp_w[x][y] > i && y + dp_w[x][y] > j)
              to_cov[i][j].push_back(k);
          }
        }

    for (stp = 0, bound = 0, hval = h_val(); bound != -1; bound = dfs(1, 1))
      ;
    printf("%d\n", stp);
  }

  return 0;
}
