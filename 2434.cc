#include <stdio.h>
#include <string.h>

int P, B1, B2, R, back_dis, map[16][16];

#define inline

inline int min(int a, int b) { return a < b ? a : b; }

inline int abs(int a) { return a > 0 ? a : -a; }

inline void put(int x, int y, int h) {
  if (x < -4 || x > 4 || y < -4 || y > 4) return;
  map[y + 4][x + 4] += h;
}

inline void left(int x, int y, int t, int h, int dir) {
  int i;

  if (!dir) {
    // left
    x -= t;
  } else {
    // right
    i = min(t, B1 - x - 1);
    t -= i;
    x += i;
    if (t > 1) {
      t--;
      x -= t;
    }
  }
  put(x, y, h);
}

inline void right(int x, int y, int t, int h, int dir) {
  int i;

  if (!dir) {
    // left
    i = min(t, x - B2 - 1);
    t -= i;
    x -= i;
    if (t > 1) {
      t--;
      x += t;
    }
  } else {
    // right
    x += t;
  }
  put(x, y, h);
}

inline void mid(int x, int y, int t, int h, int dir) {
  int i;

  if (!dir) {
    // left
    i = min(t, x - B1 - 1);
    t -= i;
    x -= i;
  } else {
    // right
    i = min(t, B2 - x - 1);
    t -= i;
    x += i;
  }

  if (t > 1) {
    i = t / back_dis;
    if (i) t -= i * back_dis;
  }

  if (!t) {
    put(x, y, h);
    return;
  }

  t--;
  mid(x, y, t, h, !dir);
}

inline void point(int x, int y, int t, int h, int dir) {
  if (x < B1)
    left(x, y, t, h, dir);
  else if (x > B1 && x < B2)
    mid(x, y, t, h, dir);
  else
    right(x, y, t, h, dir);
}

inline void pair(int x, int y, int t, int h) {
  if (t > R) return;
  if (t == R)
    put(x, y, h);
  else {
    point(x, y, R - t, h, 0);
    point(x, y, R - t, h, 1);
  }
}

inline void wave(int x, int y, int t, int h) {
  int i;

  for (i = -4; i <= 4; i++) pair(x, i, t + abs(y - i), h);
}

int main() {
  int i, x, y, t;

  scanf("%d%d%d%d", &P, &B1, &B2, &R);

  if (B1 > B2) {
    i = B2;
    B2 = B1;
    B1 = i;
  }
  back_dis = 2 * (B2 - B1) - 2;

  while (P--) {
    scanf("%d%d%d", &x, &y, &t);
    wave(x, y, t, 1);
    wave(x, y, t + 2, -1);
  }

  for (y = 4; y >= -4; y--) {
    for (x = -4; x <= 4; x++) {
      if (x == B1 || x == B2) {
        putc('X', stdout);
        continue;
      }
      i = map[y + 4][x + 4];
      if (i > 0)
        putc('*', stdout);
      else if (i < 0)
        putc('o', stdout);
      else
        putc('-', stdout);
    }
    putc('\n', stdout);
  }

  return 0;
}
