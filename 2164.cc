#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
} ;
template<class T> T sqr(T x) { return x * x;}
inline double ptDis(Point a, Point b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));}

typedef Point Vec;
Vec operator + (Vec a, Vec b) { return Vec(a.x + b.x, a.y + b.y);}
Vec operator - (Vec a, Vec b) { return Vec(a.x - b.x, a.y - b.y);}
Vec operator * (Vec a, double p) { return Vec(a.x * p, a.y * p);}
Vec operator / (Vec a, double p) { return Vec(a.x / p, a.y / p);}

const double EPS = 1e-6;
const double PI = acos(-1.0);
inline int sgn(double x) { return fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1);}
bool operator < (Point a, Point b) { return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && a.y < b.y);}
bool operator == (Point a, Point b) { return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;}

inline double dotDet(Vec a, Vec b) { return a.x * b.x + a.y * b.y;}
inline double crossDet(Vec a, Vec b) { return a.x * b.y - a.y * b.x;}
inline double crossDet(Point o, Point a, Point b) { return crossDet(a - o, b - o);}
inline double vecLen(Vec x) { return sqrt(sqr(x.x) + sqr(x.y));}
inline double toRad(double deg) { return deg / 180.0 * PI;}
inline double angle(Vec v) { return atan2(v.y, v.x);}
inline double angle(Vec a, Vec b) { return acos(dotDet(a, b) / vecLen(a) / vecLen(b));}
inline double triArea(Point a, Point b, Point c) { return fabs(crossDet(b - a, c - a));}
inline Vec vecUnit(Vec x) { return x / vecLen(x);}
inline Vec rotate(Vec x, double rad) { return Vec(x.x * cos(rad) - x.y * sin(rad), x.x * sin(rad) + x.y * cos(rad));}
Vec normal(Vec x) {
    double len = vecLen(x);
    return Vec(- x.y / len, x.x / len);
}

struct Line {
    Point s, t;
    Line() {}
    Line(Point s, Point t) : s(s), t(t) {}
    Point point(double x) {
        return s + (t - s) * x;
    }
    Line move(double x) { 
        Vec nor = normal(t - s);
        nor = nor * x;
        return Line(s + nor, t + nor);
    }
    Vec vec() { return t - s;}
} ;
typedef Line Seg;

inline bool onSeg(Point x, Point a, Point b) { return sgn(crossDet(a - x, b - x)) == 0 && sgn(dotDet(a - x, b - x)) < 0;}
inline bool onSeg(Point x, Seg s) { return onSeg(x, s.s, s.t);}

int segIntersect(Point a, Point c, Point b, Point d) {
    Vec v1 = b - a, v2 = c - b, v3 = d - c, v4 = a - d;
    int a_bc = sgn(crossDet(v1, v2));
    int b_cd = sgn(crossDet(v2, v3));
    int c_da = sgn(crossDet(v3, v4));
    int d_ab = sgn(crossDet(v4, v1));
    if (a_bc * c_da > 0 && b_cd * d_ab > 0) return 1;
    if (onSeg(b, a, c) && c_da) return 2;
    if (onSeg(c, b, d) && d_ab) return 2;
    if (onSeg(d, c, a) && a_bc) return 2;
    if (onSeg(a, d, b) && b_cd) return 2;
    return 0;
}
inline int segIntersect(Seg a, Seg b) { return segIntersect(a.s, a.t, b.s, b.t);}

Point lineIntersect(Point P, Vec v, Point Q, Vec w) {
    Vec u = P - Q;
    double t = crossDet(w, u) / crossDet(v, w);
    return P + v * t;
}
inline Point lineIntersect(Line a, Line b) { return lineIntersect(a.s, a.t - a.s, b.s, b.t - b.s);}

double pt2Line(Point x, Point a, Point b) {
    Vec v1 = b - a, v2 = x - a;
    return crossDet(v1, v2) / vecLen(v1);
}
inline double pt2Line(Point x, Line L) { return pt2Line(x, L.s, L.t);}

double pt2Seg(Point x, Point a, Point b) {
    if (a == b) return vecLen(x - a);
    Vec v1 = b - a, v2 = x - a, v3 = x - b;
    if (sgn(dotDet(v1, v2)) < 0) return vecLen(v2);
    if (sgn(dotDet(v1, v3)) > 0) return vecLen(v3);
    return fabs(crossDet(v1, v2)) / vecLen(v1);
}
inline double pt2Seg(Point x, Seg s) { return pt2Seg(x, s.s, s.t);}

