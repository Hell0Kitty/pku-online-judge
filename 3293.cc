#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#define pi acos(-1.0)
#define N 100010
#define r 6370
#define eps 1e-8
#define inf 0xfffffff
using namespace std;
struct Point
{
    int x,y;
    int id;
};
struct Line
{
    int x,y1,y2;
    Line(){}
    Line(int x0,int y11,int y22):x(x0),y1(y11),y2(y22){}
};
Line l[N];
Point p[N];
int con[N][2];
int n;
int ln;
int cmp_x(Point a,Point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int cmp_y(Point a,Point b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
int Judge(Point a,Point b)
{
    int y=a.y,x1=a.x,x2=b.x;
    for(int i=0;i<ln;i++)
    {
        if(x1<l[i].x && x2>l[i].x
        && l[i].y1<y && l[i].y2>y)
        return 1;
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].id=i;
        }
        int sum=0;
        sort(p,p+n,cmp_x);
        int cnt=1;
        int flag=0;
        ln=0;
        for(int i=1;i<n&&!flag;i++)
        {
            if(p[i].x!=p[i-1].x)
            {
                if(cnt&1)
                    flag=1;
                cnt=1;
            }
            else
            {
                cnt++;
                if((cnt&1)==0)
                {
                    sum+=p[i].y-p[i-1].y;
                    con[p[i].id][0]=p[i-1].id;//前驱
                    con[p[i-1].id][0]=p[i].id;//后继
                    l[ln++]=Line(p[i].x,p[i-1].y,p[i].y);
                }
            }
        }
        sort(p,p+n,cmp_y);
        cnt=1;
        for(int i=1;i<n && !flag;i++)
        {
            if(p[i].y!=p[i-1].y)
            {
                if(cnt&1)
                    flag=1;
                cnt=1;
            }
            else
            {
                cnt++;
                if((cnt&1)==0)
                {
                    sum+=p[i].x-p[i-1].x;
                    con[p[i].id][1]=p[i-1].id;//前驱
                    con[p[i-1].id][1]=p[i].id;//后继
                    if(Judge(p[i-1],p[i]))
                        flag=1;
                }
            }
        }
        int pp=1,x=0,cc=0;
        do
        {
            x=con[x][pp];
            pp=1-pp;
            cc++;
        }while(x!=0 && !flag);
        if(cc!=n)
            flag=1;
        if(!flag)
            cout<<sum<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}



