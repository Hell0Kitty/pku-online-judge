#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int left[10010],dp[10010][10010],dp2[10010][10010],num[10010],num2[10010],q[10010],h[10010],f;
char s[10010];
int solve(int m)
{
    int i,j,k,ret;
    for(i=1;i<=m;i++)
     num2[i]=num[i]+i-1;
    q[1]=num2[1];h[m]=num2[m];
    for(i=2;i<=m;i++)
       if(num2[i]>=q[i-1])
         q[i]=num2[i];
       else
         q[i]=q[i-1];
    for(i=m-1;i>=1;i--)
       if(num2[i]>=h[i+1])
         h[i]=num2[i];
       else
         h[i]=h[i+1];
    ret=q[m];f=m;
    for(i=1;i<m;i++)
       if(max(q[i]+m-i,h[i+1]-i)<ret)
       {
           ret=max(q[i]+m-i,h[i+1]-i);
           f=i;
       }
    return ret;
}
void dfs(int l,int r)
{
    if(l==r)
     return;
    int i,j,k,pos=r,ret;
    k=s[r]-'0';
    for(j=k;j>=1;j--)
    {
        dfs(left[pos-1],pos-1);
        pos=left[pos-1];
    }
    pos=r;
    for(j=k;j>=1;j--)
    {
        num[j]=dp[left[pos-1]][pos-1];
        pos=left[pos-1];

    }
    ret=solve(k);
    dp[l][r]=ret;
    dp2[l][r]=f;
}
void print(int l,int r)
{
    if(l==r)
    {
        printf("a");
        return;
    }
    int i,j,k,pos=r,m=dp2[l][r];
    k=s[r]-'0';
    for(j=k;j>=1;j--)
    {
        num[j]=pos-1;
        pos=left[pos-1];
    }
    vector<int> vc;
    vc.push_back(0);
    for(i=1;i<=k;i++)
     vc.push_back(num[i]);
    for(i=m+1;i<=k;i++)
       print(left[vc[i]],vc[i]);
    for(i=1;i<=m;i++)
       print(left[vc[i]],vc[i]);
    printf("%c",s[r]);
}
int main()
{
    int n,i,j,k,pos,ret=0;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(i=1;i<=n;i++)
    {
        if(s[i]=='a')
        {
           left[i]=i;
           dp[i][i]=1;
        }
        else
        {
            k=s[i]-'0';
            pos=i;
            ret=0;
            for(j=k;j>=1;j--)
                pos=left[pos-1];
            left[i]=pos;
        }
    }
    dfs(1,n);
    printf("%d\n",dp[1][n]);
    print(1,n);
    printf("\n");
}



