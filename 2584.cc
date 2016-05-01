#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define esp 1e-6
#define pb push_back
#define print(a) printf("%d\n",(a));
#define bug puts("********))))))");
#define Rep(i, c) for(__typeof(c.end()) i = c.begin(); i != c.end(); i++)
#define inf 0x0f0f0f0f
using namespace std;
typedef long long  LL;
typedef vector<int> VI;
typedef vector<int>:: iterator IT;
#define N 100
int link[N][N], use[N], cap[N], n;
VI g[N];
char s[] = "SMLXT";
int f(char ch)
{
    for(int i = 0; i < 5; i++)
        if(ch == s[i])
           return i+1;
}
bool dfs(int x)
{
    int t;
    for(int i = 0; i < (int)g[x].size(); i++)
        if(!use[t = g[x][i]])
    {
        use[t] = true;
        if(link[t][0] < cap[t])
           return link[t][++link[t][0]] = x, true;
        else for(int j = 1; j <= cap[t]; j++)
            if(dfs(link[t][j]))
            return link[t][j] = x, true;
    }
    return false;
}
int match()
{

    memset(link, 0, sizeof(link));
    for(int i = 1; i <= n; i++)
     {
         memset(use,0, sizeof(use));
         if(!dfs(i))
        return false;
     }
    return true;
}
int main(void)
{
    char ss[100];
    while(scanf("%s", ss)&& ss[0] =='S')
    {
        char op[100];
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            g[i].clear();
            scanf("%s", op);
            int a = f(op[0]);
            int b = f(op[1]);
            for(int j = a; j <= b; j++)
            {
                g[i].pb(j);
            }
        }
        for(int i = 1; i<= 5; i++)
        {
            scanf("%d", cap+i);
        }
        scanf("%*s");
        if(match())
            puts("T-shirts rock!");
        else puts("I'd rather not wear a shirt anyway...");
    }
    return  0;
}



