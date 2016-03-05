#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int low[30000],num[30000],comfort[30000],total[30000],ans[30000],counter,set[30000],sn,n,m,in[30000],max_ans;
vector<int> group[30000],arc[30000],reverse_arc[30000];
bool visited[30000],instack[30000];
stack<int> connect,start;
void tarjan(int u)
{
    int i,v;
    connect.push(u);
    instack[u]=true;
    visited[u]=true;
    low[u]=num[u]=++counter;
    for(i=0;i<arc[u].size();i++)
    {
        v=arc[u][i];
        if(!visited[v])
        {
            tarjan(v);
            if(low[u]>low[v])
                low[u]=low[v];
        }
        else if(instack[v] && low[u]>num[v])
            low[u]=num[v];
    }
    if(num[u]==low[u])
    {
        total[sn]=0;
        do
        {
            v=connect.top();
            connect.pop();
            set[v]=sn;
            group[sn].push_back(v);
            instack[v]=false;
            if(comfort[v]>0)
                total[sn]+=comfort[v];
        }while(u!=v);
        ans[sn]=total[sn];
        sn++;
    }
}
void backtrace(int u)//on condiction of indegree[u]==0
{
    int i,v;
    for(i=0;i<reverse_arc[u].size();i++)
    {
        v=reverse_arc[u][i];
        if(ans[v]<ans[u]+total[v])
            ans[v]=ans[u]+total[v];
        in[v]--;
        if(in[v]==0)
            start.push(v);
    }
    if(max_ans<ans[u])
        max_ans=ans[u];
}
int main()
{
    int i,u,v;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            visited[i]=false;
            instack[i]=false;
            scanf("%d",&comfort[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            arc[u].push_back(v);
        }
        counter=sn=0;
        for(i=0;i<n;i++)
        {
            if(!visited[i])
                tarjan(i);
        }
        //reverse_arc
        for(i=0;i<sn;i++)
            in[i]=0;
        for(u=0;u<n;u++)
        {
            for(i=0;i<arc[u].size();i++)
            {
                v=arc[u][i];
                if(set[v]!=set[u] && find(reverse_arc[set[v]].begin(),reverse_arc[set[v]].end(),set[u])==reverse_arc[set[v]].end())
                {
                    reverse_arc[set[v]].push_back(set[u]);
                    in[set[u]]++;
                }
            }
        }
        for(i=0;i<sn;i++)
        {
            if(in[i]==0)
                start.push(i);
        }
        max_ans=0;
        while(!start.empty())
        {
            u=start.top();
            start.pop();
            backtrace(u);
        }
        for(i=0;i<sn;i++)
        {
            reverse_arc[i].clear();
            group[i].clear();
        }
        for(i=0;i<n;i++)
            arc[i].clear();
        printf("%d\n",max_ans);
    }
    return 0;
}



