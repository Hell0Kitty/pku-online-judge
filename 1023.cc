#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  char str[70];
  int res[70];
  int T;
  int k;
  long long N;
  cin >> T;
  while (T--) {
    cin >> k;
    cin >> str;
    cin >> N;
    for (int i = k - 1; i >= 0; i--) {
      if (str[i] == 'p') {
        if (N % 2) {
          res[i] = 1;
          N = (N - 1) / 2;
        } else {
          res[i] = 0;
          N /= 2;
        }
      } else {
        if (N % 2) {
          res[i] = 1;
          N = (N + 1) / 2;
        } else {
          res[i] = 0;
          N /= 2;
        }
      }
    }
    if (N == 0) {
      for (int i = 0; i < k; i++) cout << res[i];
      cout << endl;
    } else
      cout << "Impossible" << endl;
  }

  return 0;
}
