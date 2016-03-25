#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
short rem[101][130100][2];
int n,m,pow9[10],ki[10],K,num[13010],num2[13010],num3[13010][10],match[50000000];
double dp[2][130100],val[10][110];
char s[10][20];
void pai(int pos,int u,int Hash)
{
    int i;
    if(pos==m+1)
    {
        num[0]++;
        num[num[0]]=Hash;
        num2[num[0]]=u;
        match[Hash]=num[0];
        for(i=1;i<=m;i++)
        {
            num3[num[0]][i]=Hash%9;
            Hash/=9;
        }
        return;
    }
    for(i=0;i<=ki[pos];i++)
       if(u+i<=K)
           pai(pos+1,u+i,Hash+i*pow9[pos]);
       else
         return;
}
void mem(int a)
{
    for(int i=1;i<=num[0];i++)
       dp[a][i]=-1;
}
void print(int day,int Hash)
{
    if(day==0)
      return;
    int Hash2=Hash,now=match[Hash];
    if(rem[day][now][0]==-1)
      Hash2+=pow9[rem[day][now][1]];
    else if(rem[day][now][0]==1)
      Hash2-=pow9[rem[day][now][1]];
    print(day-1,Hash2);
    if(rem[day][now][0]==0)
    {
        printf("HOLD\n");
    }
    else
    {
        if(rem[day][now][0]==-1)
          printf("SELL ");
        else
          printf("BUY ");
        printf("%s\n",s[rem[day][now][1]]);
    }
}
int main()
{
    int i,j,k,k2,ret,a,b,now,to;
    double c;
    pow9[1]=1;
    for(i=2;i<=9;i++)
       pow9[i]=pow9[i-1]*9;
    while(~scanf("%lf%d%d%d",&c,&n,&m,&K))
    {
        for(i=1;i<=m;i++)
        {
            scanf("%s%d%d",s[i],&ret,&ki[i]);
            for(j=1;j<=n;j++)
            {
                scanf("%lf",&val[i][j]);
                val[i][j]*=ret;
            }
        }
        num[0]=0;
        pai(1,0,0);
        mem(0);
        dp[0][1]=c;
        for(i=1;i<=n;i++)
        {
            if(i&1)
              a=0,b=1;
            else
              a=1,b=0;
            mem(b);
            for(j=1;j<=num[0];j++)
            if(dp[a][j]>=0)
            {
                now=j;
                if(dp[a][now]>dp[b][now])
                {
                    dp[b][now]=dp[a][now];
                    rem[i][now][0]=0;
                }
                for(k=1;k<=m;k++)
                {
                    k2=num3[j][k];
                    if(k2>0)
                    {
                        to=match[num[j]-pow9[k]];
                        if(dp[b][to]<dp[a][now]+val[k][i])
                        {
                            dp[b][to]=dp[a][now]+val[k][i];
                            rem[i][to][0]=-1;
                            rem[i][to][1]=k;
                        }
                    }
                    if(k2<ki[k] && num2[j]<K && dp[a][now]>=val[k][i])
                    {
                        to=match[num[j]+pow9[k]];
                        if(dp[b][to]<dp[a][now]-val[k][i])
                        {
                            dp[b][to]=dp[a][now]-val[k][i];
                            rem[i][to][0]=1;
                            rem[i][to][1]=k;
                        }
                    }
                }
            }
        }
        printf("%.2f\n",dp[b][1]);
        print(n,0);
    }
}



