#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<set>
#include<vector>
#define MAXN 15
#define INF 1000
using namespace std;
int no[2000000],maxok[2000000];
int main()
{
	int i,j,n,m,k,t,c,ca=0;
	for(scanf("%d",&t);t--;)
	{
		ca++;
		scanf("%d%d",&n,&k);
		if(n<=k+1)
		{
			printf("Case %d: lose\n",ca);
			continue;
		}
		int x=0,y=0;
		no[0]=maxok[0]=1;
		while(no[x]<n)
		{
			x++;
			no[x]=maxok[x-1]+1;
			while(no[y+1]*k<no[x])
				y++;
			if(no[y]*k<no[x])
				maxok[x]=no[x]+maxok[y];
			else
				maxok[x]=no[x];
		}
		if(no[x]==n)
		{
			printf("Case %d: lose\n",ca);
			continue;
		}
		int ans;
		while(n)
		{
			if(n>=no[x])
			{
				ans=no[x];
				n-=no[x];
			}
			x--;
		}
		printf("Case %d: %d\n",ca,ans);
	} 
	return 0;
}


