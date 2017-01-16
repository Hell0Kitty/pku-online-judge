#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
struct tim
{
    double t1,t2;
};
tim times[60][22];
int num[60],size,nu[55][22];
double len,eps=1e-8,endx,endy,vt,ve,dp[55][22][111],T,ans;
bool visit[60][22];
struct qq
{
   double value;
   int id1,id2,id3;
};
qq heap[1100001];
void heapify(int id)
{
     int l=2*id+1,r=2*id+2,ii=id;
     if(l<size&&heap[ii].value>heap[l].value)
        ii=l;
     if(r<size&&heap[ii].value>heap[r].value)
        ii=r;
     if(ii!=id)
     {
         swap(heap[ii],heap[id]);
         heapify(ii);
     }
}
void min_heapify(int id)
{
     int ii=(id-1)/2;
     if(id>0&&heap[ii].value>heap[id].value)
     {
          swap(heap[ii],heap[id]);
          min_heapify(ii);
     }
}
struct pp
{
    double value;
    int id;
    bool operator <(const pp &temp)const
    {
         return value<temp.value;
    }
};
pp y[100];
struct point
{
    double x,y;
};
point poly[100];
int n,m,cnt;
struct train
{
       double hx,hy,len,ru,tx,ty;
       int p1,p2;
       bool operator <(const train &temp)const
       {
            if(p1==temp.p1)
               return ru<temp.ru;
            return p1<temp.p1;
       }
};
train trains[100];
bool inter(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
     double ru1,ru2;
     if((x2-x1)*(y4-y3)-(y2-y1)*(x4-x3)==0)
        return false;
     ru1=((x3-x1)*(y4-y3)-(y3-y1)*(x4-x3))/((x2-x1)*(y4-y3)-(y2-y1)*(x4-x3));
     ru2=((x3-x1)*(y2-y1)-(y3-y1)*(x2-x1))/((x2-x1)*(y4-y3)-(y2-y1)*(x4-x3));
     if(ru2>-eps&&ru2<1+eps)
     {
         while(ru1>1-eps||ru1<eps)
            puts("orz");
         y[cnt].value=y1+ru1*(y2-y1);
         return true;
     }   
     return false;
}
double dist(double x1,double y1,double x2,double y2)
{
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double JiaJunpeng()
{
       int i,j,s,p,q,u1,u2,u3,id1,id2,n1,n2,n3;
       double v,in,del,t1,t2,th1,th2,value;
       for(i=0;i<cnt;i++)
         for(j=0;j<m;j++)
            for(s=0;s<100;s++)
            dp[i][j][s]=(double)1000000000.00*(double)1000000000.000;
       dp[0][0][0]=0.00;
       heap[0].value=heap[0].id1=heap[0].id2=heap[0].id3=0;
       size=1;
       memset(nu,0,sizeof(nu));
       nu[0][0]=1;
       while(size)
       {
           u1=heap[0].id1;
           u2=heap[0].id2;
           u3=heap[0].id3;
           if(u1==cnt-1)
              return dp[u1][u2][u3];   
           heap[0]=heap[size-1];
           size--;
           heapify(0);
           if(u1!=0)
           {
              n1=(int)((dp[u1][u2][u3]+T-times[u1][u2].t2+eps)/T);
              t1=times[u1][u2].t1+T*n1;
              t2=times[u1][u2].t2+T*n1;
           }
           else
           {
               t1=times[u1][u2].t1;
               t2=times[u1][u2].t2;
           }
           for(j=0;j<2;j++)
           {
                if(j==0)
                   id1=u1+1;
                else
                   id1=u1-1;
                if(id1<=0)
                   continue;
                del=fabs(y[u1].value-y[id1].value)/ve;
                if(id1==cnt-1)
                {
                    if(dp[id1][0][0]>dp[u1][u2][u3]+del)
                    {
                        dp[id1][0][0]=dp[u1][u2][u3]+del;
                        heap[size].id1=id1;
                        heap[size].id2=heap[size].id3=0;
                        heap[size++].value=dp[u1][u2][u3]+del;
                        min_heapify(size-1);
                    }
                }
                else
                {
                    for(i=0;i<m;i++)
                    {
                        th1=times[id1][i].t1-del;
                        th2=times[id1][i].t2-del;
                        n1=(int)((dp[u1][u2][u3]+T+eps-th2)/T);
                        th1+=n1*T;
                        th2+=n1*T;
                        if(th1-eps<dp[u1][u2][u3])
                        {
                             value=dp[u1][u2][u3]+del;
                             v=th2+del-value;
                             for(s=0;s<nu[id1][i];s++)
                             {
                                 if(dp[id1][i][s]<=value)
                                 {
                                    n2=(int)((dp[id1][i][s]+T-times[id1][i].t2+eps)/T);
                                    if(v<=times[id1][i].t2+n2*T-dp[id1][i][s])
                                        break;
                                 }
                             }
                             if(s>=nu[id1][i])
                             {
                                dp[id1][i][nu[id1][i]++]=value;
                                heap[size].id1=id1;
                                heap[size].id2=i;
                                heap[size].id3=nu[id1][i]-1;
                                heap[size++].value=value;
                                min_heapify(size-1);
                             }
                             th1+=T;
                             th2+=T; 
                        }
                        if(th1<min(t2,th2)-eps)
                        {
                            value=th1+del;
                            v=th2+del-value;
                            for(s=0;s<nu[id1][i];s++)
                            {
                               if(dp[id1][i][s]<=value)
                               {
                                  n2=(int)((dp[id1][i][s]+T-times[id1][i].t2+eps)/T);
                                  if(v<=times[id1][i].t2+n2*T-dp[id1][i][s])
                                     break;
                               }
                           }
                           if(s>=nu[id1][i])
                           {
                              dp[id1][i][nu[id1][i]++]=value;
                              heap[size].id1=id1;
                              heap[size].id2=i;
                              heap[size].id3=nu[id1][i]-1;
                              heap[size++].value=value;
                              min_heapify(size-1);
                           }
                        }
                    }
                }                
           }
       }
       return -1.000;
}
int main()
{
    int i,j,s,p,q,id1,id2,ip,id;
    double l; 
    while(scanf("%d%d%lf%lf%lf%lf",&n,&m,&endx,&endy,&vt,&ve)&&(n!=0||m!=0&&endx!=0&&endy!=0&&vt!=0&&ve!=0))
    {
        for(i=0;i<n;i++)
           scanf("%lf%lf",&poly[i].x,&poly[i].y);
        for(i=0;i<m;i++)
        {
           scanf("%lf%lf%lf",&trains[i].hx,&trains[i].hy,&trains[i].len);
           while(trains[i].len==0.00)
              puts("Orz");
        }
        len=0.00;
        for(i=0;i<n;i++)
        {
           id1=i;
           id2=(i+1)%n;
           len+=dist(poly[id1].x,poly[id1].y,poly[id2].x,poly[id2].y);
           for(j=0;j<m;j++)
           {
               if((trains[j].hy-poly[id1].y)*(poly[id2].x-poly[id1].x)==(trains[j].hx-poly[id1].x)*(poly[id2].y-poly[id1].y))
               {
                    trains[j].p1=id1;
                    if(poly[id1].x!=poly[id2].x)
                       trains[j].ru=(trains[j].hx-poly[id1].x)/(poly[id2].x-poly[id1].x);
                    else
                       trains[j].ru=(trains[j].hy-poly[id1].y)/(poly[id2].y-poly[id1].y);
               }
           }
        }
        while(vt==0.0||ve==0.0)
           puts("orz");
        T=len/vt;
        sort(trains,trains+m);
        for(i=0;i<m;i++)
        {
             id=trains[i].p1;
             l=dist(trains[i].hx,trains[i].hy,poly[id].x,poly[id].y);
             while(l<trains[i].len)
             {
                 ip=(id-1+n)%n;
                 l+=dist(poly[id].x,poly[id].y,poly[ip].x,poly[ip].y);
                 id=ip;
             }
             l-=trains[i].len;
             ip=(id+1)%n;
             trains[i].p2=id;
             trains[i].tx=poly[id].x+l*(poly[ip].x-poly[id].x)/dist(poly[ip].x,poly[ip].y,poly[id].x,poly[id].y);
             trains[i].ty=poly[id].y+l*(poly[ip].y-poly[id].y)/dist(poly[ip].x,poly[ip].y,poly[id].x,poly[id].y);
        }
        cnt=1;
        y[0].value=0.00;
        y[0].id=0;
        for(i=0;i<n;i++)
        {
           id1=i;
           id2=(i+1)%n;
           if(inter(endx,0,endx,endy,poly[id1].x,poly[id1].y,poly[id2].x,poly[id2].y))
              y[cnt++].id=(i+1)%n;
        }
        sort(y+1,y+cnt);
        y[cnt].value=endy;
        y[cnt++].id=n+1;
        for(i=0;i<cnt-1;i++)
            while(y[i].value>y[i+1].value);
        memset(num,0,sizeof(num));
        num[0]=1;
        times[0][0].t1=0.00;
        times[0][0].t2=(double)1000000000.000*(double)1000000000.000;
        times[cnt-1][0]=times[0][0];
        num[cnt-1]=1;
        for(i=1;i<cnt-1;i++)
        {
            ip=(y[i].id-1+n)%n;
            for(j=0;j<m;j++)
            {
                id1=j;
                id2=(j+1)%m;
                id=(trains[id2].p2+1)%n;
                l=dist(trains[id2].tx,trains[id2].ty,poly[id].x,poly[id].y);
                while(id!=ip)
                {
                   l+=dist(poly[id].x,poly[id].y,poly[(id+1)%n].x,poly[(id+1)%n].y);
                   id=(id+1)%n;
                }
                l+=dist(poly[id].x,poly[id].y,endx,y[i].value);
                times[i][j].t1=l/vt;
                id=(trains[id1].p1+1)%n;
                l=dist(trains[id1].hx,trains[id1].hy,poly[id].x,poly[id].y);
                while(id!=ip)
                {
                   l+=dist(poly[id].x,poly[id].y,poly[(id+1)%n].x,poly[(id+1)%n].y);
                   id=(id+1)%n;
                }
                l+=dist(poly[id].x,poly[id].y,endx,y[i].value);
                times[i][j].t2=l/vt;
                while(times[i][j].t2<times[i][j].t1)
                    times[i][j].t1-=T;   
                while(times[i][j].t2>0)
                {
                   times[i][j].t1-=T;
                   times[i][j].t2-=T;
                }
                times[i][j].t1+=T;
                times[i][j].t2+=T;

            }
        } 
        ans=JiaJunpeng();
        if(ans>=0)
           printf("%.4lf\n",ans);
        else
           puts("Impossible!");
    }
    return 0;
}


