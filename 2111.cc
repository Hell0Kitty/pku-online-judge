#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int N= 366;
const int INF = 0x3f3f3f3f;
int dp[N][N],pre[N][N];
int ini[N][N];
int n;
struct nod{
    int x,y,d;
    bool operator<(const nod t)const{
        return d>t.d;
    }
} re[N*N];
bool oor(int &x,int &y){
    if(x<0||x>=n) return false;
    if(y<0||y>=n) return false;
    return true;
}
int dx[]={-2,-2,-1,1,2,2,1,-1};
int dy[]={-1,1,2,2,1,-1,-2,-2};
int main()
{
     while(~scanf("%d",&n))
    {
        int cnt = 0;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&ini[i][j]);
            re[cnt].d = ini[i][j];
            re[cnt].x = i,re[cnt].y = j;
            cnt++;
        }
        sort(re,re+cnt);
        memset(dp,0,sizeof(dp));
        int i,j,tx,ty,x,y;
        int ff = INF,an = -1,rx,ry;
        for(i=0;i<cnt;i++)
        {
            x = re[i].x,y=re[i].y;
            int t = 0,ma=-1,f=INF;
            for(j=0;j<8;j++)
            {
                tx = x+dx[j],ty = y+dy[j];
                if(!oor(tx,ty)) continue;
                if(t<dp[tx][ty]||(t==dp[tx][ty]&&f>ini[tx][ty]))
                t = dp[tx][ty],ma = j,f = ini[tx][ty];
            }
            dp[x][y] = ++t;
            pre[x][y] = ma;
            if(dp[x][y]>an||(dp[x][y]==an&&ini[x][y]<ff))
            an = dp[x][y], ff = ini[x][y],rx = x,ry = y;
        }
        printf("%d\n",dp[rx][ry]);
        tx = rx,ty = ry;
        for(int i=0;i<dp[rx][ry];i++)
        {
            printf("%d\n",ini[tx][ty]);
            int k = pre[tx][ty];
            tx += dx[k];
            ty += dy[k];
        }
    }
    return 0;
}



