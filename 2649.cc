#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=(10e4+1)*2;
bool isPri[maxn];
int Pri[100001],cou=0,n,m;
void Init()
{
    isPri[1]=1;
    for(int i=2;i<maxn;i++)
    {
	if(!isPri[i])
	    Pri[cou++]=i;
	for(int j=2;i*j<maxn;j++)
	    isPri[i*j]=1;
    }
}
bool Search(int num,int count)
{
    int cou=0;
    for(int i=num;i<=n;i++)
    {
	int ita=i;
	while(ita%num==0)
	{
	    ita/=num;
	    cou++;
	}
	if(cou==count)
	    return true;
    }
    return false;
}
int main()
{
    Init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
	bool ans=1;
	int mm=m,now=0;
	if(m==0)
	{
	    printf("0 does not divide %d!\n",n);
	    continue;
	}
	if(m<=n)
	{
	    printf("%d divides %d!\n",m,n);
	    continue;
	}
	while(now<cou)
	{
	    int num=0;
	    while(mm%Pri[now]==0)
	    {
		mm/=Pri[now];
		num++;
	    }
	    if(num)
	    {
		if(!Search(Pri[now],num))
		{
		    ans=0;
		    break;
		}
		if(mm==1)
		    break;
	    }
	    now++;
	}
	if(ans&&mm<=n)
	    printf("%d divides %d!\n",m,n);
	else
	    printf("%d does not divide %d!\n",m,n);
    }
    return 0;
}



