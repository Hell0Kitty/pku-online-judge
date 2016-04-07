#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LT(x) ((x << 2) | 1)
#define RT(x) ((x << 2) | 2)
#define LB(x) ((x << 2) | 3)
#define RB(x) ((x << 2) + 4)

#define M 1024

typedef struct {
  char c;
  int lt, rt, lb, rb;
} TN;

TN T[M * M];

unsigned char map[M][M >> 3];

char tmp[M];

void Create(int ix, int t, int l, int s) {
  int m;
  if (s == 1)
    T[ix].c = map[t][l >> 3] & (1 << (l & 7)) ? 'B' : 'W';
  else {
    m = s >> 1;
    Create(LT(ix), t, l, m);
    Create(RT(ix), t, l + m, m);
    Create(LB(ix), t + m, l, m);
    Create(RB(ix), t + m, l + m, m);
    if (T[LT(ix)].c == T[RT(ix)].c && T[LT(ix)].c == T[LB(ix)].c &&
        T[LT(ix)].c == T[RB(ix)].c)
      T[ix].c = T[LT(ix)].c;
    else
      T[ix].c = 'Q';
  }
}

void Traverse(int ix) {
  putchar(T[ix].c);
  if (T[ix].c == 'Q') {
    Traverse(LT(ix));
    Traverse(RT(ix));
    Traverse(LB(ix));
    Traverse(RB(ix));
  }
}

int main() {
  int n, i, j;

  scanf("%s%s%d ", tmp, tmp, &n);
  gets(tmp);
  gets(tmp);
  for (i = 0; i < n; i++) {
    for (j = 0; j<n>> 3; j++) {
      scanf("%x,", &map[i][j]);
    }
  }
  Create(0, 0, 0, n);
  printf("%d\n", n);
  Traverse(0);
  puts("");
  return 0;
}
