#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10000
int N;
int codes[2*MAX+10];
int signs[2][MAX+10];
int ans[2][MAX+10];

bool Foo(int s, int first)
{
	int i, j, n;
	i = j = s;
	if(codes[first*N+s]*signs[first][0] < 0)
		return false;
	ans[first][0] = codes[first*N+s];
	for(n = 1; n < N; ++n)
	{
		if(codes[first*N+j]*signs[first][n] > 0)
		{
			--i;
			if(i < 0)
				return false;
			ans[first][n] = codes[first*N+i];
		}
		else
		{
			++j;
			if(j >= N)
				return false;
			ans[first][n] = codes[first*N+j];
		}
	}
	return true;
}

int main()
{
	//ifstream cin("test.txt");
	int i, j, n;
	cin >> N;
	for(n = 0; n < 2*N; ++n)
		cin >> codes[n];
	for(n = 0; n < N; ++n)
	{
		cin >> i;
		signs[0][n] = 2*(i==1||i==4)-1;
		signs[1][n] = 2*(i<=2)-1;
	}
	sort(codes, codes+2*N);
	j = signs[0][N-1];
	for(n = N-1; n >= 0; --n, j*=-1)
		codes[n] *= j;
	j = signs[1][N-1];
	for(n = 2*N-1; n >= N; --n, j*=-1)
		codes[n] *= j;
	bool done[2];
	done[0] = done[1] = false;
	int left1 = 0; int left2 = 0;
	for(i = 0; i < N-1; ++i)
	{
		if(signs[0][i]==signs[0][i+1])
			++left1;
		if(signs[1][i]==signs[1][i+1])
			++left2;
	}
	done[0] = Foo(left1, 0);
	done[1] = Foo(left2, 1);
	if(!done[0] || !done[1])
		cout << 0 << endl;
	else
	{
		for(i = 0; i < N; ++i)
		{
			if(ans[0][i] > 0)
				cout << "+";
			cout << ans[0][i] << " ";
			if(ans[1][i] > 0)
				cout << "+";
			cout << ans[1][i] << endl;
		}
	}
	return 0;
}


