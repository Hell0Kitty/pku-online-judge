#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct data {
  int v, s;
  data() {}
  data(int _v, int _s) { v = _v, s = _s; }
} po[1001000];
int main() {
  int f, r;
  f = 1;
  for (r = 1; r < 10; r++) po[r] = data(r, 1 << r);
  while (r <= 1000000) {
    int v = po[f].v, s = po[f].s;
    f++;
    for (int i = 0; i < 10; i++)
      if (!(s & (1 << i))) po[r++] = data(v * 10 + i, s | (1 << i));
  }
  int n;
  while (scanf("%d", &n), n) {
    printf("%d\n", po[n].v);
  }
  return 0;
}
