#include <stdio.h>
#include <string.h>
#include <math.h>

const int Max = 128;
const double eps = 1e-9;
struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
  void getP() { scanf("%d%d", &x, &y); }
  pt operator-(pt a) { return pt(x - a.x, y - a.y); }
} P[Max];
double A[Max][Max];
int sign(double x) { return (x > eps) - (x < -eps); }
int main() {
  int N, W, H;
  while (scanf("%d%d%d", &N, &H, &W) != EOF && N) {
    for (int i = 0; i < N; i++) P[i].getP();
    P[N] = P[0];
    memset(A, 0, sizeof(A));
    for (int i = 0; i < N; i++) {
      pt dir = P[i + 1] - P[i];
      if (dir.x == 0) continue;
      int sx, tx, sy, g;
      if (dir.x > 0) {
        sx = P[i].x;
        sy = P[i].y;
        tx = P[i + 1].x;
        g = 1;
      } else {
        sx = P[i + 1].x;
        sy = P[i + 1].y;
        tx = P[i].x;
        g = -1;
        dir.x = -dir.x, dir.y = -dir.y;
      }
      double dx = dir.x * 1.0 / dir.y;
      double dy = dir.y * 1.0 / (tx - sx);
      if (dx < 0) dx = -dx;
      int cx = sx, nx = sx + 1;
      double cy = sy, ny = sy + dy;
      int a = (int)(cy + eps);
      int b = (int)(ny + eps);
      while (cx < tx) {
        int up = a > b ? a : b;
        int dn = a < b ? a : b;
        double pre = 0.0;
        if (up > dn) {
          double uy = up == a ? cy : ny;
          double x = dx * (uy - up);
          for (int j = up; j > dn; j--) {
            double ca = x * (uy - j) * 0.5;
            A[cx][j] += g * (ca - pre);
            pre = ca, x += dx;
          }
        }
        A[cx][dn] += g * ((cy - dn + ny - dn) * 0.5 - pre);
        for (int j = 0; j < dn; j++) A[cx][j] += g;
        cx = nx++;
        cy = ny, ny += dy;
        a = b, b = (int)(ny + eps);
      }
    }
    for (int i = W - 1; i >= 0; i--) {
      for (int j = 0; j < H; j++) {
        double ca = A[j][i];
        if (ca < 0.25 - eps)
          putchar('.');
        else if (ca < 0.50 - eps)
          putchar('+');
        else if (ca < 0.75 - eps)
          putchar('o');
        else if (ca < 1.00 - eps)
          putchar('$');
        else
          putchar('#');
      }
      putchar('\n');
    }
  }
  return 0;
}
