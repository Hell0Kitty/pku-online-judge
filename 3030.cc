#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
  long long int test, a, b, c;

  cin >> test;

  for (int i = 0; i < test; i++) {
    cin >> a >> b >> c;

    if (b - c > a)
      cout << "advertise" << endl;
    else if (b - c == a)
      cout << "does not matter" << endl;

    else
      cout << "do not advertise" << endl;
  }
  return 0;
}
