#include <iostream>
using namespace std;
void solve(int n) {
  int x = (n + 1) / 2 - 1;
  int y = n;
  for (int i = 0; i < x; ++i) {
    cout << n / 2 << " " << 2 << " " << y - 2 - i << endl;
    n -= 2;
  }
  cout << "2 " << x << " " << x + 1 << endl;
}

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 2) {
    cout << "1" << endl;
    cout << "1 1 1" << endl;
    return 0;
  }
  if (n % 2 != 0) {
    cout << (n + 1) / 2 << endl;
    solve(n);
  } else {
    cout << n / 2 + 1 << endl;
    solve(n - 1);
    cout << 1 << " " << n - 1 << " 1" << endl;
  }

  return 0;
}
