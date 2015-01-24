#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
struct BigInt
{
	int len;
	int val[205];
	void Copy(BigInt &b)
	{
		int i,len2;
		len2=b.len;
		for(i=1;i<=len2;i++)
		val[i]=b.val[i];
		len=len2;
		val[len+1]=0;
		return; 
	}
	void Mul(int b)
	{
		int i;
		for(i=1;i<=len;i++)
		val[i]*=b;
		for(i=1;i<=len;i++)
		if(val[i]>999999)
		val[i+1]+=(val[i]/1000000),val[i]%=1000000;
		if(val[len+1]>0)
		len++;
		return;
	}
	void Add(BigInt &b)
	{

		int i,len2;
		len2=b.len;
		for(i=1;i<=len2;i++)
		  val[i]+=b.val[i];
		if(len2>len)
		   len=len2;
    	for(i=1;i<=len;i++)
		 if(val[i]>999999)
	        val[i+1]+=(val[i]/1000000),val[i]%=1000000;
	     if(val[len+1]>0)
	     len++;
	     return;
	}
	void print()
	{
		int i;
		printf("%d",val[len]);
		for(i=len-1;i>=1;i--)
		printf("%06d",val[i]);
		printf("\n");
		return;
     }
}f[505][505],b;
int n,k,i,j;
int main()
{
	f[0][0].val[1]=f[0][0].len=1;
	for(i=1;i<=500;i++)
	for(j=1;j<=i;j++)
	{
		f[i][j].Copy(f[i-1][j]);
		f[i][j].Mul(j);
		b.Copy(f[i-1][j-1]);
		b.Mul(i-j+1);
		f[i][j].Add(b); 
	}
	while(1)
	{
		scanf("%d %d",&n,&k);
		if(n==0&&k==0)
		break;
		f[n][k].print();
	}
	return 0;
}



