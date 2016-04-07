# include <cstdio>
# include <cstring>
# include <cstdlib>
# define max(a,b) ((a)>(b)?(a):(b))
# define min(a,b) ((a)<(b)?(a):(b))
# define legal(r,c) ((r)>=start&&(r)<n&&(c)>=0&&(c)<m&&!inqueue[r][c])
using namespace std;
const int N=1024;
char map[N][N];
int n,m,k,start,q[N*N][2],s,e;
bool inqueue[N][N];
void bfs(int tr,int tc)
{

     s=e=-1;
     q[++e][0]=tr;
     q[e][1]=tc;
	 memset(inqueue,false,sizeof(inqueue));
     while(s!=e)
     {
          s++;
          tr=q[s][0];
          tc=q[s][1];
		  inqueue[tr][tc]=true;
          if(legal(tr-1,tc)&&map[tr-1][tc]==map[tr][tc]) 
          {
             q[++e][0]=tr-1;
             q[e][1]=tc;
          }
          if(legal(tr+1,tc)&&map[tr+1][tc]==map[tr][tc]) 
          {
             q[++e][0]=tr+1;
             q[e][1]=tc;
          }
          if(legal(tr,tc-1)&&map[tr][tc-1]==map[tr][tc]) 
          {
             q[++e][0]=tr;
             q[e][1]=tc-1;
          }
          if(legal(tr,tc+1)&&map[tr][tc+1]==map[tr][tc]) 
          {
             q[++e][0]=tr;
             q[e][1]=tc+1;
          }
          map[tr][tc]=' ';
     }
}
void MoveLeft()
{
   int maxnum=-1;
   for(int i=start;i<n;i++)
   {
     int total=0;
     for(int j=m-1;j>=0;j--)
       if(map[i][j]==' ')
       {
         for(int k=j+1;k<m;k++)
           map[i][k-1]=map[i][k],map[i][k]=' ';
         total++;
       }
     maxnum=max(maxnum,m-total);
   }
   m=maxnum;
}
void MoveDown()
{
   int minnum=0xfffffff;
   for(int j=0;j<m;j++)
   {
       int total=0;
       for(int i=start;i<n;i++)
          if(map[i][j]==' ')
          {
            for(int k=i-1;k>=start;k--)
               map[k+1][j]=map[k][j],map[k][j]=' ';
            total++;
          }
       minnum=min(minnum,start+total);
   }
   start=minnum;
}
void print()
{
	for(int i=start;i<n;i++)
	{
		for(int j=0;j<m;j++)
			 putchar(map[i][j]);
		putchar('\n');
	}
//	printf("\n");
}
int main()
{
    //freopen("e.in","r",stdin);
    //freopen("ans.txt","w",stdout);
    int test=0;
    while(gets(map[0]))
    {
        m=strlen(map[0]);
        for(n=1;;n++)
        {
            gets(map[n]);
            if(map[n][0]>='0'&&map[n][0]<='9')
            {
               k=atoi(map[n]);
               break;
            }
        }

        start=0;
        for(int i=0;i<k;i++)
        {
           int tr,tc;
           scanf("%d%d",&tr,&tc);
           tr--,tc--;

           bfs(tr+start,tc);
           MoveLeft();
	   MoveDown();

        }
        printf("Test case #%d:\n",++test);
		print();
		if(k) getchar();
    }
}



