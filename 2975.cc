#include <iostream>
using namespace std;
int a[1002];
int main() {
  int n, x;
  while (cin >> n && n) {
    int res = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      res ^= a[i];
    }
    if (res) {
      for (int i = 0; i < n; i++) {
        if ((res ^ a[i]) <= a[i]) {
          cnt++;
        }
      }
      cout << cnt << endl;
    } else {
      cout << res << endl;
    }
  }
  return 0;
}
