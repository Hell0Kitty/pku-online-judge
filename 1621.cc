#include<iostream>
#include<vector>
using namespace std;

int getBits(int num)//返回num 的位数
{
	//传入的num != 0
	int b = 0;
	while(num != 0)
	{
		b++;
		num = num / 10;
	}
	return b;
}

int main()
{
	int maxDegree, an;
	vector<int> coefficient;
	int index = 1;
	while(cin >> maxDegree >> an && (maxDegree != 0 || an != 0))
	{
		coefficient.clear();
		coefficient.push_back(an);
		for(int i = 1; i < maxDegree; i++)
		{
			int c;
			cin >> c;
			coefficient.push_back(c);
		}

		int constNum, x;
		cin >> constNum >> x;
		int ans = x;//采用秦九韶算法，又因为an = 1，所以最内的括号的值为 x + An-1
		int cost = 0;
		for(int i = 1; i < coefficient.size(); i++)
		{
			if(coefficient[i] != 0)
			{
				//只要系数不为0，则需一次加法
				cost++;
				//系数的位数
				cost = cost + getBits(coefficient[i]);
				//一次乘法
				cost++;
				ans = (ans + coefficient[i]) * x;
			}
			else
			{
				ans = ans * x;
				//一次乘法
				cost++;
			}
		}
		ans = ans + constNum;
		if(constNum != 0)
			cost = cost + maxDegree + 1 + getBits(constNum) + 1;//1个1是因为加了常数，有个加法； 另一个1是等号
		else
			cost = cost + maxDegree + 1;
		if(maxDegree == 0)
			cout << "Polynomial " << index << ": " << 1 << " " << 2 << endl;
		else
			cout << "Polynomial " << index << ": " << ans << " " << cost << endl;
		index++;
	}
	return 0;
}



