# include <stdio.h>
# include <set>
# include <vector>
# include <string.h>
# include <iostream>
# include <algorithm>
using namespace std;
 struct node
 {
     char s[10],e[10];
    int nxt;
 };
 int n,m;
 vector<node> data[100001];
 vector<int> l[100001];
 int s[100001];
 int g[1000005],nxt[2000005],v[2000005],co=0,dp[1000005];
 int change(char *ori)
 {
     char tmp[10];
    strcpy(tmp,ori);
     return atoi(strtok(tmp,":"))*60+atoi(strtok(NULL,":"));
 }
 void addedge(int s,int e)
 {
     v[co]=e;
     nxt[co]=g[s];
     g[s]=co++;
 }
 int solve(int pos)
 {
     if(dp[pos]!=-1) return dp[pos];
     else if(g[pos]==-1&&pos>=s[n-1]) return dp[pos]=l[n][pos-s[n-1]];
    else
    {
       dp[pos]=(pos>=s[n-1]?l[n][pos-s[n-1]]:0xfffffff);
         for(int p=g[pos];p!=-1;p=nxt[p])
             dp[pos]=min(dp[pos],solve(v[p]));
        return dp[pos];

     }
 }
 void print(int time)
 {
     printf("%s%d:%s%d",time/60<10?"0":"",time/60,time%60<10?"0":"",time%60);
 }
 int main()
 {
     scanf("%d",&n);
     s[0]=0;
     for(int i=1;i<=n;i++)
     {
         scanf("%d",&m);
         while(m--)
         {
             node tmp;
             scanf("%s%s%d",tmp.s,tmp.e,&tmp.nxt);
             data[i].push_back(tmp);
             l[i].push_back(change(tmp.s));
             if(tmp.nxt==n) l[n].push_back(change(tmp.e));
         }
         sort(l[i].begin(),l[i].end());
         vector<int>::iterator end=unique(l[i].begin(),l[i].end());
         while(l[i].end()!=end) l[i].pop_back();
         s[i]=s[i-1]+l[i].size();
     }
     memset(g,-1,sizeof(g));
     memset(dp,-1,sizeof(dp));
     co=0;
     for(int i=1;i<=n;i++)
     {
        for(int j=s[i-1];j<s[i]-1;j++)
              addedge(j,j+1);
         for(int j=0;j<data[i].size();j++)
             if(lower_bound(l[data[i][j].nxt].begin(),l[data[i][j].nxt].end(),change(data[i][j].e))!=l[data[i][j].nxt].end())
                 addedge(s[i-1]+lower_bound(l[i].begin(),l[i].end(),change(data[i][j].s))-l[i].begin(),s[data[i][j].nxt-1]+lower_bound(l[data[i][j].nxt].begin(),l[data[i][j].nxt].end(),change(data[i][j].e))-l[data[i][j].nxt].begin());

     }
     vector<pair<int,int> >ans;
    for(int i=s[1]-1;i>=0;i--)
        if(solve(i)!=0xfffffff&&(ans.empty()||solve(i)<ans.back().second))
            ans.push_back(make_pair(l[1][i],solve(i)));
    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>=0;i--)
    {
        print(ans[i].first);
        printf(" ");
        print(ans[i].second);
        printf("\n");
    }
    return 0;

}


