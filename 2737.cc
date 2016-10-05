#include <iostream>
#include <cstdio>

using namespace std;
class Point {
 public:
  int x, y;
} p[1005];

class Line {
 public:
  Line(Point &p1, Point &p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = p1.x * (p2.y - p1.y) + p1.y * (p1.x - p2.x);
  }
  bool point_in_line(Point &p) { return a * p.x + b * p.y + c == 0; }
  int a, b, c;
};

int main() {
  int n, i, j, k, MAX, tmp, C = 1;
  while (scanf("%d", &n), n) {
    MAX = 0;
    for (i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
    for (i = 1; i <= n; i++)
      for (j = i + 1; j <= n; j++) {
        tmp = 2;
        Line L(p[i], p[j]);
        for (k = j + 1; k <= n; k++) {
          if (L.point_in_line(p[k])) tmp++;
        }
        if (tmp > MAX) MAX = tmp;
      }
    if (MAX < 4) MAX = 0;
    printf("Photo %d: %d points eliminated\n", C++, MAX);
  }
  return 0;
}
