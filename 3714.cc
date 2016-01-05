#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=200000+1;
const double INF=1e100;
struct Point{
    double x,y;
    bool flag;
};
Point m[N+1];
int tmp[N+1];
double dis(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double minL(double l1,double l2)
{
    return l1<=l2?l1:l2;
}
bool cmpy(int a,int b)
{
    return m[a].y<m[b].y;
}
bool cmpx(Point a,Point b)
{
    return a.x<b.x;
}
double getMinLen(Point *s,int left,int right)
{
    double rs=INF;
    if(left == right)
        return rs;
    if(left+1 == right)
    {
        if(s[left].flag == s[right].flag)
            return rs;
        return dis(s[left],s[right]);
    }
    int mid=(left+right)>>1;
    rs=getMinLen(s,left,mid);
    rs=minL(rs,getMinLen(s,mid+1,right));
    int i,j,num=0;
    for(i=left;i<=right;++i)
    {
        if(fabs(s[i].x-s[mid].x)<=rs)
            tmp[num++]=i;
    }
    sort(tmp,tmp+num,cmpy);
    double d=INF;
    for(i=0;i<num;++i)
    {
        for(j=i+1;j<num;++j)
        {
            if(fabs(s[tmp[i]].y-s[tmp[j]].y)>=rs)
                break;
            if(s[tmp[i]].flag!=s[tmp[j]].flag && (d=dis(s[tmp[i]],s[tmp[j]]))<rs)
                rs=d;
        }
    }

    return rs;
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;++i)
        {
            scanf("%lf%lf",&m[i].x,&m[i].y);
            m[i].flag=0;
        }
        for(i=0;i<n;++i)
        {
            scanf("%lf%lf",&m[i+n].x,&m[i+n].y);
            m[i+n].flag=1;
        }
        n<<=1;
        sort(m,m+n,cmpx);
        double ans=getMinLen(m,0,n-1);
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<ans<<endl;
    }
    return 0;
}


