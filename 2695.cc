#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const double INF=1e40;
const double EPS=1e-8;
const double pi=acos(-1.0);
struct POINT
{
    double x,y;
    POINT(){}
    POINT(double _x,double _y):x(_x),y(_y){}
    POINT operator-(const POINT &p){return POINT(x-p.x,y-p.y);}
    POINT operator+(const POINT &p){return POINT(x+p.x,y+p.y);}
    POINT operator/(double d){return POINT(x/d,y/d);}
    POINT operator*(double k){return POINT(x*k,y*k);}
    double operator*(const POINT &p){return x*p.y-y*p.x;}
    double operator&(const POINT &p){return x*p.x+y*p.y;}
    double dis(const POINT &p){return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
    void input(){scanf("%lf%lf",&x,&y);}
}p[105],v1,v2;
int ans[105],n,s,sz;
double d;
int dmp(double k)
{
    if(fabs(k)<EPS)return 0;
    return k<0? -1:1;
}
int check(int t,POINT v3)
{
    POINT c=POINT(0,0);
    int fi=-1;
    double mang=INF,the,d1,d2,d3;
    for(int i=1;i<=n;i++)
    {
        if(i==t)continue;
        if(dmp(p[i].dis(p[t])-d)>0)continue;
        v2=p[i]-p[t];
        d1=v2.dis(v3);
        d2=v2.dis(c);
        d3=v3.dis(c);
        if(d2==0||d3==0)
            the=0;
        else
        {
            the=(d2*d2+d3*d3-d1*d1)/(2*d2*d3);
            the=acos(the);
        }
        if(dmp(the-pi/2)>0)continue;

        d1=v1.dis(c);
        d2=v2.dis(c);
        d3=v1.dis(v2);
        if(dmp(d1)==0||dmp(d2)==0)
            the=0;
        else
        {
            the=(d1*d1+d2*d2-d3*d3)/(2*d1*d2);
            the=acos(the);
        }
        if(dmp(the-pi/2)>0)continue;

        if(the<mang)
        {
            mang=the;
            fi=i;
        }
    }
    return fi;
}
int main()
{
    while(scanf("%lf%lf%d%d%lf",&v1.x,&v1.y,&n,&s,&d)==5)
    {
        if(n==0)break;
        for(int i=1;i<=n;i++)
            p[i].input();
        int sz=0;
        ans[sz++]=s;
        while(1)
        {
            POINT v=POINT(0,0);
            if(sz>1) v=p[ans[sz-1]]-p[ans[sz-2]];
            int t=check(ans[sz-1],v);
            if(t==-1)break;
            ans[sz++]=t;
        }
        for(int i=0;i<sz;i++)
        {
            printf("%d",ans[i]);
            if(i<sz-1)
                printf(" ");
            else
                puts("");
        }
    }
    return 0;
}



