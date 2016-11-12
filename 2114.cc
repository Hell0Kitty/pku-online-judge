#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

const int maxn = 10500;
const int INF = 0x7FFFFFFF;
const int r1 = 2;

using namespace std;
typedef vector<int> array;
typedef array::iterator iter;
typedef vector<array>::iterator viter;

inline int getint()
{
    int ans(0); char w = getchar();
    while(w < '0' || '9' < w)w = getchar();
    while('0' <= w && w <= '9')
    {
        ans = ans * 10 + w - '0';
        w = getchar();
    }
    return ans;
}

inline int innew(int &a, int b){if(a < b){a = b; return 1;}return 0;}
inline int denew(int &a, int b){if(a > b){a = b; return 1;}return 0;}

struct edge
{
    int v, w, next;
}E[maxn << 1];
int a[maxn], nedge;
int n;
int ask[maxn], ans[maxn], nsk;

vector<array> P;
array tmp;

inline void add(int u, int v, int w)
{
    E[++nedge].v = v;
    E[nedge].w = w;
    E[nedge].next = a[u];
    a[u] = nedge;
}

namespace d_c
{
    int yff, dis[maxn], list[maxn], size[maxn], p[maxn];
    int q[maxn], st, ed;
    int d[maxn], last, now[maxn], had[maxn];
    int tlist[maxn], ttot, plist[maxn];

    inline int getcend(int k, int yff)
    {
        for(iter i = P[k].begin(); i != P[k].end(); ++i)
        {
            size[*i] = p[*i] = 0; now[*i] = a[*i];
        }
        size[d[last = 1] = P[k][0]] = 1;
        while(last)
        {
            int i = d[last], j = now[i];
            if(!j)
            {
                if(--last) size[d[last]] += size[i];
                continue;
            }
            if(!size[E[j].v])
            {
                size[d[++last] = E[j].v] = 1;
                p[E[j].v] = i;
            }
            now[i] = E[j].next;
        }
        int Max, ans, Min = INF; 
        for(iter i = P[k].begin(); i != P[k].end(); ++i)
        {
            Max = yff - size[*i];
            for(int j = a[*i]; j; j = E[j].next)if(p[*i] != E[j].v)
                innew(Max, size[E[j].v]);
            if(denew(Min, Max))ans = *i;
        }
        if(p[ans])size[p[ans]] = yff - size[ans];
        return ans;
    }

    inline void brutf(int k, int yff)
    {
        for(iter i = P[k].begin(); i != P[k].end(); ++i)
        {
            for(iter j = P[k].begin(); j != P[k].end(); ++j)dis[*j] = list[*j] = 0;
            int st = 0, ed = 1, tot;
            q[dis[*i] = 1] = *i;
            while(st < ed)
            {
                int x = q[++st];
                for(int i = a[x]; i; i = E[i].next)if(!dis[E[i].v])
                    dis[q[++ed] = E[i].v] = dis[x] + E[i].w;
            }
            for(iter j = P[k].begin(); j != P[k].end(); ++j)
                for(int need = 1; need <= nsk; ++need)
                    ans[need] += (dis[*j] == ask[need] + 1) << 1;
        }
    }

    inline void main(int k)
    {
        yff = P[k].size();
        if(yff <= r1){brutf(k, yff); return;}
        int cend = getcend(k, yff);
        for(iter i = P[k].begin(); i != P[k].end(); ++i) dis[*i] = had[*i] = 0; 
        st = 0; ed = 1; int tot;
        list[dis[q[1] = cend] = tot = 1] = 1;
        while(st < ed)
        {
            int x = q[++st];
            for(int i = a[x]; i; i = E[i].next)if(!dis[E[i].v])
            {
                list[++tot] = dis[q[++ed] = E[i].v] = dis[x] + E[i].w;
            }
        }

        sort(list + 1, list + tot + 1);
        tlist[plist[1] = ttot = 1] = list[1];
        for(int i = 2; i <= tot; ++i)
        {
            if(list[i] == list[i - 1])++plist[ttot];
            else {tlist[++ttot] = list[i]; plist[ttot] = 1;}
        }

        for(int need = 1; need <= nsk; ++need)
        {
            int j = ttot;
            for(int i = 1; i <= ttot; ++i)
            {
                while(j && (tlist[j] + tlist[i] > ask[need] + 2))--j;
                if(!j)break;
                if(tlist[j] + tlist[i] == ask[need] + 2)
                {
                    if(j != i)ans[need] += plist[i] * plist[j];
                    else ans[need] += plist[i] * (plist[i] - 1);
                }
            }
        }

        for(int i = a[cend]; i; i = E[i].next)
        {
            int sign = 0;
            if(a[E[i].v] == (i ^ 1)){a[E[i].v] = E[i ^ 1].next;}
            else
            {
                int last;
                for(int j = a[E[i].v]; j != (i ^ 1); j = E[j].next) last = j;
                E[last].next = E[i ^ 1].next;
            }
            tmp.clear(); 
            st = 0; ed = 1; q[had[E[i].v] = 1] = E[i].v;
            tmp.push_back(E[i].v);
            list[tot = 1] = dis[E[i].v];
            while(st < ed)
            {
                int x = q[++st];
                for(int j = a[x]; j; j = E[j].next)
                    if(!had[E[j].v]){tmp.push_back(E[j].v); had[E[j].v] = 1; q[++ed] = E[j].v; list[++tot] = dis[E[j].v];}
            }
            sort(list + 1, list + tot + 1);
            tlist[plist[1] = ttot = 1] = list[1];
            for(int w = 2; w <= tot; ++w)
            {
                if(list[w] == list[w - 1])++plist[ttot];
                else {tlist[++ttot] = list[w]; plist[ttot] = 1;}
            }

            for(int need = 1; need <= nsk; ++need)
            {
                int j = ttot;
                for(int w = 1; w <= ttot; ++w)
                {
                    while(j && (tlist[j] + tlist[w] > ask[need] + 2))--j;
                    if(!j)break;
                    if(tlist[w] + tlist[j] == ask[need] + 2)
                    {
                        if(j != w)ans[need] -= plist[w] * plist[j];
                        else ans[need] -= plist[w] * (plist[w] - 1);
                    }
                }
            }

            P.push_back(tmp);
            main(P.size() - 1);
        }

    }
}

int main()
{
    while(true)
    {
        n = getint();
        if(!n)break;
        P.clear(); tmp.clear();
        memset(a, 0, sizeof a);
        memset(ans, 0, sizeof ans);
        nedge = 1;

        for(int i = 1; i <= n; ++i)tmp.push_back(i);
        P.push_back(tmp);

        for(int i = 1; i <= n; ++i)
        {
            int x, w;
            while(true)
            {
                x = getint();
                if(!x)break;
                w = getint();
                add(i, x, w); add(x, i, w);
            }
        }
        nsk = 0;
        while(true)
        {
            ask[++nsk] = getint();
            if(!ask[nsk]){--nsk; break;}
        }
        d_c::main(0);
        for(int i = 1; i <= nsk; ++i)printf("%s\n", ans[i] > 0 ? "AYE" : "NAY");
        printf(".\n");
    }

    return 0;
}



