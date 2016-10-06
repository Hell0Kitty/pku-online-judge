#include <cstdio>
#include <cstring>
#include <algorithm>
int n;
char text[1 << 4][2][1 << 7], buff[1 << 8];
int len[1 << 4], pre[1 << 4][2][1 << 7], pos[1 << 4][2][1 << 4][2];
int f[1 << 16][1 << 4][2], src, ans;
void findPre(char *s, int n, int *pre) {
  pre[0] = -1;
  for (int i = 1, j = -1; i < n; ++i) {
    while (j != -1 && s[j + 1] != s[i]) {
      j = pre[j];
    }
    if (s[j + 1] == s[i]) {
      ++j;
    }
    pre[i] = j;
  }
}
int findPos(char *s, int n, char *t, int m, int *pre) {
  int j = -1;
  for (int i = 0; i < n; ++i) {
    while (j != -1 && t[j + 1] != s[i]) {
      j = pre[j];
    }
    if (t[j + 1] == s[i]) {
      ++j;
    }
    if (j == m - 1) {
      return j;
    }
  }
  return j;
}
const int inf = (int)(1e9);
int srcSubstrAns() {
  src = 0;
  for (int i = 1; i < n; ++i) {
    if (len[i] > len[src]) {
      src = i;
    }
  }
  int buff_len = 2 * len[src];
  for (int i = 2; i <= len[src]; ++i) {
    for (int j = 0; j < buff_len; ++j) {
      buff[j] = text[src][0][j % i];
    }
    bool flag = true;
    for (int j = 0; j < n && flag; ++j) {
      if (findPos(buff, buff_len, text[j][0], len[j], pre[j][0]) ==
          len[j] - 1) {
        continue;
      }
      if (findPos(buff, buff_len, text[j][1], len[j], pre[j][1]) ==
          len[j] - 1) {
        continue;
      }
      flag = false;
    }
    if (flag) {
      return i;
    }
  }
  return inf;
}
int dfs(int stat, int last, int inv) {
  int &val = f[stat][last][inv];
  if (val != inf) {
    return val;
  }
  for (int i = 0; i < n; ++i) {
    if (stat & (1 << i)) {
      if (pos[last][inv][i][0] == len[i] - 1 ||
          pos[last][inv][i][1] == len[i] - 1) {
        stat ^= (1 << i);
      }
    }
  }
  if (stat == 0) {
    return -(pos[src][0][last][inv] + 1);
  }
  for (int i = 0; i < n; ++i) {
    if (stat & (1 << i)) {
      val = std::min(val, dfs(stat ^ (1 << i), i, 0) + len[i] -
                              (pos[i][0][last][inv] + 1));
      val = std::min(val, dfs(stat ^ (1 << i), i, 1) + len[i] -
                              (pos[i][1][last][inv] + 1));
    }
  }
  return val;
}
int main() {
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; ++i) {
      scanf("%s", text[i][0]);
      len[i] = strlen(text[i][0]);
      strcpy(text[i][1], text[i][0]);
      std::reverse(text[i][1], text[i][1] + len[i]);
      findPre(text[i][0], len[i], pre[i][0]);
      findPre(text[i][1], len[i], pre[i][1]);
    }
    for (int i = 0; i < n; ++i) {
      for (int p = 0; p < 2; ++p) {
        for (int j = 0; j < n; ++j) {
          for (int q = 0; q < 2; ++q) {
            pos[i][p][j][q] =
                findPos(text[i][p], len[i], text[j][q], len[j], pre[j][q]);
          }
        }
      }
    }
    ans = srcSubstrAns();
    if (ans == inf) {
      for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
          f[i][j][0] = f[i][j][1] = inf;
        }
      }
      int mask = (1 << n) - 1;
      ans = dfs(mask ^ (1 << src), src, 0) + len[src];
    }
    printf("%d\n", ans);
  }
  return 0;
}
