#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e3+9;
int a[maxn];
int ans;
int main()
{ 

int n,p,c;
    scanf("%d %d %d",&n,&p,&c);
    for(int i=1,tmp;i<=n;i++)
    {
        scanf("%d",&tmp);
        a[tmp]++;
    }
    for(int i=1;i<p;i++)
    {
        int tmp=0,j=i;
        while(j<p&&tmp+a[j]<=c)
        {
            tmp+=a[j++];
        }
        ans=max(ans,j-i);
    }
    printf("%d\n",ans);
    return 0;
}



