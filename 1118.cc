
#include <iostream>
#include <climits>
using namespace std;

struct Info {
  int x;
  int y;
} cor[705];

int main() {
  int n, i, j, k, ans, max;
  double k1, k2;
  while (cin >> n) {
    if (n == 0) break;
    ans = 0;
    max = 0;
    for (i = 1; i <= n; i++) cin >> cor[i].x >> cor[i].y;
    for (i = 1; i <= n; i++) {
      for (j = i + 1; j <= n; j++) {
        max = 0;
        for (k = j + 1; k <= n; k++) {
          if ((cor[j].x - cor[i].x) * (cor[k].y - cor[j].y) ==
              (cor[j].y - cor[i].y) * (cor[k].x - cor[j].x))
            max++;
        }
        if (max > ans) ans = max;
      }
    }
    cout << ans + 2 << endl;
  }
}