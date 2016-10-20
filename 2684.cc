#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string.h>
#include<math.h>
#define eps 1e-8
#include<algorithm>
using namespace std;
struct Point
{
    int x,y;
    void Input()
    {
        scanf("%d%d",&x,&y);
    }
};
double Xmult(Point o,Point a,Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
int Sig(double a)
{
    return a<-eps?-1:a>eps;
}
int sqr(int a)
{
    return a*a;
}
int Dis(Point a,Point b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
void Change(Point p[],int n)
{
    for(int i=0;i<n/2;i++)//杩欎釜鍦版柟 琛�殑鏁欒浜�wa 浜嗕竴涓笅鍗�鍘熸潵鍐欐垚i<=n/2浜�
        swap(p[i],p[n-i-1]);
}
void Input(Point p[],int &n)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        p[i].Input();
}
int Equal(Point a[],Point b[],int n)
{
    a[n]=a[0];
    b[n]=b[0];
    for(int i=0;i<n;i++)
    {
        if(Dis(a[i],a[i+1])!=Dis(b[i],b[i+1]))
            return 0;
    }
    for(int i=0;i<n-2;i++)
    {
        double x1=Xmult(a[i],a[i+1],a[i+2]);
        double x2=Xmult(b[i],b[i+1],b[i+2]);
        if(x1*x2<0)
            return 0;
    }
    return 1;
}
int main()
{
    int tm,m,n;
    string ans,tmp;
    Point tp[100],p[100];
    while(scanf("%d",&n) && n)
    {
        Input(tp,tm);
        for(int i=1;i<=n;i++)
        {
            Input(p,m);
            if(m!=tm)
                continue;
            if(Equal(tp,p,m))
                printf("%d\n",i);
            else
            {
                Change(p,m);
                if(Equal(tp,p,m))
                    printf("%d\n",i);
            }
        }
        printf("+++++\n");
    }
    return 0;
}



