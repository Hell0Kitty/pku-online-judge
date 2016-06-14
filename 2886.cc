#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510010;
int a[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,  
1260,1680,2520,5040,7560,10080,15120,20160,25200,  
27720,45360,50400,55440,83160,110880,166320,221760,  
277200,332640,498960,554400,665280};
int b[]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,  
64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,216,224};
char name[N][15];
int s[N];
int n,k;
struct sgtree
{int l,r,sum;}tr[N*4];
void build(int p,int l,int r)
{
	tr[p].l=l,tr[p].r=r;
	if(l==r){tr[p].sum=1;return;}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tr[p].sum=tr[p*2].sum+tr[p*2+1].sum;
}
int change(int p,int x)
{
	tr[p].sum--;
	if(tr[p].l==tr[p].r)return tr[p].l;
	if(tr[p*2].sum>=x)return change(p*2,x);
	return change(p*2+1,x-tr[p*2].sum); 
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{	
		for(int i=1;i<=n;i++)scanf("%s%d",name[i],&s[i]);
		int pos=0,ans=0,t=0,id=0;
		while(a[pos]<=n)pos++;
		ans=b[pos-1],t=a[pos-1];
		build(1,1,n);
		while(t--)
		{
			n--;
			id=change(1,k);
			if(!n)break;
			if(s[id]>=0)k=(k-1+s[id]-1)%n+1;
			else k=((k-1+s[id])%n+n)%n+1;
		}
		printf("%s %d\n",name[id],ans);
	}
    return 0;
}



