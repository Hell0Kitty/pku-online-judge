#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define N 1000
vector<int> vec[N];
int id[N],pre[N],low[N],s[N],stop,cnt,scnt;
int e[N][2];
void tarjan(int v,int n)
{
    int t,minc = low[v] = pre[v] = cnt++;
    vector<int>::iterator pv;
    s[stop++] = v;
    for(pv = vec[v].begin(); pv != vec[v].end(); ++pv)
    {
        if(-1 == pre[*pv])
            tarjan(*pv,n);
        if(low[*pv] < minc)
            minc = low[*pv];
    }
    if(minc < low[v])
    {
        low[v] = minc;
        return;
    }
    do{
        id[t=s[--stop]] = scnt;
        low[t] = n;
    }while(t != v);
    ++scnt;
}
bool solve(int n)
{
    int i;
    for(i = 0; i < n; ++i)
        if(-1 == pre[i])
            tarjan(i,n);
    for(i = 0; i < n; i += 2)
        if(id[i] == id[i+1])
            return 0;
    return 1;
}
int main()
{
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    memset(pre,-1,sizeof(pre));
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d",e[i],e[i]+1);
        if(e[i][0] > e[i][1])
            swap(e[i][0],e[i][1]);
    }
    for(a = 0; a < m; ++a)
        for(b = a + 1; b < m; ++b)
            if(e[b][0] > e[a][0] && e[b][0] < e[a][1] && e[b][1] > e[a][1] ||
               e[a][0] > e[b][0] && e[a][0] < e[b][1] && e[a][1] > e[b][1])
            {
                vec[a<<1].push_back(b<<1|1);
                vec[a<<1|1].push_back(b<<1);
                vec[b<<1].push_back(a<<1|1);
                vec[b<<1|1].push_back(a<<1);
            }
    printf(solve(m<<1) ? "panda is telling the truth...\n" : "the evil panda is lying again\n");
    return 0;
}



