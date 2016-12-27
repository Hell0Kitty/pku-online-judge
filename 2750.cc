#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
int a[1000010];
using namespace std;
struct TREE
{
	int r,l;
	long long rm,lm,ma;
	long long rmi,lmi,mi;
	long long sum;
}t[4000040];
inline void wor(int root)
{
		t[root].sum=t[root*2].sum+t[root*2+1].sum;
		t[root].ma=max(max(t[root*2].ma,t[root*2+1].ma),t[root*2].rm+t[1+root*2].lm);
		t[root].lm=max(t[root*2].lm,t[2*root].sum+t[2*root+1].lm);
		t[root].rm=max(t[root*2+1].rm,t[2*root+1].sum+t[2*root].rm);
		t[root].mi=min(min(t[root*2].mi,t[root*2+1].mi),t[root*2].rmi+t[1+root*2].lmi);
		t[root].lmi=min(t[root*2].lmi,t[2*root].sum+t[2*root+1].lmi);
		t[root].rmi=min(t[root*2+1].rmi,t[2*root+1].sum+t[2*root].rmi);
}
inline void build(int root,int l,int r)
{
	if(r==l)
	{
		t[root].r=r;
		t[root].l=l;
		t[root].lmi=t[root].mi=t[root].rmi=a[r];
		t[root].sum=t[root].ma=t[root].rm=t[root].lm=a[r];
		return;
	}
	else
	{
		int mid=(r+l)/2;
		build(root*2,l,mid);
		build(root*2+1,mid+1,r);
		wor(root);
		t[root].l=l,t[root].r=r;
		return;
	}
}
inline void change(int root,int l,int r,int pos,int ver)
{
	if(l==r)
	{
		t[root].sum=t[root].ma=t[root].lm=t[root].rm=ver;
		t[root].lmi=t[root].rmi=t[root].mi=ver;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)
	change(root*2,l,mid,pos,ver);
	else
	change(root*2+1,mid+1,r,pos,ver);
	wor(root);
}
int main()
{
	int n,nq;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&nq);
	int aa,bb;
	for(int i=1;i<=nq;i++)
	{
		scanf("%d%d",&aa,&bb);
		change(1,1,n,aa,bb);
		if(t[1].ma!=t[1].sum)
		{
		cout<<max(t[1].ma,t[1].sum-t[1].mi)<<endl;
		}
		else
		{
		cout<<t[1].sum-t[1].mi<<endl;
		}
	}
	return 0;
}


