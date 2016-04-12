#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, r;
  int str[1010];
  while (1) {
    int cnt = 0;
    cin >> r >> n;
    if (n == -1 && r == -1) break;
    for (int i = 0; i < n; i++) {
      scanf("%d", &str[i]);
    }
    sort(str, str + n);
    for (int i = 0; i < n;) {
      int s = str[i];
      while (i < n && str[i] <= s + r) i++;
      int p = str[i - 1];
      while (i < n && str[i] <= p + r) i++;
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
