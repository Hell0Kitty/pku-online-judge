#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    char self[2005];
};
Node p[1000];
int a[2005];
int m;
int b,n;

char Change(int x)
{
    if (x<=9)
        return '0'+x;
    else
        return 'A'+x-10;
}
//从低位往高位搜索
void dfs(int dep,int sum)
{
    if(dep>n)
    {
        if(a[n]>0 || n == 1)
        {
            for(int i=n; i>=1; i--)
            {
                p[m].self[n-i] = Change(a[i]);
            }
            p[m].self[n] = '\0';
            m++;
        }
        return;
    }
    int tol = 0;
    for(a[dep]=0; a[dep]<b; a[dep]++)
    {
        tol = 0;
        for(int i=1; i<=dep; i++)
        {
            int j = dep-i+1;
            tol += a[i]*a[j];
        }
        if((tol+sum)%b == a[dep])
        {
            dfs(dep+1,(tol+sum)/b);
        }
    }
}
bool cmp(Node a,Node b)
{
    return strcmp(a.self,b.self)<0;
}
int main()
{
    while(scanf(" %d %d",&b,&n)!=EOF)
    {
        m = 0;
        dfs(1,0);
        sort(p,p+m,cmp);
        printf("%d\n",m);
        for(int i=0; i<m; i++)
        {
            printf("%s\n",p[i].self);
        }
    }
    return 0;
}



