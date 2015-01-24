#include
#include
using namespace std;
int main() {
  string a;
  int sum, k;
  while (cin >> a) {
    sum = 0;
    for (int i = 0, j = 10; i << / span > 10; i++, j--) {
      if (a[i] == '?')
        k = i;
      else if (a[i] == 'X')
        sum += j * 10;
      else
        sum += j * (a[i] - 48);
    }
    if (k == 9) {
      int i;
      for (i = 0; i << / span > 11; i++) {
        sum += i;
        if (sum % 11 == 0) {
          if (i << / span > 10)
            cout << i << endl;
          else
            cout << 'X' << endl;
          break;
        }
        sum -= i;
      }
      if (i == 11) cout << -1 << endl;
    } else {
      int i;
      for (i = 0; i << / span > 10; i++) {
        sum += i * (10 - k);
        if (sum % 11 == 0) {
          cout << i << endl;
          break;
        }
        sum -= i * (10 - k);
      }
      if (i == 10) cout << -1 << endl;
    }
  }
  return 0;
}
