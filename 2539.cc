#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

const int M = 300;
int t,a,b;

char* toString(int x)
{
    char *res = new char[M];
    memset(res,0,M);
    int i = 0;
    while(x)
    {
        res[i++] = x % 10 + '0';
        x /= 10;
    }
    return res;
}

char* multi(char* a, char* b)
{
    char *res = new char[M];
    memset(res,0,M);
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 0;i<lena; i++)
    {
        int last = 0;
        for (int j = 0; j<lenb; j++)
        {
            res[i + j] += (a[i] - '0') * (b[j] - '0') + last;
            last = res[i + j] / 10;
            res[i + j] %= 10;
        }
        for (int j = lenb + i;last;j++)
        {
            res[j] += last;
            last = res[j] / 10;
            res[j] %= 10;
        }
    }
    int lenres = M - 1;
    for (int i = M - 1;i>=0;i--) res[i] += '0';
    while(res[--lenres] == '0') res[lenres] = 0;
    return res;
}

char* pow(char* a, int b)
{
    char* res = toString(1), *tmp;
    while(b)
    {
        if (b & 1)
        {
            tmp = multi(res, a);
            delete res;
            res = tmp;
        }
        tmp = multi(a,a);
        delete a;
        a = tmp;
        b >>= 1;
    }
    delete a;
    return res;
}

char* add(char* a, char* b)
{
    if (strlen(a) < strlen(b))
    {
        swap(a,b);
    }
    int lena = strlen(a), lenb = strlen(b);
    char* res = new char[M];
    memset(res,0,M);
    int last = 0;
    for (int i = 0;i<lenb;i++)
    {
        res[i] = a[i] + b[i] + last -'0' -'0';
        last = res[i] / 10;
        res[i] %= 10;
    }
    for (int i = lenb; i < lena;i++)
    {
        res[i] = a[i] + last - '0';
        last = res[i] / 10;
        res[i] %= 10;
    }
    if (last)
        res[lena] = last + '0';
    int lenres = M - 1;
    for (int i = M - 1;i>=0;i--) res[i] += '0';
    while(res[--lenres] == '0') res[lenres] = 0;
    return res;
}

int main()
{
    while(scanf("%d%d%d",&t,&a,&b)==3)
    {
        printf("(%d^%d-1)/(%d^%d-1) ",t,a,t,b);
        if (t==1 || a%b || (long long)(log10(t+0.)*(a-b))+1>=100LL)
        {
            puts("is not an integer with less than 100 digits.");
        }
        else
        {
            if(a == b)
            {
                puts("1");
                continue;
            }
            int tmp = a / b;
            char *in,*m,*more = pow(toString(t), b);
            in = toString(0);
            m = toString(1);
            for (int i = 0;i < tmp; i++)
            {
                char* tmp = add(in,m);
                delete in;
                in = tmp;
                tmp = multi(m, more);
                delete m;
                m = tmp;
            }
            for (int i = strlen(in) - 1;i>=0;i--)
            {
                putchar(in[i]);
            }
            puts("");

            delete in;
            delete m;
            delete more;
        }
    }
    return 0;
}


