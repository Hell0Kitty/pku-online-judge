#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int n;
int ans;
char data[15];
char prt[10];
bool cmp(char a,char b)
{
	return a>b;
}
int calc(int v,int w,int x,int y,int z)
{
	return v-w*w+x*x*x-y*y*y*y+z*z*z*z*z;	
}
void solve()
{
	for(int z=1;z<=n;z++)
	{
		for(int y=1;y<=n;y++)
		{
			if(y==z)
				continue;
			for(int x=1;x<=n;x++)
			{
				if(x==z||y==x)
					continue;
				for(int w=1;w<=n;w++)
				{
					if(w==z||w==x||w==y)
						continue;
					for(int v=1;v<=n;v++)
					{
						if(v==w||v==z||v==y||v==x)
							continue;
						if(calc(data[z]-'A'+1,data[y]-'A'+1,data[x]-'A'+1,data[w]-'A'+1,data[v]-'A'+1)==ans)
						{
							printf("%c%c%c%c%c\n",data[z],data[y],data[x],data[w],data[v]);
							return ;
						}
					}
				}
			}
		}
	}
	printf("no solution\n");
}
int main()
{
	while(scanf("%d%s",&ans,data+1),ans)
	{
		n=strlen(data+1);
		sort(data+1,data+1+n,cmp);
		solve();
	}
	return 0;
}


