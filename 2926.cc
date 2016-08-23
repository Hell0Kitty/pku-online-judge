#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int dem=5;
const int maxxn=100005;
const double inf=1e200;
struct Point
{
    double x[dem];
} p[maxxn];
int n;
double minx[1<<dem], maxx[1<<dem];

double solve()
{
    int i, j, k, t, tmp=1<<dem;
    double s, ans=-inf;
    for(i=0; i<tmp; i++)
    {
        minx[i]=inf;
        maxx[i]=-inf;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<tmp; j++)
        {
            t=j;
            s=0;
            for(k=0; k<dem; k++)
            {
                if(t&1)
                    s+=p[i].x[k];
                else s-=p[i].x[k];
                t>>=1;
            }
            if(maxx[j]<s)maxx[j]=s;
            if(minx[j]>s)minx[j]=s;
        }
    }
    for(i=0; i<tmp; i++)
    {
        if(maxx[i]-minx[i]>ans)
            ans=maxx[i]-minx[i];
    }
    return ans;
}
int main()
{
    int i, j;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<dem; j++)
                scanf("%lf", &p[i].x[j]);
        }
        printf("%.2f\n", solve());
    }
    return 0;
}


