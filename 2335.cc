#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const double  pi=acos(-1.0);
typedef struct Vector
{
    double dx;
    double dy;
    double ang;
}Vector;
Vector a[5];
int cmp(Vector a,Vector b)
{
    return a.ang<b.ang;
}
int main()
{
    int n;
    double x1,y1,x2,y2,x3,y3;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);

        double cx=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2*(x3-x1)*(y2-y1)-2*((x2-x1)*(y3-y1)));
        double cy=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2*(y3-y1)*(x2-x1)-2*((y2-y1)*(x3-x1)));

        a[0].dx=x1-cx;
        a[0].dy=y1-cy;
        a[1].dx=x2-cx;
        a[1].dy=y2-cy;
        a[2].dx=x3-cx;
        a[2].dy=y3-cy;

        for(int i=0;i<3;i++)
        {
            a[i].ang=atan2(a[i].dy,a[i].dx);
        }
        sort(a,a+3,cmp);
        double a1,a2,a3;
        a1=a[1].ang-a[0].ang;
        a2=a[2].ang-a[1].ang;
        a3=a[0].ang+2*pi-a[2].ang;

        int ans=-1;

        for(int i=3;i<=200;i++)
        {
            double k=2.0*pi/(double)i;
            double b1=a1/k;
            double b2=a2/k;
            double b3=a3/k;
            int s1=fmod(b1,1.0)>=0.5?ceil(b1):floor(b1);
            int s2=fmod(b2,1.0)>=0.5?ceil(b2):floor(b2);
            int s3=fmod(b3,1.0)>=0.5?ceil(b3):floor(b3);
            if(fabs(s1-b1)<1e-5&&fabs(s2-b2)<1e-5&&fabs(s3-b3)<1e-5)
            {
                ans=i;break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


