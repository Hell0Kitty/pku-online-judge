#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

const int maxSize = 8;
const int initMod = 2E3 + 5;
int curSize = maxSize;
int curMod = initMod;

struct Matrix {
  int val[maxSize][maxSize];

  Matrix(bool ONE = false) {
    for (int i = 0; i < curSize; i++) {
      for (int j = 0; j < curSize; j++) {
        val[i][j] = 0;
      }
      if (ONE) val[i][i] = 1;
    }
  }

  void print(int _l = curSize, int _w = curSize) {
    for (int i = 0; i < _l; i++) {
      for (int j = 0; j < _w; j++) {
        if (j) putchar(' ');
        printf("%d", val[i][j]);
      }
      puts("");
    }
    puts("~~");
  }
};

Matrix operator*(Matrix &_a, Matrix &_b) {
  Matrix ret = Matrix();

  for (int i = 0; i < curSize; i++) {
    for (int k = 0; k < curSize; k++) {
      if (_a.val[i][k]) {
        for (int j = 0; j < curSize; j++) {
          ret.val[i][j] += _a.val[i][k] * _b.val[k][j];
          ret.val[i][j] %= curMod;
        }
      }
    }
  }

  return ret;
}

Matrix operator^(Matrix &_a, int _p) {
  Matrix __a = _a, ret = Matrix(true);

  while (_p) {
    if (_p & 1) {
      ret = ret * __a;
    }
    __a = __a * __a;
    _p >>= 1;
  }

  return ret;
}

int deal(int _n) {
  Matrix Base = Matrix(), op = Matrix();

  Base.val[0][0] = Base.val[0][1] = 1;
  for (int i = 0; i < 4; i++) {
    op.val[i][i << 1] = op.val[i + 4][i << 1] = 1;
    if (i != 2 && i != 3) op.val[i][i << 1 | 1] = op.val[i + 4][i << 1 | 1] = 1;
  }
  op = op ^ (_n - 1);
  Base = Base * op;

  int sum = 0;

  for (int i = 0; i < 8; i++) sum += Base.val[0][i], sum %= curMod;

  return sum;
}

int main() {
  int n;

  while (~scanf("%d", &n)) printf("%d\n", deal(n));

  return 0;
}
