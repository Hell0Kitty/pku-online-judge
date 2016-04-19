#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 20

char id[maxn];
int fac[] =
{ 9, 3, 7 };

int getpos(char ch)
{
    int len = strlen(id);

    for (int i = 0; i < len; i++)
        if (id[i] == ch)
            return i;
    return -1;
}

bool check()
{
    int sum = 0;
    int len = strlen(id);

    for (int i = len - 1; i >= 0; i--)
        sum += (id[i] - '0') * fac[(len - 1 - i) % 3];
    if (0 == sum % 10)
        return true;
    return false;
}

void work()
{
    gets(id);
    int pos = getpos('?');
    int len = strlen(id);
    for (int i = 0; i <= 9; i++)
    {
        id[pos] = i + '0';
        if (check())
            return;
    }
}

int main()
{
    int t, s = 0;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        s++;
        printf("Scenario #%d:\n", s);
        work();
        printf("%s\n\n", id);
    }
    return 0;
}



