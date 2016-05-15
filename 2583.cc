#include <iostream>
using namespace std;

int A, B, C;

void initP(int f0, int f1, int f2) {
  C = f0;
  B = (4 * f1 - 3 * C - f2) / 2;
  A = (f2 - 2 * f1 + C) / 2;
}

int main(int argc, char const *argv[]) {
  int f0, f1, f2;
  while (cin >> f0 >> f1 >> f2) {
    initP(f0, f1, f2);
    cout << A * 9 + B * 3 + C << " " << A * 16 + B * 4 + C << " "
         << A * 25 + B * 5 + C << endl;
  }
  return 0;
}
