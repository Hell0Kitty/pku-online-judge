#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,c,gp[705][705],dp_max[705],dp_min[705];
int q1[10005],q2[10005],r1,f1,r2,f2;
void insert1(int k)
{
	while(r1>f1&&dp_min[q1[r1]]>dp_min[k])
		r1--;
	q1[++r1]=k;
}
void insert2(int k)
{
	while(r2>f2&&dp_max[q2[r2]]<dp_max[k])
		r2--;
	q2[++r2]=k;
}
int main()
{

	while(~scanf("%d%d%d",&m,&n,&c))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&gp[i][j]);
		int ans=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			dp_min[j]=dp_max[j]=gp[j][i];
			for(int j=i;j<m&&j-i<100;j++)
			{
				for(int k=0;k<n;k++)
				{
					dp_min[k]=min(dp_min[k],gp[k][j]);
					dp_max[k]=max(dp_max[k],gp[k][j]);
				}
				r1=r2=f1=f2=0;
				int r=0,f=0,len=0;
				while(r<n)
				{
					insert1(r);
					insert2(r);
					while(f<=r&&f1<r1&&f2<r2&&dp_max[q2[f2+1]]-dp_min[q1[f1+1]]>c)
					{
						f++;
						while(f1<r1&&q1[f1+1]<f)
							f1++;
						while(f2<r2&&q2[f2+1]<f)
							f2++;
					}
					r++;
					len=max(len,r-f);
				}
				ans=max(ans,len*(j-i+1));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


