#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 105;
int d[N][N][2],n,m;
void dp()
{
    int i,j;
    d[1][0][0] = d[1][0][1] = 1;
    for(i = 2; i <= 100; i ++){
        d[i][0][0] = d[i-1][0][1] + d[i-1][0][0];
        d[i][0][1] = d[i-1][0][0];
    }
    for(i = 2; i <= 100; i ++){
        for(j = 1; j <= 100; j ++){
            d[i][j][0] = d[i-1][j][0] + d[i-1][j][1];
            d[i][j][1] = d[i-1][j][0] + d[i-1][j-1][1];
        }
    }
}
int main()
{
    int T,i,j,t;
    dp();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&t,&n,&m);
        printf("%d %d\n",t,d[n][m][0] + d[n][m][1]);
    }
    return 0;
}



