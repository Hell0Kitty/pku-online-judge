#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL dp[1005][1005][2],r[1005],l[1005],a[1005],n;
int main()
{
    int cl=0,cr=0,i,j;
    LL L;
    cin>>n>>L;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        if(a[i]==L)
            n--,i--;
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n&&a[i]<L;i++)
        l[++cl]=L-a[i];
    reverse(l+1,l+1+cl);
    for(;i<=n;i++)
        r[++cr]=a[i]-L;
    //reverse(r+1,r+1+cr);
    l[0]=r[0]=0;
    dp[0][0][0]=dp[0][0][1]=0;
    for(i=0;i<=cl;i++)
        for(j=0;j<=cr;j++)
        {
            if(i)
                dp[i][j][0]=min(dp[i-1][j][0]+(l[i]-l[i-1])*(n-i-j+1),dp[i-1][j][1]+(r[j]+l[i])*(n-i-j+1));
            if(j)
                dp[i][j][1]=min(dp[i][j-1][1]+(r[j]-r[j-1])*(n-i-j+1),dp[i][j-1][0]+(r[j]+l[i])*(n-i-j+1));
            if(i==0&&j)
                dp[i][j][0]=dp[i][j][1]+r[j]*(n-i-j);
            if(j==0&&i)
                dp[i][j][1]=dp[i][j][0]+l[i]*(n-i-j);
            //printf("%d")
        }
    cout<<min(dp[cl][cr][0],dp[cl][cr][1])<<endl;
    return 0;
}



