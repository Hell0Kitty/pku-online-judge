#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int tc, c = 0;
  long long sum, tmp1, tmp2, n, m;
  cin >> tc;
  while (tc--) {
    c++;
    cin >> n >> m;
    if (n > 0 && m > 0) {
      tmp1 = (n + m);
      tmp2 = (m - n + 1);
      sum = tmp1 * tmp2 / 2;
    } else if (n < 0 && m < 0) {
      n = abs(double(n));
      m = abs(double(m));
      tmp1 = (n + m);
      tmp2 = (n - m + 1);
      sum = tmp1 * tmp2 / 2;
      sum = -sum;
    } else {
      n = abs(double(n));
      m = abs(double(m));
      if (n > m) {
        tmp1 = (n + m + 1);
        tmp2 = (n - m);
        sum = tmp1 * tmp2 / 2;
        sum = -sum;
      } else {
        tmp1 = (n + m + 1);
        tmp2 = (m - n);
        sum = tmp1 * tmp2 / 2;
      }
    }
    printf("Scenario #%d:\n%lld\n\n", c, sum);
  }
}
