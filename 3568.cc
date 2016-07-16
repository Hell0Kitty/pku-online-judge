#include<iostream>
#include<cmath>
using namespace std;
bool mark[2001],ok;
double d,vd,r,w,vs,ans,di,wi;
int fi,n,m;
struct point
{
    double x,y;
};
point shark[2001];
bool dfs(int id)
{
     bool res=true;
     if(shark[id].x<r)
        return false;
     ans=max(ans,(d-shark[id].x+vd*shark[id].y+r*sqrt(1+vd*vd))/vd/vs);
     mark[id]=true;
     for(int i=0;i<m;i++)
     {
          ok=sqrt((shark[id].x-shark[i].x)*(shark[id].x-shark[i].x)+(shark[id].y-shark[i].y)*(shark[id].y-shark[i].y))<2*r;
          if(fabs(-shark[i].x+vd*shark[i].y+shark[id].x-vd*shark[id].y-r*sqrt(1+vd*vd))/sqrt(1+vd*vd)<r)
               if(vd*shark[i].x+shark[i].y-vd*shark[id].x-shark[id].y>0)
                  ok=true;
          if(ok&&!mark[i])
             res&=dfs(i);
     }
     return res;
}
int main()
{
    int i,j;
    scanf("%lf%lf%d%lf%lf%lf",&d,&vd,&n,&r,&w,&vs);
    vd/=vs;
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf%d",&di,&wi,&fi);
        shark[m].x=d-di;
        shark[m++].y=(1+fi)*w-fi*wi;
        for(j=1;j<=60;j++)
        {
            shark[m].y=shark[m-1].y+2*w;
            shark[m++].x=shark[m-1].x;
        }
    } 
    ans=d/vd/vs;
    for(i=0;i<m;i++)
        if(fabs(-shark[i].x+vd*shark[i].y)/sqrt(1+vd*vd)<r&&!mark[i]&&!dfs(i))
        {
           puts("IMPOSSIBLE");
           return 0;
        } 
    printf("%f\n",ans); 
    return 0;
}
