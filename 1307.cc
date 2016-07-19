#include<stdio.h>
#define MAX 12
struct cell
{
	int n;
	int dir[4];
	int visited;
	int sequence;
}maze[MAX+2][MAX+2];//初始化是需要
int stack[MAX*MAX][2];
int top;
int move[4][2];
/*         1
    west 0   2 east
	       3
		   south
		  */
int height,width,sr,sc,gr,gc;
int init()
{
	int i,j;
	scanf("%d%d%d%d%d%d",&height,&width,&sr,&sc,&gr,&gc);
	if(height==0)
		return 0;
	for(i=1;i<=height;i++)
		for(j=1;j<=width;j++)
		{
			scanf("%d",&maze[i][j].n);
			maze[i][j].sequence=0;
			maze[i][j].visited=0;
			switch(maze[i][j].n)
			{
			case 0:
				maze[i][j].dir[2]=0;
				maze[i][j].dir[3]=0;
				maze[i][j+1].dir[0]=0;
				maze[i+1][j].dir[1]=0;
				break;
			case 1:
				maze[i][j].dir[3]=0;
				maze[i+1][j].dir[1]=0;
				maze[i][j].dir[2]=1;
				maze[i][j+1].dir[0]=1;
				break;
			case 2:
				maze[i][j].dir[3]=1;
				maze[i+1][j].dir[1]=1;
				maze[i][j].dir[2]=0;
				maze[i][j+1].dir[0]=0;
				break;
			case 3:
				maze[i][j].dir[2]=1;
				maze[i][j].dir[3]=1;
				maze[i][j+1].dir[0]=1;
				maze[i+1][j].dir[1]=1;
				break;
			}
			if(i==1)
				maze[i][j].dir[1]=1;
			if(i==height)
				maze[i][j].dir[3]=1;
			if(j==1)
				maze[i][j].dir[0]=1;
			if(j==width)
				maze[i][j].dir[2]=1;
		}
		return 1;
}
void setmove()
{
	move[0][0]=move[2][0]=0;
	move[0][1]=-1;move[2][1]=1;
	move[1][1]=move[3][1]=0;
	move[1][0]=-1;move[3][0]=1;
}
void getpath()
{
	int ok;
	int x,y,nx,ny,i,k;
	setmove();
	stack[0][0]=sr;
	stack[0][1]=sc;
	maze[sr][sc].sequence=1;
	maze[sr][sc].visited=1;
	for(top=0;top<width*height;)
	{
		ok=0;
		for(i=0;i<4;i++)
		{
			x=stack[top][0];
			y=stack[top][1];
			if(maze[x][y].dir[i]==0)
			{
				nx=x+move[i][0];
				ny=y+move[i][1];
				if(maze[nx][ny].visited==1)
					continue;
				else
					maze[nx][ny].visited=1;
				top++;
				stack[top][0]=nx;
				stack[top][1]=ny;
				ok=1;
			}
			if(nx==gr&&ny==gc)
			{
				for(k=0;k<=top;k++)
					maze[stack[k][0]][stack[k][1]].sequence=k+1;
				return;
			}
			if(ok)
				break;
		}
		if(!ok)
			top--;
	}
}
void printmaze()
{
	int i,j;
	printf("+");
	for(j=1;j<=width;j++)
		printf("---+");
	printf("\n");
	for(i=1;i<=height;i++)
	{
		printf("|");
		for(j=1;j<=width;j++)
		{
			if(maze[i][j].sequence&&maze[i][j].visited)
				printf("%3d",maze[i][j].sequence);
			else if(!maze[i][j].sequence&&maze[i][j].visited)
				printf("???");
			else if(!maze[i][j].sequence&&!maze[i][j].visited)
				printf("   ");
			else
				;
			if(maze[i][j].dir[2]==0)
				printf(" ");
			else
				printf("|");
		}
		printf("\n");
		printf("+");
		for(j=1;j<=width;j++)
			if(maze[i][j].dir[3]==0)
				printf("   +");
			else
				printf("---+");
		printf("\n");
	}
}
int main()
{
	int i=0;
	while(init())
	{
		i++;
		printf("Maze %d\n",i);
		printf("\n");

		getpath();
		printmaze();
                printf("\n");
printf("\n");
	}
}

