#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

ll exgcd( ll a, ll b, ll& x, ll& y )
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd( b, a%b, x, y );
	ll tem = x;
	x = y;
	y = tem - a / b*y;
	return gcd;
}

int main()
{
	int n;
	ll r1, m1, r2, m2, x0, y0;
	while(cin >> n)
	{
		bool flag=1;
		cin >> m1 >> r1;
		for(int i = 1; i < n; i++)
		{
			cin >> m2 >> r2;
			ll a = m1, b = m2, c = r2 - r1;
			ll d=exgcd( a, b, x0, y0 );
			if(c%d != 0) flag = false;

			ll t = b / d;
			x0 = (x0*(c / d) % t + t) % t;
			r1 = m1*x0 + r1;
			m1 = m1*(m2 / d);
		}
		if(!flag)
		{
			cout << -1 << endl;
			continue;
		}
		cout << r1 << endl;
	}
	return 0;
}


