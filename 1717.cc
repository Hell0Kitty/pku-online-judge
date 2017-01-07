#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const int INF=1<<29;
bool dp[2][14005];
int num[2][14005], t[1005];
int main()
{
    int i, j, n, x, y;
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            t[i]=x-y;
        }
        int pre=1, last=0;
        memset(dp,0,sizeof(dp));
        dp[0][7000]=1;
        for(j=0;j<=14000;j++)
            num[pre][j]=INF;
        num[0][7000]=0;
        for(i=0;i<n;i++)
        {
            swap(pre,last);
            for(j=1000;j<=13000;j++)
            {
                if(dp[pre][j])
                {
                    dp[last][j+t[i]]=1;
                    num[last][j+t[i]]=min(num[last][j+t[i]],num[pre][j]);
                    dp[last][j-t[i]]=1;
                    num[last][j-t[i]]=min(num[last][j-t[i]],num[pre][j]+1);
                }
            }
            memset(dp[pre],0,sizeof(dp[0]));
            for(j=0;j<=14000;j++)
                num[pre][j]=INF;
        }
        for(i=0; i<=6000; i++)
        {
            if(dp[last][7000+i]||dp[last][7000-i])
            {
                printf("%d\n",min(num[last][7000+i],num[last][7000-i]));
                break;
            }
        }
    }
    return 0;
}



