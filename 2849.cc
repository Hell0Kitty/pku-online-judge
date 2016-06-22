#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

#define MAX 32767

int c;
int bf[150000];
char t[150000];
int jump[150000];
int po[32767];

stack<int> cycle;

void compile()
{
    while (!cycle.empty()) cycle.pop();
    memset(po, 0, sizeof(po));
    memset(jump, 0, sizeof(jump));
    int n = c;
    int p = 0;
    rep(c, n)
    {
        if (bf[c] == '[')
            cycle.push(c);
        if (bf[c] == ']')
        {
            if (cycle.empty() == true)
            {
                printf("COMPILE ERROR");
                return ;
            }
            int t = cycle.top();
            cycle.pop();
            jump[c] = t;
            jump[t] = c;
        }

    }
    if (cycle.empty() == false)
    {
        printf("COMPILE ERROR");
        return ;
    }
    rep(c, n)
    {
        if (bf[c] == '+')
        {
            po[p]++;
            po[p] &= 255;
        }
        if (bf[c] == '-')
        {
            po[p] += 255;
            po[p] &= 255;
        }
        if (bf[c] == '>')
        {
            p++;
            p &= MAX;
        }
        if (bf[c] == '<')
        {
            p += MAX;
            p &= MAX;
        }
        if (bf[c] == '.')
        {
            putchar((unsigned char)(po[p]));
        }
        if (bf[c] == '[')
        {
            if (po[p] == 0)
            {
                c = jump[c];
            }
        }
        if (bf[c] == ']')
        {
            if (po[p] != 0)
                c = jump[c];
        }
    }
    return ;
}
int main()
{
    int T;
    scanf("%d", &T);
    rep(cases, T)
    {
        c = 0;
        while (1)
        {
            gets(t);
            if (strcmp(t, "end") == false)
            {
                printf("PROGRAM #%d:\n", cases + 1);
                compile();
                printf("\n");
                break;
            }
            int len = strlen(t);
            rep(i, len)
            {
                if (t[i] == '%') break;
                if (t[i] == '+' || t[i] == '-' || t[i] == '>' || t[i] == '<' || t[i] == '.' || t[i] == '[' || t[i] == ']')
                    bf[c++] = t[i];
            }
        }
    }
}



