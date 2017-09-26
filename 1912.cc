#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-10;  ///这题不卡精度
const int mx = 100005;

struct P {
  double x, y;
  P(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  bool read() { return ~scanf("%lf%lf", &x, &y); }
  ///由于比较的是原始输入数据，所以不用eps
  bool operator<(const P& p) const  ///加cosnt和引用以便sort调用，其他函数不加
  {
    return x < p.x || x == p.x && y < p.y;
  }
  P operator+(P p) { return P(x + p.x, y + p.y); }
  P operator-(P p) { return P(x - p.x, y - p.y); }
  P operator*(double d) { return P(x * d, y * d); }
  P operator/(double d) { return P(x / d, y / d); }
  double dot(P p) { return x * p.x + y * p.y; }
  double det(P p) { return x * p.y - y * p.x; }
  ///根据凸包构造之后的点的顺序，规定角度范围为(-pi/2, 3/(2pi)]
  double getA() {
    double A = atan2(y, x);
    if (A < -pi / 2.0 + eps) A += pi * 2;
    return A;
  }
} p[mx], ans[mx], q1, q2;
int n, len;
double A[mx];

///求凸包
void convex_hull() {
  sort(p, p + n);
  len = 0;
  int i;
  for (i = 0; i < n; ++i) {
    while (len >= 2 &&
           (ans[len - 1] - ans[len - 2]).det(p[i] - ans[len - 1]) < eps)
      --len;
    ans[len++] = p[i];
  }
  int tmp = len;
  for (i = n - 2; i >= 0; --i) {
    while (len > tmp &&
           (ans[len - 1] - ans[len - 2]).det(p[i] - ans[len - 1]) < eps)
      --len;
    ans[len++] = p[i];
  }
  --len;
  ans[len] = ans[0];  ///这句话直接写在凸包里
  for (i = 0; i < len; ++i) A[i] = (ans[i + 1] - ans[i]).getA();
}

inline bool dcmp(double a, double b) { return a + eps < b; }

///二分找第一个角度大于x的边
inline int Find(double angle) {
  return upper_bound(A, A + len, angle, dcmp) - A;
}

inline bool judge(P q1, P q2) {
  int i = Find((q2 - q1).getA());
  int j = Find(
      (q1 - q2).getA());  ///直线两侧各找一点，若两点在直线两侧，则直线必过凸包
  if ((q2 - q1).det(ans[i] - q1) * (q2 - q1).det(ans[j] - q1) > -eps)
    return true;
  else
    return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) p[i].read();
  if (n > 1) convex_hull();
  while (q1.read()) {
    q2.read();
    puts(n <= 1 || judge(q1, q2) ? "GOOD" : "BAD");
  }
  return 0;
}
