
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
const double PI = (2.0 * asin(1.0));

int main(void) {
  double x, y, z, role, half, max;
  double R, r, triple, area;
  int hujk = 1;
  cin >> x >> y >> z >> role;
  while (x + y + z + role) {
    triple = x + y + z;
    half = triple * 0.5;
    area = sqrt(half * (half - x) * (half - y) * (half - z));
    R = area * 2.0 / triple;
    if (x + y + z <= role)
      max = area;
    else if (2.0 * PI * R >= role)
      max = role * role / (4.0 * PI);
    else {
      r = (triple - role) / (triple / R - 2.0 * PI);
      max = area + PI * r * r - (r * r * area / (R * R));
    }
    cout << "Case " << hujk++ << ": ";
    cout << setiosflags(ios::fixed) << setprecision(2) << max << endl;
    cin >> x >> y >> z >> role;
  }
  return 0;
}