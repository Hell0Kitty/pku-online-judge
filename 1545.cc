#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <memory.h>
#include <assert.h>

using namespace std;

#define LIMITS 0.00
#define MAX_NUM 30

int main(void)
{
	int n;
	char source;
	double value;
	string str;
	double map[MAX_NUM][MAX_NUM];
	int thrusto[MAX_NUM];
	int index;

	while(cin>>n)
	{
		memset(thrusto,0,sizeof(thrusto));
		for(int i=0;i<MAX_NUM;++i)
		{
			for(int j=0;j<MAX_NUM;++j)
				map[i][j]=LIMITS;
		}

		for(int i=0;i<n;++i)
		{
			cin>>source>>value>>str;
			source -='A';
			if (source=='M'-'A')
			{
				assert(source=='M'-'A');
			}
			for(int j=0;j<str.length();++j)
			{
				map[source][source]=value;
				if(str.at(j)!='*')
				{
					map[source][str.at(j)-'A']=value;
				}
				else
				{
					thrusto[source]=1;
				}
			}
		} 

		for(int i=0;i<MAX_NUM;++i)
		{
			for(int j=0;j<MAX_NUM;++j)
			{
				for(int k=0;k<MAX_NUM;++k)
				{
					//如果j和i，i和k之间有通路，而且原来从j到k的价值，比从j到i，i到k的价值低，则更新
					if(map[j][k]<map[j][i]*0.95 &&map[j][i]>0.0&&map[i][k]>0.0)
					{
						map[j][k]=map[j][i]*map[i][k]*0.95;
					}
				}
			}
		}

		index=0;
		value=0.0;
		for(int j=0;j<MAX_NUM;++j)
		{
			if(thrusto[j])
			{
				for(int i=0;i<MAX_NUM;++i)
				{
					if(value<map[i][j])
					{
						index=i;
						value=map[i][j];
					}
				}
			}
		}
		printf("Import from %c\n",index+'A');
	}
	return 0;
}


