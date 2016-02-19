#include<stdio.h>
#include <cstring>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
#define ll long long
#define MAX 999999
#define PI 3.14159265359

int nm[55555],a[55555],b[55555];

int main()
{
    int n,s,m,ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&nm[i]);

        a[0]=nm[0];

        for(int i=1;i<n;i++)
            a[i]=max(nm[i],a[i-1]+nm[i]);
        for(int i=1;i<n;i++)
            a[i]=max(a[i],a[i-1]);

        b[n-1]=nm[n-1];

        for(int i=n-2;i>-1;i--)
            b[i]=max(nm[i],nm[i]+b[i+1]);
        for(int i=n-2;i>-1;i--)
            b[i]=max(b[i],b[i+1]);

        ans = a[0]+b[1];

        for(int i=1;i<n-1;i++)
            ans=max(ans,a[i]+b[i+1]);

        printf("%d\n",ans);
    }
   return 0;
}



