#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct rec
{
    int x1,y1,x2,y2,dx1,dy1,dx2,dy2;
    bool operator <(const rec &temp)const
    {
         if(dx1==temp.dx1)
            return dy1<temp.dy1;
         return dx1<temp.dx1;
    }
};
rec a[2200],ans[2200],heap[100000];
int n,res,size;
int list[2][10000],num[2],cnt[2],ax[2],in[2],cont[2][4000],ncnt[2][4000];
struct segment
{
    int va1,va2;
    bool operator <(const segment &temp)const
    {
         return va1<temp.va1;
    }
};
segment seg[2][4000][1000];
void min_heapify(int id)
{
     int ii=(id-1)/2;
     if(id&&heap[id]<heap[ii])
     {
         swap(heap[id],heap[ii]);
         min_heapify(ii);
     }
}
void heapify(int id)
{
     int l=2*id+1,r=2*id+2,ii=id;
     if(l<size&&heap[l]<heap[ii])
        ii=l;
     if(r<size&&heap[r]<heap[ii])
        ii=r;
     if(ii!=id)
     {
        swap(heap[ii],heap[id]);
        heapify(ii);
     }
}
int binary(int left,int right,int list[],int value)
{
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(list[mid]<value)
           left=mid+1;
        else if(list[mid]>value)
           right=mid-1;
        else
           return mid;
    }
}
void add()
{
     int i,j,s,p,q,id1,id2;
     heap[size].dx1=heap[size].dy1=1000000000;
     id1=binary(0,cnt[0]-1,list[0],heap[size].x1);
     id2=binary(0,cnt[0]-1,list[0],heap[size].x2); 
     for(j=id1+1;j<=id2-1;j++)
     {
        for(s=0;s<cont[0][j];s++)
        { 
            if(seg[0][j][s].va1<=heap[size].y1&&seg[0][j][s].va2>=heap[size].y2)
            {
                 if(heap[size].dx1>list[0][j])
                 {
                     heap[size].dx1=heap[size].dx2=list[0][j];
                     heap[size].dy1=heap[size].y1;
                     heap[size].dy2=heap[size].y2;
                 }
                 else if(heap[size].dx1==list[0][j])
                 {
                     if(heap[size].dy1>heap[size].y1)
                     {
                         heap[size].dy1=heap[size].y1;
                         heap[size].dx2=list[0][j];
                         heap[size].dy2=heap[size].y2;
                     }
                 }
            }
        }
     }
     id1=binary(0,cnt[1]-1,list[1],heap[size].y1);
     id2=binary(0,cnt[1]-1,list[1],heap[size].y2);
     for(j=id1+1;j<=id2-1;j++)
     {
         for(s=0;s<cont[1][j];s++)
         {
             if(seg[1][j][s].va1<=heap[size].x1&&seg[1][j][s].va2>=heap[size].x2)
             { 
                   if(heap[size].dx1>heap[size].x1)
                   {
                      heap[size].dx1=heap[size].x1;
                      heap[size].dy1=heap[size].dy2=list[1][j];
                      heap[size].dx2=heap[size].x2;
                   }
                   else if(heap[size].dx1==heap[size].x1)
                   {
                       if(heap[size].dy1>list[1][j])
                       {
                          heap[size].dy1=heap[size].dy2=list[1][j];
                          heap[size].x2=heap[size].x2;
                       }
                   }
             }
         }
     } 
     size++;
     min_heapify(size-1);
}
void run()
{
     int i,j,s,p,q;
     rec u;
     size=0;
     heap[0].x1=in[0];
     heap[0].y1=in[1];
     heap[0].x2=ax[0];
     heap[0].y2=ax[1];
     add();
     while(size)
     {
         if(heap[0].dx1==1000000000)
             break;
         printf("%d %d %d %d\n",heap[0].dx1,heap[0].dy1,heap[0].dx2,heap[0].dy2);
         u=heap[0];
         heap[0]=heap[size-1];
         size--;
         heapify(0);
         if(u.dx1==u.dx2)
         {
            heap[size].x1=u.x1;
            heap[size].y1=u.y1;
            heap[size].x2=u.dx1;
            heap[size].y2=u.y2;
            add();
            heap[size].x1=u.dx1;
            heap[size].y1=u.y1;
            heap[size].x2=u.x2;
            heap[size].y2=u.y2;
            add();
         }
         else
         {
             heap[size].x1=u.x1;
             heap[size].y1=u.y1;
             heap[size].x2=u.x2;
             heap[size].y2=u.dy1;
             add();
             heap[size].x1=u.x1;
             heap[size].y1=u.dy1;
             heap[size].x2=u.x2;
             heap[size].y2=u.y2;
             add();
         }
     }
}
int main()
{
    int i,j,s,p,q,id,xid1,xid2,yid1,yid2,max,tst=0;
    while(scanf("%d",&n)&&n)
    {
        tst++;
        num[0]=num[1]=0;
        ax[0]=ax[1]=-1000000000;
        in[0]=in[1]=1000000000;
        for(i=0;i<n;i++)
        {
           scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
           if(a[i].x1<in[0])
              in[0]=a[i].x1;
           if(a[i].x2>ax[0])
              ax[0]=a[i].x2;
           if(a[i].y1<in[1])
              in[1]=a[i].y1;
           if(a[i].y2>ax[1])
              ax[1]=a[i].y2;
           list[0][num[0]++]=a[i].x1;
           list[0][num[0]++]=a[i].x2;
           list[1][num[1]++]=a[i].y1;
           list[1][num[1]++]=a[i].y2;
        }
        if(tst>1)
           printf("\n");
        for(i=0;i<2;i++)
        {
           sort(list[i],list[i]+num[i]);
           cnt[i]=1;
           for(j=1;j<num[i];j++)
           {
               if(list[i][j]!=list[i][cnt[i]-1])
                  list[i][cnt[i]++]=list[i][j];
           }
        }
        memset(cont,0,sizeof(cont));
        for(i=0;i<n;i++)
        {
             xid1=binary(0,cnt[0]-1,list[0],a[i].x1);
             xid2=binary(0,cnt[0]-1,list[0],a[i].x2);
             yid1=binary(0,cnt[1]-1,list[1],a[i].y1);
             yid2=binary(0,cnt[1]-1,list[1],a[i].y2);
             seg[0][xid1][cont[0][xid1]].va1=a[i].y1;
             seg[0][xid1][cont[0][xid1]++].va2=a[i].y2;
             seg[0][xid2][cont[0][xid2]].va1=a[i].y1;
             seg[0][xid2][cont[0][xid2]++].va2=a[i].y2;
             seg[1][yid1][cont[1][yid1]].va1=a[i].x1; 
             seg[1][yid1][cont[1][yid1]++].va2=a[i].x2;
             seg[1][yid2][cont[1][yid2]].va1=a[i].x1;
             seg[1][yid2][cont[1][yid2]++].va2=a[i].x2; 
        }  
        for(i=0;i<2;i++)
          for(j=0;j<cnt[i];j++)
            while(cont[i][j]>1000);
        for(i=0;i<2;i++)
        {
           for(j=0;j<cnt[i];j++)
           {
               sort(seg[i][j],seg[i][j]+cont[i][j]);
               ncnt[i][j]=0;
               max=seg[i][j][0].va2;
               for(s=1;s<cont[i][j];s++)
               {
                   if(max<seg[i][j][s].va1)
                   {
                       seg[i][j][ncnt[i][j]++].va2=max;
                       seg[i][j][ncnt[i][j]].va1=seg[i][j][s].va1;
                   }
                   if(max<seg[i][j][s].va2)
                       max=seg[i][j][s].va2;
               }
               seg[i][j][ncnt[i][j]++].va2=max;
               cont[i][j]=ncnt[i][j];
           }
        }
        run();
    }    
    return 0;
}



