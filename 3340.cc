#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int main()
{
	while(cin>>s1)
	{
		if(s1[0]=='#')
			break;
		cin>>s2;int count =0;
		int n = s1.length();
		for(int i=0;i!=n;i++)
		{
			if(s1[i] < s2[i] && s1[i]!='?')
			{
				break;
			}
			if(s1[i]=='?')//出现问号的情况
			{
				int buff = '9' - s2[i];
				for(int j=i+1;j!=n;j++)
					if(s1[j]=='?')
						buff*=10;
				count+=buff;
			}
			if(s1[i]==s2[i])//两数相等，继续计算下一个
				continue;
			if(s1[i]>s2[i]&&s1[i]!='?')//X大于W的情况，count等于10乘以之后问号个数
			{
				int buff = 1;
				for(int j=i+1;j!=n;j++)
				{
					if(s1[j]=='?')
						buff*=10;
				}
				count+=buff;
				break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}



