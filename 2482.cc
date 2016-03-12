#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;cstdlib&gt;
#include&lt;cstring&gt;
#include&lt;algorithm&gt;
using namespace std;
const int N=40005;
long long r[N*12];
int n;
long long w,h;
int tot,cnt;
long long mx=0;
long long maxl(long long a,long long b)
{return a&gt;b?a:b;}
struct line
{
	long long x,y1,y2,c;
}pos[N*6];
bool cmp(line a,line b)
{
	if(a.x==b.x)return a.c&lt;b.c;
	return a.x&lt;b.x;
}
struct sgtr
{
	int l,r;
	long long dat;
	long long add;
}tr[N*6];
void build(int p,int l,int r)
{
	tr[p].l=l,tr[p].r=r,tr[p].dat=tr[p].add=0;
	if(l==r)return;
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}
void spread(int p)
{
	if(tr[p].l==tr[p].r)return;
	if(tr[p].add)
	{
		tr[p*2].dat+=tr[p].add;
		tr[p*2+1].dat+=tr[p].add;
		tr[p*2].add+=tr[p].add;
		tr[p*2+1].add+=tr[p].add;
	}
	tr[p].add=0;
}
void change(int p,int l,int r,long long x)
{
	if(l&lt;=tr[p].l&amp;&amp;r&gt;=tr[p].r)
	{
		tr[p].dat+=x;
		tr[p].add+=x;
		return;
	}
	spread(p);
	int mid=(tr[p].l+tr[p].r)/2;
	if(l&lt;=mid)change(p*2,l,r,x);
	if(r&gt;mid)change(p*2+1,l,r,x);
	tr[p].dat=maxl(tr[p*2].dat,tr[p*2+1].dat);
}
void make()
{
	sort(r+1,r+tot+1);
	for(int i=1;i&lt;=cnt;i++)
	{
		//pos[i].x=lower_bound(r+1,r+tot+1,pos[i].x)-r;
		pos[i].y1=lower_bound(r+1,r+tot+1,pos[i].y1)-r;
		pos[i].y2=lower_bound(r+1,r+tot+1,pos[i].y2)-r;
		mx=maxl(mx,maxl(pos[i].y2,pos[i].y1));
	}
	sort(pos+1,pos+cnt+1,cmp);
}
void init()
{
	memset(&amp;tr,0,sizeof tr);
	memset(&amp;pos,0,sizeof pos);
	memset(r,0,sizeof r);
	mx=tot=cnt=0;
}
int main()
{
	while(scanf("%d%I64d%I64d",&amp;n,&amp;w,&amp;h)!=EOF)
	{
		init();
		for(int i=1;i&lt;=n;i++)
		{
			long long a,b,c;
			scanf("%I64d%I64d%I64d",&amp;a,&amp;b,&amp;c);
			pos[++cnt].x=a,pos[cnt].y1=b,pos[cnt].y2=b+h-1,pos[cnt].c=c;
			pos[++cnt].x=a+w,pos[cnt].y1=b,pos[cnt].y2=b+h-1,pos[cnt].c=-c;
			r[++tot]=b,r[++tot]=b-1,r[++tot]=b+1,r[++tot]=b+h-1,r[++tot]=b+h,r[++tot]=b+h+1;
		}
		make();
		build(1,1,mx+10);
		unsigned long long ans=0;
		for(int i=1;i&lt;=cnt;i++)
		{
			//cout&lt;&lt;"push "&lt;&lt;pos[i].y1&lt;&lt;" "&lt;&lt;pos[i].y2&lt;&lt;" "&lt;&lt;pos[i].c&lt;&lt;endl;
			change(1,pos[i].y1,pos[i].y2,pos[i].c);
			ans=maxl(ans,tr[1].dat);
			//cout&lt;&lt;ans&lt;&lt;endl;
		}
		printf("%I64d\n",ans);
	}
}



