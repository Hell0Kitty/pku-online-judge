
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int r_j(int para) { return pow(para, 1.0 / 3); }

void solve(int i) {
  for (int x = 2; x < i; x++) {
    for (int y = x + 1; y < i; y++)
      for (int z = y + 1; z < i; z++) {
        // cout << "x: " << x << "y: " << y << "z: " << z << endl;
        int tmp = x * x * x + y * y * y + z * z * z;
        if (tmp == i * i * i) {
          cout << "Cube = " << i << ", Triple = (" << x << "," << y << "," << z
               << ")" << endl;
        }
      }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  return 0;
}