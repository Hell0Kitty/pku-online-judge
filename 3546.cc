#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<iostream>
char matrix[15][15];
int vis[15][15];
const int dx[]={0,1,1,1};
const int dy[]={1,-1,0,1};
int ship[5]={0,4,3,2,1};
int dis;
int search(int i,int j,int dir)
{
	int nx,ny,ll,k,tx,ty;
	nx=i+dx[dir];ny=j+dy[dir];
	if(matrix[nx][ny]=='1')
	{
		if(vis[nx][ny])
			return -1;
		else
		{
			dis++;

			ll=search(nx,ny,dir);
			if(ll<0)
				return -1;
			else
			{
				vis[i][j]=2;

				for(k=0;k<4;k++)
				{
					tx=i+dx[k];ty=j+dy[k];
					if(vis[tx][ty]!=2)
					{
									vis[tx][ty]=1;

					}
				}
				return 0;
			}
		}
	}
    vis[i][j]=2;

	for(k=0;k<4;k++)
	{
		tx=i+dx[k];ty=j+dy[k];
		if(vis[tx][ty]!=2)
		{		
			vis[tx][ty]=1;
		}
	}
	return 0;
}

int main()
{
	int i,j,k,nx,ny,flag,tx,ty;
	memset(matrix,'0',sizeof(matrix));
	memset(vis,0,sizeof(vis));
	for(i=1;i<=10;i++)
		gets(matrix[i]+1);
	for(i=1;i<=10;i++)
	{
		if(matrix[1][i]=='1'||matrix[i][1]=='1'||matrix[10][i]=='1'||matrix[i][10]=='1')
		{
			printf("incorrect\n");
			return 0;
		}
	}
	for(i=2;i<=9;i++)
	{
		for(j=2;j<=9;j++)
		{
			if(matrix[i][j]=='1')
			{

				if(!vis[i][j])
				{
					flag=0;
					for(k=0;k<4;k++)
					{
						nx=i+dx[k];ny=j+dy[k];	
						if(matrix[nx][ny]=='1')
						{

							flag=1;
							dis=1;

							if(search(i,j,k)==0)
							{

								if(dis>4)
								{
									printf("incorrect\n");
									return 0;
								}	

								ship[dis]--;

							}
							else
							{

								printf("incorrect\n");
								return 0;
							}
						}
					}
					if(!flag)
					{

						ship[1]--;
						vis[i][j]=2;
						for(k=0;k<4;k++)
						{
							tx=i+dx[k];ty=j+dy[k];
					        vis[tx][ty]=1;
						}
					}
				}
				else
				{
					if(vis[i][j]==1)
					{
;
						printf("incorrect\n");
						return 0;
					}
				}
			}
		}
	}
	if(!ship[1]&&!ship[2]&&!ship[3]&&!ship[4])
		printf("correct\n");
	else
		printf("incorrect\n");

	return 0;
}



