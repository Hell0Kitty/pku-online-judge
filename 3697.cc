#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=10000007;
int hash[mod];
int getkey(int x)
{
    int i=1,y=x;
    y%=mod;
    while(hash[y]!=-1&&hash[y]!=x)
    {
        y+=i*i;
        i++;
        if(y>=mod)
            y%=mod;
    }
    return y;
}
int stk[10005];
bool vis[10005];
int main()
{
    int n,m,ca=0;
    while(scanf("%d%d",&n,&m),n,m)
    {
        memset(hash,-1,sizeof(hash));
        memset(vis,false,sizeof(vis));
        for(int i=0,a,b;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            a=a*10000+b;
            hash[getkey(a)]=a;
        }
        int f=0,r=1;
        stk[0]=1;
        vis[1]=true;
        while(f!=r)
        {
            int now=stk[f++];
            for(int i=2;i<=n;i++)
            {
                if(!vis[i]&&hash[getkey(now*10000+i)]==-1&&hash[getkey(i*10000+now)]==-1)
                {
                    stk[r++]=i;
                    vis[i]=true;
                }
            }
        }
        printf("Case %d: %d\n",++ca,r-1);
    }
    return 0;
}



