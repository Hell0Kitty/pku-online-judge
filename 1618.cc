#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 605
#define maxl 30
#define maxm 105

struct Edge
{
    int next, v;
}edge[maxn * maxn];

int head[maxn];
int comb_cnt, type_cnt, streamer_len;
int comb_len;
char comb[maxn][maxl];
int ecount;
int f[maxm][maxn];

void input()
{
    for (int i = 0; i < comb_cnt; i++)
        scanf("%s", comb[i]);
}

void addedge(int a, int b)
{
    edge[ecount].v = b;
    edge[ecount].next = head[a];
    head[a] = ecount++;
}

bool connect1(char *a, char *b)
{
    for (int i = 1; i < comb_len; i++)
        if (a[i] != b[i - 1])
            return false;
    return true;
}

void make()
{
    comb_len = strlen(comb[0]);
    ecount = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < comb_cnt; i++)
        for (int j = 0; j < comb_cnt; j++)
            if (connect1(comb[i], comb[j]))
                addedge(i, j);
}

void work()
{
    memset(f, 0, sizeof(f));
    for (int i = 0; i < comb_cnt; i++)
        f[comb_len][i] = 1;
    for (int i = comb_len; i < streamer_len; i++)
        for (int j = 0; j < comb_cnt; j++)
            for (int k = head[j]; k != -1; k = edge[k].next)
                f[i + 1][edge[k].v] += f[i][j];
    int ans = 0;
    for (int i = 0; i < comb_cnt; i++)
        ans += f[streamer_len][i];
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d%d%d", &type_cnt, &streamer_len, &comb_cnt), type_cnt | streamer_len | comb_cnt)
    {
        input();
        make();
        work();
    }
    return 0;
}



