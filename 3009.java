//* @author

import java.util.*;
public class Main {

static final int MAX= 30;
static int w,h;
static int start_x,start_y;
static int flag[][] = new int[MAX][MAX];
static int min=11;
static int step=1;

static void dfs(int x,int y,int step)
{
	if(step>10) return;
	if(step==min) return;
for(int i=x+1;i< h;i++)
{
 if(i==x+1&&flag[i][y]==1) break;
 if(flag[i][y]==3){if(min>step) min=step;return;}
 if(flag[i][y]==1&&step< min){flag[i][y]=0;dfs(i-1,y,step+1);flag[i][y]=1;break;}
}
for(int i=x-1;i>=0;i--)
{
 if(i==x-1&&flag[i][y]==1) break;
 if(flag[i][y]==3){if(min>step);min=step;return;}
 if(flag[i][y]==1&&step< min){flag[i][y]=0;dfs(i+1,y,step+1);flag[i][y]=1;break;}
 }
for(int i=y+1;i< w;i++)
{
 if(i==y+1&&flag[x][i]==1) break;
 if(flag[x][i]==3){if(min>step) min=step;return;}
 if(flag[x][i]==1&&step< min){flag[x][i]=0;dfs(x,i-1,step+1);flag[x][i]=1;break;}
}
for(int i=y-1;i>=0;i--)
{
 if(i==y-1&&flag[x][i]==1) break;
 if(flag[x][i]==3&&step< min){if(min>step) min=step;return;}
 if(flag[x][i]==1&&step< min){flag[x][i]=0;dfs(x,i+1,step+1);flag[x][i]=1;break;}
}
return;
}

public static void main(String[] args) {
 Scanner in = new Scanner(System.in);
  while(true)
  {
	w=in.nextInt();
	h=in.nextInt();
	if(w==0&&h==0) break;
	for(int i=0;i< h;i++)
	{
          for(int j=0;j< w;j++)
	   {
		flag[i][j]=in.nextInt();
		if(flag[i][j]==2)
		{
	        start_x=i;
		 start_y=j;
		 flag[i][j]=0;
	       }
	     }
	}
	step=1;
	min=11;
	dfs(start_x,start_y,step);
	if(min==11) System.out.println("-1");
	else System.out.println(min);
  }
 }
}

