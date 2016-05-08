#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#define LG long long
using namespace std;
int n,m,N[105],Y[105],fa[105],res[105];
map<int ,int>mp,re;
int main()
{
	int T,x,y,z,pos=0,len;
	char ch[10],sh[10];
	scanf("%d",&T);
	while(T--)
	{
		mp.clear();re.clear(),pos=1;
		memset(N,0,sizeof(N));
		memset(Y,0,sizeof(Y));
		memset(fa,0,sizeof(fa));
		scanf("%d",&n);
		int flag=0,ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(mp[x]==0)mp[x]=pos,re[pos]=x,x=pos++;
			else x=mp[x];
			scanf("%d",&y);scanf("%s",ch);
			if(mp[y]==0)mp[y]=pos,re[pos]=y,y=pos++;
			else y=mp[y];
			scanf("%d",&z);scanf("%s",sh);
			if(mp[z]==0)mp[z]=pos,re[pos]=z,z=pos++;
			else z=mp[z];
			if(ch[0]=='N'&&sh[0]=='N')
				flag=1,ans=x;
			else if(ch[0]=='N')
				N[y]++,fa[y]=x,Y[z]++;
			else if(sh[0]=='N')
				N[z]++,fa[z]=x,Y[y]++;
			else Y[z]++,Y[y]++;
		}
		if(flag==1)printf("%d\n",re[ans]);
		else
		{
			len=0;
			for(int i=1;i<pos;i++)
			{
				if(N[i]>=2)
				{
					ans=i;break;
				}
				else if(N[i]==1)
					res[len++]=i;
			}
			if(len==1&&Y[fa[res[0]]]!=0)
				ans=res[0];
			else if(len==2)
			{
				if(Y[fa[res[0]]]!=0)
					ans=res[0];
				else if(Y[fa[res[1]]]!=0)
					ans=res[1];
			}
			if(ans==0)puts("impossible");
			else printf("%d\n",re[ans]);
		}
	}
	return 0;
}


