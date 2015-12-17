

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
#define PI 3.14159265358979323846 /* pi */
#define E 2.718281828459045
int main() {
  int icounter;
  std::ios::sync_with_stdio(false);
  cin >> icounter;
  while (icounter--) {
    long double n;
    cin >> n;
    if (n == 1)
      cout << 1 << endl;
    else {
      long int result = log10(2 * PI * n) / 2 + n * log10(n / E) + 1;
      cout << result << endl;
    }
  }

  return 0;
}