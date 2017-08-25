#include <iostream>
#include <algorithm>
#define F(i, a, b) for (int i = a; i <= b; i++)
#define FD(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

struct P {
  int x, y, id;
  P() {}
  P(int a, int b, int c) { x = a, y = b, id = c; }

  bool operator<(const P& b) const {
    if (x == b.x) return y < b.y;
    return x < b.x;
  }
};

P p[50001];
int ax[50001], ay[50001];

int n;

int main() {
  int total, x, y;

  while (scanf("%d", &n) && n != 0) {
    total = 0;

    F(i, 1, n) {
      scanf("%d%d", &x, &y);
      p[i].x = x, p[i].y = y;
    }

    sort(&p[1], &p[n + 1]);

    total = 1;
    int maxy = p[n].y;
    FD(i, n - 1, 1) {
      if (p[i].y > maxy) {
        maxy = p[i].y;
        total++;
      }
    }
    printf("%d\n", total);
  }

  return 0;
}
