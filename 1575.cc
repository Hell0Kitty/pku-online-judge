#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char st[50];

bool v(char a)
{
    return a =='a' ||a =='e' ||a =='i' ||a =='o' ||a =='u';
}

bool accept()
{
    int n = strlen(st);
    bool found = false;
    for (int i = 0; i < n; i++)
        if (v(st[i]))
        {
            found = true;
            break;
        }
    if (!found)
        return false;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (v(st[i]) == v(st[i - 1]))
            count++;
        else
            count = 1;
        if (count >= 3)
            return false;
    }
    for (int i = 1; i < n; i++)
        if (st[i] == st[i - 1] && st[i] != 'e' && st[i] != 'o')
            return false;
    return true;
}

int main()
{
    while (scanf("%s", st), strcmp(st, "end"))
    {
        if (accept())
            printf("<%s> is acceptable.\n", st);
        else
            printf("<%s> is not acceptable.\n", st);
    }
    return 0;
}


