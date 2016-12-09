#include <cstdio>
#include <cmath>
#include <cstdlib>
#define pi 4*atan(1)
int main(){
    double d,h;
    scanf("%lf%lf",&d,&h);
        double a,b,c;
        while(scanf("%lf%lf%lf",&a,&b,&c),fabs(a-0)>0.00000001||fabs(b-0)>0.00000001||fabs(c-0)>0.00000001){
            //double H = d*sqrt(2/(1.0/(tan(a/180.0*pi))*(tan(a/180.0*pi))+1.0/(tan(c/180.0*pi))*(tan(c/180.0*pi))-2.0/(tan(b/180.0*pi))*(tan(b/180.0*pi))));
            double aa = tan(a*pi/180.0);
            double bb = tan(b*pi/180.0);
            double cc = tan(c*pi/180.0);
            double H = d*sqrt(2/(1.0/aa/aa+1.0/cc/cc-2.0/bb/bb));
            H = H+h;
            int rusult;
            if (H-(int)H>=0.5) rusult = (int)H+1;
            else rusult = (int)H;
            printf("%d\n",rusult);
        }
}



