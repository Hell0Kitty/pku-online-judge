#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=12;
int a[maxn],s,c,q[maxn];
double ave,ans;
int p[maxn][4],res[maxn][4];
void dfs(int idx)
{
    int i,j;
    if(idx>s)///分配完全
    {
        double sum=0;
        int i,j;
        for(i=1;i<=c;i++)
        {
            sum+=fabs(q[i]-ave);
        }
        if(sum<ans)
        {
             ans=sum;
             for(i=1;i<=c;i++)//赋值
             {
                 res[i][0]=0;
                 for(j=1;j<=p[i][0];j++)
                 {
                     res[i][0]++;
                     res[i][j]=p[i][j];
                 }
             }
        }
         return;
    }
    for(i=1; i<=c; i++)///尝试把第 idx 个分别放在这 c 个腔里！！
    {
        if(p[i][0]>=2) continue;
        p[i][0]++;
        p[i][p[i][0]]=a[idx];
        q[i]+=a[idx];
        dfs(idx+1);
        q[i]-=a[idx];
        p[i][0]--;
    }
}
void init()
{
    for(int i=0;i<=c;i++)
    {
        q[i]=0;
        for(int j=0;j<=3;j++)
        {
            p[i][j]=0;
            res[i][j]=0;
        }
    }
}
int main()
{
    int cas=1;
    while(scanf("%d%d",&c,&s)!=EOF)
    {
        int i,j,sum=0;
        for(i=1; i<=s; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        init();
        ans=200000000;
        ave=sum*1.0/c;
        dfs(1);
        printf("Set #%d\n",cas++);
        for(i=1;i<=c;i++)
        {
            printf(" %d:",i-1);
            for(j=1;j<=res[i][0];j++)
            {
                printf(" %d",res[i][j]);
            }printf("\n");
        }
        printf("IMBALANCE %.5f\n\n",ans);
    }
    return 0;
}




