#include <iostream>
#include <string>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;

struct node
{
	int a,b;
};

string str;
node a,b;
int num=0;

int OK1(char x)
{
	return x>='0'&&x<='9';
}

int OK2(char x)
{
	return x=='x';
}

int OK3(char x)
{
	return x=='+'||x=='-';
}

int find(int pos)
{
	int a=0,i;
	for(i=pos;;i++)
	{
		if(str[i]=='(') a++;
		else if(str[i]==')') a--;
		if(!a) break;
	}
	return i;
}

int get(int pos,int &pos1)
{
	int ans=0,i;
	for(i=pos;OK1(str[i]);i++) ans=ans*10+str[i]-'0';
	pos1=i-1;
	return ans;
}

node DFS(int s,int e)
{
	node ans,temp,temp1;
	int i,flag=1,pos,num;
	ans.a=ans.b=0;
	for(i=s;i<=e;i++)
	{
		if(OK1(str[i])||OK2(str[i])||str[i]=='(')
		{
			temp.a=temp.b=0;
			if(OK2(str[i])) temp.b=1;
			else if(OK1(str[i]))
			{
				temp.a=str[i]-'0';
				for(i++;i<=e&&OK1(str[i]);i++) temp.a=temp.a*10+str[i]-'0';
				i--;
			}
			else
			{
				pos=find(i);
				temp=DFS(i+1,pos-1);
				ans.a+=flag*temp.a;
				ans.b+=flag*temp.b;
				i=pos;
			}
			while(1)
			{
				if(i>e||i+1>e) break;
				if(OK3(str[++i])) {i--;break;}
				if(str[i]=='*') continue;
				if(str[i]=='(')
				{
					pos=find(i);
					temp1=DFS(i+1,pos-1);
					if(temp1.b==0) temp.a*=temp1.a,temp.b*=temp1.a;
					else temp.b=temp.a*temp1.b,temp.a=temp.a*temp1.a;
					i=pos;
					continue;
				}
				if(str[i]=='x') temp.b=temp.a,temp.a=0;
				else
				{
					num=get(i,pos);
					temp.a*=num;
					temp.b*=num;
					i=pos;
				}
			}
			ans.a+=flag*temp.a;
			ans.b+=flag*temp.b;
		}
		else if(str[i]=='+') flag=1;
		else if(str[i]=='-') flag=-1;
	}
	return ans;
}

int main()
{
	while(cin>>str)
	{
		int pos=str.find_first_of('=',0);
		a=DFS(0,pos-1);
		b=DFS(pos+1,str.length()-1);
		a.b-=b.b;
		b.a-=a.a;
		printf("Equation #%d\n",++num);
		if(a.b==0&&b.a==0) puts("Infinitely many solutions.");
		else if(a.b==0&&b.a) puts("No solution.");
		else printf("x = %.6lf\n",1.0*b.a/a.b);
		puts("");
	}
	return 0;
}



