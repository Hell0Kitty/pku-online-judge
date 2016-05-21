#include<iostream>
using namespace std;
int main()
{
	long long gcd(long long a,long long b);
	long long s;
	while(cin>>s)
	{
                 if(s==0)
                 {
                         cout<<0<<endl;
                         continue;
                         }
        if(s==-1)break;
		int k;
		long long p[64];
		p[0]=1;
		for(k=0;k<s;++k)
			p[k+1]=p[k]*3;
		long long count=s&1?s*p[s/2+1]:(s/2)*(p[s/2]+p[s/2+1]);
		for(k=1;k<=s;++k)
			count+=p[gcd(k,s)];
		count/=2*s;
		cout<<count<<endl;
	}
	return 0;
}
long long gcd(long long a,long long b)
{
	long c;
	if(a==0)
		return b;
	while(b!=0)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}


