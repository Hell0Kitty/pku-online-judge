#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
const double g=980;

double c, a, v, f;

inline double cal_c(double ang)
{
    return v*cos(ang)*(tan(a)-tan(ang))/g-1/f;
}
inline double func(double t)
{
    return t/(exp(-f*t)-1)-c;
}
inline double deriv(double t)
{
    double tmp=exp(-f*t);
    return (tmp-1+t*f*tmp)/(tmp-1)/(tmp-1);
}
inline double itsec(double x0, double y0, double k)
{
    return x0-y0/k;
}
inline double solve(double ang)
{
    c=cal_c(ang);
    double t=1;
    double res;
    while(1)
    {
        res=func(t);
        if(fabs(res)<eps)break;
        t=itsec(t, res, deriv(t));
    }
    double dis=v*cos(ang)*(1-exp(-f*t))/f;
    return dis/cos(a);
}

int main()
{
    int i, res, aa;
    double tmp, maxl;
    while(~scanf("%d%lf%lf", &aa, &v, &f))
    {
        maxl=0;
        a=aa*pi/180.0;
        for(i=aa+1; i<90; i++)
        {
            tmp=solve(i*pi/180.0);
            if(tmp>maxl)maxl=tmp, res=i;
        }
        printf("%d\n", res);
    }
    return 0;
}



