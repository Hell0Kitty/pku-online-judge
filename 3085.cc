#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  int x;

  int x1, x2, x3, x4;
  for (int i = 0; i < t; i++) {
    cin >> x;
    x1 = x / 25;
    x -= x1 * 25;
    x2 = x / 10;
    x -= x2 * 10;
    x3 = x / 5;
    x -= x3 * 5;
    x4 = x / 1;

    cout << i + 1 << " " << x1 << " QUARTER(S), " << x2 << " DIME(S), " << x3
         << " NICKEL(S), " << x4 << " PENNY(S)" << endl;
  }
}
