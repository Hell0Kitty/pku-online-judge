#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

struct Point {
    double x, y;
};

struct Line {
    Point a, b;
} house, pro;

struct Obstruction {
    Point a, b;
    double lview, rview;
};

int dblcmp(double k) {
    if (fabs(k) < eps) return 0;
    return k > 0 ? 1 : -1;
}

double getXByY(Point a, Point b, double y) {
    return (y-a.y)*(a.x-b.x)/(a.y-b.y)+a.x;
}

bool cmp(const Obstruction& obs1, const Obstruction& obs2) {
    return dblcmp(obs1.lview-obs2.lview) <= 0;
}

int main()
{
    double x1, x2, y, tmp, ans;
    int n, i, id, k;

    while (scanf ("%lf%lf%lf", &x1, &x2, &y)) {
        if (!dblcmp(x1) && !dblcmp(x2) && !dblcmp(y)) break;
        house.a.x = x1; house.b.x = x2; house.a.y = house.b.y = y;
        scanf ("%lf%lf%lf\n%d", &pro.a.x, &pro.b.x, &pro.a.y, &n);
        pro.b.y = pro.a.y;
        Obstruction* obs = new Obstruction[n];
        id = 0;
        for (i = 0; i < n; i++) {
            scanf ("%lf%lf%lf", &x1, &x2, &y);
            if (dblcmp(y-house.a.y) >= 0 || dblcmp(y-pro.a.y) <= 0) continue; 

            obs[id].a.x = x1;
            obs[id].b.x = x2;
            obs[id].a.y = obs[id].b.y = y;
            obs[id].lview = getXByY(house.b, obs[id].a, pro.a.y);             obs[id].rview = getXByY(house.a, obs[id].b, pro.a.y); 
            id++;
        }
        sort(obs, obs+id, cmp); //按lview排序
        ans = 0;
        if (dblcmp(obs[0].lview-pro.a.x) > 0) ans = obs[0].lview-pro.a.x; 
         if (dblcmp(obs[0].rview-pro.a.x) < 0) obs[0].rview = pro.a.x;         

          k = 0;  
        for (i = 1; i < id; i++) {
            if (dblcmp(obs[k].rview-pro.b.x) >= 0) break; 
            tmp = obs[i].lview-obs[k].rview;
            if (dblcmp(tmp) > 0) {
                k = i;
                if (dblcmp(tmp-ans) > 0) ans = tmp;
            }
            else if (dblcmp(obs[i].rview-obs[k].rview) > 0)  k = i;
        }
        tmp = pro.b.x - obs[k].rview; 
        if (dblcmp(tmp-ans) > 0) ans = tmp; 
        if (dblcmp(ans) > 0) printf ("%.2lf\n", ans);
        else printf ("No View\n");
        delete [] obs;
    }
    return 0;
}



