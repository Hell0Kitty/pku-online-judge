#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<iostream>
#include<map>
using namespace std;
#define inf 0x3f3f3f3f
#define Max 110
int max(int a,int b)
{
	return a>b?a:b;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int n,m;
int dp[2][100100];
int a[2010],b[101000];
int main()
{
    int i,j;
    scanf("%d%d",&m,&n);
        for(i=1;i<=m;i++)
            scanf("%d",&b[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(b+1,b+m+1);
        sort(a+1,a+n+1);
        for(i=0;i<=m;i++)
            dp[0][i]=0;
        int tmp=0;
        int pos=1;
        int st1,st2,ed1,ed2;
        st1=0;ed1=m;
        for(i=1;i<=n;i++)
        {
            for(;pos<=m;pos++)
            {
                if(b[pos]>a[i])
                    break;
            }
            st2=max(i,pos-n-10);
            ed2=min(m,pos+n+10);
            dp[1-tmp][st2-1]=inf;
            for(j=st2;j<=ed2;j++)
            {
                if(j>=st1&&j<=ed1)
                dp[1-tmp][j]=min(dp[tmp][j-1]+abs(a[i]-b[j]),dp[1-tmp][j-1]);
                else
                    dp[1-tmp][j]=min(dp[tmp][ed1]+abs(a[i]-b[j]),dp[1-tmp][j-1]);
            }
            st1=st2;
            ed1=ed2;
            tmp=1-tmp;
        }
        int ans=inf;
        printf("%d\n",dp[tmp][ed1]);
}



