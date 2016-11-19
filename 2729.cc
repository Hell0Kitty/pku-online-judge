#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
using namespace std;
struct info
{
	int x,y,z,id;
	char nm[15];
	bool live,move;
}a[1010],c[1010];
struct node
{
	int t,id,op,ag;
}b[10100];
map<string,int> mp;
string ss;
char s[15],sp[10][10]={"MOVE","STOP","TURN","SHOOT"};
int g[1010];
int cc[4]={1,0,-1,0},dd[4]={0,1,0,-1};
int main()
{
	int i,j,k,t,m,n,x,y,T,p,now;
	g[0]=0; g[90]=1; g[180]=2; g[270]=3;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		mp.clear();
		for(i=0;i<n;i++)
		{
			scanf(" %s",a[i].nm);
			ss.clear();
			for(j=0;a[i].nm[j];j++)
				ss+=a[i].nm[j];
			mp[ss]=i;
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].x=(a[i].x*6)/10; a[i].y=(a[i].y*6)/10;
			a[i].move=false;
			a[i].live=true;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i].t);
			scanf(" %s",s);
			b[i].t*=6;
			ss.clear();
			for(j=0;s[j];j++)
				ss+=s[j];
			b[i].id=mp[ss];
			scanf(" %s",s);
			for(j=0;j<4;j++)
				if(strcmp(s,sp[j])==0)
				{
					b[i].op=j;
					if(j==2) scanf("%d",&b[i].ag);
				}
		}
		for(p=now=t=0;t<=300;t++)
		{
			for(j=0;j<n;j++)
				if(a[j].live)
					for(k=1;k<=p;k++)
						if(c[k].id!=j&&c[k].live&&c[k].x==a[j].x&&c[k].y==a[j].y)
							a[j].live=c[k].live=false;
			while(now<m&&b[now].t==t)
			{
				if(a[b[now].id].live)
				{
					if(b[now].op==0)
						a[b[now].id].move=true;
					else
					if(b[now].op==1)
						a[b[now].id].move=false;
					else
					if(b[now].op==2)
						a[b[now].id].z=(a[b[now].id].z+b[now].ag+360)%360;
					else
					if(b[now].op==3)
					{
						c[++p].x=a[b[now].id].x;
						c[p].y=a[b[now].id].y;
						c[p].z=a[b[now].id].z;
						c[p].id=b[now].id;
						c[p].live=true;
					}
				}
				now++;
			}
			for(j=0;j<n;j++)
				if(a[j].live&&a[j].move)
				{
					int xx=a[j].x+cc[g[a[j].z]],yy=a[j].y+dd[g[a[j].z]];
					if(xx<0||xx>72||yy<0||yy>72)
						a[j].move=false;
					else
					{
						a[j].x=xx;
						a[j].y=yy;
					}
				}
			for(j=1;j<=p;j++)
				if(c[j].live)
				{
					c[j].x+=cc[g[c[j].z]]*2;
					c[j].y+=dd[g[c[j].z]]*2;
					if(c[j].x<0||c[j].x>72||c[j].y<0||c[j].y>72)
						c[j].live=false;
				}
		}
		int ans=0,id;
		for(i=0;i<n;i++)
			if(a[i].live)
			{
				id=i;
				ans++;
			}
		if(ans==1) printf("%s\n",a[id].nm);
		else puts("NO WINNER!");
	}
}



