#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define L(x) (x<<1)
#define R(x) (x<<1 | 1)
#define MAX 200
using namespace std;
double cy[2*MAX];
class Seg
{
    public :
        double x,y1,y2;
        int f;
        Seg(){};
        Seg(double a,double b,double c,int d):x(a),y1(b),y2(c),f(d)
        {
        }
        bool operator <(const Seg &b)const
        {
            return x<b.x;
        }
}seg[2*MAX];
struct node
{
    int l;
    int r;
    int cover;
    double length;
}a[MAX*3];
void build(int t,int l ,int r)
{
    a[t].l=l;
    a[t].r=r;
    a[t].cover=0;
    a[t].length=0;
    if(r-l==1)return ;
    int mid =(l+r)>>1;
    build(L(t),l,mid);
    build(R(t),mid,r);
}
void len(int t)
{
    if(a[t].cover>0)
      a[t].length=cy[a[t].r]-cy[a[t].l];
    else
    {
        if(a[t].r-a[t].l==1)a[t].length=0;
        else
          a[t].length=a[L(t)].length+a[R(t)].length;
    }
}
void update(int t,Seg &s)
{
    int tl=a[t].l;
    int tr=a[t].r;
    if(cy[tl]==s.y1&&cy[tr]==s.y2)
    {
        a[t].cover+=s.f;
        len(t);
        return ;
    }
    int mid=(tl+tr)>>1;
    if(s.y2<=cy[mid])
      update(L(t),s);
    else
      if(s.y1>=cy[mid])
        update(R(t),s);
      else
      {
          Seg temp=s;
          temp.y2=cy[mid];
          update(L(t),temp);
          temp=s;
          temp.y1=cy[mid];
          update(R(t),temp);
      }
    len(t);
}
int main()
{
    int n,m;
    int i,j;
    double x1,x2,y1,y2;
    int ca=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        m=0;        
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            seg[++m]=Seg(x1,y1,y2,1);
            cy[m]=y1;
            seg[++m]=Seg(x2,y1,y2,-1);
            cy[m]=y2;
        }
        sort(seg+1,seg+1+m);
        sort(cy+1,cy+1+m);
        build(1,1,m);
        double ary=0;
        for(i=1;i<=m-1;i++)
        {
            update(1,seg[i]);
            ary+=a[1].length*(seg[i+1].x-seg[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",ca,ary);
        ca++;
    }
}


