#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define N 110
#define M 10010
#define INF 0x3f3f3f3f

int n,m,cost,tot;
struct State
{
   int n,d,c;
   bool operator < (const struct State a)const
   {
      if(a.d == d) return a.c < c;
      return a.d < d;
   }
};
struct edge
{
   int u,v,w,c,next;
};
typedef struct State State;
typedef struct edge edge;
int head[N];
int d[N];
edge e[M];

void add(int u , int v , int w , int c)
{
   e[tot].u = u; e[tot].v = v; e[tot].w = w; e[tot].c = c;
   e[tot].next = head[u]; head[u] = tot++;
}

void Dij()
{
   priority_queue<State>q;
   State sta;
   int res = INF ;
   memset(d,0x3f,sizeof(d));
   while(!q.empty()) q.pop();
   sta.d = 0;
   sta.n = 1;
   sta.c = 0;
   q.push(sta);
   while(!q.empty())
   {
      State x,y;
      int u,v,w,d,c;

      x = q.top(); q.pop();
      u = x.n; d = x.d;

      if(u == n)
      {
         res = x.d;
         break;
      }

      for(int k=head[u]; k!=-1; k=e[k].next)
      {
         v = e[k].v; w = e[k].w; c = e[k].c;
         if(x.c + c <= cost) //在花费允许的范围内可以去到这个点
         {
            y.n = v;  y.d = d + w;  y.c = x.c + c;
            q.push(y);
         }
      }
   }
   if(res == INF) printf("-1\n");
   else           printf("%d\n",res);
}

int main()
{
   scanf("%d%d%d",&cost,&n,&m);
   memset(head,-1,sizeof(head));
   tot = 0;
   while(m--)
   {
      int u,v,w,c;
      scanf("%d%d%d%d",&u,&v,&w,&c);
      add(u,v,w,c);
   }
   Dij();
   return 0;
}