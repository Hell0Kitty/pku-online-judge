#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define lowbit(x) ((x) & (-(x)))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define max3(a, b, c) (max(a, max(b, c)))
#define min(a, b) ((a) < (b) ? (a) : (b))

const int N = 105;
const double dinf = 1e15;
const double EPS = 1e-7;

struct point3 {
  double x, y, z;

  point3() {}
  point3(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
  }

  void Get() { scanf("%lf%lf%lf", &x, &y, &z); }

  point3 operator+(point3 a) { return point3(x + a.x, y + a.y, z + a.z); }

  point3 operator-(point3 a) { return point3(x - a.x, y - a.y, z - a.z); }

  point3 operator*(point3 a)  //叉积
  {
    return point3(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
  }

  point3 operator*(double t) { return point3(x * t, y * t, z * t); }

  double operator^(point3 a)  //点积
  { return x * a.x + y * a.y + z * a.z; }

  point3
  operator/(double t) {
    return point3(x / t, y / t, z / t);
  }

  double len()  //长度
  {
    return sqrt(x * x + y * y + z * z);
  }

  point3 adjust(double L)  //调整为L长
  {
    double t = len();
    L /= t;
    return point3(x * L, y * L, z * L);
  }

  void print() { printf("%.10lf %.10lf %.10lf\n", x + EPS, y + EPS, z + EPS); }
};

int sgn(double x) {
  if (fabs(x) < EPS) return 0;
  return x > 0 ? 1 : -1;
}

double len(point3 a) { return a.len(); }

double getArea(point3 a, point3 b, point3 c)  //三角形面积
{
  double x = len((b - a) * (c - a));
  return x / 2;
}

double getVolume(point3 a, point3 b, point3 c, point3 d)  //四面体体积
{
  double x = (b - a) * (c - a) ^ (d - a);
  return x / 6;
}

point3 pShadowOnPlane(point3 p, point3 a, point3 b, point3 c)  //点在平面的投影
{
  point3 v = (b - a) * (c - a);
  if (sgn(v ^ (a - p)) < 0) v = v * -1;
  v = v.adjust(1);
  double d = fabs(v ^ (a - p));
  return p + v * d;
}

double lineToLine(point3 a, point3 b, point3 p, point3 q)  //异面直线间距离
{  //参数：直线上两点
  point3 v = (b - a) * (q - p);
  return fabs((a - p) ^ v) / v.len();
}
//两异面直线距离：两直线上的点的连线在其法向量上的投影
double LineToLine(point3 p1, point3 k1, point3 p2,
                  point3 k2) {  //参数：直线上一点及其法向量
  point3 nV = k1 * k2;
  return fabs(nV ^ (p1 - p2)) / nV.len();
}

int pInPlane(point3 p, point3 a, point3 b, point3 c)  //点是否在面上
{
  double S = getArea(a, b, c);
  double S1 = getArea(a, b, p);
  double S2 = getArea(a, c, p);
  double S3 = getArea(b, c, p);
  return sgn(S - S1 - S2 - S3) == 0;
}

int opposite(point3 p, point3 q, point3 a, point3 b, point3 c)  // p q在平面两侧
{
  point3 v = (b - a) * (c - a);
  double x = v ^ (p - a);
  double y = v ^ (q - a);
  return sgn(x * y) < 0;  //投影异号
}

int segCrossTri(point3 p, point3 q, point3 a, point3 b,
                point3 c)  // pq是与三角形abc相交
{
  return opposite(p, q, a, b, c) && opposite(a, b, p, q, c) &&
         opposite(a, c, p, q, b) && opposite(b, c, p, q, a);
}

double pToPlane(point3 p, point3 a, point3 b, point3 c)  // p到面abc的距离
{
  double v = ((b - a) * (c - a) ^ (p - a)) / 6;
  double s = len((b - a) * (c - a)) / 2;
  return fabs(3 * v / s);
}

double pToLine(point3 p, point3 a, point3 b)  //点到直线的距离
{
  double S = len((a - p) * (b - p));
  return S / len(a - b);
}

double pToSeg(point3 p, point3 a, point3 b)  //点到线段的距离
{
  if (sgn((p - a) ^ (b - a)) <= 0) return len(a - p);
  if (sgn((p - b) ^ (a - b)) <= 0) return len(b - p);
  return pToLine(p, a, b);
}

double pToPlane1(point3 p, point3 a, point3 b, point3 c)  //点到三角形的距离
{
  point3 k = pShadowOnPlane(p, a, b, c);
  if (pInPlane(k, a, b, c)) return pToPlane(p, a, b, c);
  double x = pToSeg(p, a, b);
  double y = pToSeg(p, a, c);
  double z = pToSeg(p, b, c);
  return min(x, min(y, z));
}

double getAng(point3 a, point3 b)  //求两向量的夹角
{
  double x = (a ^ b) / len(a) / len(b);
  return acos(x);
}

double segToSeg(point3 a, point3 b, point3 p, point3 q)  //线段到线段的距离
{
  point3 v = (b - a) * (q - p);

  double A, B, A1, B1;
  A = ((b - a) * v) ^ (p - a);
  B = ((b - a) * v) ^ (q - a);

  A1 = ((p - q) * v) ^ (a - q);
  B1 = ((p - q) * v) ^ (b - q);
  if (sgn(A * B) <= 0 && sgn(A1 * B1) <= 0) {
    return lineToLine(a, b, p, q);
  }

  double x = min(pToSeg(a, p, q), pToSeg(b, p, q));
  double y = min(pToSeg(p, a, b), pToSeg(q, a, b));
  return min(x, y);
}

struct face {
  int a, b, c, ok;

