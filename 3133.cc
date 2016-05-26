#include<stdio.h>
#include<string.h>
#include<algorithm>
#define HASH 41941 
#define SIZE 100010
#define MAXN 15
struct HashMap
{
    int head[HASH], size, next[SIZE], st[SIZE], f[SIZE];
    void init()
    {
        memset(head, -1, sizeof(head)), size = 0;
    }
    void push(int _st, int _f)
    {
        int i, h = _st % HASH;
        for(i = head[h]; i != -1; i = next[i])
            if(st[i] == _st) break;
        if(i == -1)
        {
            st[size] = _st, f[size] = _f;
            next[size] = head[h], head[h] = size ++;    
        }
        else f[i] = std::min(f[i], _f);
    }
}hm[2];
int N, M, g[MAXN][MAXN], h[MAXN], code[MAXN];
inline int encode(int *code, int m)
{
    int i, st = 0, cnt = 2;
    memset(h, -1, sizeof(h)), h[0] = 0, h[1] = 1, h[2] = 2;
    for(i = 0; i <= m; i ++)
    {
        if(h[code[i]] == -1) h[code[i]] = ++ cnt;
        st = st << 3 | h[code[i]];
    }
    return st;
}
inline void decode(int *code, int m, int st)
{
    for(int i = m; i >= 0; i --) code[i] = st & 7, st >>= 3;    
}
void init()
{
    int i, j;
    memset(g, 0, sizeof(g));
    for(i = 1; i <= N; i ++)
        for(j = 1; j <= M; j ++)
        {
            scanf("%d", &g[i][j]);
            if(g[i][j] == 0) g[i][j] = 1;
            else if(g[i][j] == 1) g[i][j] = 0;
        }
}
inline void trans(int x, int y)
{
    for(int i = 0; i <= M; i ++) if(code[i] == x) code[i] = y;    
}
void dpblock(int i, int j, int cur)
{
    int k;
    for(k = 0; k < hm[cur].size; k ++)
        hm[cur ^ 1].push(hm[cur].st[k] >> 3 * (j == M), hm[cur].f[k]);
}
void dpblank(int i, int j, int cur)
{
    int k;
    for(k = 0; k < hm[cur].size; k ++)
    {
        decode(code, M, hm[cur].st[k]);
        if(code[j] && code[j - 1])
        {
            if(code[j] <= 2 && code[j - 1] <= 2 && code[j] != code[j - 1]) continue;
            if(code[j] != code[j - 1])
                trans(std::max(code[j], code[j - 1]), std::min(code[j], code[j - 1]));
            code[j] = code[j - 1] = 0;
            hm[cur ^ 1].push(encode(code, M - (j == M)), hm[cur].f[k] + 1);
        }
        else if(code[j])
        {
            if(g[i][j + 1]) hm[cur ^ 1].push(hm[cur].st[k], hm[cur].f[k] + 1);
            if(g[i + 1][j])
            {
                code[j - 1] = code[j], code[j] = 0;
                hm[cur ^ 1].push(encode(code, M - (j == M)), hm[cur].f[k] + 1);    
            }
        }
        else if(code[j - 1])
        {
            if(g[i + 1][j]) hm[cur ^ 1].push(hm[cur].st[k] >> 3 * (j == M), hm[cur].f[k] + 1);
            if(g[i][j + 1])
            {
                code[j] = code[j - 1], code[j - 1] = 0;
                hm[cur ^ 1].push(encode(code, M), hm[cur].f[k] + 1);    
            }
        }
        else
        {
            hm[cur ^ 1].push(hm[cur].st[k] >> 3 * (j == M), hm[cur].f[k]);
            if(g[i][j + 1] && g[i + 1][j])
            {
                code[j] = code[j - 1] = M + 2;
                hm[cur ^ 1].push(encode(code, M), hm[cur].f[k] + 1);
            }
        }
    }    
}
void dp(int i, int j, int cur)
{
    int k;
    for(k = 0; k < hm[cur].size; k ++)
    {
        decode(code, M, hm[cur].st[k]);
        if(code[j] && code[j - 1]) continue;
        else if(code[j])
        {
            if(code[j] <= 2 && code[j] != g[i][j] - 1) continue;
            if(code[j] > 2) trans(code[j], g[i][j] - 1);
            code[j] = 0;
            hm[cur ^ 1].push(encode(code, M - (j == M)), hm[cur].f[k] + 1);

        }
        else if(code[j - 1])
        {
            if(code[j - 1] <= 2 && code[j - 1] != g[i][j] - 1) continue;
            if(code[j - 1] > 2) trans(code[j - 1], g[i][j] - 1);
            code[j - 1] = 0;
            hm[cur ^ 1].push(encode(code, M - (j == M)), hm[cur].f[k] + 1);
        }
        else
        {
            if(g[i][j + 1])
            {
                code[j] = g[i][j] - 1;
                hm[cur ^ 1].push(encode(code, M), hm[cur].f[k] + 1);
                code[j] = 0;    
            }
            if(g[i + 1][j])
            {
                code[j - 1] = g[i][j] - 1;
                hm[cur ^ 1].push(encode(code, M - (j == M)), hm[cur].f[k] + 1);    
            }
        }
    }
}
void solve()
{
    int i, j, cur = 0;
    hm[0].init(), hm[0].push(0, 0);
    for(i = 1; i <= N; i ++)
        for(j = 1; j <= M; j ++)
        {
            hm[cur ^ 1].init();
            if(g[i][j] == 0) dpblock(i, j, cur);
            else if(g[i][j] == 1) dpblank(i, j, cur);
            else dp(i, j, cur);
            cur ^= 1;
        }
    if(hm[cur].size == 0) printf("0\n");
    else printf("%d\n", hm[cur].f[0] - 2);
}
int main()
{
    while(scanf("%d%d", &N, &M), N)
    {
        init();
        solve();    
    }
    return 0;    
}



