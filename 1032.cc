#include <iostream>
using namespace std;
int main() {
  int n;
  int sum = 2;
  cin >> n;
  int i;
  for (i = 3;; i++) {
    if ((sum <= n) && (sum + i > n)) {
      break;
    }
    sum += i;
  }
  if (sum == n) {
    for (int j = 2; j <= i - 1; j++) cout << j << " ";
  } else if ((n - sum) == (i - 1)) {
    int j;
    for (j = 2; j <= i - 1; j++) {
      if (j == i - 1) {
        cout << j + 2 << " ";
        break;
      }
      cout << j + 1 << " ";
    }
  } else if ((n - sum) < (i - 1)) {
    int k = n - sum;
    int k1 = i - k;
    for (int j = 2; j <= i - 1; j++) {
      if (j >= k1) {
        cout << j + 1 << " ";
      } else {
        cout << j << " ";
      }
    }
  }
  return 0;
}
