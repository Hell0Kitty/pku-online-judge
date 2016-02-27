#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
double eps=1e-10;
int dcmp(double x)
{
    if(fabs(x)<eps)
      return 0;
    return x<0 ? -1 : 1 ;
}
Point operator +(Point A,Point B){return Point(A.x+B.x,A.y+B.y);}
Point operator -(Point A,Point B){return Point(A.x-B.x,A.y-B.y);}
Point operator *(Point A,double p){return Point(A.x*p,A.y*p);}
Point operator /(Point A,double p){return Point(A.x/p,A.y/p);}
bool operator ==(Point A,Point B){return dcmp(A.x-B.x)==0 && dcmp(A.y-B.y)==0;}
bool operator <(Point A,Point B)
{
    if(dcmp(A.x-B.x)==0)
      return A.y<B.y;
    return A.x<B.x;
}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
bool parallel(Point aa,Point ab,Point ba,Point bb){return dcmp(Cross(aa-ab,ba-bb))==0;}
bool jiaodian(Point aa,Point ab,Point ba,Point bb,Point &as)
{
    if(parallel(aa,ab,ba,bb))
      return 0;
    double s1=Cross(aa-ba,bb-ba);
    double s2=Cross(ab-ba,bb-ba);
    as=(ab*s1-aa*s2)/(s1-s2);
    return 1;
}
bool Onsegment(Point p,Point s,Point t){return dcmp(Cross(s-p,t-p))==0 && dcmp(Dot(s-p,t-p))<=0;}
Point p[510],temp,p2[100010];
int n,t,tot;
int main()
{
    int i,j,k,ret,ret2;
    while(~scanf("%d",&n) && n>0)
    {
        for(i=1;i<=n;i++)
           scanf("%lf%lf",&p[i].x,&p[i].y);
        tot=0;
        for(i=2;i<=n;i++)
           for(j=i+1;j<=n;j++)
              if(jiaodian(p[i],p[i-1],p[j],p[j-1],temp) && Onsegment(temp,p[i],p[i-1])&& Onsegment(temp,p[j],p[j-1]))
                p2[++tot]=temp;
        for(i=1;i<=n;i++)
           p2[++tot]=p[i];
        sort(p2+1,p2+1+tot);
        ret=1;
        for(i=2;i<=tot;i++)
           if(!(p2[i]==p2[i-1]))
             p2[++ret]=p2[i];
        tot=ret;
        ret2=0;
        for(i=2;i<=n;i++)
           for(j=1;j<=tot;j++)
              if(Onsegment(p2[j],p[i],p[i-1]))
                ret2++;
        printf("Case %d: There are %d pieces.\n",++t,2-tot+ret2-n+1);
    }
}



