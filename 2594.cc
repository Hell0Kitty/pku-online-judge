#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef char C;
typedef string S;

const double PI = 2.0 * acos(0.0);

#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)

#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define sz(a) (int)a.size()
#define sf scanf
#define pf printf
#define NL pf("\n")
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d", &a,&b, &c);
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d);
#define oo 1000000000

#define MOD 1000007
#define M 100099

int cases = 1;
bool vis[510];
bool g[510][510];
int par[510];
int n;

void floyd_warshall(void)
{
    REPE(k,1,n)
        REPE(i,1,n)
            REPE(j,1,n)
                if(g[i][k] && g[k][j]) g[i][j] = true;
    return ;
}

bool dfs(int u)
{
    REPE(i,1,n)
    {
        if(vis[i] == 0 && g[u][i] == true)
        {
            vis[i] = true;
            if(par[i] == -1 || dfs(par[i]))
            {
                par[i] = u;
                return true;
            }
        }
    }
    return 0;
}

int hungary(void)
{
    mem(par,-1);
    int ret = 0;
    REPE(i,1,n)
    {
        mem(vis,0);
        ret += dfs(i);
    }
    return ret;
}

int main()
{
    int test,m,u,v;
    while(sf2(n,m) == 2 && n)
    {
        mem(g,0);
        while(m--)
        {
            sf2(u,v);
            g[u][v] = true;
        }
        floyd_warshall();
        int ans = n-hungary();
        pf("%d\n",ans);
    }
    return 0;
}



