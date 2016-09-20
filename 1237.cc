#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int degree[40],g[40][40],odd[5];
int main()
{
	int i,j,l,k,a,b,flag,sum=0;
	char s[100];
	while(scanf("%s",&s)!=EOF)
	{
		flag=1;
		if(strcmp(s,"deadend")==0)
		{
			flag=0;
		}
		if(flag)
		{
			l=strlen(s);
			a=s[0]-'a'+1;
			b=s[l-1]-'a'+1;
			degree[a]++;
			degree[b]++;
			g[a][b]=g[b][a]=l;
			sum+=l;
			continue;
		}
		k=0;
		for(i=1;i<=26;i++)
		{
			if(degree[i]%2==1)
				odd[k++]=i;
		}
		if(k==0)
		{
			printf("%d\n",sum);
		}
		else
		{
			for(k=1;k<=26;k++)
				for(i=1;i<=26;i++)
					for(j=1;j<=26;j++)
					{
						if(g[i][k]>0&&g[k][j]>0)
						{
							if(g[i][j]>0)
							{
								if(g[i][j]>g[i][k]+g[k][j])
									g[i][j]=g[i][k]+g[k][j];
							}
							else
								g[i][j]=g[i][k]+g[k][j];
						}
					}
		printf("%d\n",sum+g[odd[0]][odd[1]]);
		}
		sum=0;
		memset(g,0,sizeof(g));
		memset(degree,0,sizeof(degree));
	}
	return 0;
}


