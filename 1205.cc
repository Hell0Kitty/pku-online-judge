#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string add(string s1,string s2)
{
	string result;
	result.reserve(1000);

	if(s1.length()<s2.length())
		s1.swap(s2);
	s2.insert(s2.begin(),s1.length()-s2.length(),'0');

	int g=0;
	for(int i=s1.length()-1;i>=0;i--)
	{
		g+=s1[i]+s2[i]-2*'0';
		result+=g%10+'0';
		g/=10;
	}
	if(g>0)
		result+=g+'0';
	reverse(result.begin(),result.end());

	return result;
}

string a[101];

void Initial()
{
	a[1]="1";
	for(int i=2;i<=100;i++)
	{
		string temp;
		temp="1";
		for(int k=1;k<i-1;k++)
			temp=add(temp,a[k]);
		string te=add(a[i-1],a[i-1]);
		temp=add(temp,te);

		a[i]=temp;
	}
}

int main(int argc, char* argv[])
{
	Initial();

	int x;
	while(cin>>x)
		cout<<a[x]<<endl;
	return 0;
}


