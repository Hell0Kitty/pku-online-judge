nclude<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50005,M=500005;
const int inf=1<<29;
struct Line
{
    int left,right,val;
}line[N*4];
struct data
{
    int x,y;
    bool operator<(const data &ne)const
    {
        if(x!=ne.x)
            return x<ne.x;
        else
            return y<ne.y;
    }
}po[M];
void build(int now,int left,int right)
{
    line[now].left=left;
    line[now].right=right;
    line[now].val=inf;
    if(left==right)
        return;
    int mid=(left+right)>>1;
    build(now*2,left,mid);
    build(now*2+1,mid+1,right);
}
int getpos(int now,int pos)
{
    int ll=line[now].left,rr=line[now].right,mid=(ll+rr)>>1;
    if(ll==rr)
        return line[now].val;
    else if(pos<=mid)
        return min(line[now].val,getpos(now*2,pos));
    else
        return min(line[now].val,getpos(now*2+1,pos));
}
void modify(int now,int left,int right,int v)
{
    int ll=line[now].left,rr=line[now].right,mid=(ll+rr)>>1,val=line[now].val;
    if(ll==left&&rr==right)
    {
        line[now].val=min(val,v);
        return;
    }
    if(right<=mid)
        modify(now*2,left,right,v);
    else if(left>mid)
        modify(now*2+1,left,right,v);
    else
    {
        modify(now*2,left,mid,v);
        modify(now*2+1,mid+1,right,v);
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,1,n);
        modify(1,1,1,0);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&po[i].x,&po[i].y);
            int x=max(po[i].x,1),y=min(po[i].y,n);
            int tp=getpos(1,x);
            if(tp==inf)
                continue;
            modify(1,x,y,tp+1);
        }
        printf("%d\n",getpos(1,n));
    }
    return 0;
}



