#include<iostream>
#include<fstream>
#include<queue>
#include <cmath>
#include<cstring>
using namespace std;

int n,m;
int map[65][35];
int sx[65],sy[35];//起点
int end[65][35];//终点
int top;
int d[2][65][35];//d[i][j][k]左脚（0）或右脚（1）踏进i行j列的最小时间

struct node
{
   int s,t;
   int kind;//走的类型
   int weight;
};
struct cmp//优先队列weight从小到大
{
  bool operator()(node a,node b)
  {
    return a.weight>b.weight;
  }
};
int v[2][61][31];
void spfa()
{
    int i,j,k,s,t;
    for(i=0;i<=1;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=m;k++)
                d[i][j][k]=10000000;
    memset(v,0,sizeof(v));
    priority_queue<node, vector<node>,cmp>q;
    node a;
    for(i=1;i<=top;i++)
    {
        d[0][sx[i]][sy[i]]=0;
        d[1][sx[i]][sy[i]]=0;
        v[0][sx[i]][sy[i]]=1;
        v[0][sx[i]][sy[i]]=1;
        a.kind=0;
        a.s=sx[i];
        a.t=sy[i];
        a.weight=0;
        q.push(a);
        a.kind=1;
        q.push(a);
    }
    int ans=-1;
    while(!q.empty())
    {
        a=q.top();
        q.pop();
        if(end[a.s][a.t])//找到终点
        {
            if(ans==-1)
             ans=a.weight;
            else
             ans=min(ans,a.weight);
            continue;
        }
        v[a.kind][a.s][a.t]=0;
        i=a.kind;
        s=a.s;
        t=a.t;
        if(i==0)//踏左脚
        {
            for(j=max(1,s-2);j<=n&&j<=s+2;j++)
                for(k=t+1;k<=m&&k<=t+3;k++)
                    if(abs(j-s*1.0)+abs(k-t*1.0)<=3.0&&map[j][k]!=-1)
                    {
                        if(d[1][j][k]>a.weight+map[j][k])
                        {
                            d[1][j][k]=a.weight+map[j][k];
                            if(!v[1][j][k])
                            {
                                node b;
                                b.kind=1;
                                b.s=j;
                                b.t=k;
                                b.weight=d[1][j][k];
                                q.push(b);
                                v[1][j][k]=1;
                            }
                        }
                    }
        }
        else//踏右脚
        {
            for(j=max(1,s-2);j<=s+2&&j<=n;j++)
                for(k=max(1,t-3);k<=t-1;k++)
                    if(abs(j*1.0-s)+abs(k*1.0-t)<=3&&map[j][k]!=-1)
                    {
                        if(d[0][j][k]>a.weight+map[j][k])
                        {
                            d[0][j][k]=a.weight+map[j][k];
                            if(!v[0][j][k])
                            {
                                node b;
                                b.kind=0;
                                b.s=j;
                                b.t=k;
                                b.weight=d[0][j][k];
                                q.push(b);
                                v[0][j][k]=1;
                            }
                        }
                    }
        }
    }
    cout<<ans<<endl;
}

void read()
{
    int i,j,k;
    char c;
    while(cin>>m>>n)
    {
        if(n==0&&m==0) return;
        memset(end,0,sizeof(end));
        top=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='X')
                    map[i][j]=-1;
                if(c=='S')
                {
                    map[i][j]=0;
                    sx[++top]=i;
                    sy[top]=j;
                }
                if(c=='T')
                {
                    map[i][j]=0;
                    end[i][j]=1;
                }
                if(c>='1'&&c<='9')
                    map[i][j]=c-'0';
            }
        spfa();
    }
}

int main()
{
    read();
    return 0;
}



