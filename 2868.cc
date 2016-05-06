#include<iostream>
#include<map>
#include<string>
#include<math.h>
using namespace std;

int ta;
int f(int n)
{
	int i=0;
	while(i*pow(double(ta),i)<n)
	{

		n-=i*pow(double(ta),i);
		i++;

	}
	n--;
	int x,y,tmp;
	x=(n/i);
	y=i-(n%i);
	//cout<<i<<" "<<ta<<" "<<y<<" "<<x<<endl;
	int k=0;
	while(k!=y)
	{
		tmp=x%ta;
		x/=ta;
		k++;
	}
	return tmp;
}

int main()
{
	string s[27];
	int q;
	cin>>ta>>q;

	while(ta+q)
	{
		for(int i=0; i<ta; i++)
			cin>>s[i];

		for(int i=0; i<q; i++)
		{
			int x,ans;
			cin>>x;
			ans=f(x);
			cout<<s[ans]<<endl;
		}
		cout<<endl;
		cin>>ta>>q;
	}
}


