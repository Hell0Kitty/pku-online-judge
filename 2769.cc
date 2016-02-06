#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;

const int MAXN = 1e5+10;
const int MAXM = 1e6 + 10;

int stu[MAXN];
int m[MAXN];

int main()
{
	int kase;
	cin >> kase;
	while(kase--)
	{
		//memset( mod, 0, sizeof mod );
		int n;

		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> stu[i];

		bool flag;
		int i;
		for(i = 1; ; i++)
		{
			memset( m, 0, sizeof m );
			flag = true;
			for(int j = 1; j <= n; j++)
			{
				if(m[stu[j] % i] == 1)
				{
					flag = false;
					break;
				}
				else
					m[stu[j] % i] = 1;
			}
			if(flag)break;
		}
		cout << i << endl;
	}
	return 0;
}



