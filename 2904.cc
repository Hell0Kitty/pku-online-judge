#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<set>
#include<list>
#include<numeric>
#include<cassert>

using namespace std;

const int INF = 1000000000;

int dp[11][101][101];

int main()
{
    for(int i = 1 ; i <= 100 ; i ++){
        for(int j = i ; j <= 100 ;j++){
            dp[1][i][j] = (j-i+1)*(j+i)/2;
        }
    }
    for(int k = 2 ; k <= 10 ; k++){
        for(int j = 100 ; j > 0 ; j--){
            for(int i = j;  i > 0 ; i--){//dp[k,j,j] = j
                dp[k][i][j] = INF;
                for(int  t = i; t <= j ; t++){
                    dp[k][i][j] = min(dp[k][i][j] , t + max(dp[k][t+1][j] , dp[k-1][i][t-1]));
                }
            }
        }
    }

    int T;
    for(scanf("%d",&T); T-- ;){
        int k , m;
        scanf("%d%d",&k,&m);
        printf("%d\n",dp[k][1][m]);
    }

    return 0;
}


