#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

char card[20][10];
int n;
int m;
bool found;

bool ok(char a, char b, char c)
{
    if (a == b && b == c)
        return true;
    if (a == b || b == c || c == a)
        return false;
    return true;
}

bool ok(char *s1, char *s2, char *s3)
{
    for (int i = 0; i < 4; i++)
        if (!ok(s1[i], s2[i], s3[i]))
            return false;
    return true;
}

void work()
{
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (ok(card[i], card[j], card[k]))
                {
                    if (m == 0)
                        printf("%d.  %s %s %s\n", ++m, card[i], card[j], card[k]);
                    else
                        printf("        %d.  %s %s %s\n", ++m, card[i], card[j], card[k]);
                }
}

int main()
{
    while (true)
    {
        n = 0;
        m = 0;
        if (gets(card[n++]) == NULL)
            break;
        while (gets(card[n]) != NULL && strcmp(card[n], ""))
            n++;
        printf("CARDS: ");
        for (int i = 0; i < n; i++)
            printf(" %s", card[i]);
        putchar('\n');
        printf("SETS:   ");
        work();
        if (m == 0)
            printf("*** None Found ***\n");
        putchar('\n');
    }
    return 0;
}



