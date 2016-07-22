#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int maxn = 22;
int map[maxn][maxn],onoff[maxn][maxn],download[maxn],already[maxn];
bool server[maxn];
int m,n,s,t;

void read()
{
    memset(server,false,sizeof(server));
    memset(download,-1,sizeof(download));
    memset(already,0,sizeof(already));
    scanf("%d %d %d %d",&n,&t,&m,&s);
    int num;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&num);
        server[num] = true;
        already[num] = s;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&onoff[i][0]);
        onoff[i][0] <<= 1;
        for(int j=1;j<=onoff[i][0];j++)
        {
            scanf("%d",&onoff[i][j]);
        }
    }
    scanf("%d",&m);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        download[y] = x;
    }
    return;
}

bool check(int num,int ti)
{
    for(int i=1;i<onoff[num][0];i+=2)
    {
        if(onoff[num][i] <= ti && onoff[num][i+1] > ti)
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    for(int i=0;i<=t;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(download[j] == -1 || download[j] > i || server[j] || check(j , i) == false) continue;
            int sum = 0;
            for(int k=1;k<=n;k++)
            {
                if(server[k] && check(k , i))
                {
                    sum += map[j][k];
                }
            }
            already[j] += sum;
            if(already[j] >= s)
            {
                already[j] = s;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(server[j] == false && already[j] == s)
            {
                server[j] = true;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d%%\n",100 * already[i] / s);
    }
    return;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        read();
        solve();
    }
    return 0;
}




