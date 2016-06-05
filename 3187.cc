#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10;
int data[MAX];
int n, sum;

void showResult()
{
	for(int i=0; i < n; i++)
		cout << data[i] << ' ';
	cout << endl;
}

bool adjCase()
{
	int temp[MAX], i;

	for(i=0; i < n; i++)
		temp[i] = data[i];

	for(int num=n; num > 0; num --)
	{
		for(i=0; i < num-1; i++)
		{
			temp[i]=temp[i]+temp[i+1];
		}
	}
	if(temp[0]==sum) return true;
	return false;
}

void solveCase()
{
	if(adjCase()){
		showResult();
		return ;
	}
	while(next_permutation(data, data+n))
	{
		if(adjCase())
		{
			showResult();
			break;
		}		
	}
}

int main()
{
	cin >> n >> sum;
	for(int i=1; i <= n; i++)
		data[i-1]=i;
	solveCase();
	return 0;
}



