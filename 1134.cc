#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int num[3][3]={0};
int cnt[3][3][3]=//map to the sorted row 3 numbers
{
	{{5,6,8},{5,7,7},{5,7,7}},
	{{5,7,7},{5,6,8},{5,7,7}},
	{{5,7,7},{5,7,7},{5,6,8}}
};
int cases=0;//the count of the test
/*for test*/
int test()
{
	return(0);
}
/*main process*/
int MainProc()
{
	int t=0,i=0,j=0,k=0;
	scanf("%d",&cases);
	for(t=1;t<=cases;t++)
	{
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=2;j++)
			{
				scanf("%d",&num[i][j]);
			}
			sort(num[i],num[i]+3);
		}
		int sum=0;
		int maxsum=0;
		for(k=0;k<=2;k++)//cnt[0] map to num[k]
		{
			sum=0;
			for(i=0;i<=2;i++)
			{
				for(j=0;j<=2;j++)
				{
					sum+=num[i][j]*cnt[k][i][j];
				}
			}
			if(sum>maxsum)
			{
				maxsum=sum;
			}
		}
		printf("Test #%d\n%d\n\n",t,maxsum);
	}
	return(0);
}
int main(int argc, char const *argv[])
{
	/* code */
	MainProc();
	return 0;
}


