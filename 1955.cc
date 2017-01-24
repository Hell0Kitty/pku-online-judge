#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int mofang[60];

void SHOW() {
  int cnt = 1;
  printf("      ");
  for (int i = 0; i < 9; i++, cnt++) {
    printf("%c ", mofang[i]);
    if (cnt % 3 == 0) {
      if (i != 0) putchar(10);
      if (i != 8) printf("      ");
    }
  }
  cnt = 1;
  for (int i = 9; i < 45; i++, cnt++) {
    printf("%c ", mofang[i]);
    if (cnt % 12 == 0) putchar(10);
  }
  cnt = 1;
  printf("      ");
  for (int i = 45; i < 54; i++, cnt++) {
    printf("%c ", mofang[i]);
    if (cnt % 3 == 0) {
      putchar(10);
      if (i != 53) printf("      ");
    }
  }
  putchar(10);
}

void quanCLOCKwise(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                   int a8, int a9) {
  int a, b, c;
  a = mofang[a1];
  b = mofang[a2];
  c = mofang[a3];
  mofang[a1] = mofang[a7];
  mofang[a2] = mofang[a4];
  mofang[a3] = a;
  mofang[a7] = mofang[a9];
  mofang[a4] = mofang[a8];
  mofang[a8] = mofang[a6];
  mofang[a6] = b;
  mofang[a9] = c;
}

void quanFANCLOCKwise(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                      int a8, int a9) {
  int a = mofang[a1], b = mofang[a2], c = mofang[a3];
  mofang[a1] = c;
  mofang[a2] = mofang[a6];
  mofang[a3] = mofang[a9];
  mofang[a6] = mofang[a8];
  mofang[a9] = mofang[a7];
  mofang[a7] = a;
  mofang[a8] = mofang[a4];
  mofang[a4] = b;
}

void huanCLOCKwise(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                   int a8, int a9, int a10, int a11, int a12) {
  int a = mofang[a1], b = mofang[a2], c = mofang[a3];
  mofang[a1] = mofang[a10];
  mofang[a2] = mofang[a11];
  mofang[a3] = mofang[a12];
  mofang[a10] = mofang[a7];
  mofang[a11] = mofang[a8];
  mofang[a12] = mofang[a9];
  mofang[a9] = mofang[a6];
  mofang[a8] = mofang[a5];
  mofang[a7] = mofang[a4];
  mofang[a6] = c;
  mofang[a5] = b;
  mofang[a4] = a;
}

void huanFANCLOCKwise(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                      int a8, int a9, int a10, int a11, int a12) {
  int a = mofang[a1], b = mofang[a2], c = mofang[a3];
  mofang[a1] = mofang[a4];
  mofang[a2] = mofang[a5];
  mofang[a3] = mofang[a6];
  mofang[a4] = mofang[a7];
  mofang[a5] = mofang[a8];
  mofang[a6] = mofang[a9];
  mofang[a9] = mofang[a12];
  mofang[a8] = mofang[a11];
  mofang[a7] = mofang[a10];
  mofang[a10] = a;
  mofang[a11] = b;
  mofang[a12] = c;
}

void QianClockwise() {
  quanCLOCKwise(12, 13, 14, 24, 25, 26, 36, 37, 38);
  huanCLOCKwise(6, 7, 8, 15, 27, 39, 47, 46, 45, 35, 23, 11);
}

void QianFanClockwise() {
  quanFANCLOCKwise(12, 13, 14, 24, 25, 26, 36, 37, 38);
  huanFANCLOCKwise(6, 7, 8, 15, 27, 39, 47, 46, 45, 35, 23, 11);
}

void BackClockwise() {
  quanCLOCKwise(18, 19, 20, 30, 31, 32, 42, 43, 44);
  huanCLOCKwise(2, 1, 0, 9, 21, 33, 51, 52, 53, 41, 29, 17);
}

void BackFanClockwise() {
  quanFANCLOCKwise(18, 19, 20, 30, 31, 32, 42, 43, 44);
  huanFANCLOCKwise(2, 1, 0, 9, 21, 33, 51, 52, 53, 41, 29, 17);
}

void LeftClockwise() {
  quanCLOCKwise(9, 10, 11, 21, 22, 23, 33, 34, 35);
  huanCLOCKwise(0, 3, 6, 12, 24, 36, 45, 48, 51, 44, 32, 20);
}

void LeftFanClockwise() {
  quanFANCLOCKwise(9, 10, 11, 21, 22, 23, 33, 34, 35);
  huanFANCLOCKwise(0, 3, 6, 12, 24, 36, 45, 48, 51, 44, 32, 20);
}

void RightClockwise() {
  quanCLOCKwise(15, 16, 17, 27, 28, 29, 39, 40, 41);
  huanCLOCKwise(8, 5, 2, 18, 30, 42, 53, 50, 47, 38, 26, 14);
}

void RightFanClockwise() {
  quanFANCLOCKwise(15, 16, 17, 27, 28, 29, 39, 40, 41);
  huanFANCLOCKwise(8, 5, 2, 18, 30, 42, 53, 50, 47, 38, 26, 14);
}

void TopClockwise() {
  quanCLOCKwise(0, 1, 2, 3, 4, 5, 6, 7, 8);
  huanCLOCKwise(20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9);
}

void TopFanClockwise() {
  quanFANCLOCKwise(0, 1, 2, 3, 4, 5, 6, 7, 8);
  huanFANCLOCKwise(20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9);
}

void BotClockwise() {
  quanCLOCKwise(45, 46, 47, 48, 49, 50, 51, 52, 53);
  huanCLOCKwise(36, 37, 38, 39, 40, 41, 42, 43, 44, 33, 34, 35);
}

void BotFanClockwise() {
  quanFANCLOCKwise(45, 46, 47, 48, 49, 50, 51, 52, 53);
  huanFANCLOCKwise(36, 37, 38, 39, 40, 41, 42, 43, 44, 33, 34, 35);
}

int main() {
  int t, cas = 1;
  scanf("%d", &t);
  while (t--) {
    printf("Scenario #%d:\n", cas++);
    for (int i = 0; i < 54; i++) {
      char c[3];
      scanf("%s", c);
      mofang[i] = (int)c[0];
    }
    int m;
    scanf("%d", &m);
    while (m--) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (a == 0) {
        if (b == 1)
          LeftClockwise();
        else
          LeftFanClockwise();
      } else if (a == 1) {
        if (b == 1)
          QianClockwise();
        else
          QianFanClockwise();
      } else if (a == 2) {
        if (b == 1)
          RightClockwise();
        else
          RightFanClockwise();
      } else if (a == 3) {
        if (b == 1)
          BackClockwise();
        else
          BackFanClockwise();
      } else if (a == 4) {
        if (b == 1)
          TopClockwise();
        else
          TopFanClockwise();
      } else if (a == 5) {
        if (b == 1)
          BotClockwise();
        else
          BotFanClockwise();
      }
    }
    SHOW();
  }
  return 0;
}
