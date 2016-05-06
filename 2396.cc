#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<string>  
#include<cstring>  

using namespace std;  

#define MAXN 500   
#define INF 0xFFFFFF  
#define MAXM 9999999  

struct edge  
{  
    int to,c,next;  
}e[MAXM];  

struct node  
{  
    int c,l;  
}matrix[250][50];  

int head[MAXN],en,l[MAXN];  
int dis[MAXN],gap[MAXN],st,ed;  
int n,m,vn;  

void add(int a,int b,int c)  
{  
    e[en].to=b,e[en].c=c,e[en].next=head[a],head[a]=en++;  
    e[en].to=a,e[en].c=0,e[en].next=head[b],head[b]=en++;  
}  

int isap(int u,int flow)   
{  
    if(u==ed)  
        return flow;  
    int j,mindis=vn-1,t=flow,d;  
    for(j=head[u];j!=-1;j=e[j].next)   
    {  
        int v=e[j].to,val=e[j].c;  
        if(val>0)  
         {  
            if(dis[v]+1==dis[u])  
             {  
                if(t<e[j].c)   
                    d=t;  
                else   
                    d=e[j].c;  
                d=isap(v,d);  
                e[j].c-=d,e[j^1].c+=d;  
                t-=d;  
                if(dis[st]>=vn)  
                    return flow-t;  
                if(t==0)   
                    break;  
            }  
            if(dis[v]<mindis)  
                mindis=dis[v];  
        }  
    }  
    if(t==flow)   
    {  
        --gap[dis[u]];  
        if (gap[dis[u]]==0)   
            dis[st]=vn;  
        dis[u]=mindis+1;  
        ++gap[dis[u]];  
    }  
    return flow-t;  
}  

