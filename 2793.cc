#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct edge {
    int u, v;
};

const int MAXN = 20000;

struct HP   {
    int a[10000];
    void init(int x = 1) {
        memset(a, 0, sizeof(a));
        a[0] = a[1] = 1;
        a[1] = x;
    }
    void operator *= (int x)    {
        int i, len = a[0];
        for(i = 1; i <= len; i++)   a[i] *= x;
        for(i = 1; i <= len; i++)   {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            if(i >= len && a[i + 1])    len++;
        }
        a[0] = len;
    }
    void Print()    {
        for(int i = a[0]; i >= 1; i--)
            printf("%d", a[i]);
        puts("");
    }
}   cnt;

struct BCC  {
    int n;
    vector<edge> Edge;
    vector<int> G[MAXN + 10];

    void init(int n) {
        this->n = n;
        Edge.clear();
        for(int i = 1; i <= n; i++) G[i].clear();
    }

    void Addedge(int u, int v)  {
        Edge.push_back((edge){u, v});
        G[u].push_back(Edge.size() - 1);
    }

    int dcnt, dfn[MAXN + 10], low[MAXN + 10];
    stack<edge> S;

    void dfs(int u, int fa)  {
        dfn[u] = low[u] = ++dcnt;
        int f = 0;
        for(int i = 0; i < G[u].size(); i++)    {
            edge &e = Edge[G[u][i]];
            if(!dfn[e.v])   {
                S.push(e);
                dfs(e.v, e.u);
                low[e.u] = min(low[e.u], low[e.v]);
                if(dfn[e.u] <= low[e.v])    {
                    int c = 0;
                    edge x;
                    do  {
                        x = S.top();    S.pop();
                        c++;
                    }   while(x.u != e.u || x.v != e.v);
                    if(c != 1)
                        cnt *= (c + 1);
                }
                if(low[e.v] < dfn[e.u]) f++;
            }
            else if(dfn[e.v] < dfn[e.u] && fa != e.v)   {
                S.push(e);
                low[e.u] = min(low[e.u], dfn[e.v]);
                if(low[e.v] < dfn[e.u]) f++;
            }
        }
        if(f > 1)
            cnt.init(0);
    }

    void find_bcc() {
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        dcnt = 0;
        cnt.init(1);
        dfs(1, -1);
    }

}   sp;

int n, m;

void work() {
    sp.find_bcc();
    if(sp.dcnt != sp.n)    {
        puts("0");
        return ;
    }
    cnt.Print();
}

void Read_input()   {
    int i, j, u, v, c;
    sp.init(n);

    for(i = 1; i <= m; i++) {
        scanf("%d%d", &c, &u);
        for(j = 1; j < c; j++)  {
            scanf("%d", &v);
            sp.Addedge(u, v);
            sp.Addedge(v, u);
            u = v;
        }
    }
}

int main()  {
    while(scanf("%d%d", &n, &m) == 2)   {
        Read_input();
        work();
    }
    return 0;
}



