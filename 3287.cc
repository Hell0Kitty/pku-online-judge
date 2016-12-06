#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10e4+10;
int a[maxn],num[maxn*10];
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
	memset(num,0,sizeof(num));
	int k=0;
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	    num[a[i]]++;
	    k=max(k,num[a[i]]);
	}
	sort(a,a+n);
	printf("%d\n",k);
	for(int i=0;i<k;i++)
	{
	    printf("%d",a[i]);
	    for(int j=i+k;j<n;j+=k)
		printf(" %d",a[j]);
	    printf("\n");
	}
    }
    return 0;
}