void solve()  
{  
    int a,b,c,q;  
    char str[5];  
    en=0;  
    scanf("%d%d",&m,&n);  
    memset(matrix,0,sizeof(matrix));  
    memset(l,0,sizeof(l));  
    memset(head,-1,sizeof(head));  
    for(int i=1;i<=m;i++)  
        for(int j=1;j<=n;j++)  
            matrix[i][j].c=INF;  
    for(int i=1;i<=m;i++)  
    {  
        scanf("%d",&matrix[i][0].c);  
        matrix[i][0].l=matrix[i][0].c;  
    }  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&matrix[0][i].c);  
        matrix[0][i].l=matrix[0][i].c;  
    }  
    scanf("%d",&q);  
    bool flag=false;  
    while(q--)  
    {  
        scanf("%d%d%s%d",&a,&b,&str,&c);  
        if(flag)  
            continue;  
        if(str[0]=='<')  
        {  
            if(a && b)  
            {  
                matrix[a][b].c=min(c-1,matrix[a][b].c);  
                if(matrix[a][b].c<matrix[a][b].l) flag=true;  
            }  
            if(!a && !b)  
            {  
                for(int i=1;i<=m;i++)  
                    for(int j=1;j<=n;j++)  
                    {  
                            matrix[i][j].c=min(c-1,matrix[i][j].c);  
                            if(matrix[i][j].c<matrix[i][j].l) flag=true;  
                    }  
            }  
            if(!a && b)  
            {  
                for(int i=1;i<=m;i++)  
                {  
                    matrix[i][b].c=min(c-1,matrix[i][b].c);  
                    if(matrix[i][b].c<matrix[i][b].l) flag=true;  
                }  
            }  
            if(a && !b)  
            {  
                for(int i=1;i<=n;i++)  
                {  
                    matrix[a][i].c=min(c-1,matrix[a][i].c);  
                    if(matrix[a][i].c<matrix[a][i].l) flag=true;  
                }  
            }  
        }     
        if(str[0]=='>')  
        {  
            if(a && b)  
            {  
                matrix[a][b].l=max(c+1,matrix[a][b].l);  
                if(matrix[a][b].l>matrix[a][b].c) flag=true;  
            }  

            if(!a && !b)  
            {  
                for(int i=1;i<=m;i++)  
                    for(int j=1;j<=n;j++)  
                    {  
                        matrix[i][j].l=max(c+1,matrix[i][j].l);  
                        if(matrix[i][j].l>matrix[i][j].c) flag=true;  
                    }  
            }  
            if(!a && b)  
            {  
                for(int i=1;i<=m;i++)  
                {  
                    matrix[i][b].l=max(c+1,matrix[i][b].l);  
                    if(matrix[i][b].l>matrix[i][b].c) flag=true;  
                }  
            }  
            if(a && !b)  
            {  
                for(int i=1;i<=n;i++)  
                {  
                    matrix[a][i].l=max(c+1,matrix[a][i].l);  
                    if(matrix[a][i].l>matrix[a][i].c) flag=true;  
                }  
            }     
        }  
        if(str[0]=='=')  
        {  
            if(a && b)  
            {  
                if(c<=matrix[a][b].c && c>=matrix[a][b].l) matrix[a][b].c=matrix[a][b].l=c;  
                else flag=true;  
            }  

            if(!a && !b)  
            {  
                for(int i=1;i<=m;i++)  
                    for(int j=1;j<=n;j++)  
                    {  
                        if(c<=matrix[i][j].c && c>=matrix[i][j].l) matrix[i][j].c=matrix[i][j].l=c;  
                        else flag=true;  
                    }  
            }  
            if(!a && b)  
            {  
                for(int i=1;i<=m;i++)  
                {  
                    if(c<=matrix[i][b].c && c>=matrix[i][b].l) matrix[i][b].c=matrix[i][b].l=c;  
                    else flag=true;  
                }  
            }  
            if(a && !b)  
            {  
                for(int i=1;i<=n;i++)  
                {  
                    if(c<=matrix[a][i].c && c>=matrix[a][i].l) matrix[a][i].c=matrix[a][i].l=c;  
                    else flag=true;  
                }  
            }  
        }     
    }  
    if(flag)  
    {  
        printf("IMPOSSIBLE\n");  
        return ;  
    }  
    for(int i=1;i<=m;i++)  
    {  
        for(int j=1;j<=n;j++)  
        {  
            l[i]-=matrix[i][j].l;  
            l[j+m]+=matrix[i][j].l;  
            add(i,j+m,matrix[i][j].c-matrix[i][j].l);  
        }  
    }  

    for(int i=1;i<=m;i++)  
    {  
        l[i]+=matrix[i][0].l;  
        l[0]-=matrix[i][0].l;  
        add(0,i,0);  
    }  
    for(int i=1;i<=n;i++)  
    {  
        l[i+m]-=matrix[0][i].l;  
        l[n+m+1]+=matrix[0][i].l;  
        add(i+m,m+n+1,0);  
    }  
    st=n+m+2,ed=n+m+3;  
    vn=n+m+4;  
    int full=0;  
    int maxflow=0;  
    for(int i=0;i<=n+m+1;i++)  
    {  
        if(l[i]>0)  
        {  
            add(st,i,l[i]);  
            full+=l[i];  
        }  
        else  
            add(i,ed,-l[i]);  
    }  
    add(0,n+m+1,INF);  
    add(n+m+1,0,INF);  
    memset(gap,0,sizeof(gap)),memset(dis,0,sizeof(dis));  
    gap[0]=vn;  
    while(dis[st]<vn)  
        maxflow+=isap(st,INF);  
    if(maxflow!=full)  
    {  
        printf("IMPOSSIBLE\n");  
        return ;  
    }  
    for(int i=1;i<=m;i++)  
    {  
        for(int j=1;j<=n;j++)  
        {  
            printf("%d",e[((i-1)*n+j-1)*2^1].c+matrix[i][j].l);  
            if(j!=n)  
                printf(" ");  
        }  
        printf("\n");  
    }  
}  

int main()  
{  
    int t;  
    bool flag=false;  
    scanf("%d",&t);  
    while(t--)  
    {  
        if(flag)  
            printf("\n");  
        flag=true;  
        solve();  
    }  
    return 0;  
}



