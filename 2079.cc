#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<complex>
#include<algorithm>
#define EPS 1e-10
#define largty(x,y) (x-EPS)>(y)
#define smalty(x,y) (x+EPS)<(y)
#define nlargty(x,y) (x-EPS)<(y)
#define nsmalty(x,y) (x+EPS)>(y)
#define equal(x,y) (nlargty(x,y) && (nsmalt(x,y)))
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define MAXN 50004
using namespace std;

struct point {
    double x, y;
    point(){}
    point(double _x, double _y):x(_x),y(_y){}
    point(const point &temp)
    {
        x = temp.x;
        y = temp.y;
    }
}data[MAXN],convex[MAXN];
point start(0,0);

inline double cross(const point &p1, const point &p2, const point &q1, const point &q2)
{
    return (q2.y - q1.y)*(p2.x - p1.x) - (q2.x - q1.x)*(p2.y - p1.y);    
}

inline bool cmp1(const point &a, const point &b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);    
}

inline bool cmp2(const point &a, const point &b)//逆时针排序 
{
    point origin;
    origin = start;
    return cross(origin,a,origin,b) > 0 || (cross(origin,a,origin,b) == 0 && fabs(a.x) < fabs(b.x));
}

inline void convex_hull(int &cnt, int n)
{
    sort(data,data+n,cmp1);
    start = data[0];
    sort(data+1,data+n,cmp2);
    convex[cnt++] = start;
    convex[cnt++] = data[1];
    for (int i(2); i<n; ++i) {
        while (cnt >= 2 && cross(convex[cnt-2],convex[cnt-1],convex[cnt-1],data[i]) <= 0)--cnt;
        convex[cnt++] = data[i];    
    }        
}

inline double rotating_calipers(int n)
{
    int j = 1,k = 0;
    double area(0);
    for (int i(0); i<n; ++i) {
        j = (i + 1)%n;
        k = (j + 1)%n;
        while (fabs(cross(convex[i],convex[j],convex[i],convex[k])) < 
                    fabs(cross(convex[i],convex[j],convex[i],convex[(k+1)%n]))) {
            k = (k + 1)%n;            
        }
        while (j != i && k != i) {
            area = max(area,fabs(cross(convex[i],convex[j],convex[i],convex[k])));
            while (fabs(cross(convex[i],convex[j],convex[i],convex[k])) <
                         fabs(cross(convex[i],convex[j],convex[i],convex[(k+1)%n]))) {
                k = (k + 1)%n;                    
            }
            j = (j + 1)%n;    
        }
    }
    return area;    
}

int main()
{
    int n;
    while (scanf("%d",&n) && n != -1) {
        for (int i(0); i<n; ++i) {
            scanf("%lf%lf",&data[i].x,&data[i].y);    
        }
        if (n <= 2) {
            cout<<"0.00"<<endl;
            continue;    
        }    
        int cnt(0);
        convex_hull(cnt,n);
        if (cnt <= 2) {
            cout<<"0.00"<<endl;
            continue;    
        } else {
            if (cnt == 3) {
                printf("%.2lf\n",fabs(cross(convex[0],convex[1],convex[0],convex[2]))/2);    
            } else {
                printf("%.2lf\n",rotating_calipers(cnt)/2);    
            }    
        }
    }
    return 0;    
}



