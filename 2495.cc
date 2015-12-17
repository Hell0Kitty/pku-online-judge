#include <iostream>
using namespace std;
int main() {
  int t, k = 0;
  cin >> t;
  while (++k <= t) {
    int a, b, c, d, ok;
    cin >> a >> b >> c >> d;
    cout << "Scenario #" << k << ":" << endl;
    cout << (a + b + c + d) % 2 << endl << endl;
  }
  return 0;
}