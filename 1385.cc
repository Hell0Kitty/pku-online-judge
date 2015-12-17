#include <stdio.h>
#include <iostream>
using namespace std;

struct point {
  double x, y;
};

double xmult(point p1,point p2,point p0){
  return (p1.x - p0.x) * (p2.y - p0.y)
       - (p2.x - p0.x) * (p1.y - p0.y);
}

point barycenter(int n, point* p)
{
    point ret;
    double area = 0.0, t;
    ret.x = ret.y = 0.0;
    for(int i = 1; i < n - 1; i++) {
        t = xmult(p[i], p[i+1], p[0]) / 2.0;
    area += t;
        ret.x += (p[0].x + p[i].x + p[i+1].x) * t;
        ret.y += (p[0].y + p[i].y + p[i+1].y) * t;
    }
    ret.x /= (3 * area);
    ret.y /= (3 * area);
    return ret;
}

int main() {
  point* p, ret;
  int ncases, n;  //ncases 个测试用例, n 个点
  scanf("%d", &ncases);
  while(ncases--) {
    scanf("%d", &n);
    p = new point[n];

    for(int i = 0; i < n; i++)
      scanf("%lf %lf", &p[i].x, &p[i].y);
    ret = barycenter(n, p);
    printf("%.2lf %.2lf\n", ret.x, ret.y);
    delete []p;
  }
  return 0;
}
