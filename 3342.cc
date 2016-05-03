#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
#define max(a,b) a>b?a:b
const int maxn  =  201;
vector<int> edge[maxn];
int dp[210][2];
void dfs(int u,int p)
{
    int i,j;
    dp[u][1]=1;
    dp[u][0]=0;
    for(i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==p) continue;
        dfs(v,u);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][0],dp[v][1]);
    }
}
int main(){
     map<string,int> mm;
     int n,i,tot;
     char bos[110],a[110],b[110];
     while(scanf("%d",&n),n)
     {
         tot=0;
         for(i=0;i<=200;i++) edge[i].clear();
         mm.clear();
         scanf("%s",bos);mm[bos]=tot++;
         for(i=0;i<n-1;i++)
         {
             scanf("%s%s",a,b);
             if(mm.find(a)==mm.end()) mm[a]=tot++;
             if(mm.find(b)==mm.end()) mm[b]=tot++;
             edge[mm[b]].push_back(mm[a]);
         }
         dfs(0,0);bool flag=true;
         for(i=0;i<n;i++)
         {
             flag=true;
             if(dp[i][0]>dp[i][1])
             {
                 for(int j=0;j<edge[i].size();j++)
                 {
                     if(dp[edge[i][j]][0]==dp[edge[i][j]][1])
                     {
                         flag=false;
                         break;
                     }
                 }
             }
             if(!flag) break;
         }
         printf("%d",max(dp[0][0],dp[0][1]));
         if(dp[0][0]==dp[0][1]||!flag) printf(" No\n");
         else printf(" Yes\n");
     }
     return 0;
}



