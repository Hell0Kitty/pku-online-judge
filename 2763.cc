#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn=100005;
typedef long long LL;
int fa[maxn],dep[maxn],siz[maxn],son[maxn],num[maxn];
int top[maxn],Hash[maxn],d[maxn][3];
int n,s,z,q,tree[maxn*4];
int head[maxn],ip;
void init()
{
    memset(head,-1,sizeof(head));
    memset(tree,0,sizeof(tree));
    ip=0;
}

struct note
{
    int v,w,next;
}edge[maxn*4];

void addedge(int u,int v,int w)
{
    edge[ip].v=v,edge[ip].w=w,edge[ip].next=head[u],head[u]=ip++;
}

void dfs(int u,int pre)
{
    son[u]=0,siz[u]=1;
    dep[u]=dep[pre]+1;
    fa[u]=pre;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==pre)continue;
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v])
        {
            son[u]=v;
        }
    }
   /// printf("%d dep fa siz son %d %d %d %d\n",u,dep[u],fa[u],siz[u],son[u]);
}

void set_que(int u,int tp)
{
    num[u]=++z,top[u]=tp;
    Hash[z]=u;
    if(son[u])
    {
        set_que(son[u],tp);
    }
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==son[u]||v==fa[u])continue;
        set_que(v,v);
    }
}

void push_up(int root)
{
    tree[root]=tree[root<<1]+tree[root<<1|1];
}
void update(int root,int l,int r,int loc,int z)
{
    if(l>loc||r<loc) return;
    if(l==r)
    {
        tree[root]=z;
        return;
    }
    int mid=(l+r)>>1;
    update(root<<1,l,mid,loc,z);
    update(root<<1|1,mid+1,r,loc,z);
    push_up(root);
}

int query(int root,int l,int r,int x,int y)
{
    if(r<x||l>y)return 0;
    if(x<=l&&r<=y)
    {
        return tree[root];
    }
    int mid=(l+r)>>1;
    return query(root<<1,l,mid,x,y)+query(root<<1|1,mid+1,r,x,y);
}
int main()
{
    //freopen("data.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&q,&s))
    {
        init();
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            d[i][0]=u,d[i][1]=v,d[i][2]=w;
            addedge(u,v,w);
            addedge(v,u,w);
        }
        int root=(n+1)>>1;
        z=0,dep[0]=0,siz[0]=0;
        dfs(root,0);
        set_que(root,root);
        for(int i=1;i<n;i++)
        {
            if(dep[d[i][0]]>dep[d[i][1]])
            {
                swap(d[i][0],d[i][1]);
            }
            update(1,1,z,num[d[i][1]],d[i][2]);
        }
        int s1;
        while(q--)
        {
            int x,y,zz;
            scanf("%d",&x);
            if(x==0)
            {
                scanf("%d",&y);
                s1=s;
                s=y;
                int f1=top[s1],f2=top[y],sum=0;
                while(f1!=f2)
                {
                    if(dep[f1]<dep[f2])
                    {
                        swap(f1,f2);
                        swap(s1,y);
                    }
                    sum+=query(1,1,z,num[f1],num[s1]);
                    s1=fa[f1],f1=top[s1];
                }
                if(y!=s1)
                {
                    if(dep[s1]>dep[y])
                    {
                        swap(s1,y);
                    }
                    sum+=query(1,1,z,num[son[s1]],num[y]);
                }
                printf("%d\n",sum);
            }
            else
            {
                scanf("%d%d",&y,&zz);
                update(1,1,z,num[d[y][1]],zz);
            }
        }
    }
    return 0;
}



