
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAXN 11

long h[MAXN];
long n;

bool Init() {
  long k;
  cin >> n;
  for (k = 0; k < n; k++) cin >> h[k];
  return n != 0;
}

bool GirlWin() {
  long k;
  if (n % 2 == 1) return true;
  std::sort(h, h + n);
  for (k = 0; k < n; k += 2)
    if (h[k] != h[k + 1]) return true;
  return false;
}

int main() {
  while (Init()) {
    if (GirlWin())
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}