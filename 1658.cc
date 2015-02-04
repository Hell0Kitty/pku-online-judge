
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

bool judge_diff(int a, int b, int c, int d) {
  if (a + d == b + c)
    return true;
  else
    return false;
}

int main(int argc, char const *argv[]) {
  /* code */
  std::ios::sync_with_stdio(false);
  int ncase;
  cin >> ncase;
  while (ncase--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (judge_diff(a, b, c, d)) {
      cout << a << " " << b << " " << c << " " << d << " " << d + (b - a)
           << endl;
    } else {
      cout << a << " " << b << " " << c << " " << d << " " << d *(b / a)
           << endl;
    }
  }
  return 0;
}