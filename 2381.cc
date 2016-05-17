#include<iostream>
using namespace std;
char lock[16000000];

int main()
{
	__int64 i,a,c,m,r0,temp;
	while(scanf("%I64d%I64d%I64d%I64d",&a,&c,&m,&r0)!=EOF)
	{
		memset(lock,0,sizeof(lock));
		temp=r0;
		while(!lock[temp])
		{
			lock[temp]=1;
			temp=(a*temp+c)%m;
		}
		int flag=0,max=0,j;
		for(i=0;i<16000000;i++)
		{
			if(lock[i]&&flag)
			{
				if(j>max)
					max=j;
				j=1;
			}
			if(lock[i]&&flag==0)
			{
				flag=1;	j=1;
			}
			if(lock[i]==0&&flag)
				j++;
		}
		cout<<max<<endl;
	}
	return 0;
}


