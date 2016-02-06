#include<iostream>

#include<cstdio>
#include<queue>
#include <cstring>
using namespace std;
int N,a[35][35];
char A[35][35];

typedef struct stq
{
	int x,y;
}stq;
queue <stq> Q;
int m[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void BFS(int x, int y);

int main()
{
	int i,j,c;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<=N+1;i++)
	 		for(j=0;j<=N+1;j++)
	 			a[i][j]=0;
		for(i=1;i<=N;i++)
	 		scanf("%s",A[i]+1);

		BFS(1,1);BFS(N,N);

		c=0;
	 	for(i=1;i<=N;i++)
	 		for(j=1;j<=N;j++)
	 		{		
	 			if(a[i][j]==1)
	 			{
			 		if(a[i-1][j]==0)c++;
			 		if(a[i+1][j]==0)c++;
			 		if(a[i][j-1]==0)c++;
			 		if(a[i][j+1]==0)c++;
			 	}
		 	}
		printf("%d\n",(c-4)*9);	 
	}
	return 0;
}

void BFS(int aa,int b)
{
	int i,j;
 	stq sq,q;
	sq.x=aa; sq.y=b;
	a[sq.x][sq.y]=1;
	Q.push(sq);
	while(!Q.empty())
	{
		q=Q.front();
		Q.pop();
		for(i=0;i<4;i++)
		{
			sq.x= q.x+m[i][0];
			sq.y=q.y+m[i][1];
		 	if(sq.x>N||sq.x<1|| sq.y>N||sq.y<1 ||A[sq.x][sq.y]=='#'||a[sq.x][sq.y]==1) continue;
		 	a[sq.x][sq.y]=1;
	 		Q.push(sq);
		}		
	}
}



