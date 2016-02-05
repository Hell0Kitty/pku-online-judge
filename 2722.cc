#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include<iostream>
#include<cstring>
using namespace std;
const double PI = acos(-1.0);
#define EPS 1e-7

double f(double a,double b,double l)
{
    l=l*l;
    double ret;
   // printf("%lf %lf %lf\n",a,b,l);
    ret=l*sin(a+b+PI/4)*sin(a+PI/4)/sin(b);
    return ret;
}

int main()
{
    int n;
    double xa,ya,xb,yb;
    while (scanf("%d", &n) == 1)
    {
        if(!n) break;
        double len[11];
        scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
        double ang1=atan2(ya,xa),ang2=atan2(yb,xb);
        if(ang1>ang2)
            swap(ang1,ang2);
        ang2=ang2-ang1;
        double tot=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&len[i]);
            tot+=len[i];
        }
        if(fabs(ang2)<EPS)
            puts("0.000");
        else
        {
            double ans=f(ang1,ang2,tot);
            for(int i=0;i<n;i++)
                ans-=len[i]*len[i]/2;
            printf("%.3lf\n",ans+EPS);
        }

    }
    return 0;
}



