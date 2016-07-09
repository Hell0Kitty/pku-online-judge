#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <memory> 
#include <cctype> 
#include <string> 
#include <vector>
#include <map> 
#include <set> 
#include <algorithm> 
#include <cstring>
using namespace std;
const int add=200;
int max_s=200,left_=1,right_=2,up=4,down=8,st[401][401],ps,b[2][401][401];
struct point
{
    int x,y;
};
point ll[2][1000],rr[2][1000];
struct rectangle
{
    int x1,y1,x2,y2;
};
rectangle rec[100000];
int n,node[2],_out_=0,_side1_=1,_side2_=2,_trace_=3,_in_=4;
int l[1000],r[1000],num_rec;
bool gao,mat[1000][1000],vl[1000],vr[1000],in[2][401][401];
bool tr[401][401],r_tr[401][401],out[401][401];
point pt[444];
bool dfs(int id)
{
     int i,j,s,p,q;
     vl[id]=true;
     for(i=0;i<node[1];i++)
     {
         if(mat[id][i]) 
            vr[i]=true;
         if(mat[id][i]&&(r[i]<0||(!vl[r[i]]&&dfs(r[i]))))
         {
             l[id]=i;
             r[i]=id;
             return true;
         }
     }
     return false;
}
bool test(int state,int flag)
{
     return (state&flag)==flag;
}
void draw(int x1,int y1,int x2,int y2)
{
     int i,j,s,p,q;
     if(y1==y2)
     {
        for(i=min(x1,x2);i<max(x1,x2);i++)
        {
            st[i+add][y1+add]|=left_;
            st[i+1+add][y1+add]|=right_;
        }
     }
     else
     {
         for(i=min(y1,y2);i<max(y1,y2);i++)
         {
            st[x1+add][i+add]|=down;
            st[x1+add][i+1+add]|=up; 
         }
     }
}
void get_node()
{
     int i,j,s,p,q,x,y,sx,sy,px,py;
     memset(b,-1,sizeof(b));
     node[0]=node[1]=0;
     memset(tr,false,sizeof(tr));
     memset(r_tr,false,sizeof(r_tr));
     memset(out,false,sizeof(out));
     for(s=0;s<2;s++)
     {
        for(i=-max_s;i<=max_s;i++)
        {
          ps=_out_;
          for(j=-max_s;j<=max_s;j++)
          {
             gao=false;
             x=i;
             y=j;
             if(s==1)
                swap(x,y);
             int nle,ndo,nri;
             nle=left_;
             ndo=down;
             nri=right_;
             if(s==1)
             {
                 nle=down;
                 ndo=left_;
                 nri=up;
             }
             if(ps==_out_)
             {
                int vv=test(st[x+add][y+add],nle),vp=test(st[x+add][y+add],ndo);
                int vx=test(st[x+add][y+add],nri);
                if(vv&&vp)
                    ps=_side1_;
                else if(vp)
                {
                    ps=_side2_;
                }
                if(vv&&!vp)
                    ps=_in_;
             }
             else if(ps==_side1_)
             {
                int vv=test(st[x+add][y+add],nle),vp=test(st[x+add][y+add],nri);
                if(vv)
                {
                    ps=_out_;
                    out[x+add][y+add]=true;
                }
                else if(vp)
                {
                    ps=_trace_;
                    if(s==0) 
                      tr[i+add][j+add]=true;
                }
             }
             else if(ps==_side2_)
             {
                int vv=test(st[x+add][y+add],nle),vp=test(st[x+add][y+add],nri);
                if(vv)
                {
                   ps=_trace_;
                   if(s==0) 
                      tr[i+add][j+add]=true;
                }
                else if(vp)
                {
                   ps=_out_;
                   out[x+add][y+add]=true;
                }
             }
             else if(ps==_in_)
             {
                 int vv=test(st[x+add][y+add],nle),vp=test(st[x+add][y+add],ndo);
                 int vx=test(st[x+add][y+add],nri);
                 if(vv&&vp)
                 {
                    ps=_side2_;
                    out[x+add][y+add]=true;
                    if(s==0)
                       r_tr[x+add][y+add]=true;
                 }
                 else if(vp)
                 {
                    ps=_side1_;
                    if(s==0)
                       r_tr[x+add][y+add]=true;
                 }
                 else if(vv||vx)
                 {
                    ps=_out_;
                    out[x+add][y+add]=true;
                 }
             }
             else
             {
                 int vv=test(st[x+add][y+add],nle),vp=test(st[x+add][y+add],ndo);
                 int vx=test(st[x+add][y+add],nri);
                 if(vp)
                 {
                    gao=true;
                    if(vv)
                    {
                      ps=_side2_;
                      out[x+add][y+add]=true;
                    }
                    else
                       ps=_side1_;
                    if(s==0) 
                      r_tr[i+add][j+add]=true;
                }
                else if(vv||vx)
                {
                   out[x+add][y+add]=true;
                   ps=_out_;
                }
             }
             if(gao)
             {
                 ll[s][node[s]].x=sx;
                 ll[s][node[s]].y=sy;
                 rr[s][node[s]].x=x;
                 rr[s][node[s]].y=y;
                 for(px=sx;px<=x;px++)
                    for(py=sy;py<=y;py++)
                        b[s][px+add][py+add]=node[s];
                 node[s]++;
             }
             if(ps!=_trace_)
             {
                 sy=j+1;
                 sx=i;
                 if(s==1)
                    swap(sx,sy);
             }
         }
       }
     }
     for(i=0;i<node[0];i++)
        for(j=0;j<node[1];j++)
           mat[i][j]=false;
     for(i=-max_s;i<=max_s;i++)
        for(j=-max_s;j<=max_s;j++)
        {
            if(b[0][i+add][j+add]>=0&&b[1][i+add][j+add]>=0)
              mat[b[0][i+add][j+add]][b[1][i+add][j+add]]=true;
        }
     for(i=0;i<node[0];i++)
     {
         l[i]=-1;
         vl[i]=false;
     }
     for(i=0;i<node[1];i++)
     {
         r[i]=-1;
         vr[i]=false;
     }
     for(i=0;i<node[0];i++)
     {
         if(l[i]<0&&dfs(i))
         {
             for(j=0;j<node[0];j++)
                 vl[j]=false;
             for(j=0;j<node[1];j++)
                 vr[j]=false;
         }
     }
     memset(vl,false,sizeof(vl));
     memset(vr,false,sizeof(vr));
     for(i=0;i<node[0];i++)
     {
         if(l[i]<0)
            dfs(i);
     }
     for(i=0;i<node[0];i++)
     {
         if(vl[i])
            draw(ll[0][i].x,ll[0][i].y,rr[0][i].x,rr[0][i].y);
     }
     for(i=0;i<node[1];i++)
     {
         if(!vr[i])
            draw(ll[1][i].x,ll[1][i].y,rr[1][i].x,rr[1][i].y);
     }
     for(i=-max_s;i<=max_s;i++)
     {
       bool now_tr=false;
       for(j=-max_s;j<=max_s;j++)
       {
          int v1,v2;
          v1=(test(st[i+add][j+add],up)&test(st[i+add][j+add],down));
          v2=(test(st[i+add][j+add],left_)&test(st[i+add][j+add],right_));
          if(tr[i+add][j+add]&&!now_tr)
          {
             now_tr=true;
             sy=j;
          }
          if((v1||v2)&&now_tr)
          {
              if(sy<j)
                 draw(i,sy,i,j);
              now_tr=false;
          }
       }
       now_tr=false;
       for(j=max_s;j>=-max_s;j--)
       {
          int v1,v2;
          v1=(test(st[i+add][j+add],up)&test(st[i+add][j+add],down));
          v2=(test(st[i+add][j+add],left_)&test(st[i+add][j+add],right_));
          if(r_tr[i+add][j+add]&&!now_tr)
          {
              now_tr=true;
              sy=j;
          }
          if((v1||v2)&&now_tr)
          {
              if(j<sy)
                draw(i,j,i,sy);
              now_tr=false;
          }
       }
     }
     num_rec=0;
     for(i=-max_s;i<=max_s;i++)
        for(j=-max_s;j<=max_s;j++)
        {
           int v=(test(st[i+add][j+add],down)&test(st[i+add][j+add],left_));
           v&=!out[i+add][j+add];
           if(v)
           {
              for(p=i+1;p<=max_s;p++)
              {
                  v=(test(st[p+add][j+add],down)&test(st[p+add][j+add],right_));
                  if(v)
                     break;
              }
              if(p<=max_s)
              {
                 rec[num_rec].x1=i;
                 rec[num_rec].x2=p;
                 for(p=j+1;p<=max_s;p++)
                 {
                    v=(test(st[i+add][p+add],up)&test(st[i+add][p+add],left_));
                    if(v)
                       break;
                 }
                 if(p<=max_s)
                 {
                    rec[num_rec].y1=j;
                    rec[num_rec++].y2=p;
                 }
              }
           }
        }
       printf("%d\n",num_rec);
        for(i=0;i<num_rec;i++)
          printf("%d %d %d %d\n",rec[i].x1,rec[i].y1,rec[i].x2,rec[i].y2);
}
int main()
{
    int i,j,s,p,q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%d%d",&pt[i].x,&pt[i].y);
    memset(st,0,sizeof(st));
    for(i=0;i<n;i++)
       draw(pt[i].x,pt[i].y,pt[(i+1)%n].x,pt[(i+1)%n].y);
    get_node();
    return 0;
}



