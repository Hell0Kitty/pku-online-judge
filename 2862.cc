#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#define ll long long
#define MAX 100001
using namespace std;
int g[MAX];
int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;
    int one = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> g[i];
      if (g[i] == 1) one = i;
    }
    if (one == -1)
      cout << (n + 1) / 2 << endl;
    else {
      for (int i = (one + 1) % n; i != one;) {
        int j = i, cnt = 0;
        while (j != one && g[j] == 0) {
          j = (j + 1) % n;
          cnt++;
        }
        ans += cnt / 2;
        if (j == one) break;
        i = (j + 1) % n;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
