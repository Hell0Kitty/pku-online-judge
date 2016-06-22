#include <cstdio>
#include <algorithm>

int n;

struct pt_st;
int det(const pt_st &, const pt_st &);

struct pt_st {
  int x, y, sign;
  void read() { scanf("%d %d %d", &x, &y, &sign); }
  bool operator<(const pt_st &rhs) const { return det(*this, rhs) > 0; }
} pt[1 << 10], npt[1 << 10];

int det(const pt_st &a, const pt_st &b) { return a.x * b.y - b.x * a.y; }

int solve(int idx) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i == idx) {
      continue;
    }
    npt[j].x = pt[i].x - pt[idx].x;
    npt[j].y = pt[i].y - pt[idx].y;
    npt[j].sign = pt[i].sign;
    if (npt[j].y < 0 || (npt[j].y == 0 && npt[j].x < 0)) {
      npt[j].x *= -1;
      npt[j].y *= -1;
      npt[j].sign ^= 1;
    }
    ++j;
  }
  std::sort(npt, npt + n - 1);
  int lhs = 0, rhs = 0, ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    lhs += npt[i].sign ^ 1;
  }
  for (int i = 0, j; i < n - 1; i = j) {
    int cnt = 0;
    for (j = i; j < n - 1 && !det(npt[i], npt[j]); ++j) {
      cnt += npt[j].sign ^ 1;
      rhs += npt[j].sign;
    }
    ans = std::max(ans, lhs + rhs + 1);
    ans = std::max(ans, (n - 1) - (lhs + rhs) + j - i + 1);
    lhs -= cnt;
  }
  return ans;
}

int main() {
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; ++i) {
      pt[i].read();
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = std::max(ans, solve(i));
    }
    printf("%d\n", ans);
  }
  return 0;
}
