#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI=acos(-1.0),eps=1e-8;
inline bool same(double a,double b)
{
    double t=a-b;
    return fabs(t)<eps||fabs(t-2*PI)<eps;
}
int main()
{
    int T;
    for(scanf("%d",&T);T;T--)
    {
        double th[3],po[3][2];
        scanf("%lf",&th[0]);
        bool flag=false;
        for(int i=0;i<3;i++)
        {
            scanf("%lf%lf",&po[i][0],&po[i][1]);
            th[i]=atan2(po[i][0],po[i][1]);
            if(same(po[i][0],po[i][1])&&same(po[i][0],0.0))
                flag=true;
        }
        if(flag||same(th[0],th[1])||same(th[0],th[2])||same(th[1],th[2]))
            printf("No\n");
        else
        {
            sort(th,th+3);
            if(th[2]-th[0]<2.0*PI/3.0+eps||th[1]-th[0]>4.0*PI/3.0-eps)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }



