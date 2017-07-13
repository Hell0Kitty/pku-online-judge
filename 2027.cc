#include <iostream>

using namespace std;

int main() {
  int n, a, b;

  cin >> n;

  while (n-- > 0) {
    cin >> a >> b;

    cout << (a < b ? "NO BRAINS\n" : "MMM BRAINS\n");
  }

  return 0;
}