// Polygon class
struct Poly {
    vector<Point> pt;
    Poly() { pt.clear();}
    Poly(vector<Point> pt) : pt(pt) {}
    Point operator [] (int x) const { return pt[x];}
    int size() { return pt.size();}
    double area() {
        double ret = 0.0;
        int sz = pt.size();
        for (int i = 1; i < sz; i++) {
            ret += crossDet(pt[i], pt[i - 1]);
        }
        return fabs(ret / 2.0);
    }
} ;

struct Circle {
    Point c;
    double r;
    Circle() {}
    Circle(Point c, double r) : c(c), r(r) {}
    Point point(double a) {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
} ;

int lineCircleIntersect(Line L, Circle C, double &t1, double &t2, vector<Point> &sol) {
    double a = L.s.x, b = L.t.x - C.c.x, c = L.s.y, d = L.t.y - C.c.y;
    double e = sqr(a) + sqr(c), f = 2 * (a * b + c * d), g = sqr(b) + sqr(d) - sqr(C.r);
    double delta = sqr(f) - 4.0 * e * g;
    if (sgn(delta) < 0) return 0;
    if (sgn(delta) == 0) {
        t1 = t2 = -f / (2.0 * e);
        sol.push_back(L.point(t1));
        return 1;
    }
    t1 = (-f - sqrt(delta)) / (2.0 * e);
    sol.push_back(L.point(t1));
    t2 = (-f + sqrt(delta)) / (2.0 * e);
    sol.push_back(L.point(t2));
    return 2;
}

int lineCircleIntersect(Line L, Circle C, vector<Point> &sol) {
    Vec dir = L.t - L.s, nor = normal(dir);
    Point mid = lineIntersect(C.c, nor, L.s, dir);
    double len = sqr(C.r) - sqr(ptDis(C.c, mid));
    if (sgn(len) < 0) return 0;
    if (sgn(len) == 0) {
        sol.push_back(mid);
        return 1;
    }
    Vec dis = vecUnit(dir);
    len = sqrt(len);
    sol.push_back(mid + dis * len);
    sol.push_back(mid - dis * len);
    return 2;
}

// -1 : coincide
int circleCircleIntersect(Circle C1, Circle C2, vector<Point> &sol) {
    double d = vecLen(C1.c - C2.c);
    if (sgn(d) == 0) {
        if (sgn(C1.r - C2.r) == 0) {
            return -1;
        }
        return 0;
    }
    if (sgn(C1.r + C2.r - d) < 0) return 0;
    if (sgn(fabs(C1.r - C2.r) - d) > 0) return 0;
    double a = angle(C2.c - C1.c);
    double da = acos((sqr(C1.r) + sqr(d) - sqr(C2.r)) / (2.0 * C1.r * d));
    Point p1 = C1.point(a - da), p2 = C1.point(a + da);
    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

void circleCircleIntersect(Circle C1, Circle C2, vector<double> &sol) {
    double d = vecLen(C1.c - C2.c);
    if (sgn(d) == 0) return ;
    if (sgn(C1.r + C2.r - d) < 0) return ;
    if (sgn(fabs(C1.r - C2.r) - d) > 0) return ;
    double a = angle(C2.c - C1.c);
    double da = acos((sqr(C1.r) + sqr(d) - sqr(C2.r)) / (2.0 * C1.r * d));
    sol.push_back(a - da);
    sol.push_back(a + da);
}

int tangent(Point p, Circle C, vector<Vec> &sol) {
    Vec u = C.c - p;
    double dist = vecLen(u);
    if (dist < C.r) return 0;
    if (sgn(dist - C.r) == 0) {
        sol.push_back(rotate(u, PI / 2.0));
        return 1;
    }
    double ang = asin(C.r / dist);
    sol.push_back(rotate(u, -ang));
    sol.push_back(rotate(u, ang));
    return 2;
}
int tangent(Circle A, Circle B, vector<Point> &ptA, vector<Point> &ptB) {
    if (A.r < B.r) {
        swap(A, B);
        swap(ptA, ptB);
    }
    double d2 = sqr(A.c.x - B.c.x) + sqr(A.c.y - B.c.y);
    double rdiff = A.r - B.r, rsum = A.r + B.r;
    if (d2 < sqr(rdiff)) return 0;
    double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
    if (d2 == 0 && A.r == B.r) return -1;
    if (d2 == sqr(rdiff)) {
        ptA.push_back(A.point(base));
        ptB.push_back(B.point(base));
        return 1;
    }
    double ang = acos((A.r - B.r) / sqrt(d2));
    ptA.push_back(A.point(base + ang));
    ptB.push_back(B.point(base + ang));
    ptA.push_back(A.point(base - ang));
    ptB.push_back(B.point(base - ang));
    if (d2 == sqr(rsum)) {
        ptA.push_back(A.point(base));
        ptB.push_back(B.point(PI + base));
    } else if (d2 > sqr(rsum)) {
        ang = acos((A.r + B.r) / sqrt(d2));
        ptA.push_back(A.point(base + ang));
        ptB.push_back(B.point(PI + base + ang));
        ptA.push_back(A.point(base - ang));
        ptB.push_back(B.point(PI + base - ang));
    }
    return (int) ptA.size();
}

int ptInPoly(Point p, Poly &poly) {
    int wn = 0, sz = poly.size();
    for (int i = 0; i < sz; i++) {
        if (onSeg(p, poly[i], poly[(i + 1) % sz])) return -1;
        int k = sgn(crossDet(poly[(i + 1) % sz] - poly[i], p - poly[i]));
        int d1 = sgn(poly[i].y - p.y);
        int d2 = sgn(poly[(i + 1) % sz].y - p.y);
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn != 0) return 1;
    return 0;
}

int andrew(Point *pt, int n, Point *ch) {
    sort(pt, pt + n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && crossDet(ch[m - 1] - ch[m - 2], pt[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = pt[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && crossDet(ch[m - 1] - ch[m - 2], pt[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = pt[i];
    }
    if (n > 1) m--;
    return m;
}

Point origin;
inline bool cmpAng(Point p1, Point p2) { return crossDet(origin, p1, p2) > 0;}
inline bool cmpDis(Point p1, Point p2) { return ptDis(p1, origin) > ptDis(p2, origin);}

void removePt(Point *pt, int &n) {
    int idx = 1;
    for (int i = 2; i < n; i++) {
        if (sgn(crossDet(origin, pt[i], pt[idx]))) pt[++idx] = pt[i];
        else if (cmpDis(pt[i], pt[idx])) pt[idx] = pt[i];
    }
    n = idx + 1;
}

int graham(Point *pt, int n, Point *ch) {
    int top = -1;
    for (int i = 1; i < n; i++) {
        if (pt[i].y < pt[0].y || (pt[i].y == pt[0].y && pt[i].x < pt[0].x)) swap(pt[i], pt[0]);
    }
    origin = pt[0];
    sort(pt + 1, pt + n, cmpAng);
    removePt(pt, n);
    for (int i = 0; i < n; i++) {
        if (i >= 2) {
            while (!(crossDet(ch[top - 1], pt[i], ch[top]) <= 0)) top--;
        }
        ch[++top] = pt[i];
    }
    return top + 1;
}

struct DLine {
    Point p;
    Vec v;
    double ang;
    DLine() {}
    DLine(Point p, Vec v) : p(p), v(v) { ang = atan2(v.y, v.x);}
    bool operator < (const DLine &L) const { return ang < L.ang;}
    DLine move(double x) { // while x > 0 move to v's left
        Vec nor = normal(v);
        nor = nor * x;
        return DLine(p + nor, v);
    }

} ;

Poly cutPoly(Poly &poly, Point a, Point b) {
    Poly ret = Poly();
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        Point c = poly[i], d = poly[(i + 1) % n];
        if (sgn(crossDet(b - a, c - a)) >= 0) ret.pt.push_back(c);
        if (sgn(crossDet(b - a, c - d)) != 0) {
            Point ip = lineIntersect(a, b - a, c, d - c);
            if (onSeg(ip, c, d)) ret.pt.push_back(ip);
        }
    }
    return ret;
}
inline Poly cutPoly(Poly &poly, DLine L) { return cutPoly(poly, L.p, L.p + L.v);}

inline bool onLeft(DLine L, Point p) { return crossDet(L.v, p - L.p) > 0;}
Point dLineIntersect(DLine a, DLine b) {
    Vec u = a.p - b.p;
    double t = crossDet(b.v, u) / crossDet(a.v, b.v);
    return a.p + a.v * t;
}

Poly halfPlane(DLine *L, int n) {
    Poly ret = Poly();
    sort(L, L + n);
    int fi, la;
    Point *p = new Point[n];
    DLine *q = new DLine[n];
    q[fi = la = 0] = L[0];
    for (int i = 1; i < n; i++) {
        while (fi < la && !onLeft(L[i], p[la - 1])) la--;
        while (fi < la && !onLeft(L[i], p[fi])) fi++;
        q[++la] = L[i];
        if (fabs(crossDet(q[la].v, q[la - 1].v)) < EPS) {
            la--;
            if (onLeft(q[la], L[i].p)) q[la] = L[i];
        }
        if (fi < la) p[la - 1] = dLineIntersect(q[la - 1], q[la]);
    }
    while (fi < la && !onLeft(q[fi], p[la - 1])) la--;
    if (la - fi <= 1) return ret;
    p[la] = dLineIntersect(q[la], q[fi]);
    for (int i = fi; i <= la; i++) ret.pt.push_back(p[i]);
    return ret;
}

// 3D Geometry
void getCoor(double R, double lat, double lng, double &x, double &y, double &z) {
    lat = toRad(lat);
    lng = toRad(lng);
    x = R * cos(lat) * cos(lng);
    y = R * cos(lat) * sin(lng);
    z = R * sin(lat);
}

const int N = 111;
Point ori[N];
vector<Point> ex;
//vector<int> nx[5555], on[N];
int nx[5555][N << 1], on[N][N << 1];

int main() {
    int n;
    while (cin >> n) {
        ex.clear();
        for (int i = 0; i < 5555; i++)
            nx[i][0] = 0;
        for (int i = 0; i < n; i++) {
            on[i][0] = 0;
            cin >> ori[i].x >> ori[i].y;
            ex.push_back(ori[i]);
        }
        ori[n] = ori[0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (segIntersect(ori[i], ori[i + 1], ori[j], ori[j + 1]) == 1) {
                    ex.push_back(lineIntersect(Line(ori[i], ori[i + 1]), Line(ori[j], ori[j + 1])));
                }
            }
        }
        sort(ex.begin(), ex.end());
        int t = unique(ex.begin(), ex.end()) - ex.begin();
        while (ex.size() > t) ex.pop_back();
        int sz = ex.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < n; j++) {
                if (ex[i] == ori[j] || ex[i] == ori[j + 1] || onSeg(ex[i], Seg(ori[j], ori[j + 1])))
                    on[j][++on[j][0]] = i;
            }
        }

        for (int i = 0; i < n; i++) {
            int csz = on[i][0] - 1;
            for (int j = 0; j < csz; j++) {
                nx[on[i][j + 1]][++nx[on[i][j + 1]][0]] = on[i][j + 2];
                nx[on[i][j + 2]][++nx[on[i][j + 2]][0]] = on[i][j + 1];
            }
        }
        vector<int> path;
        path.clear();
        path.push_back(0);
        int sz0 = nx[0][0];
        int cur = nx[0][1];
        for (int i = 1; i < sz0; i++) {
            int id = nx[0][i + 1];
            if (sgn(crossDet(ex[cur] - ex[0], ex[id] - ex[0])) < 0) cur = id;
        }
        int cnt = 500000;
        while (cnt-- && cur) {
            path.push_back(cur);
            int l1 = path[path.size() - 1], l0 = path[path.size() - 2];
            int t = (nx[cur][1] == l0) ? nx[cur][2] : nx[cur][1], csz = nx[cur][0];
            Vec dr = ex[l1] - ex[l0];
            double ang = angle(dr);
            for (int i = 1; i < csz; i++) {
                int id = nx[cur][i + 1];
                if (id == l0) continue;
                Vec t1 = ex[t] - ex[l1], t2 = ex[id] - ex[l1];
                t1 = rotate(t1, -ang), t2 = rotate(t2, -ang);
                if (angle(t1) > angle(t2)) t = id;
            }
            cur = t;
        }
        int psz = path.size();
        vector<int> out;
        out.clear();
        path.push_back(path[0]);
        for (int i = 0; i < psz; i++) {
            if (i > 0 && sgn(crossDet(ex[path[i]] - ex[path[i - 1]], ex[path[i + 1]] - ex[path[i]])) == 0) continue;
            out.push_back(path[i]);
        }
        cout << out.size() << endl;
        psz = out.size();
        for (int i = 0; i < psz; i++) {
            cout << ex[out[i]].x << ' ' << ex[out[i]].y << endl;
        }
    }
    return 0;
}



