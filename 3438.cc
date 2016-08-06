#include <iostream>
using namespace std;

int main() {
  int t;
  char digits[1001];
  cin >> t;
  while (t--) {
    cin >> digits;
    int len = strlen(digits);
    int count = 1;
    for (int i = 0; i < len; i++) {
      if (digits[i] == digits[i + 1])
        count++;
      else {
        cout << count << digits[i];
        count = 1;
      }
    }
    cout << endl;
  }
  return 0;
}
