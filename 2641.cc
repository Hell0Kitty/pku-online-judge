#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

const double EPS = 1e-6;
const double PI = acos(-1.0);
bool zero(double x) { return abs(x) < EPS; }

inline double SQR(double x) { return x * x; }

double a, b, s, m, n;

int main() {
  while (scanf("%lf %lf %lf %lf %lf", &a, &b, &s, &m, &n) != EOF &&
         (!zero(a) || !zero(b) || !zero(s) || !zero(m) || !zero(n))) {
    double v = sqrt(double(SQR(a * m) + SQR(b * n))) / s;
    double ang = acos(a * m / (v * s)) / PI * 180;
    printf("%0.2lf %0.2lf\n", ang, v);
  }
  return 0;
}
