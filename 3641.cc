#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long a,p;
	int isprime(long long n);
	long long modular(long long a,long long r,long long m);
	while(cin>>p>>a)
	{
		if(p==0&&a==0)
			break;
		long long result;
		if(isprime(p))
			cout<<"no"<<endl;
		else
		{
			if(a==modular(a,p,p))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
	}
	return 0;
}
int isprime(long long n)
{
	if(n==2)
		return 1;
	if(n<=1||n%2==0)
		return 0;
	long long j=3;
	while(j<=(long long)sqrt(double(n)))
	{
		if(n%j==0)
			return 0;
		j+=2;
	}
	return 1;
}
long long modular(long long a,long long r,long long m)
{
	long long d=1,t=a;
	while(r>0)
	{
		if(r%2==1)
			d=(d*t)%m;
		r/=2;
		t=t*t%m;
	}
	return d;
}



