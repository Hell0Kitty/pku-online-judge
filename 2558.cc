#include <iostream>
#include <cstring>
#include <cstdio>

#define M 5005
using namespace std;

int n;
char str[M],a[4]="NOP";
bool bb;

bool ok(char ch,int k)
{
	int i,j=(k+1)/2,p;
	str[k]=ch;
	for(i=1;i<=j;i++)
	{
		for(p=1;p<=i;p++)
		{
			if(str[k-p+1]!=str[k-i-p+1])
				break;
		}
		if(p>i)
			return false;
	}
	return true;
}

void dfs(int k)
{
	if(k==n)
	{
		str[k]='\0';
		bb=true;
		return ;
	}
	if(k==0)
	{
		str[k]='N';
		dfs(k+1);
	}
	else
	{
		int i;
		for(i=0;i<3;i++)
		{
			if(ok(a[i],k))
			{
				str[k]=a[i];
				dfs(k+1);
				if(bb)
					return ;
			}
		}		
	}
}

int main()
{
	bb=false;
	n=5000;
	dfs(0);
	while(scanf("%d",&n),n)
		printf("%s\n",str+5000-n);
	return 0;
}



