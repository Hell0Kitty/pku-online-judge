#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = (1 << 15) + 1;
int po[200], ans[N + 2];
int main() {
  for (int i = 1; i < 200; po[i] = i * i, i++)
    ;
  memset(ans, 0, sizeof(ans));
  for (int i1 = 1, tp1; po[i1] <= N; i1++) {
    ans[tp1 = po[i1]]++;
    for (int i2 = i1, tp2; tp1 + po[i2] <= N; i2++) {
      ans[tp2 = tp1 + po[i2]]++;
      for (int i3 = i2, tp3; tp2 + po[i3] <= N; i3++) {
        ans[tp3 = tp2 + po[i3]]++;
        for (int i4 = i3; tp3 + po[i4] <= N; i4++) ans[tp3 + po[i4]]++;
      }
    }
  }
  int n;
  while (scanf("%d", &n) && n) printf("%d\n", ans[n]);
  return 0;
}
