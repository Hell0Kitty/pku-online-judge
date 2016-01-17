#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<set>
using namespace std;
const int MAX=20005;
const int inf=1<<30;
#define ll long long
#define PII pair<int,int>
#define MP(x,y) make_pair(x,y)
int a[505][26],b[505][26],n,m,S,from[505],to[505],c[505];
bool vis[505][505];
bool bfs(int s1,int s2)
{
    memset(vis,0,sizeof(vis));
    vis[s1][s2]=1;
    queue<pair<int,int> >que;
    que.push(MP(s1,s2));
    int u1,u2;
    while(!que.empty())
    {
        PII now=que.front();
        que.pop();
        int x1=now.first,x2=now.second;
        for(int i=0;i<26;i++)
        {
            if(a[x1][i]!=-1)
            {
                u1=a[x1][i];
                u2=b[x2][i];
                if(u2==-1)
                    u2=x2;
                if(u2==0)
                    return false;
                if(!vis[u1][u2])
                {
                    vis[u1][u2]=1;
                    que.push(MP(u1,u2));
                }

            }
        }
    }
    return true;
}
char str[300];
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&S);
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        int s1=S;
        for(int x=0;x<m;x++)
        {
            scanf("%d%s%d",&from[x],str,&to[x]);
            c[x]=str[0]-'a';
            a[from[x]][c[x]]=to[x];
        }
        scanf("%d%d%d",&n,&m,&S);
        for(int x=0;x<m;x++)
        {
            scanf("%d%s%d",&from[x],str,&to[x]);
            if(to[x]==-1)
                to[x]++;
            c[x]=str[0]-'a';
            b[from[x]][c[x]]=to[x];
        }
        if(bfs(s1,S))
            puts("satisfied");
        else
            puts("violated");
    }
    return 0;
}




