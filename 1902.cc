#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<map>
using namespace std;
double xx,yy;
struct point
{
    double x,y,l;
    int id;
    bool operator<(const point &temp)const
    {
         return l<temp.l;
    }
};
point a[111],na[111];
int stack[111];
bool cmp(point a,point b)
{
     return a.y<b.y; 
}
int n,N;
double pi=acos(-1.00),ans[111],eps=1e-7,in;
bool cmft(point p,point q)
{
     if(fabs((p.y-yy)*(q.x-xx)-(p.x-xx)*(q.y-yy))<eps)
        return fabs(p.x-xx)+fabs(p.y-yy)<fabs(q.x-xx)+fabs(q.y-yy);
     return (p.y-yy)*(q.x-xx)-(p.x-xx)*(q.y-yy)<0;   
}
void solve(double x0,double y0,double theta1,double theta2,point a[],int n)
{
     int nn=n/2,i;
     point b[111];
     double alpha,x,y,nx,ny,theta,arg1,arg2;
     if(n==1)
     {
        ans[a[0].id]=theta1+pi/N;
        return;
     }
     if(nn*2.00*pi/N>=theta2-theta1)
     {
         for(i=nn;i<n;i++)
             ans[a[i].id]=0.00;
         solve(x0,y0,theta1,theta2,a,nn);
     }
     else
     {
         alpha=nn*2.00*pi/N;
         for(i=0;i<n;i++)
         {
            x=((y0-a[i].y)*cos(alpha+theta1)*cos(theta1)+a[i].x*sin(alpha+theta1)*cos(theta1)-x0*sin(theta1)*cos(alpha+theta1))/sin(alpha);
            y=(y0*sin(alpha+theta1)*cos(theta1)-a[i].y*sin(theta1)*cos(alpha+theta1)+(a[i].x-x0)*sin(alpha+theta1)*sin(theta1))/sin(alpha);
            double value=cos(theta1);
            if(fabs(value)>1e-5)
               a[i].l=(x-x0)/value;
            else
               a[i].l=(y-y0)/sin(theta1);          
         }
         sort(a,a+n);
         x=(a[nn-1].x+a[nn].x)/2.00;
         y=(a[nn-1].y+a[nn].y)/2.00;
         nx=((y0-y)*cos(alpha+theta1)*cos(theta1)+x*sin(alpha+theta1)*cos(theta1)-x0*sin(theta1)*cos(alpha+theta1))/sin(alpha);
         ny=(y0*sin(alpha+theta1)*cos(theta1)-y*sin(theta1)*cos(alpha+theta1)+(x-x0)*sin(alpha+theta1)*sin(theta1))/sin(alpha);
         solve(nx,ny,theta1,theta1+alpha,a,nn);
         for(i=nn;i<n;i++)
            b[i-nn]=a[i];
         alpha-=theta2-theta1;
         theta1=theta2;
         nx=((y0-y)*cos(alpha+theta1)*cos(theta1)+x*sin(alpha+theta1)*cos(theta1)-x0*sin(theta1)*cos(alpha+theta1))/sin(alpha);
         ny=(y0*sin(alpha+theta1)*cos(theta1)-y*sin(theta1)*cos(alpha+theta1)+(x-x0)*sin(alpha+theta1)*sin(theta1))/sin(alpha);
         solve(nx,ny,theta2+alpha,theta2,b,n-nn);
     }
}
void convexhull()
{
     int i,j,s,p,q,id,top,id1,id2,ip,ip1,ip2,nn;
     double arg,sine,cosine,arg1,arg2; 
     in=1000000000;
     for(i=0;i<n;i++)
     {
         if(in>a[i].y)
         {
            in=a[i].y;
            id=i;
         }
     }
     swap(a[0],a[id]);
     xx=a[0].x;
     yy=a[0].y;
     sort(a+1,a+n,cmft);
     stack[0]=0;
     stack[1]=1;
     top=2;
     for(i=2;i<n;i++)
     {
        while(top>=2&&(a[i].y-a[stack[top-2]].y)*(a[stack[top-1]].x-a[stack[top-2]].x)<(a[i].x-a[stack[top-2]].x)*(a[stack[top-1]].y-a[stack[top-2]].y)+eps)
             top--;
        stack[top++]=i;
     }
     in=1000000000;
     for(i=0;i<top;i++)
     {
         ip=stack[i];
         ip1=stack[(i+top-1)%top];
         ip2=stack[(i+1)%top];
         double aa,bb,cc;
         aa=sqrt((a[ip1].x-a[ip].x)*(a[ip1].x-a[ip].x)+(a[ip1].y-a[ip].y)*(a[ip1].y-a[ip].y));
         bb=sqrt((a[ip2].x-a[ip].x)*(a[ip2].x-a[ip].x)+(a[ip2].y-a[ip].y)*(a[ip2].y-a[ip].y));
         cc=sqrt((a[ip1].x-a[ip2].x)*(a[ip1].x-a[ip2].x)+(a[ip1].y-a[ip2].y)*(a[ip1].y-a[ip2].y));
         arg=(aa*aa+bb*bb-cc*cc)/(2*aa*bb);
         arg=acos(arg);
         if(in>arg)
         {
            in=arg;
            id=stack[i];
         }
     }
     if(top<3)
        id=stack[0];
     swap(a[id],a[0]);
     xx=a[0].x;
     yy=a[0].y;
     sort(a+1,a+n,cmft);
     xx=(a[n/2].x+a[n/2+1].x)/2.00;
     yy=(a[n/2].y+a[n/2+1].y)/2.00;
     nn=0;
     for(i=1;i<=n/2;i++)
        na[nn++]=a[i];
     cosine=(xx-a[0].x)/sqrt((xx-a[0].x)*(xx-a[0].x)+(yy-a[0].y)*(yy-a[0].y));
     if(cosine>1)
        cosine=1;
     if(cosine<-1)
        cosine=-1;
     arg=acos(cosine);
     if(yy-a[0].y<-eps)
        arg=-arg;
     arg1=arg-(pi-pi/N);
     arg2=arg;
     solve(a[0].x,a[0].y,arg1+pi,arg2+pi,na,nn);
     nn=0;
     for(i=n/2+1;i<n;i++)
         na[nn++]=a[i];
     arg1=arg;
     arg2=arg+pi-pi/N;
     solve(a[0].x,a[0].y,arg1+pi,arg2+pi,na,nn);
     ans[a[0].id]=arg;
}
int main()
{
    int i,j,s,p,q;
    scanf("%d",&n);
    N=n;
    for(i=0;i<n;i++)
    { 
       scanf("%lf%lf",&a[i].x,&a[i].y);
       a[i].id=i;
    }
    if(n%2==0)
    {
       sort(a,a+n,cmp);
       solve(0,(a[n/2-1].y+a[n/2].y)/2.00,0,pi,a,n/2);
       for(i=n/2;i<n;i++)
          na[i-n/2]=a[i];
       solve(0,(a[n/2-1].y+a[n/2].y)/2.00,pi,2*pi,na,n/2);
    }
    else
        convexhull();
    for(i=0;i<N;i++)
       printf("%.15f\n",ans[i]);
    return 0;
}



