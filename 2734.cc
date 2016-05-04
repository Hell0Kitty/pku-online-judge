#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

struct Piece {
  int row, col;
};

Piece Q[MAXN], K[MAXN], P;
int chess[MAXN][MAXN];
int jump[8][2] = {
    {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

int main() {
  int i, j, k, ii, jj, n, m, qn, kn, pn, t, T;
  for (T = 1; scanf("%d%d", &n, &m), n + m; T++) {
    memset(chess, 0, sizeof(chess));
    scanf("%d", &qn);
    for (i = 0; i < qn; i++) {
      scanf("%d%d", &Q[i].row, &Q[i].col);
      chess[Q[i].row][Q[i].col] = 15;
    }
    scanf("%d", &kn);
    for (i = 0; i < kn; i++) {
      scanf("%d%d", &K[i].row, &K[i].col);
      chess[K[i].row][K[i].col] = 15;
    }
    scanf("%d", &pn);
    for (i = 0; i < pn; i++) {
      scanf("%d%d", &P.row, &P.col);
      chess[P.row][P.col] = 15;
    }
    for (qn--; qn >= 0; qn--)
      for (k = 0; k < 9; k++)
        if (k != 4) {
          ii = k / 3 - 1, jj = k % 3 - 1;
          if (ii == 0)
            t = 1;
          else if (ii == jj)
            t = 2;
          else if (jj == 0)
            t = 4;
          else
            t = 8;
          for (i = Q[qn].row + ii, j = Q[qn].col + jj;; i += ii, j += jj) {
            if (i < 1 || j < 1 || i > n || j > m || (chess[i][j] & t)) break;
            chess[i][j] |= t;
          }
        }
    for (kn--; kn >= 0; kn--)
      for (k = 0; k < 8; k++) {
        ii = jump[k][0];
        jj = jump[k][1];
        i = K[kn].row + ii, j = K[kn].col + jj;
        if (i < 1 || j < 1 || i > n || j > m || chess[i][j]) continue;
        chess[i][j] |= 15;
      }
    for (i = 1, k = 0; i <= n; i++)
      for (j = 1; j <= m; j++) {
        if (!chess[i][j]) k++;
      }
    printf("Board %d has %d safe squares.\n", T, k);
  }
  return 0;
}
