#include <iostream>

#include <vector>

#include <map>

#include <cmath>

#include <memory>

#include <algorithm>

#include <cstdio>

#include <cstdlib>

using namespace std;

const int MAXN = 100;

const int INF = 1<<30;

#define CLR(x,y) memset(x,y,sizeof(x))

#define MIN(m,v) (m)<(v)?(m):(v)

#define MAX(m,v) (m)>(v)?(m):(v)

#define ABS(x) ((x)>0?(x):-(x))

#define rep(i,x,y) for(i=x;i<y;++i)

int n,m,k;

double ans = 0;

int select[MAXN];

int g[MAXN][MAXN];

int val[MAXN];

int visit[MAXN];

double dist[MAXN];

int ind[MAXN];

double Prim()

{

    int i,j,tmp,mark_i;

    int mark_min;

    int sum_node = 0;

    int sum_edge = 0;

    for(i = 0; i < n; ++i)

    {

        dist[i] = INF;

        visit[i] = 0;

    }

    for(i = 0; i < n; ++i)

        if(select[i]>0)

        {

            dist[i] = 0;

            break;

        }

    int cnt = 0;

    for(i = 0; i < n; ++i,++cnt)

    {

        if(cnt>=m) break;

        mark_min = INF;

        for(j  = 0; j < n; ++j)

        {

            if(select[j]>0 && !visit[j] && mark_min>dist[j])

            {

                mark_min = dist[j];

                mark_i = j;

            }

        }

        visit[mark_i] = 1;

        sum_edge += dist[mark_i];

        for( j = 0; j < n; ++j)

        {

            if(visit[j]==0 && select[j]>0 && dist[j] > g[mark_i][j])

                dist[j] = g[mark_i][j];

        }

    }

    for( i = 0; i < n; ++i)

        if(select[i] > 0 )

            sum_node += val[i];

    return double(sum_edge)/sum_node;

}
int DFS(int cur, int deep)

{

    double res = INF;

    select[cur] = 1;

    if(deep < m)

    {

        for(int i = cur+1; i < n; ++i)

        {

            DFS(i,deep+1);

        }

    }

    if(deep == m)

    {

        res = Prim();

        if(res < ans)

        {

            ans = res;

            for(int i = 0; i < n; ++i)

                ind[i] = select[i];

        }

    }

    select[cur] = 0;

    return 0;

}
int Solve()

{

    while(scanf("%d%d",&n,&m)!=EOF)

    {

        if(n == 0 && m == 0) break;

        for(int i = 0 ; i < n; ++i)

            scanf("%d",&val[i]);

        for(int i = 0; i < n; ++i)

            for(int j = 0; j < n; ++j)
            {
                scanf("%d",&g[i][j]);
            }
        CLR(select,0);

        ans = INF;

        for(int i = 0 ; i < n; ++i)

            DFS(i,1);

        int tag = 0;

        for(int i = 0; i < n; ++i)

            if(ind[i] > 0)

                if(tag == 0)

                {

                    printf("%d",i+1);

                    tag = 1;

                }

                else

                    printf(" %d",i+1);
        printf("\n");
    }
    return 0;
}
int main()
{
    Solve();
    return 0;
}


