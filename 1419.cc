#include<cstdio>
#include<cstring>
#define N 1010
bool flag[N], a[N][N];
int ans, cnt[N], group[N], n, m, vis[N]; 
bool dfs( int u, int pos ){
    int i, j;
    for( i = u+1; i <= n; i++){
        if( cnt[i]+pos <= ans ) return 0;
        if( a[u][i] ){
             // 与目前团中元素比较，取 Non-N(i) 
            for( j = 0; j < pos; j++ ) if( !a[i][ vis[j] ] ) break; 
            if( j == pos ){     // 若为空，则皆与 i 相邻，则此时将i加入到 最大团中 
                vis[pos] = i;
                if( dfs( i, pos+1 ) ) return 1;    
            }    
        }
    }    
    if( pos > ans ){
            for( i = 0; i < pos; i++ )
                group[i] = vis[i]; // 最大团 元素 
            ans = pos;
            return 1;    
    }    
    return 0;
} 
void maxclique()
{
    ans=-1;
    for(int i=n;i>0;i--)
    {
        vis[0]=i;
        dfs(i,1);
        cnt[i]=ans;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while( T-- ){
        scanf("%d%d",&n,&m );
        int x, y;
        memset( a, 0, sizeof(a));
        for(int i = 0; i < m; i++){
            scanf("%d%d",&x,&y);
            a[x][y] = a[y][x] = 1;
        }    
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if( i == j ) a[i][j] = 0;
                else    a[i][j] ^= 1;
        maxclique();

        if( ans < 0 ) ans = 0;
        printf("%d\n", ans );
        for(int i = 0; i < ans; i++)
            printf( i == 0 ? "%d" : " %d", group[i] );
        if( ans > 0 ) puts("");
    }        
}




