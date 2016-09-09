#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int phi[66000];
int main() {
  int i, j;
  for (i = 2; i <= 65536; i++) phi[i] = 0;
  phi[1] = 1;
  for (i = 2; i <= 65536; i++)
    if (!phi[i]) {
      for (j = i; j <= 65536; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }

  int n;
  while (cin >> n) cout << phi[n - 1] << endl;

  return 0;
}
