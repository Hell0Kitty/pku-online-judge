#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxn 2100
using namespace std;

int fa[maxn];
int N;
int num[maxn];
int vis[maxn];

int find(int x)
{
    return x==fa[x]? x: fa[x]=find(fa[x]);
}
void Union(int x,int y)
{
    if(find(x)!=find(y))
    {
        fa[find(x)]=find(y);
    }
}
void solve()
{
    int i,j;
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    for(i=1;i<=N;i++)
    {
        num[find(i)]++;
    }
    int ans=0;
    for(i=1;i<=N;i++)
    {
        if(vis[find(i)]||vis[find(i+N)]) continue;
        ans+=max(num[find(i)],num[find(i+N)]);
        vis[find(i)]=vis[find(i+N)]=1;
    }
    printf("%d\n",ans);
}

int main()
{
    //freopen("input.txt","r",stdin);
    int i,j;
    while(scanf("%d",&N)==1&&N)
    {
        char s1[10],s2[10],s3[10];
        int temp;
        int flag=0;
        for(i=1;i<=N*2;i++)
        {
            fa[i]=i;
        }
        for(i=1;i<=N;i++)
        {
            scanf("%s %d %s %s",s1,&temp,s2,s3);
            if(s3[0]=='f')
            {
                if((find(i+N)==find(temp+N))||(find(i)==find(temp)))
                {
                    flag=1;
                }
                else
                {
                    Union(i,temp+N);
                    Union(i+N,temp);
                }
            }
            else
            {
                if((find(i+N)==find(temp))||(find(i)==find(temp+N)))
                {
                    flag=1;
                }
                else
                {
                    Union(i,temp);
                    Union(i+N,temp+N);
                }
            }
        }

        if(flag)
        {
            puts("Inconsistent");
        }
        else
        {
            solve();
        }
    }
    return 0;
}


