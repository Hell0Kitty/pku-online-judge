#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define pi acos(-1.0)
double angle,d,u;
int main()
{
    int i,j,t,flag;
    double ans;
    double a,b,c,k;
    double x1,x2;
    while(scanf("%lf%lf%lf",&u,&angle,&d)){
        if(fabs(u)<eps&&fabs(d)<eps&&fabs(angle)<eps)break;
        angle=angle*pi/180.0;
        ans=exp((angle+sqrt(3.0)*log(d))/sqrt(3.0))-d;
        ans/=u;
        if(ans>10000+eps)printf("God help me!\n");
        else printf("%.0lf\n",ans);
    }
    return 0;
}



