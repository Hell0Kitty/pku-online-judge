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
#include <utility>
#include <ctime>
#define sqr(x) ((x)*(x))
using namespace std;

const int N = 110;
const int M = 20;
const double eps = 1e-8;
int n, n2, vis[N][M];

int dcmp(double x) {
    if (x < -eps) return -1; else return x > eps;
}

struct cpoint {
    double x, y;
    cpoint() {}
    cpoint(double x, double y) : x(x), y(y) {}
    bool operator == (const cpoint &u) const {
        return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0;
    }
    void get() {
        scanf("%lf%lf", &x, &y);
    }
}tp[N * M], bp;

struct poly {
    int n;
    cpoint cp[M];
    cpoint& operator [] (int k) {
        return cp[k];
    }
}ply[N], ply2[N];

double cross(cpoint p0, cpoint p1, cpoint p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

double dot(cpoint p0, cpoint p1, cpoint p2) {
    return (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y);
}

int PointOnSegment(cpoint p0, cpoint p1, cpoint p2) {
    return dcmp(cross(p0, p1, p2)) == 0 && dcmp(dot(p0, p1, p2)) <= 0;
}

int LineInter(cpoint p1, cpoint p2, cpoint p3, cpoint p4, cpoint &cp) {
    double u = cross(p1, p2, p3), v = cross(p2, p1, p4);
    if ( dcmp(u + v) ) {
        cp.x = (p3.x * v + p4.x * u) / (u + v);
        cp.y = (p3.y * v + p4.y * u) / (u + v);
        return 1;
    }
    if ( dcmp(u) ) return 0;
    if ( dcmp(cross(p3, p4, p1)) ) return 0;
    return -1;
}

int SegmentInter(cpoint p1, cpoint p2, cpoint p3, cpoint p4, cpoint &cp) {
    int ret = LineInter(p1, p2, p3, p4, cp);
    if (ret == 1) return PointOnSegment(cp, p1, p2) && PointOnSegment(cp, p3, p4);
    if (ret == -1 && (PointOnSegment(p1, p3, p4) || PointOnSegment(p2, p3, p4)
                   || PointOnSegment(p3, p1, p2) || PointOnSegment(p4, p1, p2) ))
       return -1;
    return 0;
}

bool cmp(const cpoint &u, const cpoint &v) {
    return dcmp( fabs(u.x - bp.x) + fabs(u.y - bp.y)
               - fabs(v.x - bp.x) - fabs(v.y - bp.y)) < 0;
}

bool check(cpoint u, cpoint v, poly ply[], int id) {
    int i, k, d1, d2, wn = 0;
    cpoint cp, *p1, *p2 = ply[id].cp;
    cp.x = (u.x + v.x) / 2;
    cp.y = (u.y + v.y) / 2;
    for (i = 0; i < ply[id].n; ++i) {
        p1 = p2++;
        if (PointOnSegment(cp, *p1, *p2)) {
            int chk = dcmp(u.x - v.x) * dcmp(p1->x - p2->x);
            if (chk == 0)
                chk = dcmp(u.y - v.y) * dcmp(p1->y - p2->y);
            if (chk == -1) return 0;
            return vis[id][i];
        }
        k = dcmp( cross(*p1, *p2, cp) );
        d1 = dcmp( p1->y - cp.y );
        d2 = dcmp( p2->y - cp.y );
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    return wn != 0;
}

double PolyUnion(poly ply[], int &n) {
    double ans = 0;
    int i, j, k, vi, vj, tn = n; n = 0;
    cpoint cp, p1, p2;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < tn; ++i) {
        if (dcmp(cross(ply[i][0], ply[i][1], ply[i][2])) <= 0)
            continue; 
        ply[i][ply[i].n] = ply[i][0];
        ply[n++] = ply[i];
    }
    for (i = 0; i < n; ++i) {
        for (vi = 0; vi < ply[i].n; ++vi) {
            tp[0] = p1 = bp = ply[i][vi];
            tp[1] = p2 = ply[i][vi + 1];
            tn = 2;
            for (j = 0; j < n; ++j) if (i != j) 
                for (vj = 0; vj < ply[j].n; ++vj)
                    if (SegmentInter(p1, p2, ply[j][vj], ply[j][vj + 1], cp) == 1)
                        tp[tn++] = cp;
            sort(tp, tp + tn, cmp);
            tn = unique(tp, tp + tn) - tp;
            for (k = 1; k < tn; ++k) {
                for (j = 0; j < n; ++j) if (i != j)
                    if (check(tp[k - 1], tp[k], ply, j))
                        break;
                if (j == n)
                    ans += tp[k - 1].x * tp[k].y - tp[k - 1].y * tp[k].x;
            }
            vis[i][vi] = 1;
        }
    }
    return ans / 2;
}

double dissqr(cpoint u, cpoint v) {
    return sqr(u.x - v.x) + sqr(u.y - v.y);
}

int PolarCmp(const cpoint &p1, const cpoint &p2) {
    int u = dcmp(cross(bp, p1, p2));
    return u > 0 || (u == 0 && dcmp(dissqr(bp, p1)-dissqr(bp, p2)) < 0);
}

void graham(cpoint pin[], int n, cpoint ch[], int &m) {
    int i, j, k, u, v;
    memcpy(ch, pin, n * sizeof(cpoint));
    for (i = k = 0; i < n; ++i) {
        u = dcmp(ch[i].x - ch[k].x);
        v = dcmp(ch[i].y - ch[k].y);
        if (v < 0 || (v == 0 && u < 0)) k = i;
    }
    bp = ch[k];
    sort(ch, ch + n, PolarCmp);
    n =  unique(ch, ch + n) - ch;
    if (n <= 1) { m = n; return ;}
    if (dcmp(cross(ch[0], ch[1], ch[n - 1])) == 0) {
        m = 2; ch[1] = ch[n - 1]; return;
    }
    ch[n++] = ch[0];
    for (i = 1, j = 2; j < n; ++j) {
        while (i > 0 && dcmp(cross(ch[i - 1], ch[i], ch[j])) <= 0) i--;
        ch[++i] = ch[j];
    }
    m = i;
}

void solve(int cas) {
    double h, x, y, bh;
    scanf("%lf%lf%lf", &h, &x, &y);
    int m; n = n2 = 0;
    scanf("%d", &m);
    cpoint a[5], tmp[20];
    double ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j)
            a[j].get();
        scanf("%lf", &bh);
        bool flag = false;
        for (int j = 0; j < 3; ++j) {
            if (dcmp(dot(a[j], a[(j + 1) % 3], a[(j + 2) % 3])) == 0) {
                swap(a[j], a[1]);
                a[3].x = a[0].x + a[2].x - a[1].x;
                a[3].y = a[0].y + a[2].y - a[1].y;
                flag = true;
                break;
            }
        }
        if (dcmp(cross(a[0], a[1], a[2])) < 0)
            reverse(a, a + 4);
        a[4] = a[0];
        int tn = 0;
        for (int j = 0; j < 4; ++j) {
            tmp[tn++] = a[j];
            tmp[tn++] = cpoint(a[j].x + x * bh / h, a[j].y + y * bh / h);
        }
        graham(tmp, tn, ply[n].cp, ply[n].n);
        n++;
        ans -= fabs(cross(a[0], a[1], a[2]));
    }
    ans += PolyUnion(ply, n);
    printf("Case %d: %.3lf\n", cas, ans);
}

int main() {
    int cas;
    scanf("%d", &cas);
    for (int i = 1; i <= cas; ++i) {
        solve(i);
    }
    return 0;
}



