#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int l = 1; l <= t; l++) {
    string a, b;
    int first[80] = {0}, second[80] = {0}, result[81] = {0};
    cin >> a >> b;
    for (int i = a.length() - 1; i >= 0; i--)
      first[a.length() - 1 - i] = a[i] - '0';
    for (int i = b.length() - 1; i >= 0; i--)
      second[b.length() - 1 - i] = b[i] - '0';
    int len = a.length() > b.length() ? a.length() : b.length();
    for (int i = 0; i < len; i++) result[i] = first[i] + second[i];
    for (int i = 0; i < len; i++) {
      if (result[i] >= 2) {
        result[i + 1] += 1;
        result[i] %= 2;
      }
    }
    cout << l << " ";
    int i = 80;
    for (; i >= 0; i--)
      if (result[i] != 0) break;
    if (i < 0) i = 0;
    for (int k = i; k >= 0; k--) cout << result[k];
    cout << endl;
  }
  return 0;
}
