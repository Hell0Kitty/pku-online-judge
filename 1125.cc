#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

const int inf=20;       
int dist[101][101];

int i,j,k;
int n;   //经纪人个数

void floyd()
{
	/*Floyd Algorithm*/

	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)                                                 
			for(j=1;j<=n;j++)      
				if(i!=j && dist[i][j] > dist[i][k] + dist[k][j])  
					dist[i][j] = dist[i][k] + dist[k][j];

	int maxlength;
	int min_in_max=inf;
	int flag_source;

	for(i=1;i<=n;i++)                     //以i点作为各通路源点
	{
		maxlength=0;
		for(j=1;j<=n;j++)
			if(i!=j && maxlength<dist[i][j])   //寻找i到j的最长路径
				maxlength=dist[i][j];
		if(min_in_max>maxlength)
		{
			min_in_max=maxlength;       //寻找最长路径中的最短路
			flag_source=i;              //该短路所在路径的源点记录
		}
	}

	/*Output*/

	if(min_in_max<inf)
		cout<<flag_source<<' '<<min_in_max<<endl;
	else
		cout<<"disjoint"<<endl;

	return;
}

int main(void)
{
	while(1)
	{
		/*Initial*/

		memset(dist,inf,sizeof(dist));

		/*Input*/

		cin>>n;     
		if(!n)break;

		for(i=1;i<=n;i++)
		{
			int pair;
			cin>>pair;
			for(j=1;j<=pair;j++)
			{
				int cat,time;      //i的接触人，接触时间(边权)
				cin>>cat>>time;
				dist[i][cat]=time;
			}
		}

		/*Floyd Algorithm & Output*/

		floyd();
	}
	return 0;
}


