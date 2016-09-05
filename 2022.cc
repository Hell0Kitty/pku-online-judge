#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#define mp make_pair
#define pb push_back
using namespace std;
const int N=1020;
string stack[N],str;
int top=0;
char cmd[N];
bool cantprt(char x)
{
	return x=='\n'||x=='\t'||x==' ';
}
bool ckURL(const string &s)
{
	if(s.size()<11)return false;
	if(s.substr(0,7)!="http://")return false;
	if(s.substr(s.size()-4,4)!=".com")return false;
	int i;
	for(i=0;i<s.size();i++)
		if(cantprt(s[i])||s[i]=='<'||s[i]=='>')return false;
	return true;
}
bool cktag(const string &s,bool flag=0)
{
	if(s=="B")return true;
	if(s=="I")return true;
	if(flag)return s=="A";
	if(s.size()<9)return false;
	if(s[0]=='A'&&s[1]==' '&&s.substr(2,5)=="HREF=")
		return ckURL(s.substr(7,s.size()-7));
	return false;
}
bool cmp(const string &a,const string &b)
{
	if(a==b)return true;
	if(b=="A")return a[0]=='A';
	return false;
}
bool cktext(const string &s)
{
	int i;
	string tmp;
	for(i=0;i<s.size();i++)
		if(s[i]=='<')
		{
			tmp="";
			if(s[i+1]=='/')
			{
				for(i+=2;s[i]!='>'&&i<s.size();i++)
					tmp+=s[i];
				if(i==s.size())return false;
				if(top&&cktag(tmp,true)&&cmp(stack[top],tmp))top--;
				else return false;
			}
			else
			{
				for(i++;s[i]!='>'&&i<s.size();i++)
					tmp+=s[i];
				if(i==s.size())return false;
				if(cktag(tmp))stack[++top]=tmp;
				else return false;
			}
		}
	return top==0;
}
bool ckbody(const string &s)
{
	if(s.size()<13)return false;
	if(s.substr(0,6)!="<BODY>")return false;
	if(s.substr(s.size()-7,7)!="</BODY>")return false;
	return cktext(s.substr(6,s.size()-13));
}
bool ckhtml(const string &s)
{
	if(s.size()<13)return false;
	if(s.substr(0,6)!="<HTML>")return false;
	if(s.substr(s.size()-7,7)!="</HTML>")return false;
	return ckbody(s.substr(6,s.size()-13));
}
int main()
{
	int cas;
	scanf("%d\n",&cas);
	while(cas--)
	{
		top=0;
		gets(cmd);
		str=cmd;
		if(ckhtml(str))puts("Syntax Included");
		else puts("No Syntax Included");
	}
}



