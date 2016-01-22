#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int a[310][310];
int nk,ns;
int vis[1010];
int xc,yc;
inline int abs(int x)
{
	if(x<0)
	return -x;
	return x;
}
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int lcm(int x,int y){return x*y/gcd(x,y);}
inline int Guass()
{
	xc=nk,yc=ns;
	int cnt=1;
	int panm=0;
	if(xc>yc)
	panm=1;
	for(int x=1;x<=xc;x++)
	{
		int y;
		for(y=cnt;y<=yc;y++)
		{
			if(a[y][x]!=0)
			break;
		}

		if(y==yc+1)
		{
			panm=1;
			continue;
		}
		swap(a[cnt],a[y]);
		for(y=1;y<=yc;y++)
		if(a[y][x]&&y!=cnt)
		{
			int p=lcm(abs(a[y][x]),abs(a[cnt][x]));
			int pp=p/abs(a[y][x]);
			int ppp=p/abs(a[cnt][x]);
			if(a[y][x]*a[cnt][x]<0) 
			for(int r=1;r<=xc+1;r++)
			a[y][r]*=pp,a[y][r]=((a[y][r]+14+ppp*a[cnt][r])%7+7)%7;
			else
			{

				for(int r=1;r<=xc+1;r++)
			a[y][r]*=pp,a[y][r]=((a[y][r]+14-ppp*a[cnt][r])%7+7)%7;
			}
		}
		cnt++;
	} 
		int yr,xr;
	for(yr=1;yr<=yc;yr++)
	{
		for(xr=1;xr<=xc;xr++)
		if(a[yr][xr])
		break;
		if(xr==xc+1&&a[yr][xr])
		return -2;	
	}
	if(panm)
	return -1;
	return 0;

}
int main()
{
	int ans;
	map<string,int> h;
	h["MON"]=1;
	h["TUE"]=2;
	h["WED"]=3;
	h["THU"]=4;
	h["FRI"]=5;
	h["SAT"]=6;
	h["SUN"]=7;
	while(1)
	{
		scanf("%d%d",&nk,&ns);
		if(nk==0&&ns==0)
		break;
		memset(a,0,sizeof(a));
		string st1,st2;
		for(int i=1;i<=ns;i++)
		{
			int rr;
			int n;
			scanf("%d",&n);
			cin>>st1>>st2;
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&rr);
				vis[rr]++;
			}
			for(int j=1;j<=nk;j++)
			a[i][j]=vis[j]%7;
			a[i][nk+1]=((h[st2]-h[st1]+7)%7+1)%7;
		}

		ans=Guass();

		if(ans==-2){
			printf("Inconsistent data.\n");
		}
		else if(ans==-1)
		{
			printf("Multiple solutions.\n");
		}
		else
		{
			int hee[1010];
			 for(int i=1;i<=xc;i++)
			 {
			 	for(int k=3;k<=9;k++)
			 	if(a[i][i]*k%7==a[i][xc+1])
			 	{
			 		hee[i]=k;
			 		break;
			 	}
			 }
			 for(int i=1;i<=nk;i++)
			 cout<<hee[i]<<" "; 
			 cout<<"\n";
		 }
	}
	return 0;
}


