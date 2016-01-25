#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define N 750010

using namespace std;

struct PO
{
    int a,w;
}po[N];

struct TR
{
    int u,l,r;
}tr[N];

struct Q
{
    int bh,l,r;
}q[N],wc;

struct QQ
{
    int bh,pd;
}qq[N],we;

int s[N],p,pos,n,cnt,tt,next[N],b[N],len,mx[N*2];

char str[N];

inline bool cmp(const PO &a,const PO &b)
{
    return a.a<b.a;
}

inline int jmin(int x,int y)
{
    if(po[x].w<po[y].w) return x;
    return y;
}

void build(int u,int l,int r)
{
    if(l==r) {mx[u]=l;return;}
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    mx[u]=jmin(mx[u<<1],mx[u<<1|1]);
}

void query(int u,int L,int R,int l,int r)
{
    if(L<=l&&r<=R) {pos=jmin(pos,mx[u]);return;}
    int mid=(l+r)>>1;
    if(L<=mid) query(u<<1,L,R,l,mid);
    if(R>mid) query(u<<1|1,L,R,mid+1,r);
}

void read()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&po[i].a);
        po[i].w=i;
    }
    po[0].w=0x7f7f7f7f;
    sort(po+1,po+1+n,cmp);
    build(1,1,n);
}

void create()
{
    cnt=1;
    int size=1;
    q[size].bh=1; q[size].l=1; q[size].r=n;
    while(size)
    {
        wc=q[size--];
        pos=0;
        query(1,wc.l,wc.r,1,n);
        tr[wc.bh].u=po[pos].a;
        if(wc.l<=pos-1)
        {
            tr[wc.bh].l=++cnt;
            q[++size].bh=cnt;
            q[size].l=wc.l;
            q[size].r=pos-1;
        }
        if(wc.r>=pos+1)
        {
            tr[wc.bh].r=++cnt;
            q[++size].bh=cnt;
            q[size].l=pos+1;
            q[size].r=wc.r;
        }
    }
}

void dfs()
{
    int size=1;
    qq[size].bh=1; qq[size].pd=0;
    while(size)
    {
        we=qq[size];
        if(we.pd==0)
        {
            s[++p]=tr[we.bh].u&1;
            if(tr[we.bh].l!=-1)
            {
                qq[size].pd=1;
                qq[++size].bh=tr[we.bh].l;
                qq[size].pd=0;
                continue;
            }
            if(tr[we.bh].r!=-1)
            {
                qq[size].pd=2;
                qq[++size].bh=tr[we.bh].r;
                qq[size].pd=0;
                continue;
            }
        }
        if(we.pd==1)
        {
            s[++p]=tr[we.bh].u&1;
            if(tr[we.bh].r!=-1)
            {
                qq[size].pd=2;
                qq[++size].bh=tr[we.bh].r;
                qq[size].pd=0;
                continue;
            }
        }
        if(we.pd==2) s[++p]=tr[we.bh].u&1; 
        size--;
    }
}

void getnext()
{
    next[1]=0;
    int i,j=0;
    for(i=2;i<=len;i++)
    {
        while(j>0&&b[j+1]!=b[i]) j=next[j];
        if(b[j+1]==b[i]) j+=1;
        next[i]=j;
    }
}

int kmp()
{
    int i,j=0,num=0;
    for(i=1;i<=p;i++)
    {
        while(j>0&&b[j+1]!=s[i]) j=next[j];
        if(b[j+1]==s[i]) j+=1;
        if(j==len)
        {
            num++;
            j=next[j];
        }
    }
    return num;
}

void go()
{
    memset(tr,-1,sizeof tr);
    create();
    p=0;
    dfs();
    scanf("%s",str+1);
    len=strlen(str+1);
    for(int i=1;i<=len;i++) b[i]=str[i]-'0';
    getnext();
    printf("%d\n",kmp());
}

int main()
{
    scanf("%d",&tt);
    for(int i=1;i<=tt;i++)
    {
        read();
        printf("Case #%d: ",i);
        go();
    }
    return 0;
}



