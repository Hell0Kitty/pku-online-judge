#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <iomanip>
using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long LL;
typedef pair<int,int> pii;

#define CLR(x,y) memset(x,y,sizeof(x));
#define PB push_back
#define MP make_pair
#define FOR(i,x,y) for(int i = (x) ; i < (y) ; ++i)
#define ROF(i,x,y) for(int i = (y)-1 ; i >= (x); --i)
#define INF 0x3f3f3f3f

const int N = 100+20;
int g[N][N];
int n,m,k;

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k)){
        CLR(g,-1);
        for(int i = 0; i < k ;i ++){
            int x,y,r,t;
            scanf("%d%d%d%d",&x,&y,&r,&t);
            if(t == 1){
                for(int i = 1; i <= n ; i++){
                    for(int j = 1 ;j <= m ; j ++){
                        if(g[i][j] == 1 || g[i][j] == -1)g[i][j] = 2;
                    }
                }
            }
            for(int i = x-r/2; i <= x+r/2 ; i ++){
                for(int j = y-r/2; j <= y+r/2 ; j ++){
                    if(!(i>0 && j>0 && i <= n && j <= m))continue;
                    if(t == 1){
                        if(g[i][j]==2)g[i][j] = 1;
                        else if(g[i][j]==-1)g[i][j] = 1;
                    }else{
                        g[i][j] = 0;
                    }
                }
            }
            for(int i = 1; i <= n ; i++){
                for(int j = 1 ;j <= m ;j ++)if(g[i][j] == 2)g[i][j] = 0;
            }
        }
        int ans = 0,tmp = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ;j <= m ; j++){
                if(g[i][j] == 1)ans ++;
                else if(g[i][j] == -1)tmp ++;
            }
        }
        if(ans > 0)printf("%d\n",ans);
        else printf("%d\n",tmp);
    }
    return 0;
}



