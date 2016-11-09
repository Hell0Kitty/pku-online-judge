#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
double x,y,z,a,b,c,d;
struct point
{
    double x,y,z;
}; 
point poly[4];
double eps=1e-7,ans,pi=acos(-1.000);
bool inter(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
     double a1,b1,c1,a2,b2,c2,z1,z2,z3,z4;
     z1=(d-a*x1-b*y1)/c;
     z2=(d-a*x2-b*y2)/c;
     z3=(d-a*x3-b*y3)/c;
     z4=(d-a*x4-b*y4)/c;
     a1=y2-y1;
     b1=x1-x2;
     c1=y1*x2-y2*x1;
     a2=y4-y3;
     b2=x3-x4;
     c2=y3*x4-y4*x3;
     if(a1*b2==a2*b1)
        return false;
     x=(c2*b1-c1*b2)/(a1*b2-a2*b1);
     y=(c2*a1-c1*a2)/(b1*a2-b2*a1);
     z=(d-a*x-b*y)/c;
     if(!((x<x1+eps&&x>x2-eps)||(x<x2+eps&&x>x1-eps)))
         return false;
     if(!((y<y1+eps&&y>y2-eps)||(y<y2+eps&&y>y1-eps)))
         return false;
     if(!((z<z1+eps&&z>z2-eps)||(z<z2+eps&&z>z1-eps)))
         return false;
     if(!((x<x3+eps&&x>x4-eps)||(x<x4+eps&&x>x3-eps)))
         return false;
     if(!((y<y3+eps&&y>y4-eps)||(y<y4+eps&&y>y3-eps)))
         return false;
     if(!((z<z3+eps&&z>z4-eps)||(z<z4+eps&&z>z3-eps)))
         return false;
     return true;
}
double dist(double x1,double y1,double z1,double x2,double y2,double z2)
{
     return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
double fermat(double x1,double y1,double z1,double x2,double y2,double z2,double x3,double y3,double z3)
{
       double arg,res=1000000000,a,b,c,A,B,C;
       a=dist(x1,y1,z1,x2,y2,z2);
       b=dist(x2,y2,z2,x3,y3,z3);
       c=dist(x1,y1,z1,x3,y3,z3);
       A=(b*b+c*c-a*a)/(2*b*c);
       A=acos(A);
       B=(a*a+c*c-b*b)/(2*a*c);
       B=acos(B);
       C=(a*a+b*b-c*c)/(2*a*b);
       C=acos(C);
       res=min(res,a+b);
       res=min(res,a+c);
       res=min(res,b+c);
       if(A>pi*2.00/3.00||B>pi*2.00/3.00||C>pi*2.00/3.00)
          return res;
       arg=(sin(B)*sin(A)-sin(A)*sin(B-pi/3.00))/(sin(A)*cos(B-pi/3.00)+sin(B)*cos(A));
       arg=atan(arg);
       if(arg<0)
         arg+=pi;
       if(arg>pi/3.00||arg>A)
          return res;
       res=min(res,2*sqrt(3.000)*(c*(sin(pi/3.000-arg)+sin(arg))+b*sin(A-arg))/3.0);
       return res;
}
double cal(point aa,point bb,point cc,point dd)
{
       double arg,a,b,c,d,A,B,C,D,dig1,dig2,res=1000000000;
       a=dist(aa.x,aa.y,aa.z,dd.x,dd.y,dd.z);
       b=dist(dd.x,dd.y,dd.z,cc.x,cc.y,cc.z);
       c=dist(cc.x,cc.y,cc.z,bb.x,bb.y,bb.z);
       d=dist(bb.x,bb.y,bb.z,aa.x,aa.y,aa.z);
       dig1=dist(bb.x,bb.y,bb.z,dd.x,dd.y,dd.z);
       A=(a*a+d*d-dig1*dig1)/(2*a*d);
       A=acos(A);
       C=(b*b+c*c-dig1*dig1)/(2*b*c);
       C=acos(C);
       dig2=dist(aa.x,aa.y,aa.z,cc.x,cc.y,cc.z);
       B=(d*d+c*c-dig2*dig2)/(2*c*d);
       B=acos(B);
       D=(a*a+b*b-dig2*dig2)/(2*a*b);
       D=acos(D);
       arg=(d*sin(2.00*pi/3.00-A)-a*sqrt(3.000)/2.00-b*sin(D))/(b*cos(D)-a-d*cos(2.00*pi/3.00-A)-a/2.00);
       arg=atan(arg);
       if(arg<0)
          arg+=pi;
       if(arg>pi/3.00||arg>A||B+A-arg-pi*2/3.000<0||C+D+arg-pi<0)
           return res;
       return 2*sqrt(3.000)*(a*sin(arg)+d*sin(pi/3.00+A-arg)+c*(sin(C+D+arg-pi)+sin(B+A-arg-2.00*pi/3.00)))/3.000;
}
int main()
{
    int n,id1,id2,id3,i,j,s,p,q,t,id[3],tst=0;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    scanf("%d",&t);
    while(t--)
    {
        tst++;
        scanf("%d",&n);
        for(i=0;i<n;i++)
           scanf("%lf%lf%lf",&poly[i].x,&poly[i].y,&poly[i].z);
        ans=1000000000;
       if(n==4)
       {
            if(inter(poly[0].x,poly[0].y,poly[1].x,poly[1].y,poly[2].x,poly[2].y,poly[3].x,poly[3].y))
            {
               if(ans>dist(poly[0].x,poly[0].y,poly[0].z,poly[1].x,poly[1].y,poly[1].z)+dist(poly[2].x,poly[2].y,poly[2].z,poly[3].x,poly[3].y,poly[3].z))
                  ans=dist(poly[0].x,poly[0].y,poly[0].z,poly[1].x,poly[1].y,poly[1].z)+dist(poly[2].x,poly[2].y,poly[2].z,poly[3].x,poly[3].y,poly[3].z);
               if(ans>min(cal(poly[0],poly[2],poly[1],poly[3]),cal(poly[0],poly[3],poly[1],poly[2])))
                  ans=min(cal(poly[0],poly[2],poly[1],poly[3]),cal(poly[0],poly[3],poly[1],poly[2]));
            }
            if(inter(poly[0].x,poly[0].y,poly[2].x,poly[2].y,poly[1].x,poly[1].y,poly[3].x,poly[3].y))
            {
               if(ans>dist(poly[0].x,poly[0].y,poly[0].z,poly[2].x,poly[2].y,poly[2].z)+dist(poly[1].x,poly[1].y,poly[1].z,poly[3].x,poly[3].y,poly[3].z))
                  ans=dist(poly[0].x,poly[0].y,poly[0].z,poly[2].x,poly[2].y,poly[2].z)+dist(poly[1].x,poly[1].y,poly[1].z,poly[3].x,poly[3].y,poly[3].z);
               if(ans>min(cal(poly[0],poly[1],poly[2],poly[3]),cal(poly[0],poly[3],poly[2],poly[1])))
                  ans=min(cal(poly[0],poly[1],poly[2],poly[3]),cal(poly[0],poly[3],poly[2],poly[1]));
            }       
            if(inter(poly[0].x,poly[0].y,poly[3].x,poly[3].y,poly[1].x,poly[1].y,poly[2].x,poly[2].y))
            {
               if(ans>dist(poly[0].x,poly[0].y,poly[0].z,poly[3].x,poly[3].y,poly[3].z)+dist(poly[1].x,poly[1].y,poly[1].z,poly[2].x,poly[2].y,poly[2].z))
                  ans=dist(poly[0].x,poly[0].y,poly[0].z,poly[3].x,poly[3].y,poly[3].z)+dist(poly[1].x,poly[1].y,poly[1].z,poly[2].x,poly[2].y,poly[2].z);
               if(ans>min(cal(poly[0],poly[1],poly[3],poly[2]),cal(poly[0],poly[2],poly[3],poly[1])))
                  ans=min(cal(poly[0],poly[1],poly[3],poly[2]),cal(poly[0],poly[2],poly[3],poly[1]));                                                                                       
            } 
            for(i=0;i<4;i++)
            { 
               if(i==0)
               {
                  id[0]=1;
                  id[1]=2;
                  id[2]=3;
               }
               else if(i==1)
               {
                  id[0]=0;
                  id[1]=2;
                  id[2]=3;
               }
               else if(i==2)
               {
                  id[0]=0;
                  id[1]=1;
                  id[2]=3;
               }
               else
               {
                  id[0]=0;
                  id[1]=1;
                  id[2]=2;
               }
               if(ans>dist(poly[i].x,poly[i].y,poly[i].z,poly[id[0]].x,poly[id[0]].y,poly[id[0]].z)+dist(poly[i].x,poly[i].y,poly[i].z,poly[id[1]].x,poly[id[1]].y,poly[id[1]].z)+dist(poly[i].x,poly[i].y,poly[i].z,poly[id[2]].x,poly[id[2]].y,poly[id[2]].z))
                  ans=dist(poly[i].x,poly[i].y,poly[i].z,poly[id[0]].x,poly[id[0]].y,poly[id[0]].z)+dist(poly[i].x,poly[i].y,poly[i].z,poly[id[1]].x,poly[id[1]].y,poly[id[1]].z)+dist(poly[i].x,poly[i].y,poly[i].z,poly[id[2]].x,poly[id[2]].y,poly[id[2]].z);
               double temp=1000000000;
               for(j=0;j<3;j++)
               { 
                  if(temp>dist(poly[i].x,poly[i].y,poly[i].z,poly[id[j]].x,poly[id[j]].y,poly[id[j]].z))
                     temp=dist(poly[i].x,poly[i].y,poly[i].z,poly[id[j]].x,poly[id[j]].y,poly[id[j]].z);
               }
               if(ans>temp+fermat(poly[id[0]].x,poly[id[0]].y,poly[id[0]].z,poly[id[1]].x,poly[id[1]].y,poly[id[1]].z,poly[id[2]].x,poly[id[2]].y,poly[id[2]].z))
                  ans=temp+fermat(poly[id[0]].x,poly[id[0]].y,poly[id[0]].z,poly[id[1]].x,poly[id[1]].y,poly[id[1]].z,poly[id[2]].x,poly[id[2]].y,poly[id[2]].z);
           }
        } 
        else
           ans=fermat(poly[0].x,poly[0].y,poly[0].z,poly[1].x,poly[1].y,poly[1].z,poly[2].x,poly[2].y,poly[2].z);
        printf("Province # %d : %.2lf\n",tst,ans);
    } 
    return 0;
}


