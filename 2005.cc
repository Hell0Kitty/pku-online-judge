#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  int deck;
  while (cin >> deck, deck) {
    double total = 52 * deck - 3, sum;
    int n0, dl, pl1, pl2, player;
    char a, b, c;
    cin >> a >> b >> c;
    if (a > 49 && a < 58)
      dl = a - 48;
    else if (a == 'A')
      dl = 11;
    else
      dl = 10;
    if (b > 49 && b < 58)
      pl1 = b - 48;
    else if (b == 'A')
      pl1 = 11;
    else
      pl1 = 10;
    if (c > 49 && c < 58)
      pl2 = c - 48;
    else if (c == 'A')
      pl2 = 11;
    else
      pl2 = 10;
    player = pl1 + pl2 == 22 ? 12 : pl1 + pl2;
    if (dl != 11)
      if (dl >= player - 2) {
        cout << "0.000%" << endl
             << endl;
        continue;
      }
    if (player - dl > 11) {
      cout << "100.000%" << endl
           << endl;
      continue;
    }
    n0 = player - dl - 2, sum = 0;
    if (dl == 11) {
      if (dl >= player - 1) {
        cout << "0.000%" << endl
             << endl;
        continue;
      }
      if (pl1 == 11)
        sum += 4 * deck - 2;
      else if (pl2 == 11)
        sum += 4 * deck - 2;
      else
        sum += 4 * deck - 1;
    }
    for (int i = 0, j = 2; i < n0; i++, j++) {
      if (j == dl) {
        if (j == 10)
          sum += 16 * deck - 1;
        else
          sum += 4 * deck - 1;
        if (j == pl1) sum -= 1;
        if (j == pl2) sum -= 1;
        continue;
      }
      if (j == pl1) {
        if (j == 10)
          sum += 16 * deck - 1;
        else
          sum += 4 * deck - 1;
        if (j == pl2) sum -= 1;
        continue;
      }
      if (j == pl2) {
        if (j == 10)
          sum += 16 * deck - 1;
        else
          sum += 4 * deck - 1;
        continue;
      }
      if (j == 10)
        sum += 16 * deck;
      else
        sum += 4 * deck;
    }
    cout << fixed << setprecision(3) << sum / total * 100 << "%" << endl
         << endl;
  }
  return 0;
}
