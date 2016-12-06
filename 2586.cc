#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int a[14];

int main() {
  int s, d;

  while (cin >> s >> d) {
    d = -1 * d;
    memset(a, 0, sizeof(a));
    // 1~5
    int l = 1, r = 5;
    int sum = 0;
    while (r >= l) {
      a[r--] = d;
      sum += d;
      while (sum + s < 0 && r >= l) {
        a[l++] = s;
        sum += s;
      }
    }
    for (int i = 2; i <= 8; i++) {
      sum -= a[i - 1];
      if (sum + s < 0) {
        a[i + 4] = s;
        sum += s;
      } else {
        a[i + 4] = d;
        sum += d;
      }
    }
    long long int ans = 0;
    for (int i = 1; i <= 12; i++) {
      ans += a[i];
    }
    if (ans > 0)
      cout << ans << endl;
    else
      cout << "Deficit" << endl;
  }
  return 0;
}
