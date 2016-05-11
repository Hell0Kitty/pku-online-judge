#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {
  int num, i, j, k, ans, min, a, b, c;
  cin >> num;
  ans = INT_MAX;
  for (i = 1; i <= sqrt(float(num)) + 1; i++)
    for (j = 1; j <= i; j++) {
      if (num % (i * j) == 0) {
        k = num / (i * j);
        min = i * j * 2 + i * k * 2 + j * k * 2;
        if (ans > min) {
          ans = min;
          a = i;
          b = j;
          c = k;
        }
      } else
        continue;
    }
  cout << a << " " << b << " " << c << endl;

  return 0;
}
