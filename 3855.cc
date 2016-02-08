#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 100000
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;
struct point
{
    double x,y;
    point(double x=0,double y = 0):x(x),y(y){}
}p[N];
typedef point pointt;
point operator -(point a,point b)
{
    return point(a.x-b.x,a.y-b.y);
}
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
int main()
{
    int i,j,n;
    int kk = 0;
    while(scanf("%d",&n)&&n)
    {
        for(i = 0 ;  i< n; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[n] = p[0];
        double sx = 0,sy = 0,sum =0 ;
        for(i = 1; i < n-1 ;i++)
        {
            double ts = cross(p[i]-p[0],p[i+1]-p[0])/2;
            double x = p[0].x+p[i].x+p[i+1].x;
            double y = p[0].y+p[i].y+p[i+1].y;
            sum+=ts;
            sx+=x*ts;
            sy+=y*ts;
        }
        printf("Stage #%d: %.6f %.6f\n",++kk,sx/3.0/sum,sy/3.0/sum);
    }
    return 0;
}



