#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 105
#define maxl 10

struct Word
{
    char w[maxl];
}word[maxn];

bool operator < (const Word &a, const Word &b)
{
    return strcmp(a.w, b.w) < 0;
}

bool ok(char *a, char *b)
{
    int ac[26], bc[26];
    memset(ac, 0, sizeof(ac));
    memset(bc, 0, sizeof(bc));
    for (int i = 0; i < strlen(a); i++)
        ac[a[i] - 'a']++;
    for (int i = 0; i < strlen(b); i++)
        bc[b[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (ac[i] != bc[i])
            return false;
    return true;
}

int main()
{
    int i = 0;
    while (gets(word[i].w), strcmp(word[i].w, "XXXXXX") != 0)
        i++;
    int n = i;
    sort(word, word + n);
    char st[maxl];
    while (gets(st), strcmp(st, "XXXXXX") != 0)
    {
        bool found = false;
        for (i = 0; i < n; i++)
            if (ok(word[i].w, st))
            {
                found = true;
                printf("%s\n",  word[i].w);
            }
        if (!found)
            printf("NOT A VALID WORD\n");
        printf("******\n");
    }
    return 0;
}


