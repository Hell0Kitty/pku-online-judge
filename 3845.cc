#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <bitset>
#include <cmath>
#include <set>
using namespace std;

const double eps = 1e-12;
const int N = 110;
int n, d;
double f, r[N];

struct cpoint {
    double x, y;
}cp[N];

int dcmp(double x) {
    if (x < -eps) return -1; else return x > eps;
}

double cross(cpoint p0, cpoint p1, cpoint p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double dot(cpoint p0, cpoint p1, cpoint p2) {
    return (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y);
}

double sqr(double x) {return x * x;}

double dis(cpoint a, cpoint b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double angle(cpoint p0, cpoint p1, cpoint p2) {
    double cr = cross(p0, p1, p2);
    double dt = dot(p0, p1, p2);
    if (dcmp(cr) == 0) cr = 0;
    if (dcmp(dt) == 0) dt = 0;
    return atan2(cr, dt);
}

cpoint rotate(cpoint v, cpoint o, double angle, double scale) {
    double c, s;
    v.x -= o.x; v.y -= o.y;
    c = scale * cos(angle);
    s = scale * sin(angle);
    o.x += v.x * c - v.y * s;
    o.y += v.x * s + v.y * c;
    return o;
}

void solve() {
    double len = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &cp[i].x, &cp[i].y);
        if (i) len += dis(cp[i], cp[i - 1]);
    }
    r[0] = 0;
    for (int i = 1; i < n; ++i) {
        r[i] = r[i - 1] + dis(cp[i], cp[i - 1]) / len;
    }
    scanf("%d%lf", &d, &f);
    int id;
    double ang, dx, dy, s;
    cpoint p;
    for (int deep = 1; deep < d; ++deep) {
        for (int i = 0; i < n; ++i) {
            if (dcmp(f - r[i]) <= 0) {
                id = i;
                break;
            }
        }
        if (dcmp(f - r[id]) == 0) {
            printf("(%.7lf,%.7lf)\n", cp[id].x, cp[id].y);
            return;
        }
        dx = cp[id - 1].x - cp[0].x;
        dy = cp[id - 1].y - cp[0].y;
        p.x = cp[n - 1].x + dx;
        p.y = cp[n - 1].y + dy;
        ang = angle(cp[id - 1], p, cp[id]);
        s = dis(cp[id], cp[id - 1]) / dis(cp[0], cp[n - 1]);
        for (int i = 1; i < n; ++i)
            cp[i] = rotate(cp[i], cp[0], ang, s);
        for (int i = 0; i < n; ++i)
            cp[i].x += dx, cp[i].y += dy;
        f = (f - r[id - 1]) / (r[id] - r[id - 1]);
    }
    for (int i = 0; i < n; ++i) {
        if (dcmp(f - r[i]) <= 0) {
            id = i;
            break;
        }
    }
    if (dcmp(f - r[id] == 0)) {
        printf("(%.7lf,%.7lf)\n", cp[id].x, cp[id].y);
        return;
    }
    f = (f - r[id - 1]) / (r[id] - r[id - 1]);
    dx = cp[id - 1].x + (cp[id].x - cp[id - 1].x) * f;
    dy = cp[id - 1].y + (cp[id].y - cp[id - 1].y) * f;
    printf("(%.7lf,%.7lf)\n", dx, dy);
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        solve();
    }
    return 0;
}



