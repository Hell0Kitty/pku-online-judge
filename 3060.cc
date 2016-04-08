#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N=1000;
const int inf=1e9;
int a[N][N],d,n,nx[N],ny[N];
int main()
{
    int w;cin>>w;
    while(w--)
    {
        scanf("%d%d",&d,&n);
        memset(a,0,sizeof(a));
        memset(nx,0,sizeof(nx));
        memset(ny,0,sizeof(ny));
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x=(x+inf)%d;y=(y+inf)%d;
            a[x][y]++;
            nx[x]++;
            ny[y]++;
        }
        int ans=inf;
        for(int i=0;i<d;i++)
        for(int j=0;j<d;j++) ans=min(ans,nx[i]+ny[j]-a[i][j]);
        printf("%d\n",ans);
    }
    return 0;
}



