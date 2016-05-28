#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int dir[8][4]={{-1,0,0,1},{-1,1,1,1},{0,1,1,0},{1,1,1,-1},{1,0,0,-1},{1,-1,-1,-1},{0,-1,-1,0},{-1,-1,-1,1}};   
int map[201][201];

int Isxie(int x1,int y1,int x2,int y2,int c)
{
	int i;
	switch(c%4)
	{
		case 0:
			if(x1>x2)
			{
				for(i=x2+1;i<x1;i++)
					if(map[y2+i-x2][i]!=1)return 0;
				return 1;
			}
			else
			{
				for(i=x1+1;i<x2;i++)
					if(map[y1+i-x1][i]!=1)return 0;
				return 1;
			}
		case 1:
			if(y1>y2)
			{
				for(i=y2+1;i<y1;i++)
					if(map[i][x1]!=1)return 0;
				return 1;
			}
			else
			{
				for(i=y1+1;i<y2;i++)
					if(map[i][x1]!=1)return 0;
				return 1;
			}
		case 2:
			if(x1>x2)
			{
				for(i=x2+1;i<x1;i++)
					if(map[y2-i+x2][i]!=1)return 0;
				return 1;
			}
			else
			{
				for(i=x1+1;i<x2;i++)
					if(map[y1-i+x1][i]!=1)return 0;
				return 1;
			}
		case 3:
			if(x1>x2)
			{
				for(i=x2+1;i<x1;i++)
					if(map[y1][i]!=1)return 0;
				return 1;
			}
			else
			{
				for(i=x1+1;i<x2;i++)
					if(map[y1][i]!=1)return 0;
				return 1;
			}
	}
	return 0;
}
int Istriangles(int x,int y,int M,int N)
{
	int nowx1,nowx2,nowy1,nowy2,c,sum=0;
	for(c=0;c<8;c++)
	{
	    nowx1=x;nowx2=x;nowy1=y;nowy2=y;
		if(nowy1+dir[c][0]<0||nowy1+dir[c][0]>M||nowx1+dir[c][1]<0||nowx1+dir[c][1]>N)continue;	
		if(nowy2+dir[c][0]<0||nowy2+dir[c][0]>M||nowx2+dir[c][1]<0||nowx2+dir[c][1]>N)continue;		
		nowy1=nowy1+dir[c][0];
		nowx1=nowx1+dir[c][1];
		nowy2=nowy2+dir[c][2];
		nowx2=nowx2+dir[c][3];
		if(map[nowy1][nowx1]*map[nowy2][nowx2]==0)continue;
		while(map[nowy1][nowx1]*map[nowy2][nowx2]==1)
		{
			nowy1=nowy1+dir[c][0];
			nowx1=nowx1+dir[c][1];
			nowy2=nowy2+dir[c][2];
			nowx2=nowx2+dir[c][3];
		}
		if(map[nowy1][nowx1]*map[nowy2][nowx2]==0)continue;
		if(map[nowy1][nowx1]==1||map[nowy2][nowx2]==1)continue;
		if(Isxie(nowx1,nowy1,nowx2,nowy2,c))sum++;
	}
	return sum;
}

int Find(int N,int M)
{
	int count=0;
	int i,j;
	for(i=0;i<=M;i++)
		for(j=0;j<=N;j++)
		{
			if(map[i][j]>1)
			{
				count=count+Istriangles(j,i,M,N);
			}
			else ;
		}
	return count;
}
int main()
{
	int N,M,K;
	while(scanf("%d%d%d",&M,&N,&K)!=EOF)
	{
		int i,j;
		memset(map,0,sizeof(map));
		for(i=0;i<=4*N;i++)
		{
			map[0][i]++;
			map[4*M][i]++;
		}
		for(i=0;i<=4*M;i++)
		{
			map[i][0]++;
			map[i][4*N]++;
		}
		while(K--)
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
			int t=(y2-y1)*(x2-x1);
			if(t==0)
			{
				if(x1==x2)
				{
					if(y1<y2)
						for(j=4*y1;j<=4*y2;j++)
							map[j][4*x1]++;
					else
						for(j=4*y2;j<=4*y1;j++)
							map[j][4*x1]++;
				}
				else
				{
					if(x1<x2)
						for(j=4*x1;j<=4*x2;j++)
							map[4*y1][j]++;
					else
						for(j=4*x2;j<=4*x1;j++)
							map[4*y1][j]++;
				}
			}
			else if(t>0)
			{
				if(x1<x2)
					for(j=4*x1;j<=4*x2;j++)
						map[4*y1-4*x1+j][j]++;
				else
					for(j=4*x2;j<=4*x1;j++)
						map[4*y2-4*x2+j][j]++;
			}
			else if(t<0)
			{
				if(x1<x2)
					for(j=4*x1;j<=4*x2;j++)
						map[4*y1+4*x1-j][j]++;
				else
					for(j=4*x2;j<=4*x1;j++)
						map[4*y2+4*x2-j][j]++;
			}
			else ;
		}
		printf("%d\n",Find(4*N,4*M));
	}
	return 0;
}


