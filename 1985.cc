#include<cstdio>

#include<cstring>

#include<algorithm>

#include<queue>

using namespace std;

const int N=40005;

int head[N],nc;

struct edge

{

    int to,cost,next;

}edge[N*3];

void add(int a,int b,int c)

{

    edge[nc].to=b;edge[nc].next=head[a];edge[nc].cost=c;head[a]=nc++;

    edge[nc].to=a;edge[nc].next=head[b];edge[nc].cost=c;head[b]=nc++;

}

struct data

{

    int id;

    int val;

    bool operator<(const data &next)const

    {

        return val<next.val;

    }

    data(int _id,int _val){id=_id;val=_val;}

    data(){}

};

int dist[N];

bool vis[N],mark[N];

priority_queue<data> Q;

int diji(int s)

{

    memset(dist,-1,sizeof(dist));

    memset(vis,false,sizeof(vis));

    dist[s]=0;

    while(!Q.empty())

        Q.pop();

    Q.push(data(s,0));

    int id,mm=-1,last=s;

    data a;

    while(!Q.empty())

    {

        a=Q.top();

        Q.pop();

        if(vis[a.id]||dist[a.id]!=a.val)

            continue;

        if(mm<a.val)

            mm=a.val,id=a.id;

        mark[a.id]=vis[a.id]=true;

        for(int i=head[a.id];i!=-1;i=edge[i].next)

        {

            int t=edge[i].to;

            if(!vis[t]&&dist[t]<dist[a.id]+edge[i].cost)

            {

                dist[t]=dist[a.id]+edge[i].cost;

                Q.push(data(t,dist[t]));

            }

        }

    }

    return id;

}

int main()

{

    int n,m;

    while(scanf("%d%d",&n,&m)!=EOF)

    {

        memset(head,-1,sizeof(head));

        nc=0;

        for(int i=0;i<m;i++)

        {

            int a,b,c;

            char op[3];

            scanf("%d%d%d%s",&a,&b,&c,op);

            add(a,b,c);

        }

        memset(mark,false,sizeof(mark));

        int ans=0;

        for(int i=1;i<=n;i++)

            if(!mark[i])

                ans=max(ans,dist[diji(diji(i))]);

        printf("%d\n",ans);

    }

    return 0;

}



