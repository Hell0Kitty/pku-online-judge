#include <cstdio>
#include <algorithm>

int n, col[3], row[1 << 7];
typedef long long int64;
int64 f[2][1 << 7][1 << 7], g[2][1 << 7][1 << 7];
const int64 p = (int64)(1e17);

bool check() {
  int col_sum = 0, row_sum = 0;
  for (int i = 0; i < 3; ++i) {
    col_sum += col[i];
  }
  for (int i = 0; i < n; ++i) {
    row_sum += row[i];
  }
  return col_sum == row_sum;
}

int64 sum(int at, int s, int t1, int t2) {
  if (at == 0) {
    t1 = std::max(t1, 0);
    return t1 ? (g[0][s][t2] - g[0][s][t1 - 1] + p) % p : g[0][s][t2];
  } else {
    t1 = std::max(t1, 0);
    return t1 ? (g[1][t2][s] - g[1][t1 - 1][s] + p) % p : g[1][t2][s];
  }
}

int64 solve() {
  if (!check()) {
    return 0LL;
  }

  int x = 0, y = 1;
  for (int a = 0; a <= col[0]; ++a) {
    for (int b = 0; b <= col[1]; ++b) {
      f[x][a][b] = (a + b <= row[0] ? 1LL : 0LL);
    }
  }
  for (int i = 1; i < n; ++i, std::swap(x, y)) {
    for (int a = 0; a <= col[0]; ++a) {
      g[0][a][0] = f[x][a][0];
      for (int b = 1; b <= col[1]; ++b) {
        g[0][a][b] = (f[x][a][b] + g[0][a][b - 1]) % p;
      }
    }
    for (int b = 0; b <= col[1]; ++b) {
      g[1][0][b] = f[x][0][b];
      for (int a = 1; a <= col[0]; ++a) {
        g[1][a][b] = (f[x][a][b] + g[1][a - 1][b]) % p;
      }
    }

    for (int a = 0; a <= col[0]; ++a) {
      for (int b = 0; b <= col[1]; ++b) {
        if (a - 1 >= 0 && b + 1 <= col[1]) {
          f[y][a][b] = f[y][a - 1][b + 1] + sum(0, a, b - row[i], b + 1) -
                       sum(1, b + 1, a - row[i] - 1, a) + p;
          f[y][a][b] %= p;
        } else {
          f[y][a][b] = 0LL;
          for (int aa = 0; aa <= a; ++aa) {
            for (int bb = 0; bb <= b && aa + bb <= row[i]; ++bb) {
              f[y][a][b] += f[x][a - aa][b - bb];
              f[y][a][b] %= p;
            }
          }
        }
      }
    }
  }
  return f[x][col[0]][col[1]];
}

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < 3; ++i) {
      scanf("%d", &col[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &row[i]);
    }
    printf("%lld\n", solve());
  }
  return 0;
}
