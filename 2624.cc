#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  double x[4], y[4], rx[255], ry[255];
  int i, n = 0;
  while (cin >> x[0] >> y[0]) {
    for (i = 1; i < 4; i++) cin >> x[i] >> y[i];
    int k, m;
    double t;
    for (k = 0; k < 4; k++)
      for (m = k + 1; m < 4; m++)
        if (x[k] == x[m] && y[k] == y[m]) {
          t = x[m], x[m] = x[1], x[1] = t;
          t = y[m], y[m] = y[1], y[1] = t;
          t = x[k], x[k] = x[3], x[3] = t;
          t = y[k], y[k] = y[3], y[3] = t;
          break;
        }
    rx[n] = x[0] - x[1] + x[2];
    ry[n] = y[0] - y[1] + y[2];
    n++;
  }
  for (i = 0; i < n; i++)
    cout << setprecision(3) << fixed << rx[i] << " " << setprecision(3) << fixed
         << ry[i] << endl;
  return 0;
}
