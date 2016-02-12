#include <stdio.h>
struct player{
	int w,b;
};
int max(int a,int b)
{
	if (a>b) return a;else return b;
}
int f[1003][16][16]={0};
main()
{
	struct player a[1003];
	int l=0,x,y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		l++;
		a[l].w=x;a[l].b=y;
	}
	int i;
	f[1][1][0]=a[1].w;f[1][0][1]=a[1].b;
	for (i=2;i<=l;i++)
	{
		int j,k;
		for (j=0;j<=15;j++)
		{
			int t=(i-j)<15?(i-j):15;
			for (k=0;k<=t;k++) 
			{
				if (j==0&&k==0) f[i][j][k]=0;
				else if (j==0)				
					f[i][j][k]=max(f[i-1][j][k-1]+a[i].b,f[i-1][j][k]);
				else if (k==0)				
					f[i][j][k]=max(f[i-1][j-1][k]+a[i].w,f[i-1][j][k]);
				else
					f[i][j][k]=max(max(f[i-1][j-1][k]+a[i].w,f[i-1][j][k-1]+a[i].b),f[i-1][j][k]);
			}
		}
	}
	printf("%d\n",f[l][15][15]);	
}



