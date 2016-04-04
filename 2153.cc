#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

#define maxn 10006

char li[40];
int n, m;
string name[maxn];
map <string, int> score;

int main()
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(li);
        name[i] = li;
        string st(li);
        score[st] = 0;
    }
    scanf("%d", &m);
    getchar();
    char na[40];
    strcpy(li, "Li Ming");
    int mark;
    while (m--)
    {
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            getchar();
            gets(na);
            string st(na);
            score[st] += a;
            if (strcmp(na, li) == 0)
                mark = score[st];
        }
        int rank = 1;
        for (int i = 0; i < n; i++)
            if (score[name[i]] > mark)
                rank++;
        printf("%d\n", rank);
    }
    return 0;
}



