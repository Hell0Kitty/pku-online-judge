#include <stdio.h>
#include <string.h>
#define xlson kx << 1, xl, mid
#define xrson kx << 1 | 1, mid + 1, xr
#define ylson ky << 1, yl, mid
#define yrson ky << 1 | 1, mid + 1, yr
#define MAXN 1005
#define mem(a) memset(a, 0, sizeof(a))

bool tree[MAXN << 2][MAXN << 2];
int X, N, T;
int num, X1, X2, Y1, Y2;
char ch;

void editY(int kx, int ky, int yl, int yr) {
  if (Y1 <= yl && yr <= Y2) {
    tree[kx][ky] = !tree[kx][ky];
    return;
  }
  int mid = (yl + yr) >> 1;
  if (Y1 <= mid) editY(kx, ylson);
  if (Y2 > mid) editY(kx, yrson);
}

void editX(int kx, int xl, int xr) {
  if (X1 <= xl && xr <= X2) {
    editY(kx, 1, 1, N);
    return;
  }
  int mid = (xl + xr) >> 1;
  if (X1 <= mid) editX(xlson);
  if (X2 > mid) editX(xrson);
}

void queryY(int kx, int ky, int yl, int yr) {
  if (tree[kx][ky]) num++;
  if (yl == yr) return;
  int mid = (yl + yr) >> 1;
  if (Y1 <= mid)
    queryY(kx, ylson);
  else
    queryY(kx, yrson);
}

void queryX(int kx, int xl, int xr) {
  queryY(kx, 1, 1, N);
  if (xl == xr) return;
  int mid = (xl + xr) >> 1;
  if (X1 <= mid)
    queryX(xlson);
  else
    queryX(xrson);
}

int main() {
  while (~scanf("%d", &X))
    while (X--) {
      mem(tree);
      scanf("%d %d%*c", &N, &T);
      for (int i = 0; i < T; i++) {
        scanf("%c %d %d%*c", &ch, &X1, &Y1);
        if (ch == 'C') {
          scanf("%d %d%*c", &X2, &Y2);
          editX(1, 1, N);
        } else {
          num = 0;
          queryX(1, 1, N);
          if (num & 1)
            printf("1\n");
          else
            printf("0\n");
        }
      }
      if (X) printf("\n");
    }
  return 0;
}
