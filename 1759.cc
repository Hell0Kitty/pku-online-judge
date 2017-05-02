#include<cstdio>
#include<iostream>
#define Max 1008
#define eps 1e-6
double a,h2;
int N;
double solve(int t)
{
    return ( (t-1)*h2 - (t-2)*a + t*t - 3*t + 2);
}
bool judge()
{
    bool flag=true;
    for(int i=2;i<=N;i++)
        if(solve(i)<0)
            {
                flag=false;
                break;
            }
    return flag;
}

int main()
{
    int i,j;
    double left,mid,right,temp;
    double ans=2000000000.0;
    scanf("%d %lf",&N,&a);
    for(left=a,right=0.0;left-right>eps;)
    {
        mid=(left+right)/2;
        h2=mid;
        if(judge())
        {
            temp=solve(N);
            if(temp<ans)
                ans=temp;
            left=mid;
        }
        else
            right=mid;
    }
    printf("%.2lf\n",ans);
}