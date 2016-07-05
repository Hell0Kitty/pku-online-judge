#include<iostream>
#include<algorithm>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int n;
int data[64];
void init()
{
	for(int i=1;i<=20;i++)
	{
		data[i]=i;
		data[i+20]=i*2;
		data[i+40]=i*3;
	}
	data[61]=0;
	data[62]=50;
	data[63]=25;
}
int main()
{
	init();
	int cases;
	scanf("%d",&cases);
	for(int m=1;m<=cases;m++)
	{
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=63;i++)
		{
			for(int j=i;j<=63;j++)
			{
				for(int k=j;k<=63;k++)
				{
					if(data[i]+data[j]+data[k]==n)
					{
						ans++;
					}
				}
			}
		}
		printf("Scenario #%d:\n%d\n\n",m,ans);
	}
	return 0;
}



