#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int i;
	int cipher[26],clear[26];
	memset(cipher,0,sizeof(cipher));       
	memset(clear,0,sizeof(clear));
	string input;
	cin>>input;
	for(i=0;i<input.length();i++)
	{
		cipher[input[i]-'A']++;
	}
	cin>>input;
	for(i=0;i<input.length();i++)
	{
		clear[input[i]-'A']++;
	}
	sort(cipher,cipher+26);        
        sort(clear,clear+26);         
	for(i=0;i<26;i++)
		if(cipher[i]!=clear[i])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	cout<<"YES"<<endl;
	return 0;
}



