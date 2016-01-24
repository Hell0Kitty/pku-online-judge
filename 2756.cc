#include <stdio.h>
#include <string>
#include <algorithm>
using std::string;

const int MAX_B = 5120;
char buf[MAX_B];
int id = 0, len = 0;

inline char getFromBuf()
{
	if (id >= len)
	{
		len = fread(buf, 1, MAX_B, stdin);
		id = 0;
	}
	return buf[id++];
}

void getIntFromBuf(string &n)
{
	char a = getFromBuf();
	while ((a == ' ' || a == '\n') && len) a = getFromBuf();

	bool sign = true;
	if (a == '-' || a == '+')
	{
		if (a == '-') sign = false;
		a = getFromBuf();
	}
	n.clear();
	while ((a != ' ' && a != '\n') && len)
	{
		n.push_back(a);
		a = getFromBuf();
	}
	if (sign) n.push_back('+');
	else n.push_back('-');
}

string operator+(string &a, string &b)
{
	string c;
	int N1 = (int)a.size(), N2 = (int)b.size();
	int carry = 0;
	for (int i = N1-1, j = N2-1; i>=0 || j>=0 || carry; i--, j--)
	{
		int an = i>=0? a[i]-'0' : 0;
		int bn = j>=0? b[j]-'0' : 0;
		int sum = an + bn + carry;
		carry = sum / 10;
		c.push_back(sum % 10 + '0');
	}
	reverse(c.begin(), c.end());
	return c;
}

string operator-(string &a, string &b)
{
	string c;
	int N1 = (int)a.size(), N2 = (int)b.size();
	int carry = 0;
	for (int i = N1-1, j = N2-1; i>=0 || j>=0 || carry; i--, j--)
	{
		int an = i>=0? a[i]-'0' : 0;
		int bn = j>=0? b[j]-'0' : 0;
		int sum = an - bn + carry;
		if (sum < 0)
		{
			carry = -1;
			sum += 10;
		}
		else carry = 0;
		c.push_back(sum % 10 + '0');
	}
	reverse(c.begin(), c.end());
	return c;
}

int cmpAbsStr(string &a, string &b)
{
	if (a.size() < b.size()) return -1;
	else if (a.size() > b.size()) return 1;
	if (a == b) return 0;

	for (int i = 0; i < (int)a.size(); i++)
	{
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	string n1, n2;
	while (T--)
	{
		getIntFromBuf(n1);
		getIntFromBuf(n2);
		if (n1[n1.size()-1] == '+' && n2[n2.size()-1] == '+'
			|| n1[n1.size()-1] == '-' && n2[n2.size()-1] == '-')
		{
			if (n1[n1.size()-1] == '-' && n2[n2.size()-1] == '-') putchar('-');
			n1.erase(n1.size()-1); n2.erase(n2.size()-1);
			string c = n1 + n2;
			puts(c.c_str());
		}
		else
		{
			if (n1[n1.size()-1] == '-' && n2[n2.size()-1] == '+') n1.swap(n2);
			n1.erase(n1.size()-1), n2.erase(n2.size()-1);

			int sign = cmpAbsStr(n1, n2);
			if (sign == 0) puts("0");
			else if (sign == 1)
			{
				string c = n1 - n2;
				puts(c.c_str());
			}
			else
			{
				string c = n2 - n1;
				putchar('-');
				puts(c.c_str());
			}
		}
	}
	return 0;
}



