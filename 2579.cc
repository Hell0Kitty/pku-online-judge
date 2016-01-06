#include <iostream>
#include <string>
using namespace std;
char d[15][15];
int main() {
  string op;
  int r, c, i, j;
  while (cin >> op) {
    if (op == "START") {
      cin >> r >> c;
      for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) cin >> d[i][j];
      }
      cin >> op;
      for (i = 0; i < r - 1; i++) {
        for (j = 0; j < c - 1; j++) {
          cout << char((d[i][j] + d[i][j + 1] + d[i + 1][j] + d[i + 1][j + 1]) /
                       4);
        }
        cout << endl;
      }
    } else {
      break;
    }
  }
  return 0;
}
