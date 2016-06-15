#include <iostream>
#include <string>
#include <list>
using namespace std; 

string str;
list<string> table;
list<string>::iterator it;

int NUM(char x)
{
	return x>='0'&&x<='9';
}

int ALP(char x)
{
	return x>='a'&&x<='z'||x>='A'&&x<='Z';
}

int main()
{
	char c;
	while((c=getchar())!=-1) str+=c;
	int i,pos,num;
	string temp;
	pos=str.find_last_of("0");
	str.erase(pos,str.size()-pos);
	for(i=0;i<str.size();i++)
	{
		if(NUM(str[i]))
		{
			num=0;
			while(NUM(str[i])) num=num*10+str[i++]-'0';
			i--; pos=0;
			it=table.begin();
			while(++pos!=num) it++;
			temp=*it;
			printf("%s",it->c_str());
			table.erase(it);
			table.push_front(temp);
		}
		else if(ALP(str[i]))
		{
			temp="";
			while(ALP(str[i])) temp+=str[i++];
			i--;
			table.push_front(temp);
			printf("%s",temp.c_str());
		}
		else putchar(str[i]);
	}
	return 0;
}



