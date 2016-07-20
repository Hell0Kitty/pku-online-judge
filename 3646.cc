#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX 20001
using namespace std;
int n,m,a[MAX],b[MAX];
int main()
{
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
	for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
	    scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
	int ans=0,cou=0,i;
	for(i=0;i<n;i++)
	{
	    while(cou<m&&b[cou]<a[i])
		cou++;
	    if(cou<m)
		ans+=b[cou++];
	    else
		break;
	}
	if(i==n)
	    printf("%d\n",ans);
	else
	    printf("Loowater is doomed!\n");
    }
    return 0;
}


