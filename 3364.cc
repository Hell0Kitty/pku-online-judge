#include <iostream>
#include <cstdio>
using namespace std;
int main() {
  int n, m, i;
  while (scanf("%d%d%d", &n, &m, &i)) {
    if (n == 0 && m == 0 && i == 0) break;
    n = n - 7;
    m = m - 7;
    if ((n * m) % 2 == 0) {
      cout << (n * m) / 2 << endl;
    } else {
      if (i == 1) {
        cout << (n * m) / 2 + 1 << endl;
      }
      if (i == 0) {
        cout << (n * m) / 2 << endl;
      }
    }
  }
  return 0;
}
