#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-10;
double C6[7]= {1.0,6.0,15.0,20.0,15.0,6.0,1.0};
double PT[7],PXT[4][7],PTX[7][4],PX[4];
double ans,num;
void cal(int t1,int t2,int t3,int t4,double pp)
{
    double p1,p2,p3,p4;
    for(int n1=0; n1<2; n1++)
    {
        if(t1<n1||(n1==0&&t1==6))
            continue;
        p1=(n1==0)?(6-t1)/6.0:t1/6.0;
        for(int n2=0; n2<2; n2++)
        {
            if(t2<n2||(n2==0&&t2==6))
                continue;
            p2=(n2==0)?(6-t2)/6.0:t2/6.0;
            for(int n3=0; n3<2; n3++)
            {
                if(t3<n3||(n3==0&&t3==6))
                    continue;
                p3=(n3==0)?(6-t3)/6.0:t3/6.0;
                for(int n4=0; n4<2; n4++)
                {
                    if(t4<n4||(n4==0&&t4==6))
                        continue;
                    p4=(n4==0)?(6-t4)/6.0:t4/6.0;
                    double p=p1*p2*p3*p4*pp;
                    num+=p;
                    ans+=(n1+n2+n3+n4)*p;
                }
            }
        }
    }
}
int main()
{
    for(int t=0; t<7; t++)
        PT[t]=C6[t]/64.0;
    memset(PX,0,sizeof(PX));
    memset(PXT,0,sizeof(PXT));
    memset(PTX,0,sizeof(PTX));
    for(int t=0; t<7; t++)
    {
        for(int x=0; x<4; x++)
        {
            int a=x%2,b=(x>>1)%2;
            PXT[x][t]=((a==0)?(6-t)/6.0:t/6.0)*((b==0)?(6-t)/6.0:t/6.0);
            PX[x]+=PXT[x][t];
        }
    }
    for(int t=0; t<7; t++)
    {
        for(int x=0; x<4; x++)
        {
            PTX[t][x]=PXT[x][t]*PT[t]/PX[x];
        }
    }
    int T;
    for(scanf("%d",&T); T; T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ans=0.0;
        num=0.0;
        for(int x1=0; x1<4; x1++)
        {
            for(int x2=0; x2<4; x2++)
            {
                for(int x3=0; x3<4; x3++)
                {
                    for(int x4=0; x4<4; x4++)
                    {
                        int aa=x1%2+x2%2+x3%2+x4%2;
                        int bb=x1/2%2+x2/2%2+x3/2%2+x4/2%2;
                        if(aa==a&&bb==b)
                        {
                            for(int t1=0; t1<7; t1++)
                            {
                                if(PTX[t1][x1]>eps)
                                for(int t2=0; t2<7; t2++)
                                {
                                    if(PTX[t2][x2]>eps)
                                    for(int t3=0; t3<7; t3++)
                                    {
                                        if(PTX[t3][x3]>eps)
                                        for(int t4=0; t4<7; t4++)
                                        {
                                            if(PTX[t4][x4]>eps)
                                            {
                                                cal(t1,t2,t3,t4,PTX[t1][x1]*PTX[t2][x2]*PTX[t3][x3]*PTX[t4][x4]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%.3lf\n",ans/num);
    }
    return 0;
}



