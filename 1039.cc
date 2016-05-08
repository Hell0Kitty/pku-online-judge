#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double precision = 1e-3;  //精度限制
const double inf = 99999.0;     //正无穷，注意下面使用的是负无穷

typedef class Node  //折点坐标
    {
 public:
  double x;
  double y;
} point;

int max(int a, int b) { return a > b ? a : b; }

/*把浮点p的值转化为0,1或-1  (精度讨论)*/

int dblcmp(double p) {
  if (fabs(p) < precision)  // fabs()  浮点数的绝对值
    return 0;               //只要是在0的邻域，就认为是0

  return p > 0 ? 1 : -1;
}

/*叉积运算*/

double det(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}

/*计算P点在AB的左侧还是右侧（AC与AB的螺旋关系）*/

double cross(point A, point B, point P) {
  return det(B.x - A.x, B.y - A.y, P.x - A.x, P.y - A.y);
}

/*判断直线AB、CD是否相交*/

bool check(point A, point B, point C, point D) {
  return (dblcmp(cross(A, B, C)) * dblcmp(cross(A, B, D)) <= 0);
}

double intersection(point A, point B, point C, point D) {
  double area1 = cross(A, B, C);
  double area2 = cross(A, B, D);
  int c = dblcmp(area1);
  int d = dblcmp(area2);

  if (c * d < 0)  // CD在AB的两侧，规范相交
    return (area2 * C.x - area1 * D.x) / (area2 - area1);
  if (c * d == 0)  // CD的其中一个端点在AB上，不规范相交
    if (c == 0)
      return C.x;  // C在AB上,返回AB与CD非规范相交时的交点C的横坐标
    else
      return D.x;  // D在AB上,返回AB与CD非规范相交时的交点D的横坐标

  return -inf;  // CD在AB同侧，无交点,返回 负无穷
}

int main(int i, int j, int k) {
  int n;  //折点数
  while (cin >> n) {
    if (!n) break;

    point* up = new point[n + 1];    //上折点
    point* down = new point[n + 1];  //下折点

    double max_x = -inf;  //最大可见度(管中最远可见点的横坐标)
    /*Input*/

    for (i = 1; i <= n; i++) {
      cin >> up[i].x >> up[i].y;
      down[i].x = up[i].x;
      down[i].y = up[i].y - 1;
    }

    bool flag = false;  //标记当前光线L(直线up[i]->down[j])能否贯通全管
    for (i = 1; i <= n; i++)  //枚举所有通过一个上折点、一个下折点的直线
    {
      for (j = 1; j <= n; j++)
        if (i != j) {
          for (k = 1; k <= n; k++)  //直线L最大延伸到第k-1节管子
            if (!check(up[i], down[j], up[k],
                       down[k]))  // up[k]->down[k]为折点处垂直x轴的直线
              break;

          if (k > n) {
            flag = true;
            break;
          } else if (k > max(i, j)) {
            double temp = intersection(up[i], down[j], up[k], up[k - 1]);
            if (max_x < temp)  // L与第k-1节管子的上管壁相交
              max_x = temp;

            temp = intersection(up[i], down[j], down[k], down[k - 1]);
            if (max_x < temp)  // L与第k-1节管子的上管壁相交
              max_x = temp;
          }
        }

      if (flag) break;
    }

    if (flag)
      cout << "Through all the pipe." << endl;
    else
      cout << fixed << setprecision(2) << max_x << endl;

    delete up, down;
  }
  return 0;
}
