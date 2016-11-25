#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n,cnt,pa[100000],ans[10000],ncnt,adj[11000][100],num[100000],f[100][11000],cont[100];
double v1,v2,ru,ru1,ru2,dp[100000],t1[100],t2[100],eps=1e-7;
struct point
{
       double x,y;
       int id,id1,id2;
};
point list[100000];
bool visit[100000];
double dist(double x1,double y1,double x2,double y2)
{
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double dijkstra()
{
       int i,j,s,p,q,u,id;
       double in;
       for(i=0;i<cnt;i++)
          dp[i]=1000000000;
       dp[0]=0.000;
       memset(visit,false,sizeof(visit));
       while(true)
       {
           in=1000000000;
           for(i=0;i<cnt;i++)
           {
               if(visit[i]==false&&in>dp[i])
               {
                   u=i;
                   in=dp[i];
               }
           } 
           if(u==1)
              return dp[u];
           visit[u]=true;
           for(int ii=0;ii<num[u];ii++)//for(i=0;i<cnt;i++)
           {
              i=adj[u][ii];
              double val,vs1,vs2;
              if(list[u].id==list[i].id)
                 val=dist(list[u].x,list[u].y,list[i].x,list[i].y)/(v1+v2);
              else
              {
                 if(list[u].id==0||list[u].id==n+1)
                    vs1=0;
                 else
                   vs1=t2[list[u].id];
                 if(list[i].id==0||list[i].id==n+1)
                    vs2=0;
                 else
                    vs2=t1[list[i].id];
                 val=vs1+vs2+dist(list[u].x,list[u].y,list[i].x,list[i].y)/v1;
              }
              if(dp[i]>dp[u]+val)
              {
                 dp[i]=dp[u]+val;
                 pa[i]=u;
              }
           }
           id=list[u].id;
           for(int ii=0;ii<cont[id];ii++)
           {
               i=f[id][ii];
              double val,vs1,vs2;
              if(list[u].id==list[i].id)
                 val=dist(list[u].x,list[u].y,list[i].x,list[i].y)/(v1+v2);
              else
              {
                 if(list[u].id==0||list[u].id==n+1)
                    vs1=0;
                 else
                   vs1=t2[list[u].id];
                 if(list[i].id==0||list[i].id==n+1)
                    vs2=0;
                 else
                    vs2=t1[list[i].id];
                 val=vs1+vs2+dist(list[u].x,list[u].y,list[i].x,list[i].y)/v1;
              }
              if(dp[i]>dp[u]+val)
              {
                 dp[i]=dp[u]+val;
                 pa[i]=u;
              }   
           }
       }
}
int main()
{
    double xa,ya,xb,yb,v,x1[100],y1[100],x2[100],y2[100];
    int i,j,s,p,q;
    scanf("%d",&n);
    scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&v1,&v2);
    for(i=1;i<=n;i++)
        scanf("%lf%lf%lf%lf%lf%lf",&x1[i],&y1[i],&x2[i],&y2[i],&t1[i],&t2[i]);  
    swap(v1,v2);
    cnt=0;
    list[cnt].x=xa;
    list[cnt].y=ya;
    list[cnt].id1=list[cnt].id2=list[cnt].id=0;
    cnt++;
    list[cnt].x=xb;
    list[cnt].y=yb;
    list[cnt].id1=list[cnt].id2=list[cnt].id=n+1;
    cnt++;
    v=sqrt(2*v1*v2+v2*v2);
    memset(num,0,sizeof(num));
    memset(cont,0,sizeof(cont));
    adj[0][num[0]++]=1;
    adj[1][num[1]++]=0;
    for(i=1;i<=n;i++)
    {
        ru=v1*((x2[i]-x1[i])*(ya-y1[i])-(y2[i]-y1[i])*(xa-x1[i]))/v-(x1[i]-xa)*(x2[i]-x1[i])-(y1[i]-ya)*(y2[i]-y1[i]);
        ru/=((x2[i]-x1[i])*(x2[i]-x1[i])+(y2[i]-y1[i])*(y2[i]-y1[i]));
        list[cnt].x=x1[i]+ru*(x2[i]-x1[i]);
        list[cnt].y=y1[i]+ru*(y2[i]-y1[i]);
        list[cnt].id=i;
        list[cnt].id1=0;
        list[cnt++].id2=i;
        f[i][cont[i]++]=cnt-1;
        adj[cnt-1][num[cnt-1]++]=0;
        adj[0][num[0]++]=cnt-1;
        ru=-v1*((x2[i]-x1[i])*(ya-y1[i])-(y2[i]-y1[i])*(xa-x1[i]))/v-(x1[i]-xa)*(x2[i]-x1[i])-(y1[i]-ya)*(y2[i]-y1[i]);
        ru/=((x2[i]-x1[i])*(x2[i]-x1[i])+(y2[i]-y1[i])*(y2[i]-y1[i])); 
        list[cnt].x=x1[i]+ru*(x2[i]-x1[i]);
        list[cnt].y=y1[i]+ru*(y2[i]-y1[i]);
        list[cnt].id=i;
        list[cnt].id1=0;
        list[cnt++].id2=i;
        f[i][cont[i]++]=cnt-1;  
        adj[cnt-1][num[cnt-1]++]=0;
        adj[0][num[0]++]=cnt-1;
        ru=v1*((x2[i]-x1[i])*(yb-y1[i])-(y2[i]-y1[i])*(xb-x1[i]))/v-(x1[i]-xb)*(x2[i]-x1[i])-(y1[i]-yb)*(y2[i]-y1[i]);
        ru/=((x2[i]-x1[i])*(x2[i]-x1[i])+(y2[i]-y1[i])*(y2[i]-y1[i]));
        list[cnt].x=x1[i]+ru*(x2[i]-x1[i]);
        list[cnt].y=y1[i]+ru*(y2[i]-y1[i]);
        list[cnt].id=i;
        list[cnt].id1=i;
        list[cnt++].id2=n+1;
        f[i][cont[i]++]=cnt-1;
        adj[cnt-1][num[cnt-1]++]=1;
        adj[1][num[1]++]=cnt-1;
        ru=-v1*((x2[i]-x1[i])*(yb-y1[i])-(y2[i]-y1[i])*(xb-x1[i]))/v-(x1[i]-xb)*(x2[i]-x1[i])-(y1[i]-yb)*(y2[i]-y1[i]);
        ru/=((x2[i]-x1[i])*(x2[i]-x1[i])+(y2[i]-y1[i])*(y2[i]-y1[i])); 
        list[cnt].x=x1[i]+ru*(x2[i]-x1[i]);
        list[cnt].y=y1[i]+ru*(y2[i]-y1[i]);
        list[cnt].id=i;
        list[cnt].id1=i;
        list[cnt++].id2=n+1;
        f[i][cont[i]++]=cnt-1;
        adj[cnt-1][num[cnt-1]++]=1;
        adj[1][num[1]++]=cnt-1;
    }
    for(i=1;i<=n;i++)
      for(j=i+1;j<=n;j++)
      {
          double a1,b1,c1,a2,b2,c2;
          for(s=0;s<4;s++)
          {
              a1=v*((x2[i]-x1[i])*(x2[i]-x1[i])+(y2[i]-y1[i])*(y2[i]-y1[i]));
              if(s==0||s==2)
              {
                  b1=-v*((x2[i]-x1[i])*(x2[j]-x1[j])+(y2[i]-y1[i])*(y2[j]-y1[j]))-v1*((x2[i]-x1[i])*(y2[j]-y1[j])-(y2[i]-y1[i])*(x2[j]-x1[j]));
                  c1=v*((x2[i]-x1[i])*(x1[i]-x1[j])+(y2[i]-y1[i])*(y1[i]-y1[j]))-v1*((y2[i]-y1[i])*(x1[i]-x1[j])-(x2[i]-x1[i])*(y1[i]-y1[j]));
              }
              else
              {
                  b1=-v*((x2[i]-x1[i])*(x2[j]-x1[j])+(y2[i]-y1[i])*(y2[j]-y1[j]))+v1*((x2[i]-x1[i])*(y2[j]-y1[j])-(y2[i]-y1[i])*(x2[j]-x1[j]));
                  c1=v*((x2[i]-x1[i])*(x1[i]-x1[j])+(y2[i]-y1[i])*(y1[i]-y1[j]))+v1*((y2[i]-y1[i])*(x1[i]-x1[j])-(x2[i]-x1[i])*(y1[i]-y1[j]));
              }
              b2=-v*((x2[j]-x1[j])*(x2[j]-x1[j])+(y2[j]-y1[j])*(y2[j]-y1[j]));
              if(s==0||s==1)
              {
                   a2=v*((x2[j]-x1[j])*(x2[i]-x1[i])+(y2[j]-y1[j])*(y2[i]-y1[i]))-v1*((x2[i]-x1[i])*(y2[j]-y1[j])-(y2[i]-y1[i])*(x2[j]-x1[j]));
                   c2=v*((x2[j]-x1[j])*(x1[i]-x1[j])+(y2[j]-y1[j])*(y1[i]-y1[j]))-v1*((x1[i]-x1[j])*(y2[j]-y1[j])-(y1[i]-y1[j])*(x2[j]-x1[j]));
              }
              else
              {
                   a2=v*((x2[j]-x1[j])*(x2[i]-x1[i])+(y2[j]-y1[j])*(y2[i]-y1[i]))+v1*((x2[i]-x1[i])*(y2[j]-y1[j])-(y2[i]-y1[i])*(x2[j]-x1[j]));
                   c2=v*((x2[j]-x1[j])*(x1[i]-x1[j])+(y2[j]-y1[j])*(y1[i]-y1[j]))+v1*((x1[i]-x1[j])*(y2[j]-y1[j])-(y1[i]-y1[j])*(x2[j]-x1[j]));
              }
              ru1=(c2*b1-c1*b2)/(a1*b2-a2*b1);
              ru2=(c2*a1-c1*a2)/(b1*a2-b2*a1);
              list[cnt].x=x1[i]+ru1*(x2[i]-x1[i]);
              list[cnt].y=y1[i]+ru1*(y2[i]-y1[i]);
              list[cnt].id1=i;
              list[cnt].id2=j;
              list[cnt++].id=i;
              f[i][cont[i]++]=cnt-1;
              adj[cnt-1][num[cnt-1]++]=cnt;
              list[cnt].x=x1[j]+ru2*(x2[j]-x1[j]);
              list[cnt].y=y1[j]+ru2*(y2[j]-y1[j]);
              list[cnt].id1=i;
              list[cnt].id2=j;
              list[cnt++].id=j;
              f[j][cont[j]++]=cnt-1;
              adj[cnt-1][num[cnt-1]++]=cnt-2;
          }
      }
    printf("%.6lf\n",dijkstra());
    int u=1;
    ncnt=0;
    while(u!=0)
    {
        ans[ncnt++]=u;
        u=pa[u];
    }
    printf("%d\n",ncnt);
    for(i=ncnt-1;i>=0;i--)
    {
        int val,id=ans[i];
        if(i==ncnt-1||list[ans[i]].id!=list[ans[i+1]].id)
           val=0;
        else
           val=list[id].id;
        printf("%d %.6lf %.6lf\n",val,list[id].x+eps,list[id].y+eps);
    }
    return 0;
}




