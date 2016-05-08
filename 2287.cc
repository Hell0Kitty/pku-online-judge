#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010],b[1010];
int main()
{
	int n,i,j,i1,j1,sum;
	while(scanf("%d",&n) && n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(b,b+n);
		for(i=0,j=n-1,i1=0,j1=n-1;i1<=j1&&i<=j;)
		{
			if(a[i]>b[i1])
			{
				i++;
				i1++;
				sum++;
			}
			else if(a[i]<b[i1])
			{
				i++;
				j1--;
				sum--;
			}
			else if(a[j]>b[j1])
			{
				j--;
				j1--;
				sum++;
			}
			else if(a[j]<b[j1])
			{
				i++;
				j1--;
				sum--;
			}
			else if(a[i]<b[j1])
			{
				i++;
				j1--;
				sum--;
			}
			else
			{
				i++;
				j1--;
			}
		}
		printf("%d\n",sum*200);
	}
	return 0;
}




