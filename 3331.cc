#include <iostream>
#include <string.h>
using namespace std;
int a[1005];
void mul(int n) {
  int left = 0;
  for (int i = 0; i < 1000; i++) {
    a[i] = left + a[i] * n;
    left = a[i] / 10;
    a[i] %= 10;
  }
}
int main() {
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    memset(a, 0, sizeof(a));
    a[0] = 1;
    for (int i = 2; i <= n; i++) {
      mul(i);
    }
    int k = 1000;

    for (; k >= 0; --k) {
      if (a[k]) break;
    }

    int count = 0;
    for (int i = 0; i <= k; i++) {
      if (a[i] == x) count++;
    }
    cout << count << endl;
  }
  return 0;
}
