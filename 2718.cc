#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int inf=1<<29;
int num[20],cnt,cnta,cntb,val,ans;
int nums[10]={1,10,100,1000,10000,100000,1000000};
bool usea[20],useb[20];
char ch;
void DFS_B(int vals,int deep)
{
    if(deep>0&&abs(val-vals*nums[cntb-deep])>=ans)
	return;
    if(deep==cntb)
    {
	ans=min(ans,max(val,vals)-min(val,vals));
	return;
    }
    for(int i=0;i<cnt;i++)
	if(!usea[i]&&!useb[i])
	{
	    if(deep==0&&num[i]==0)
		continue;
	    useb[i]=1;
	    DFS_B(vals*10+num[i],deep+1);
	    useb[i]=0;
	}
}
void DFS_A(int vals,int deep)
{
    if(deep==cnta)
    {
	val=vals;
	memset(useb,0,sizeof(useb));
	DFS_B(0,0);
	return;
    }
    for(int i=0;i<cnt;i++)
	if(!usea[i])
	{
	    if(deep==0&&num[i]==0)
		continue;
	    usea[i]=1;
	    DFS_A(vals*10+num[i],deep+1);
	    usea[i]=0;
	}
}
int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
	getchar();
	while(T--)
	{
	    cnt=0;
	    while((ch=getchar())!='\n')
	    {
		if(ch>='0'&&ch<='9')
		    num[cnt++]=ch-'0';
	    }
	    cnta=cnt>>1;
	    cntb=cnt-cnta;
	    ans=inf;
	    DFS_A(0,0);
	    if(ans==inf)
		printf("%d\n",val);
	    else
		printf("%d\n",ans);
	}
    }
    return 0;
}



