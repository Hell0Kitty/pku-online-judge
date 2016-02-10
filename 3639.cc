#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#define LL long long
#define clr(s,x) memset(s,x,sizeof(s))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const double PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn=1005;

double dp[maxn][2];
double per[maxn];

double get_ans(double x){
    x=x*100.0;
    int xx=(int)x;
    return xx/100.0;
}

int main()
{
    int n;
    while(cin>>n){
        clr(dp,0);
        clr(per,0);
        if(n==0)break;
        for(int i=1;i<=n;i++){
            cin>>per[i];
        }
        dp[0][0]=1000.0;
        dp[0][1]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=max(dp[i-1][0],get_ans(dp[i-1][1]*per[i]*0.97));
            dp[i][1]=max(dp[i-1][1],get_ans(dp[i-1][0]/per[i]*0.97));
        }
        printf("%.2f\n",dp[n][0]);
    }
    return 0;
}




