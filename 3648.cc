#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

const int MAXN=200;
char color[MAXN];
bool visit[MAXN];
queue<int>q1,q2;

vector<vector<int> >adj; 
vector<vector<int> >radj;
vector<vector<int> >dag;
int n,m,cnt;

int id[MAXN],order[MAXN],ind[MAXN];

void dfs(int u)
{
    visit[u]=true;
    int i,len=adj[u].size();
    for(i=0;i<len;i++)
      if(!visit[adj[u][i]])
        dfs(adj[u][i]);
    order[cnt++]=u;
}
void rdfs(int u)
{
    visit[u]=true;
    id[u]=cnt;
    int i,len=radj[u].size();
    for(i=0;i<len;i++)
      if(!visit[radj[u][i]])
        rdfs(radj[u][i]);
}
void korasaju()
{
    int i;
    memset(visit,false,sizeof(visit));
    for(cnt=0,i=0;i<2*n;i++)
      if(!visit[i])
        dfs(i);
    memset(id,0,sizeof(id));
    memset(visit,false,sizeof(visit));
    for(cnt=0,i=2*n-1;i>=0;i--)
      if(!visit[order[i]])
      {
          cnt++;
          rdfs(order[i]);
      }
}
bool solvable()
{
    for(int i=0;i<n;i++)
      if(id[2*i]==id[2*i+1])
        return false;
   return true;
}
void topsort()
{
    int i,j,len,now,p,pid;
    while(!q1.empty())
    {
        now=q1.front();
        q1.pop();
        if(color[now]!=0)continue;
        color[now]='R';
        ind[now]=-1;
        for(i=0;i<2*n;i++)
        {
            if(id[i]==now)
            {

                p=i^1;
                pid=id[p];
                q2.push(pid);
                while(!q2.empty())
                {
                    pid=q2.front();
                    q2.pop();
                    if(color[pid]=='B')continue;
                    color[pid]='B';
                    len=dag[pid].size();
                    for(j=0;j<len;j++)
                        q2.push(dag[pid][j]);
                }
            }
        }
        len=dag[now].size();
        for(i=0;i<len;i++)
        {
            ind[dag[now][i]]--;
            if(ind[dag[now][i]]==0)
              q1.push(dag[now][i]);
        }
    }
}

int main()
{
    int x,y;
    char c1,c2;
    int i,j;
    int len;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        adj.assign(2*n,vector<int>());
        radj.assign(2*n,vector<int>());
        while(m--)
        {
            scanf("%d%c%d%c",&x,&c1,&y,&c2);
            if(c1=='w')x=2*x;
            else x=2*x+1;
            if(c2=='w')y=2*y;
            else y=2*y+1;
            if(x!=(y^1))
            {
                adj[x].push_back(y^1);
                adj[y].push_back(x^1);
                radj[y^1].push_back(x);
                radj[x^1].push_back(y);
            }

        }
        adj[0].push_back(1);
        radj[1].push_back(0);
        korasaju();
        if(!solvable())printf("bad luck\n");
        else
        {
            dag.assign(cnt+1,vector<int>());
            memset(ind,0,sizeof(ind));
            memset(color,0,sizeof(color));
            for(i=0;i<2*n;i++)
            {
                len=adj[i].size();
                for(j=0;j<len;j++)
                  if(id[i]!=id[adj[i][j]])
                  {
                      dag[id[adj[i][j]]].push_back(id[i]);
                      ind[id[i]]++;
                  }
            }
            for(i=1;i<=cnt;i++)
              if(ind[i]==0)
                 q1.push(i);
            topsort();
            for(i=1;i<n;i++)
            {
                if(i>1)printf(" ");
                if(color[id[2*i]]=='R')printf("%dh",i);

                else printf("%dw",i);
            }
            printf("\n");
        }
    }
    return 0;
}


