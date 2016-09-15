#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 1005
#define maxl 100

struct Word
{
    int id;
    int len;
}word[maxn];

int n, m;
char st[maxn][maxl];
bool vis[maxn];
bool found;

bool operator < (const Word &a, const Word &b)
{
    return a.len < b.len;
}

void input()
{
    scanf("%d", &n);
    scanf("%s", st[n]);
    m = 0;
    int len1 = strlen(st[n]);
    found = false;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", st[i]);
        if (strcmp(st[n], st[i]) == 0)
            found = true;
        word[m].id = i;
        word[m].len = strlen(st[i]);
        if (word[m].len > len1)
            m++;
    }
    if (!found)
        abort();
    word[m].len = len1;
    word[m].id = n;
    m++;
}

bool match(char *st1, char *st2, int len)
{
    int l = 0;
    while (l < len && st1[l] == st2[l])
        l++;
    int r = len;
    while (r > 0 && st1[r - 1] == st2[r])
        r--;
    return l >= r;
}

void work()
{
    memset(vis, 0, sizeof(vis));
    vis[0] = true;
    for (int i = 0; i < m; i++)
        if (vis[i])
            for (int j = i + 1; j < m && word[j].len <= word[i].len + 1; j++)
                if (!vis[j] && word[j].len == word[i].len + 1 && match(st[word[i].id], st[word[j].id], word[i].len))
                    vis[j] = true;
    int i = m - 1;
    while (!vis[i])
        i--;
    printf("%s\n", st[word[i].id]);
}

int main()
{
    input();
    sort(word, word + m);
    work();
    return 0;
}



