#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#define MAXN 2005
#define MAXM 20000005
#define oo 1000000007
#define ll long long
using namespace std;  
struct Dinic    
{    
      struct node     
      {    
             int x,y,c,next;    
      }line[MAXM];       
      int Lnum,_next[MAXN],dis[MAXN],dp[MAXN];
      bool inqueue[MAXN];
      void initial(int n)     
      {    
             for (int i=0;i<=n;i++) _next[i]=-1;   
             Lnum=-1;    
      }     
      void addline(int x,int y,int c)    
      {    
             line[++Lnum].next=_next[x],_next[x]=Lnum;    
             line[Lnum].x=x,line[Lnum].y=y,line[Lnum].c=c;    
             line[++Lnum].next=_next[y],_next[y]=Lnum;    
             line[Lnum].x=y,line[Lnum].y=x,line[Lnum].c=0;                 
      }    
      bool BFS(int s,int e)    
      {     
             queue<int> Q;    
             while (!Q.empty()) Q.pop();    
             memset(dis,0,sizeof(dis));    
             dis[s]=1,Q.push(s);    
             while (!Q.empty())    
             {    
                   int h,k;    
                   h=Q.front(),Q.pop();    
                   if (h==e) return dis[e];    
                   for (k=_next[h];k!=-1;k=line[k].next)    
                      if (line[k].c && !dis[line[k].y])    
                         dis[line[k].y]=dis[h]+1,Q.push(line[k].y);                     
             }     
             return false;    
      }    
      int dfs(int x,int flow,int e)      
      {          
             if (x==e) return flow;       
             int temp,cost=0;      
             for (int k=_next[x];k!=-1;k=line[k].next)      
             if (line[k].c && dis[line[k].y]==dis[x]+1)      
             {      
                    temp=dfs(line[k].y,min(flow-cost,line[k].c),e);       
                    if (temp)      
                    {      
                           line[k].c-=temp,line[k^1].c+=temp;      
                           cost+=temp;      
                           if (flow==cost) return cost;      
                    }else dis[line[k].y]=-1;      
             }      
             return cost;      
      }      
      int MaxFlow(int s,int e)    
      {    
             int MaxFlow=0;     
             while (BFS(s,e)) MaxFlow+=dfs(s,oo,e);     
             return MaxFlow;    
      } 
}T;
struct node
{
      int x,y,n,m;    
}P[105];
bool A[105][105];
bool judge(int e,int n,int sum)
{
      int i,j,s=n*2+5;
      T.initial(n*2+5);
      for (i=0;i<n;i++) T.addline(s,i<<1,P[i].n),T.addline(i<<1,i<<1|1,P[i].m);
      for (i=0;i<n;i++) 
         for (j=0;j<n;j++)
            if (i!=j && A[i][j])
               T.addline(i<<1|1,j<<1,oo);
      return T.MaxFlow(s,e)==sum;
}
int main() 
{      
      int n,C,i,j,sum,cases;
      double v;
      bool f;  
      scanf("%d",&C);
      for (cases=1;cases<=C;cases++)
      {
               scanf("%d%lf",&n,&v),v*=v,sum=0;
               for (i=0;i<n;i++) 
                   scanf("%d%d%d%d",&P[i].x,&P[i].y,&P[i].n,&P[i].m),sum+=P[i].n;
               for (i=0;i<n;i++)
                   for (j=0;j<n;j++) 
                     if ((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y)<=v) 
                             A[i][j]=true;
                        else A[i][j]=false;
               f=true;
               for (i=0;i<n;i++)
                  if (judge(i<<1,n,sum))
                  {
                         if (f) printf("%d",i);
                           else printf(" %d",i);
                         f=false;
                  } 
               if (f) printf("-1");
               printf("\n");
      }
      return 0;
}


