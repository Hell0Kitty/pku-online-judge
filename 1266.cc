#include<iostream>
#include<stdio.h>
#include<math.h>
#define eps 1e-8
using namespace std;
struct point{double x,y;};
struct line{point a,b;};
point a1,a2,a3,a;
double xmult(point p1,point p2,point p0){
 return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
point intersection(line u,line v){
 point ret=u.a;
 double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
   /((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
 ret.x+=(u.b.x-u.a.x)*t;
 ret.y+=(u.b.y-u.a.y)*t;
 return ret;
}
point circumcenter(point a,point b,point c){
 line u,v;
 u.a.x=(a.x+b.x)/2;
 u.a.y=(a.y+b.y)/2;
 u.b.x=u.a.x-a.y+b.y;
 u.b.y=u.a.y+a.x-b.x;
 v.a.x=(a.x+c.x)/2;
 v.a.y=(a.y+c.y)/2;
 v.b.x=v.a.x-a.y+c.y;
 v.b.y=v.a.y+a.x-c.x;
 return intersection(u,v);
}
double dog1(double a,double b,double c)
{
    double max;
    if (a>b) max=a;
    else
      max=b;
    if (max<c) max=c;
    return max;
}
double dog2(double a,double b,double c)
{
    double min;
    if (a<b) min=a;
    else
       min=b;
    if (min>c) min=c;
    return min;
}
bool pig(point p)
{
    double t1,t2;
    t1=(xmult(a1,a3,a2));
    t2=(xmult(a1,p,a2));
    if ((t1<0&&t2<0)||(t1>0&&t2>0)) return true;
    return false;
}
int main()
{
    double maxx,maxy,minx,miny,r;
    point p1;
    int px,py;
    scanf("%lf%lf%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y,&a3.x,&a3.y);
    a=circumcenter(a1,a2,a3);
    r=sqrt(0.0+(a1.x-a.x)*(a1.x-a.x)+(a1.y-a.y)*(a1.y-a.y));
    maxx=dog1(a1.x,a2.x,a3.x);
    maxy=dog1(a1.y,a2.y,a3.y);
    minx=dog2(a1.x,a2.x,a3.x);
    miny=dog2(a1.y,a2.y,a3.y);
    p1.x=a.x-r;
    p1.y=a.y;
    if (pig(p1)) minx=p1.x;
    p1.x=a.x+r;
    if (pig(p1)) maxx=p1.x;
    p1.x=a.x;
    p1.y=a.y-r;
    if (pig(p1)) miny=p1.y;
    p1.y=a.y+r;
    if (pig(p1)) maxy=p1.y;
    px=(long)ceil(maxx-eps)-(long)floor(minx+eps);
    py=(long)ceil(maxy-eps)-(long)floor(miny+eps);
    printf("%d\n",px*py);
    cin>>r;
    return 0;
}


