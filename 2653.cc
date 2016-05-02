#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;
const int maxn = 100010;
const double eps = 1e-10;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};
typedef Point Vector;
Point operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Point operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Point operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
Point operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
int dcmp(double x) {
  if (fabs(x) < eps)
    return 0;
  else
    return x < -eps ? -1 : 1;
}
double mul(Point p0, Point p1, Point p2) { return Cross(p1 - p0, p2 - p1); }
int cross(Point p1, Point p2, Point p3, Point p4) {
  double a1 = mul(p1, p2, p3), a2 = mul(p1, p2, p4);
  if (dcmp(a1) == 0 && dcmp(a2) == 0) return 2;
  if (dcmp(a1) == dcmp(a2)) return 0;
  return 1;
}
Point p1[maxn], p2[maxn];
int n;
int main() {
  while (~scanf("%d", &n) && n) {
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf %lf %lf", &p1[i].x, &p1[i].y, &p2[i].x, &p2[i].y);
    }
    int f1 = 0;
    printf("Top sticks:");
    for (int i = 0; i < n; i++) {
      int flag = 0;
      for (int j = i + 1; j < n; j++) {
        if (cross(p1[i], p2[i], p1[j], p2[j]) == 1 &&
            cross(p1[j], p2[j], p1[i], p2[i]) == 1) {
          flag = 1;
          break;
        }
      }
      if (flag == 0 && f1 == 1) printf(",");
      if (flag == 0) printf(" %d", i + 1), f1 = 1;
    }
    printf(".\n");
  }
  return 0;
}
