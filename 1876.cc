#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>
#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define eps 1e-6
#define LL long long
#define PAU	assert(0)
using namespace std;

struct MTA
{
	vector<string> users;
	string name;
	int un;
};

vector<MTA> allMta;

struct MAIL
{
	string data;
	string sender;
	vector<string> recer;
};

void kg()
{
	cout << "     ";
}

int findrec(bool *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!arr[i])
			return i;
	}
	return -1;
}

string getname(const string &s)
{
	string tmp = s;
	int i = 0;
	for (; i < s.size(); i++)
	{
		if (s[i] == '@')
			break;
	}
	tmp.resize(i);
	return tmp;
}

string getmta(const string &s)
{
	string tmp = s;
	int i = 0;
	for (; i < s.size(); i++)
	{
		if (s[i] == '@')
			break;
	}
	int k = 0;
	i++;
	for (; i < s.size(); i++, k++)
		tmp[k] = s[i];
	tmp.resize(k);
	return tmp;
}

int main()
{
	string stmp;
	MTA mtmp;
	int n;
	int pfn;
	set<string> cache;
	while (true)
	{
		cin >> stmp;
		if (stmp[0] == '*')
			break;
		cin >> stmp;
		mtmp.name = stmp;
		cin >> n;
		mtmp.un = n;
		mtmp.users.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> stmp;
			mtmp.users.push_back(stmp);
		}
		allMta.push_back(mtmp);
	}
	while (true)
	{
		MAIL mail;
		cache.clear();
		cin >> stmp;
		if (stmp[0] == '*')
			break;
		mail.sender = stmp;
		while (true)
		{
			cin >> stmp;
			if (stmp[0] == '*')
				break;
			if (cache.count(stmp))
				;
			else
			{
				cache.insert(stmp);
				mail.recer.push_back(stmp);
			}
		}
		getchar();
		getline(cin, stmp, '*');
		mail.data = stmp;
		bool *processed = new bool[mail.recer.size()];
		for (int i = 0; i < mail.recer.size(); i++)
			processed[i] = false;
		pfn = mail.recer.size();
		while (pfn)
		{
			int reci = findrec(processed, mail.recer.size());
			cout << "Connection between " << getmta(mail.sender) << " and " << getmta(mail.recer[reci]) << endl;
			kg();
			cout << "HELO " << getmta(mail.sender) << endl;
			kg();
			cout << 250 << endl;
			kg();
			cout << "MAIL FROM:<" << mail.sender << ">" << endl;
			kg();
			cout << 250 << endl;
			bool sentData = false;
			bool finded;
			string recMtaStr = getmta(mail.recer[reci]);
			for (int i = reci; i < mail.recer.size(); i++)
			{
				if (getmta(mail.recer[i]) == recMtaStr)
				{
					kg();
					cout << "RCPT TO:<" << mail.recer[i] << '>' << endl;
					pfn--;
					processed[i] = true;
					for (vector<MTA>::iterator p = allMta.begin(); p != allMta.end(); p++)
					{
						if (p->name == recMtaStr)
						{
							finded = false;
							for (int y = 0; y < p->un; y++)
							{
								if (p->users[y] == getname(mail.recer[i]))
								{
									finded = true;
									break;
								}
							}
							break;
						}
					}
					if (finded)
					{
						kg();
						cout << 250 << endl;
						sentData = true;
					}
					else
					{
						kg();
						cout << 550 << endl;
					}
				}
			}
			if (sentData)
			{
				kg();
				cout << "DATA" << endl;
				kg();
				cout << 354 << endl;
				stringstream ss(mail.data);
				string tmp;
				while (getline(ss, tmp))
				{
					kg();
					cout << tmp << endl;
				}
				kg();
				cout << "." << endl;
				kg();
				cout << 250 << endl;
			}
			kg();
			cout << "QUIT" << endl;
			kg();
			cout << 221 << endl;
		}
	}

	return 0;
}



