#include <iostream>
using namespace std;

struct node
{
	int a,b,c,used;

	void input()
	{
		scanf("%d%d%d",&a,&b,&c);
		used=0;
	}
};

node p[10];
int ans,t;

void DFS(int dep,int find,int sum)
{
	int i;

	if(dep==7)
	{
		if(find==t&&sum>ans) ans=sum;
		return;
	}
	for(i=1;i<=5;i++) if(!p[i].used&&(p[i].a==find||p[i].b==find||p[i].c==find))
	{
		p[i].used=1;
		if(p[i].a==find) DFS(dep+1,p[i].c,sum+p[i].b);
		else if(p[i].b==find) DFS(dep+1,p[i].a,sum+p[i].c);
		else DFS(dep+1,p[i].b,sum+p[i].a);
		p[i].used=0;
	}
}

void deal()
{
	ans=-1;
	p[0].used=1;
	t=p[0].c;DFS(2,p[0].b,p[0].a);
	t=p[0].b;DFS(2,p[0].a,p[0].c);
	t=p[0].a;DFS(2,p[0].c,p[0].b);
	if(ans==-1) printf("none\n");
	else printf("%d\n",ans);
}

int main()
{
	while(1)
	{
		int i;
		char str[10];
		for(i=0;i<6;i++) p[i].input();
		deal();
		scanf("%s",str);
		if(str[0]=='$') break;
	}
	return 0;
}



