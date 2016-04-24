#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int f[30];

int find(int top, int pos)
{
    while (f[pos] < top && pos < 26)
        pos++;
    if (pos == 26)
        return -1;
    return pos;
}

int main()
{
    char ch;
    while ((ch = getchar()) != EOF)
        if (ch <= 'Z' && ch >= 'A')
            f[ch - 'A']++;
    int top = 0;
    for (int i = 0; i < 26; i++)
        top = max(f[i], top);
    for (int i = top; i >= 1; i--)
    {
        int pos = 0;
        bool first = true;
        while (1)
        {
            int temp = find(i, pos);
            if (temp == -1)
                break;
            if (!first)
                printf(" ");
            else
                first = false;
            for (int j = pos; j < temp; j++)
                printf("  ");
            printf("*");
            pos = temp + 1;
        }
        printf("\n");
    }
    printf("A");
    for (int i = 0; i < 25; i++)
        printf(" %c", i + 'B');
    printf("\n");
    return 0;
}



