#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 2000
#define eps 10E-9

struct Point
{
    double x, y;
    Point operator-(const Point &a) const
    {
        Point ret;
        ret.x = x - a.x;
        ret.y = y - a.y;
        return ret;
    }
} point[maxn], peg;

double pegr;
int n;

int dblcmp(double a)
{
    if (fabs(a) < eps)
        return 0;
    return a >0?1 : -1;
}

double xmult(const Point &a, const Point &b)
{
    return a.x * b.y - b.x * a.y;
}

void input()
{
    scanf("%lf%lf%lf", &pegr, &peg.x, &peg.y);
    for (int i =0; i < n; i++)
        scanf("%lf%lf", &point[i].x, &point[i].y);
    int t =0;
    int i =0;
    while (i < n && t ==0)
    {
        t = dblcmp(xmult(point[(i +1)%n] - point[i], point[(i +2)%n] - point[i]));
        i++;
    }
    if (t <0)
        reverse(point, point + n);
}

bool convex()
{
    for (int i =0; i < n; i++)
        if (dblcmp(xmult(point[(i +1)%n] - point[i], point[(i +2)%n] - point[(i +1)%n]))    <0)
            return false;
    return true;
}

bool inconvex()
{
    for (int i =0; i < n; i++)
        if (dblcmp(xmult(point[(i +1)%n] - point[i], peg - point[(i +1)%n])) <=0)
            return false;
    return true;
}

double dist(const Point &a, const Point &b)
{
    Point p;
    p = a - b;
    return sqrt(p.x * p.x + p.y * p.y);
}

bool ok()
{
    for (int i =0; i < n; i++)
        if (dblcmp(abs(xmult(peg - point[i], point[(i +1)%n] - point[i]))/dist(point[i], point[(i +1)%n]) - pegr) <0)
            return false;
    return true;
}

int main()
{

    while (scanf("%d", &n) != EOF)
    {
        if (n <3)
            break;
        input();
        if (!convex())
            printf("HOLE IS ILL-FORMED\n");
        else if (!inconvex()||!ok())
            printf("PEG WILL NOT FIT\n");
        else
            printf("PEG WILL FIT\n");
    }
    return 0;
}


