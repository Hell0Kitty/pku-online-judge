#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXD 1010
int n, pat;
char b[MAXD];
void init()
{
    int i, j, k, p;
    gets(b);
    for(i = 0; b[i] == ' '; i ++);
    for(j = strlen(b) - 1; b[j] == ' '; j --);
    for(k = 0, p = i; p <= j; p ++, k ++)
        b[k] = b[p];
    b[k] = '\0';
    n = k;
}
void pattern(int i)
{
    if(pat == 0)
    {
        if(b[i] == '+' || b[i] == '-')
            pat = 1;
        else
            pat = 2;
    }
    else if(pat == 1)
    {
        pat = 2;
    }
    else if(pat == 2)
    {
        if(b[i] == '.')
            pat = 3;
        else if(b[i] == 'e' || b[i] == 'E')
            pat = 5;
    }
    else if(pat == 3)
    {
        pat = 4;
    }
    else if(pat == 4)
    {
        if(b[i] == 'e' || b[i] == 'E')
            pat = 5;
    }
    else if(pat == 5)
    {
        if(b[i] == '+' || b[i] == '-')
            pat = 6;
        else
            pat = 7;
    }
    else if(pat == 6)
    {
        pat = 7;
    }
}
int check(int i)
{
    if(pat == 1)
    {
        if(b[i] == '+' || b[i] == '-')
            return 1;
        else
            return 0;
    }
    else if(pat == 2)
    {
        if(isdigit(b[i]))
            return 1;
        else
            return 0;
    }
    else if(pat == 3)
    {
        if(b[i] == '.')
            return 1;
        else
            return 0;
    }
    else if(pat == 4)
    {
        if(isdigit(b[i]))
            return 1;
        else
            return 0;
    }
    else if(pat == 5)
    {
        if(b[i] == 'e' || b[i] == 'E')
            return 1;
        else
            return 0;
    }
    else if(pat == 6)
    {
        if(b[i] == '+' || b[i] == '-')
            return 1;
        else
            return 0;
    }
    else
    {
        if(isdigit(b[i]))
            return 1;
        else
            return 0;
    }
}
int solve()
{
    int i;
    pat = 0;
    for(i = 0; i < n; i ++)
    {
        pattern(i);
        if(!check(i))
            return 0;
    }
    if(pat == 2 || pat == 4 || pat == 7)
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    gets(b);
    sscanf(b, "%d", &t);
    while(t --)
    {
        init();
        if(solve())
            printf("LEGAL\n");
        else
            printf("ILLEGAL\n");
    }
    return 0;
}


