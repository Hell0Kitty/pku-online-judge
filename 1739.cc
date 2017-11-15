#include<stdio.h>
#include<string.h>
#define HASH 30007
#define MAXD 15
#define SIZE 1000010
int N, M, maze[MAXD][MAXD], code[MAXD], ch[MAXD], ex, ey;
char b[MAXD];
struct Hashmap
{
    int head[HASH], next[SIZE], state[SIZE], size;
    long long f[SIZE];
    void init()
    {
        memset(head, -1, sizeof(head));
        size = 0;
    }
    void push(int st, long long ans)
    {
        int i, h = st % HASH;
        for(i = head[h]; i != -1; i = next[i])
            if(st == state[i])
            {
                f[i] += ans;
                return ;
            }
        state[size] = st, f[size] = ans;
        next[size] = head[h];
        head[h] = size ++;
    }
}hm[2];
void decode(int *code, int m, int st)
{
    int i;
    for(i = m; i >= 0; i --)
    {
        code[i] = st & 7;
        st >>= 3;
    }
}
int encode(int *code, int m)
{
    int i, cnt = 1, st = 0;
    memset(ch, -1, sizeof(ch));
    ch[0] = 0;
    for(i = 0; i <= m; i ++)
    {
        if(ch[code[i]] == -1)
            ch[code[i]] = cnt ++;
        code[i] = ch[code[i]];
        st <<= 3;
        st |= code[i];
    }
    return st;
}
void init()
{
    int i, j, k;
    ex = 0;
    memset(maze, 0, sizeof(maze));
    for(i = 1; i <= N; i ++)
    {
        scanf("%s", b + 1);
        for(j = M; j >= 1; j --)
            if(b[j] == '.')
            {
                maze[i][j] = 1;
                if(ex == 0)
                    ex = i, ey = j;
            }
    }
}
void shift(int *code, int m)
{
    int i;
    for(i = m; i > 0; i --)
        code[i] = code[i - 1];
    code[0] = 0;
}
void dpblank(int i, int j, int cur)
{
    int k, t, left, down;
    for(k = 0; k < hm[cur].size; k ++)
    {
        decode(code, M, hm[cur].state[k]);
        left = code[j - 1], down = code[j];
        if(left && down)
        {
            if(left == down)
            {
                if(i == ex && j == ey)
                {
                    code[j - 1] = code[j] = 0;
                    if(j == M)
                        shift(code, M);
                    hm[cur ^ 1].push(encode(code, M), hm[cur].f[k]);
                }
            }
            else
            {
                code[j - 1] = code[j] = 0;
                for(t = 0; t <= M; t ++)
                    if(code[t] == down)
                        code[t] = left;
                if(j == M)
                    shift(code, M);
                hm[cur ^ 1].push(encode(code, M), hm[cur].f[k]);
            }
        }
        else if(left || down)
        {
            if(maze[i][j + 1])
            {
                code[j - 1] = 0, code[j] = left + down;
                hm[cur ^ 1].push(encode(code, M), hm[cur].f[k]);
            }
            if(maze[i - 1][j])
            {
                code[j - 1] = left + down, code[j] = 0;
                if(j == M)
                    shift(code, M);
                hm[cur ^ 1].push(encode(code, M), hm[cur].f[k]);
            }
        }
        else
        {
            if(maze[i - 1][j] && maze[i][j + 1])
            {
                code[j - 1] = code[j] = 13;
                hm[cur ^ 1].push(encode(code, M), hm[cur].f[k]);
            }
        }
    }
}
void dpblock(int i, int j, int cur)
{
    int k;
    for(k = 0; k < hm[cur].size; k ++)
    {
        decode(code, M, hm[cur].state[k]);
        code[j - 1] = code[j] = 0;
        if(j == M)
            shift(code, M);
        hm[cur ^ 1].push(encode(code, M), hm[cur].f[k]);
    }
}
void solve()
{
    int i, j, cur = 0;
    long long ans = 0;
    memset(code, 0, sizeof(code));
    code[1] = code[M] = 1;
    hm[cur].init();
    hm[cur].push(encode(code, M), 1);
    for(i = N; i >= 1; i --)
        for(j = 1; j <= M; j ++)
        {
            hm[cur ^ 1].init();
            if(maze[i][j])
                dpblank(i, j, cur);
            else
                dpblock(i, j, cur);
            cur ^= 1;
        }
    for(i = 0; i < hm[cur].size; i ++)
        ans += hm[cur].f[i];
    printf("%lld\n", ans);
}
int main()
{
    for(;;)
    {
        scanf("%d%d", &N, &M);
        if(!N && !M)
            break;
        init();
        solve();
    }
    return 0;
}