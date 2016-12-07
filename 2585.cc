#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<string>
#include <vector>
#define INF 1E9
using namespace std;
vector<int> map[16];
bool ok[10][10];
int vis[10];
void init()
{
    int i,now=0;
    for(i=1;i<10&&now<15;i++)
    {
        map[now].push_back(i);
        map[now+1].push_back(i);
        map[now+4].push_back(i);
        map[now+5].push_back(i);
        now++;
        if(i%3==0)now++;
    }
    return;
}
bool dfs(int m)
{
    int i;
    vis[m]=-1;
    for(i=1;i<10;i++)
    {
        if(!ok[m][i])continue;
        if(vis[i]<0)return 0;
        if(!vis[i]&&!dfs(i))return 0;
    }
    vis[m]=1;
    return 1;
}
bool topo()
{
    for(int i=1;i<10;i++)
      if(!vis[i]&&!dfs(i))return 0;
    return 1;
}
int main()
{
    init();
    string s;
    int i,t,j;
    while(cin>>s&&s!="ENDOFINPUT")
    {
        memset(vis,0,sizeof(vis));
        memset(ok,0,sizeof(ok));
        for(i=0;i<16;i++)
        {
           scanf("%d",&t);
           for(j=0;j<map[i].size();j++)
           {
               if(t==map[i][j])continue;
               ok[t][map[i][j]]=1;
           }
        }
        if(topo())cout<<"THESE WINDOWS ARE CLEAN"<<endl;
        else cout<<"THESE WINDOWS ARE BROKEN"<<endl;
        cin>>s;
    }
}


