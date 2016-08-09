#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<cmath>
#define cl(x,v) memset(x,v,sizeof(x))
#define INF 1<<29
#define rep(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
#define EPS 1e-8
#define MID int mid=(l+r)>>1; int ls=o<<1; int rs=o<<1|1;
#define pii pair<int,int>
#define F first
#define S second
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

int cal[120][120];
int mol[120][120];
int tagc[120],tagm[120],n,m,c;

int dfs(int gra[120][120],int vis[120], int v)
{
    int i,j,ret='N';
    vis[v]=1;
    if(gra[v][m]==0)ret='Y';
    for(i=1;i<=n;i++){
        if(vis[i]==1)continue;
        if(tagc[i]==1)continue;
        if(gra[v][i]==0){
            if(dfs(gra,vis,i)=='Y')ret='Y';
        }
    }
    return ret;
}

int  main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d %d %d",&n,&c,&m);
        int i,j,k,a,b;
        cl(cal,0x37);
        cl(mol,0x37);
        cl(tagc,0);
        cl(tagm,0);
        while(scanf("%d %d",&a,&b)){
            if(a==-1&&b==-1)break;
            cal[a][b]=0;
        }
        while(scanf("%d %d",&a,&b)){
            if(a==-1&&b==-1)break;
            mol[a][b]=0;
        }
        dfs(mol,tagm,m);
        dfs(cal,tagc,c);
        int tag1='N',tag2='N';
        for(i=1;i<=n;i++){
            if(tagc[i]==1&&tagm[i]==1)tag1='Y';
        }
        cl(tagm,0);
        tag2=dfs(mol,tagm,m);
        if(tag2=='Y')
        {
            tag2='N';
            for(i=1;i<=n;i++)
            {
                if(i==m)continue;
                if(tagm[i]==1)tag2='Y';
            }
        }
        printf("%c %c\n",tag1,tag2);
    }
        return 0;
}



