#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
class node
{
public:
	char ch[25];
	int vis[29];
	int len;
	int par;
	int t;
	node()
	{
		par=-1;t=0;
		memset(vis,0,sizeof(vis));
	}
};
node str[100005];
char ch[25],pri[100005][25];
int cnt;
bool cmp(node &a,node &b)
{
	if(a.len <b.len ) return true;
	return false;
}
bool isexten(int a,int b)
{
	int i,len=str[b].len ;
	for(i=0;i<len;i++)
	{
		int k=str[b].ch [i]-'a';
		if(str[a].vis [k]<str[b].vis [k]) return false;
	}
	return true;
}
int par[10005];
void build()
{
	int i,j;
	int maxlen=0,index=0;
	int star,end;
	end=cnt-1;
	star=1;
	while(star<=end)
	{
		i=star-1;
		while(i>=0 )
		{
			int dis=str[star].len -str[i].len ;
			if(dis==0) {}
			else 
			{
				if(dis>1) break;
				if(isexten(star,i))
				{
					if(str[star].t  <str[i].t +1)
					{
						str[star].t=str[i].t +1;
						str[star].par =i;
					}
				}
			}
			i--;
		}
		if(str[star].t >maxlen)
		{
			maxlen=str[star].t ;
			index=star;
		}
		star++;
	}
	int k=index ,pr=0;
	while(k!=-1)
	{
		strcpy(pri[pr++],str[k].ch );
		k=str[k].par ;
	}
	for(i=pr-1;i>=0;i--)
		printf("%s\n",pri[i]);
}
int main()
{
	cnt=0;
	while(scanf("%s",ch)!=EOF)
	{
		strcpy(str[cnt].ch ,ch);
		str[cnt].len =strlen(ch);
		for(int i=0;i<str[cnt].len ;i++)
		{
			str[cnt].vis [str[cnt].ch [i]-'a']++;
		}
		cnt++;
	}
	sort(str,str+cnt,cmp);
	build();
	return 0;
}



