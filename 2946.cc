#include<cstdio>
#include<cstring>
#define MAX 10
#define mod 3000007
struct map
{
    char smap[MAX][MAX];
    int x,y,moves;
}q[1000000];
int n,movex[4]={1,-1,0,0},movey[4]={0,0,-1,1};
bool ipos[mod];
bool isborder(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n)
	return true;
    return false;
}
int GetHash(int index)
{
    int ans=0;
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	    ans=(ans*131+q[index].smap[i][j])%mod;
    ans=(ans+q[index].x*33+q[index].y*131)%mod;
    return ans;
}
int main()
{
    while(scanf("%d%d%d",&n,&q[0].x,&q[0].y)&&n)
    {
	memset(ipos,0,sizeof(ipos));
	int front=0,last=1,pos=0;
	q[0].x--;
	q[0].y--;
	q[0].moves=0;
	for(int i=0;i<n;i++)
	{
	    getchar();
	    for(int j=0;j<n;j++)
		scanf("%c",&q[0].smap[i][j]);
	}
	ipos[GetHash(0)]=1;
	int flag=0,ans=0;
	while(front!=last)
	{
	    char smap[8][8];
	    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		    smap[i][j]=q[front].smap[i][j];
	    int itx=q[front].x;
	    int ity=q[front].y;
	    int moves=q[front++].moves;
	    for(int i=0;i<4;i++)
	    {
		int xx=itx+movex[i];
		int yy=ity+movey[i];
		if(!(isborder(xx,yy)||smap[xx][yy]=='.'))
		{
		    if(smap[xx][yy]=='E')
		    {
			flag=1;
			ans=moves+1;
			break;
		    }
		    int hash=0;
		    for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			    hash=(hash*131+smap[j][k])%mod;
		    if(!ipos[(hash+xx*33+yy*131)%mod])
		    {
			for(int j=0;j<n;j++)
			    for(int k=0;k<n;k++)
				q[last].smap[j][k]=smap[j][k];
			q[last].x=xx;q[last].y=yy;
			q[last].moves=moves+1;
			last++;
			ipos[(hash+xx*33+yy*131)%mod]=1;
		    }
		}
		if(smap[itx][ity]!='.'&&smap[itx][ity]!='1')
		{
		    int flaga=0,mx=itx,my=ity;
			for(int j=0;j<smap[itx][ity]-'0';j++)
			{
			    mx+=movex[i];
			    my+=movey[i];
			    if(isborder(mx,my)||smap[mx][my]!='.')
			    {
				flaga=1;
				break;
			    }
			}
			if(!flaga)
			{
			    for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
				    q[last].smap[j][k]=smap[j][k];
			    mx=itx,my=ity;
			    for(int j=0;j<smap[itx][ity]-'0';j++)
			    {
				mx+=movex[i];
				my+=movey[i];
				q[last].smap[mx][my]='1';
			    }
			    q[last].smap[itx][ity]='.';
			    q[last].x=xx;
			    q[last].y=yy;
			    q[last].moves=moves+1;
			    ipos[GetHash(last)]=1;
			    last++;
			}

		}
	    }
	    if(flag)
		break;
	}
	if(flag)
	    printf("%d\n",ans);
	else
	    printf("Impossible.\n");
    }
    return 0;
}


