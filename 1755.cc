#include<stdio.h>
#include<string.h>
#define zero 1e-8
#define MAXD 210
#define INF 10000
struct point
{
    double x, y;
}wa[MAXD], wb[MAXD], *a, *b;
int N, na, nb;
double u[MAXD], v[MAXD], w[MAXD];
double fabs(double x)
{
    return x < 0 ? -x : x;
}
int dcmp(double x)
{
    return fabs(x) < zero ? 0 : (x < 0 ? -1 : 1);
}
double det(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}
void init()
{
    int i, j, k;
    for(i = 0; i < N; i ++)
        scanf("%lf%lf%lf", &v[i], &u[i], &w[i]);
}
void add(double x, double y)
{
    b[nb].x = x, b[nb].y = y;
    ++ nb;
}
void cut(double a1, double a2, double a3)
{
    int i, j, k;
    point *t;
    double x, y, t1, t2, x1, y1, x2, y2;
    nb = 0;
    if(dcmp(a2) == 0)
    {
        x1 = x2 = (-a3) / a1;
        if(dcmp(a1) < 0)
            y1 = INF, y2 = 0;
        else
            y1 = 0, y2 = INF;
    }
    else
    {
        if(dcmp(a2) < 0)
            x1 = 0, x2 = INF;
        else
            x1 = INF, x2 = 0;
        y1 = (-a3 - a1 * x1) / a2, y2 = (-a3 - a1 * x2) / a2;
    }
    for(i = 0; i < na; i ++)
    {
        t1 = det(x2 - x1, y2 - y1, a[i].x - x1, a[i].y - y1);
        t2 = det(x2 - x1, y2 - y1, a[i + 1].x - x1, a[i + 1].y - y1);
        if(dcmp(t1) >= 0)
            add(a[i].x, a[i].y);
        if(dcmp(t1) * dcmp(t2) < 0)
        {
            x = (fabs(t2) * a[i].x + fabs(t1) * a[i + 1].x) / (fabs(t1) + fabs(t2));
            y = (fabs(t2) * a[i].y + fabs(t1) * a[i + 1].y) / (fabs(t1) + fabs(t2));
            add(x, y);
        }
    }
    t = a, a = b, b = t;
    na = nb;
    a[na] = a[0];
}
int check()
{
    int i, j, k;
    double s = 0;
    for(i = 0; i < na; i ++)
        s += det(a[i].x, a[i].y, a[i + 1].x, a[i + 1].y);
    if(dcmp(s) == 0)
        return 0;
    return 1;
}
void solve()
{
    int i, j, k;
    double a1, a2, a3;
    a = wa, b = wb;
    for(i = 0; i < N; i ++)
    {
        na = 3;
        a[0].x = 0, a[0].y = 0, a[1].x = INF, a[1].y = 0, a[2].x = 0, a[2].y = INF;
        a[na] = a[0];
        for(j = 0; j < N; j ++)
        {
            if(j == i)
                continue;
            a1 = (w[i] - v[i]) / (w[i] * v[i]) - (w[j] - v[j]) / (w[j] * v[j]);
            a2 = (w[i] - u[i]) / (w[i] * u[i]) - (w[j] - u[j]) / (w[j] * u[j]);
            a3 = INF * (w[j] - w[i]) / (w[i] * w[j]);
            if(dcmp(a2) == 0 && dcmp(a1) == 0)
            {
                if(dcmp(a3) < 0)
                    continue;
                break;
            }
            cut(a1, a2, a3);
        }
        if(j != N || !check())
            printf("No\n");
        else
            printf("Yes\n");
    }
}
int main()
{
    while(scanf("%d", &N) == 1)
    {
        init();
        solve();
    }
    return 0;
}