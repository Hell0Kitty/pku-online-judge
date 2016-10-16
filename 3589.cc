#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int T;
	string a,b;
	int count1,count2;
	cin>>T;
	while(T--)
	{
		count1 = 0;
		count2 = 0;
		cin>>a>>b;
		for(int i = 0;i<4;i++)
		{
			if(a[i] == b[i])
				count1++;
			else
			{
				for(int j = i+1;j<4;j++)
				{
					if(a[i] == b[j])
						count2++;
					if(b[i] == a[j])
						count2++;
				}
			}
		}
		cout<<count1<<'A'<<count2<<'B'<<endl;
	}
	return 0;
}


