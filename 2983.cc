#include <stdio.h>  
#include <math.h>  
#include <string.h>  
#include <stdlib.h>  
#include <iostream>  
#include <sstream>  
#include <algorithm>  
#include <set>  
#include <queue>  
#include <stack>  
#include <map>  
using namespace std;  
typedef long long LL;  
const int inf=0x3f3f3f3f;  
const double pi= acos(-1.0);  
const double esp=1e-6;  
const int maxn=2010;  
int dis[maxn],head[2010];  
int cnt;  
struct node  
{  
    int u,v,w;  
    int next;  
}edge[1000010];  
void add(int u,int v,int w)  
{  
    edge[cnt].u=u;  
    edge[cnt].v=v;  
    edge[cnt].w=w;  
    edge[cnt].next=head[u];  
    head[u]=cnt++;  
}  
int Bellman_ford(int n)  
{  
    int i,j;  
    memset(dis,inf,sizeof(dis));  
    dis[1]=0;  
    for(i=1;i<=n;i++){  
        int flag=0;  
        for(j=0;j<cnt;j++){  
            int u=edge[j].u;  
            int v=edge[j].v;  
            if(dis[v]>dis[u]+edge[j].w){  
                dis[v]=dis[u]+edge[j].w;  
                flag=1;  
            }  
        }  
        if(!flag) break;  
    }  
    for(i=0;i<cnt;i++){  
        if(dis[edge[i].v]>dis[edge[i].u]+edge[i].w)  
            return 0;  
    }  
    return 1;  
}  
int main()  
{  
    int n,m,i;  
    int u,v,w;  
    char str;  
    while(~scanf("%d %d",&n,&m)){  
        memset(head,-1,sizeof(head));  
        cnt=0;  
        while(m--){  
            getchar();  
            scanf("%c",&str);  
            if(str=='P'){  
                scanf("%d %d %d",&u,&v,&w);  
                add(u,v,w);  
                add(v,u,-w);  
            }  
            else{  
                scanf("%d %d",&u,&v);  
                add(v,u,-1);  
            }  
        }  
        int ans=Bellman_ford(n);  
        if(ans)  
            puts("Reliable");  
        else  
            puts("Unreliable");  
    }  
    return 0;  
}  
