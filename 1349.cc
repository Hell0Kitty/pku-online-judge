#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXIL 300
#define MAXN 52
#define MAXVL 300
char jie[MAXN][MAXVL];
char A[MAXVL];
char s[MAXN][MAXN];
int stop;
bool first=true;

void ditoa(int n,char *c)
{
	if(n==0)
		strcpy(c,"0");
	else
	{
		int i=0;
		while(n)
		{
			c[i]=n%10+'0';
			n/=10;
			i++;
		}
		c[i]='\0';
		std::reverse(c,c+strlen(c));
	}
}

int compare(char *a,char *b)
{
	int len1=strlen(a),len2=strlen(b);
	if(len1==len2)
	{
		int i=0;
		while(i<len1&&a[i]==b[i]) 
			i++;
		if(i==len1) 
			return true;
		else
			return a[i]-b[i];
	}
	else
		return len1-len2;
}

void add(char a[],char b[],char back[])
{
	int i,j,k,up,x,y,z,l;
	char *c;
	if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;
	c=(char *) malloc(l*sizeof(char));
	i=strlen(a)-1;
	j=strlen(b)-1;
	k=0;up=0;
	while(i>=0||j>=0)
	{
		if(i<0) x='0'; else x=a[i];
		if(j<0) y='0'; else y=b[j];
		z=x-'0'+y-'0';
		if(up) z+=1;
		if(z>9) {up=1;z%=10;} else up=0;
		c[k++]=z+'0';
		i--;j--;
	}
	if(up) c[k++]='1';
	i=0;
	c[k]='\0';
	for(k-=1;k>=0;k--)
		back[i++]=c[k];
	back[i]='\0';
}

void mult(char a[],char b[],char s[])
{
	const int MAXL=300;
	int i,j,k=0,alen,blen,sum=0,res[MAXL][MAXL]={0},flag=0;
	char result[MAXL];
	alen=strlen(a);blen=strlen(b);
	for (i=0;i<alen;i++)
		for (j=0;j<blen;j++) res[i][j]=(a[i]-'0')*(b[j]-'0');
	for (i=alen-1;i>=0;i--)
	{
		for (j=blen-1;j>=0;j--) sum=sum+res[i+blen-j-1][j];
		result[k]=sum%10;
		k=k+1;
		sum=sum/10;
	}
	for (i=blen-2;i>=0;i--)
	{
		for (j=0;j<=i;j++) sum=sum+res[i-j][j];
		result[k]=sum%10;
		k=k+1;
		sum=sum/10;
	}
	if (sum!=0) {result[k]=sum;k=k+1;}
	for (i=0;i<k;i++) result[i]+='0';
	for (i=k-1;i>=0;i--) s[i]=result[k-1-i];
	s[k]='\0';
	while(1)
	{
		if (strlen(s)!=strlen(a)&&s[0]=='0')
			strcpy(s,s+1);
		else
			break;
	}
}

void init()
{
	memcpy(jie[0],"1",sizeof("1"));
	char temp[MAXVL];
	for(int i=1;i<MAXN;i++)
	{
		ditoa(i,temp);
		mult(jie[i-1],temp,jie[i]);
		//printf("%s\n",jie[i]);
	}
}

void solve()
{
	strcpy(A,"0");
	int temp;
	char ctemp[MAXVL];
	int n=0;
	n+=(s[0][0]-'0');
	if(s[0][1]!='\0')
	{
		n=n*10+(s[0][1]-'0');
	}
	for(int i=1;i<stop;i++)
	{
		temp=0;
		for(int j=i+1;j<=stop;j++)
			if(compare(s[i],s[j])>0)
				temp++;
		ditoa(temp,ctemp);
		//	printf("ctemp=%s ",ctemp);
		mult(ctemp,jie[n-i],ctemp);
		//	printf("ctemp*jie[n-i]=%s ",ctemp);
		add(ctemp,A,A);
		//printf("A=%s\n",A);
	}
	add(A,"1",A);
}

int main()
{
	//freopen("c:/aaa.txt","r",stdin);
	init();
	char str[MAXIL];
	int len;
	while(gets(str)&&strcmp(str,"-1")!=0)
	{
		len=strlen(str);
		int i=0,c;
		stop=-1;
		while(i<len)
		{
			while(i<len&&(str[i]=='('||str[i]==')'||str[i]==','))
				i++;
			if(i==len) break;
			stop++;
			c=0;
			while(i<len&&str[i]!='('&&str[i]!=')'&&str[i]!=',')
				s[stop][c++]=str[i++];
			s[stop][c]='\0';

		}
		if(!first)
			printf(",");
		solve();
		printf("%s",A);
		first=false;
	}
	printf("\n");

	return 0;
}


