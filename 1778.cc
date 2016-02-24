#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX= 100100;

vector<int> num[MAX];
queue<int> que[2];
int n1, n2, d;
int dat[MAX], bak[MAX];

int line(int k)
{
    return k>n1?1:0;
}

int bfs( int k )
{
    int i;
    for ( i = 0 ; i < 2 ; i++ )
    {
        while ( !que[i].empty() )
            que[i].pop();
    }
    for ( i = 1 ; i <= n1+n2 ; i++ )
    {
        if ( !dat[i] )
            que[line(i)].push(i);
    }
    int count = 1 ;
    while ( !que[0].empty() || !que[1].empty() )
    {
        while(!que[k].empty())
        {
            int t= que[k].front();
            que[k].pop();
            for ( i = 0 ; i < num[t].size() ; i++ )
            {
                if ( !(--dat[num[t][i]]) )
                {
                    que[line(num[t][i])].push(num[t][i]);
                }
            }
        }
        k^=1;
        count++;
    }
    return count;
}

int main()
{
    while ( scanf("%d%d%d", &n1, &n2, &d) , n1 || n2 || d )
    {
        int i, x, y;
        for ( i = 1 ; i <= n1+n2 ; i++ )
        {
            num[i].clear();
            bak[i]= 0;
        }
        for ( i = 0 ; i < d ; i++ )
        {
            scanf("%d%d", &x, &y);
            num[y].push_back(x);
            bak[x]++;
        }
        for ( i = 1 ; i <= n1+n2 ; i++ )
            dat[i]=bak[i];
        x=bfs(0);
        for ( i = 1 ; i <= n1+n2 ; i++ )
            dat[i]=bak[i];
        y=bfs(1);
        printf("%d\n", x<y?x:y);
    }
    return 0;
}



