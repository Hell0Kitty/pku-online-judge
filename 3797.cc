#include <iostream>
using namespace std;

int main() {
  int f[20];
  int a[20];
  int b[20];

  int n;
  f[0] = 1;
  f[1] = 1;
  a[0] = 0;
  a[1] = 1;
  b[0] = 0;
  b[1] = 1;
  int i;
  for (i = 2; i < 20; i++) {
    f[i] = f[i - 1] + f[i - 2] + a[i - 1] + 2 * b[i - 1];
    a[i] = f[i - 1] + a[i - 2];
    b[i] = f[i - 1] + b[i - 1];
  }
  cin >> n;
  int j = 0;
  while (j < n) {
    cin >> i;
    cout << ++j << " " << f[i] << endl;
  }
  return 0;
}