  face() {}
  face(int _a, int _b, int _c, int _ok) {
    a = _a;
    b = _b;
    c = _c;
    ok = _ok;
  }
};

struct _3DCH  //三维凸包
    {
  face F[N << 2];
  int b[N][N], cnt, n;
  point3 p[N];

  int getDir(point3 t, face F) {
    double x = (p[F.b] - p[F.a]) * (p[F.c] - p[F.a]) ^ (t - p[F.a]);
    return sgn(x);
  }

  void deal(int i, int x, int y) {
    int f = b[x][y];
    if (!F[f].ok) return;
    if (getDir(p[i], F[f]) == 1)
      DFS(i, f);
    else {
      b[y][x] = b[x][i] = b[i][y] = cnt;
      F[cnt++] = face(y, x, i, 1);
    }
  }

  void DFS(int i, int j) {
    F[j].ok = 0;
    deal(i, F[j].b, F[j].a);
    deal(i, F[j].c, F[j].b);
    deal(i, F[j].a, F[j].c);
  }

  void construct() {
    int i, j, k = 0;
    for (i = 1; i < n; i++)
      if (sgn(len(p[i] - p[0])))  //找出两个点不共点
      {
        swap(p[i], p[1]);
        k++;
        break;
      }
    if (k != 1) return;
    for (i = 2; i < n; i++)
      if (sgn(getArea(p[0], p[1], p[i])))  //找出三点不共线
      {
        swap(p[i], p[2]);
        k++;
        break;
      }
    if (k != 2) return;
    for (i = 3; i < n; i++)
      if (sgn(getVolume(p[0], p[1], p[2], p[i])))  //找出四点不共面
      {
        swap(p[i], p[3]);
        k++;
        break;
      }
    if (k != 3) return;

    cnt = 0;
    for (i = 0; i < 4; i++) {
      face k = face((i + 1) % 4, (i + 2) % 4, (i + 3) % 4, 1);
      if (getDir(p[i], k) == 1) swap(k.b, k.c);
      b[k.a][k.b] = b[k.b][k.c] = b[k.c][k.a] = cnt;
      F[cnt++] = k;
    }

    for (i = 4; i < n; i++)
      for (j = 0; j < cnt; j++) {
        if (F[j].ok && getDir(p[i], F[j]) == 1) {
          DFS(i, j);
          break;
        }
      }
    j = 0;
    for (i = 0; i < cnt; i++)
      if (F[i].ok) F[j++] = F[i];
    cnt = j;
  }

  point3 getCenter()  //求三维凸包的重心
  {
    point3 ans = point3(0, 0, 0), o = point3(0, 0, 0);
    double s = 0, temp;
    int i;
    for (i = 0; i < cnt; i++) {
      face k = F[i];
      temp = getVolume(o, p[k.a], p[k.b], p[k.c]);
      ans = ans + (o + p[k.a] + p[k.b] + p[k.c]) / 4 * temp;
      s += temp;
    }
    ans = ans / s;
    return ans;
  }

  double getMinDis(point3 a)  //求凸包内一个点到面的最短距离
  {
    double ans = dinf;
    int i;
    for (i = 0; i < cnt; i++) {
      face k = F[i];
      ans = min(ans, pToPlane(a, p[k.a], p[k.b], p[k.c]));
    }
    return ans;
  }
};

int n;
point3 data[N];
double R[N];
vector<point3> V;

void Deal(point3 a, double ra, point3 b, double rb) {
  double x = len(a), y = len(b);
  b = b / y * x;
  rb = rb / y * x;
  double d = len(a - b);
  if (sgn(d - ra - rb) == 0) {
    V.push_back(a + (b - a) / d * ra);
    return;
  }
  if (sgn(d - ra - rb) > 0) return;
  if (sgn(d - fabs(ra - rb)) <= 0) return;
  x = (ra * ra + d * d - rb * rb) / (2 * d);
  y = sqrt(ra * ra - x * x);
  point3 M = a + (b - a) / d * x;
  point3 v = a * M;
  v = v.adjust(y) + M;
  V.push_back(v);
  V.push_back(M * 2 - v);
}

int Judge(point3 a, point3 p, double r) {
  double x = pToLine(p, point3(0, 0, 0), a);
  return sgn(x - r) <= 0;
}

int main() {
  scanf("%d", &n);
  int i, j;
  for (i = 1; i <= n; i++) {
    data[i].Get();
    scanf("%lf", &R[i]);
    V.push_back(data[i]);
  }
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) Deal(data[i], R[i], data[j], R[j]);

  int ans = 0, size = V.size(), temp, k;  // k记录选中的点
  for (i = 0; i < size; i++) {
    temp = 0;
    for (j = 1; j <= n; j++) temp += Judge(V[i], data[j], R[j]);
    if (temp > ans) ans = temp, k = i;
  }
  printf("%d\n", ans);
  for (i = 1; i <= n && ans; i++)
    if (Judge(V[k], data[i], R[i])) {
      ans--;
      printf(ans != 0 ? "%d " : "%d\n", i);
    }
  return 0;
}
