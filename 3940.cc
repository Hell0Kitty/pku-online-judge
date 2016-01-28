#include <iostream>
using namespace std;
const int maxL = 64;
int cnt[maxL + 10];
double color[maxL];
double area[maxL];

int main() {
  double p = 0.10000;
  int n, w;
  while (scanf("%d%d", &n, &w) == 2 && (n + w)) {
    memset(cnt, 0, sizeof(cnt));
    int max_cnt = -1;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      ++cnt[x / w];
      max_cnt = max(max_cnt, cnt[x / w]);
    }
    int L;
    for (L = maxL; L >= 0; --L)
      if (cnt[L]) break;
    for (int i = 0; i < L; ++i) color[i] = (L - i) * 1.0 / L;
    for (int i = 0; i < L; ++i) area[i] = cnt[i] * 1.0 / max_cnt;
    double ans = 0.0;
    for (int i = 0; i < L; ++i) ans += color[i] * area[i];
    printf("%.10lg\n", ans + 0.01);
  }
  return 0;
}
