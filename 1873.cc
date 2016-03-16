#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double inf = 999999999;

int stk[20], top, tc[20], cuted[20], num;

struct Point {
    double x, y, v, l;
    Point& operator=(Point a) {
         x = a.x; y = a.y;
         v = a.v; l = a.l;
         return *this;
    }
} pnt[20], p[20];

int dblcmp(double k) {
    if (fabs(k) < eps) return 0;
    return k > 0 ? 1 : -1;
}

double multi(Point p0, Point p1, Point p2) {
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

double getDis(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(const Point& a, const Point& b) {
    int d = dblcmp(multi(p[0], a, b));
    if (!d) return getDis(p[0], a) < getDis(p[0], b);
    return d > 0;
}

double solve(Point p[], int sz) {
    if (sz <= 1) return 0;

    int i, k = 0;
    Point tp = p[0];
    for (i = 1; i < sz; i++) {
        int d = dblcmp(tp.y-p[i].y);
        if ((!d && dblcmp(tp.x-p[i].x) > 0) || d > 0) {
            k = i;
            tp = p[i];
        }
    }
    p[k] = p[0];
    p[0] = tp;

    sort(p+1, p+sz, cmp);
    stk[0] = 0; stk[1] = 1;
    top = 1;
    for (i = 2; i < sz; i++) {
        while (top >= 1 && dblcmp(multi(p[stk[top-1]], p[i], p[stk[top]])) >= 0) top--;
        stk[++top] = i;
    }
    double len = 0;
    for (i = 0; i < top; i++)
        len += getDis(p[stk[i]], p[stk[i+1]]);
    return len+getDis(p[stk[top]], p[0]);
}

int main()
{
    int n, i, j, cas = 0;

    while (scanf ("%d", &n) && n) {
        cas++;
        for (i = 0; i < n; i++)
            scanf ("%lf%lf%lf%lf", &pnt[i].x, &pnt[i].y, &pnt[i].v, &pnt[i].l);
        int n0, n1, N = 1 << n;
        double val, len, minVal = inf, extra;
        num = n;
        for (i = 1; i < N-1; i++) {
             len = val = 0;
             n0 = n1 = 0;
             for (j = 0; j < n; j++)
                if ((i>>j)&1) {
                    tc[n0++] = j;
                    val += pnt[j].v;
                    len += pnt[j].l;
                } else p[n1++] = pnt[j];
             double tl = solve(p, n1);
             if (dblcmp(len-tl) >= 0) {
                int d = dblcmp(minVal-val);
                if (d > 0 || (!d && n0 < num)) {
                    minVal = val;
                    for (j = 0; j < n0; j++) cuted[j] = tc[j];
                    num = n0;
                    extra = len-tl;
                }
             }
        }
        printf ("Forest %d\nCut these trees:", cas);
        for (i = 0; i < num; i++)
            printf (" %d", cuted[i]+1);
        printf("\nExtra wood: %.2lf\n\n", extra);
    }
    return 0;
}




