#include<iostream>
#include<fstream>
using namespace std;
int main (int argc, char **argv)
{
	int n;
	int i;
	int before;
	int now;
	while(cin>>n)
	{
		if (n ==0)
			break;
		cin>>before;
		cout<<before<<" ";
		for(i =0; i < n-1; i++)
		{
			cin>>now;
			if(now!=before)
				cout<<now<<" ";
			before=now;
		}
		cout<<"$"<<endl;
	}
	return 0;
}


