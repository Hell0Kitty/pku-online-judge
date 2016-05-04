#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define clr(x,a) memset(x,a,sizeof(x))
const int inf = 1012345678;
int rd(){int x;scanf("%d",&x); return x;}
const int maxn = 200001;
const int maxe =1000010;
#define sz(x) (int)x.size()
#define pb push_back
#define L nod<<1
#define R nod<<1|1
#define lson nod<<1,l,mid
#define rson nod<<1|1,mid+1,r
int n,m;
struct node
{
	int v,w;
	node(){}
	node(int aa,int bb){v=aa; w=bb;}
}a[maxn];

bool cmp1(node a,node b)
{
	if(a.v==b.v)	return a.w>b.w;
	return a.v>b.v;
}
bool cmp2(node a,node b)
{
	if(a.v==b.v)	return a.w<b.w;
	return a.v<b.v;
}
int tr[maxe*4],fd;
void find(int nod,int l,int r,int x,int y)
{
	if(x<=l && r<=y)
	{
		fd=max(fd,tr[nod]);
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)	
		find(lson,x,y);
	if(mid<y)
		find(rson,x,y);
}

void insert(int nod,int l,int r,int x,int y,int a)
{
	if(x<=l && r<=y)
	{
		tr[nod]=max(tr[nod],a);
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)
		insert(lson,x,y,a);
	if(mid<y)
		insert(rson,x,y,a);
	tr[nod]=max(tr[L],tr[R]);
}

vector<node>vc[maxe];
int main()
{
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		int x,y;
		int maxx=0;
		for(i=0; i<n; i++)
		{
			scanf("%d%d",&x,&y);
			a[i]=node(x,y);
			maxx=max(maxx,y);
		}
		sort(a,a+n,cmp1);
		int cnt=0;
		for(i=0; i<n; i++)
		{
			fd=0;
			find(1,0,maxx,a[i].w,maxx);
			fd++;
			cnt=max(cnt,fd);
			vc[fd].pb(a[i]);
			insert(1,0,maxx,a[i].w,a[i].w,fd);
		}
		for(i=1; i<=cnt; i++)
		{
			printf("%d:",sz(vc[i]));
			sort(vc[i].begin(),vc[i].end(),cmp2);
			for(j=0; j<sz(vc[i]); j++)
			{
				printf(" (%d,%d)",vc[i][j].v,vc[i][j].w);	
			}
			puts("");
			vc[i].clear();
		}
	}
}


