#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#define NUM_INF 0x7FFFFFFF

int Judge(int n,char tmp[30])
{

	for(int i=n;i<30;i++)

		if(tmp[i])

			return 1;

		return 0;

}

void DecToBin(char a[30])
{
	int i,j,tmp=0,k=0,len=strlen(a);
	char res[30],b[30],cop[30];
	memset(res,0,sizeof(res));
	strcpy(cop,a);
	while(strcmp(cop,"0"))
	{
		i=tmp=j=0;
		while(i<len)
		{
			while(tmp<26&&i<len)
			{
				tmp=tmp*10+cop[i++]-'0';
				if(j&&tmp<26&&i<len)
					b[j++]='0';
			}
			b[j++]=tmp/26+'0';
			tmp=tmp%26;
		}
		res[k++]=tmp;
		memset(cop,0,sizeof(cop));
		for(i=0;i<j;i++)
			cop[i]=b[i];
		len=strlen(cop);
		memset(b,0,sizeof(b));
	}
	for(i=0;i<k;i++)
	   {
		if(!Judge(i,res))
		{
			k=i;
			break;
		}
		while(!res[i])
		{
			res[i]='z';
			res[i+1]--;
			i++;
		}
		if(res[i]==-1)
		{
			res[i]=25;
			res[i+1]--;
		}
		res[i]=res[i]+'a'-1;
	}
	for(i=k-1;i>=0;i--)
		printf("%c",res[i]);
	for(i=k+1;i<23;i++)
		printf(" ");
}

void BigNumMultiSmall(int a1[],int &n)
{
	int i;
	a1[0]=a1[0]*26;
	for(i=1;i<n;i++)
	{
		a1[i]*=26;
		a1[i]+=a1[i-1]/10;
		a1[i-1]=a1[i-1]%10;
	}
	while(a1[i-1]>9)
	{
		a1[i]=a1[i-1]/10;
		a1[i-1]=a1[i-1]%10;
		i++;
	}
	n=i;
}
void BinToDec(char a[30])
{
	int j,k,t,m=0,len=strlen(a),i=0;
	int res[30]={0},tmp[30]={0};
	for(i=0;i<len;i++)
		a[i]=a[i]-'a'+1;
	while(a[0])
	{
		res[m++]=a[0]%10;
		a[0]/=10;
	}
	for(i=1;i<len;i++)
	{
		BigNumMultiSmall(res,m);
		memset(tmp,0,sizeof(tmp));
		k=t=0;
		while(a[i])
		{
			tmp[k++]=a[i]%10;
			a[i]/=10;
		}
		for(j=0;j<m;j++)
		{
			t=t+res[j]+tmp[j];
			res[j]=t%10;
			t/=10;
		}
	}
	for(i=m-1;i>=0;i--)
	{
		printf("%d",res[i]);
		if((i+1)%3==1&&i)
			printf(",");
	}
}

int main()
{
	int i,t;
	char ch[30];
	while(scanf("%s",ch)!=EOF&&strcmp(ch,"*"))
	{
		if(ch[0]>='a'&&ch[0]<='z')
		{
			printf("%s",ch);
			for(i=strlen(ch)+1;i<23;i++)
				printf(" ");
			BinToDec(ch);
		}
		else
		{
			DecToBin(ch);
			t=strlen(ch);
			for(i=0;i<t;i++)
			{
				printf("%c",ch[i]);
				if((i+1)%3==t%3&&i<t-1)
					printf(",");
			}
		}
		printf("\n");
	}
	return 0;
}



