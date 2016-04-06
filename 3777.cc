#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#define Inf 0x3f3f3f3f
using namespace std;
typedef __int64 LL;
const int maxn = 10;

LL mul_mod(LL a, LL b, LL c) {
  LL ret = 0;
  while (b) {
    if (b & 1) ret = (ret + a) % c;
    a = (2 * a) % c;
    b >>= 1;
  }
  return ret;
}

LL power_mod(LL a, LL b, LL c) {
  LL ret = 1;
  while (b) {
    if (b & 1) ret = mul_mod(ret, a, c);
    a = mul_mod(a, a, c);
    b >>= 1;
  }
  return ret;
}

struct Mat {
  LL mat[2][2];
} E;
LL P;

void Init() {
  memset(E.mat, 0, sizeof(E.mat));
  for (int i = 0; i < 2; ++i) E.mat[i][i] = 1;
}

Mat operator*(Mat a, Mat b) {
  Mat c;
  memset(c.mat, 0, sizeof(c.mat));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (a.mat[i][k] && b.mat[k][j]) {
          c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % P;
        }
      }
    }
  }
  return c;
}

Mat operator+(Mat a, Mat b) {
  Mat c;
  memset(c.mat, 0, sizeof(c.mat));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
    }
  }
  return c;
}

Mat operator^(Mat A, int x) {
  Mat c;
  c = E;
  for (; x; x >>= 1) {
    if (x & 1) c = c * A;
    A = A * A;
  }
  return c;
}

int main() {
  LL x1, y1, z1, y2, z2;
  Mat A, C;
  LL q;
  while (scanf("%I64d %I64d %I64d", &x1, &y1, &z1)) {
    if (x1 == -1 && y1 == -1 && z1 == -1) break;
    Init();
    scanf("%I64d %I64d", &y2, &z2);
    scanf("%I64d", &P);
    q = (power_mod(x1, y1, P) + z1) % P;
    A.mat[0][0] = q - 1, A.mat[0][1] = q;
    A.mat[1][0] = 1, A.mat[1][1] = 0;
    C = A ^ z2;
    for (int i = 1; i <= y2; ++i) {
      C = C * A;
      A = A * A;
    }
    printf("%I64d\n", C.mat[0][0]);
  }
  return 0;
}
