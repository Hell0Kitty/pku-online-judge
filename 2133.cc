#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
struct T
{
    int n;
    int c;
};
queue<T> q;
int tar,len,le,v[68000],E[120];
char str[20]="11001";
T tp,tp2;
int f(int len,char *str)
{
    int i,cnt;
    cnt=0;
    for (i=len-1; i>=0; i--)
    {
        cnt+=(str[i]=='1')?pow(2,len-i-1):0;
    }
    return cnt;
}
char *g(int len,int n)
{

    int i;
    for (i=len-1; i>=0; i--)
    {
        if (n>=pow(2,i))
        {
            str[len-i-1]='1';
            n-=pow(2,i);
        }
        else
            str[len-i-1]='0';
    }
    str[len]='\0';
    return str;
}
int judge(int a,int b)
{
    int cnt,t,i;
    cnt=0;
    for (i=len-1; i>=0; i--)
    {
        t=pow(2,i);
        if (a >= t && b >= t)
        {
            a-=t;
            b-=t;
        }
        else if (a >= t && b < t)
        {
            a-=t;
            cnt++;
        }
        else if (a < t && b >= t)
        {
            b-=t;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int i,j,ans,degree;
    scanf("%d%d",&len,&le);
    getchar();
    scanf("%s",str);

    tar=f(len,str);
    while (!q.empty())
        q.pop();
    memset(v,0,sizeof(v));
    for (i=0; i<le; i++)
    {
        scanf("%s",str);
        E[i]=f(len,str);
        tp.n=E[i];
        tp.c=0;
        q.push(tp);
    }
    while (!q.empty())
    {
        tp=q.front();
        q.pop();
        for (i=0; i<le; i++)
        {
            tp2.n=tp.n^E[i];
            if (v[tp2.n] == 0)
            {
                v[tp2.n]=tp.c+1;
                tp2.c=tp.c+1;
                q.push(tp2);
            }
            else if (v[tp2.n] != 0 && tp.c+1 < v[tp2.n])
            {
                v[tp2.n]=tp.c+1;
                q.push(tp2);
            }
        }
    }
    if (v[tar] != 0)
    {
        printf("%d\n%s\n",v[tar],g(len,tar));
        return 0;
    }
    degree=-1;
    ans=-1;
    for (i=0; i<68000; i++)
    {
        if (v[i] != 0)
        {
            j=judge(tar,i);
            if (degree == -1 || degree > j)
            {
                ans=i;
                degree=j;
            }
            else if (degree == j)
            {
                if (v[ans] > v[i])
                {
                    ans=i;
                }
            }
        }
    }
    printf("%d\n%s\n",v[ans],g(len,ans));
}



