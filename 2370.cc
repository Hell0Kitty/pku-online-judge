#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 110
int v[MAX];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
        }
        sort(v+1,v+n+1);
        int mid=n/2+1;
        int sum=0;
        for(i=1;i<=mid;i++)
        {
            sum+=v[i]/2+1;
        }
        printf("%d\n",sum);
    }
}



