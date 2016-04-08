#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int n,m;
struct A
{
	int a,b;
	int len;
}E[10101];
int set[111];

int cmp(const void *a,const void *b)
{
	struct A *c,*d;
	c=(struct A *)a;
	d=(struct A *)b;
	return c->len-d->len;
}

void build(int num)
{
	int i;
	for(i=1;i<=num;i++)	set[i]=i;
}
int find(int k)
{
	if(set[k]==k)	return k;
	set[k]=find(set[k]);
	return set[k];
}
void Union(int f1,int f2)
{
	set[f1]=f2;
}

int Kruskal()
{
	int ans;
	int i;
	int f1,f2;

	ans=0;
	for(i=0;i<m;i++)
	{
		f1=find(E[i].a);
		f2=find(E[i].b);
		if(f1==f2)	continue;
		Union(f1,f2);
		ans+=E[i].len;
	}

	return ans;
}
int main()
{
	int i;

	while(scanf("%d",&n),n)
	{
		build(n);

		scanf("%d",&m);
		for(i=0;i<m;i++)	scanf("%d%d%d",&E[i].a,&E[i].b,&E[i].len);

		qsort(E,m,sizeof(E[0]),cmp);
		printf("%d\n",Kruskal());
	}
	return 0;
}


