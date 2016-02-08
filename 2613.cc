#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
const int MAX=10000;
int pri[MAX+5];
int mark[MAX+5];
int cnt;
int p1[MAX+5],p2[MAX+5],p3[MAX+5],p4[MAX+5],x1[MAX+5],x2[MAX+5];

void Prime()
{
    int i,j;
    cnt=0;
    for(i=0;i<MAX;i++)
        mark[i]=i;
    for(i=2;i<MAX;i++)
    {
        if(mark[i]==i)
            pri[cnt++]=i;
        for(j=0;j<cnt&&pri[j]*i<MAX;j++)
        {
            mark[i*pri[j]]=pri[j];
            if(i%pri[j]==0)
                break;
        }
    }
}

void solve(int x,int y,int p[])
{
    int i,j,n;
    for(i=x;i<=y;i++)
    {
        n=i;
        for(j=0;j<cnt;j++)
        {
            if(n%pri[j]==0)
            {
                while(n%pri[j]==0)
                {
                    p[pri[j]]++;
                    n=n/pri[j];
                }
            }
            if(n==1)
                break;
        }
    }
}

int main()
{
    Prime();

    int p,q,r,s,i,j;
    while(scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF)
    {

        q=min(p-q,q);
        s=min(r-s,s);
        memset(p1,0,sizeof(p1));
        memset(p2,0,sizeof(p2));
        memset(p3,0,sizeof(p3));
        memset(p4,0,sizeof(p4));
        solve(p-q+1,p,p1);
        solve(1,s,p2);
        solve(1,q,p3);
        solve(r-s+1,r,p4);
        for(i=0;i<MAX;i++)
        {
            x1[i]=p1[i]+p2[i];
            x2[i]=p3[i]+p4[i];
        }

        double ans=1.0;
        for(i=0;i<MAX;i++)
        {
            if(x1[i]>x2[i])
            {
                for(j=1;j<=x1[i]-x2[i];j++)
                    ans=ans*i;
            }
            else
            {
                for(j=1;j<=x2[i]-x1[i];j++)
                {
                    ans=ans/i;
                }
            }
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}



