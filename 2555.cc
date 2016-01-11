#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
int main() {
  double q1, q2, m1, t1, m2, t2, p1, p2;
  while (scanf("%lf%lf%lf%lf", &m1, &m2, &t1, &t2)) {
    if (m1 == 0 && m2 == 0 && t1 == 0 && t2 == 0) break;
    p1 = 4.19 * t1 * m1;
    p2 = -2.09 * t2 * m2;
    q1 = p1 + 335.0 * m1;
    q2 = p2 + 335 * m2;
    if (q1 > q2) {
      if (q2 < p1 - eps) {
        p1 -= q2;
        m1 += m2;
        t1 = p1 / m1 / 4.19;
        printf("0.0 g of ice and %.1lf g of water at %.1lf C\n", m1, t1);
      } else {
        p1 -= p2;
        double m = p1 / 335.0;
        m1 += m;
        m2 -= m;
        printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n", m2, m1);
      }
    } else {
      if (q1 < p2 - eps) {
        p2 -= q1;
        m2 += m1;
        t2 = -p2 / m2 / 2.09;
        printf("%.1lf g of ice and 0.0 g of water at %.1lf C\n", m2, t2);
      } else {
        p2 -= p1;
        double m = p2 / 335.0;
        m2 += m;
        m1 -= m;
        printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n", m2, m1);
      }
    }
  }
  return 0;
}
