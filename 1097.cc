#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX_N 30
#define MAX_L 1000
#define MAX_VAL 1000000
using namespace std;

//graph
double graph[MAX_N + 1][MAX_N + 1];
double D[2][MAX_N + 1][MAX_N + 1];
double pre[2][MAX_N + 1][MAX_N + 1];
//

struct node1
{
	int from;
	int to;
	double dist;
	int townNum;
	int townList[MAX_N + 1];
	int distToTown[MAX_N + 1];
}signs[MAX_L + 1];
struct node2
{
	string name;
}towns[MAX_N + 1];
int nodeNum, roadNum, towNum, sigNum, resPos;
void init()
{
	int i, j;
	for(i = 1; i <= MAX_L; i++)
	{
		signs[i].townNum = 0;
		signs[i].dist = 0;
		signs[i].from = signs[i].to = 0;
		if(i <= MAX_N)
		{
			towns[i].name = " ";
			for(j = 1; j <= MAX_N; j++)
			{
				graph[i][j] = D[0][i][j] = D[1][i][j] = MAX_VAL;
				pre[0][i][j] = pre[1][i][j] = 0;
			}
		}
	}
}

bool byPass(int from, int to, int mid)
{
	while(to != from && to != 0)
	{
		if(to == mid)
			return true;
		to = pre[resPos][from][to];
	}
	return false;
}

void swap(int pos1, int pos2, int signPos)
{
	int tempPos = signs[signPos].townList[pos2];
	int tempDist = signs[signPos].distToTown[pos2];

	signs[signPos].townList[pos2] = signs[signPos].townList[pos1];
	signs[signPos].distToTown[pos2] = signs[signPos].distToTown[pos1];

	signs[signPos].townList[pos1] = tempPos;
	signs[signPos].distToTown[pos1] = tempDist;

}
int compare(int pos1, int pos2, int signPos)
{
	if(signs[signPos].distToTown[pos1] < signs[signPos].distToTown[pos2])
		return -1;
	else if(signs[signPos].distToTown[pos1] > signs[signPos].distToTown[pos2])
		return 1;
	else
	{
		string str1 = towns[signs[signPos].townList[pos1]].name;
		string str2 = towns[signs[signPos].townList[pos2]].name;
		if(str1 < str2)
			return -1;
		else if(str1 == str2)
			return 0;
		else
			return 1;
	}
}
void fastSort(int start, int end, int signPos)
{
	if(start < end)
	{
		int posS = start, posE = end + 1;
		int curPos = start;
		while(true)
		{
			while(compare(curPos, ++posS, signPos) > 0 && posS < end);
			while(compare(curPos, --posE, signPos) < 0 && posE > start);
			if(posS < posE)
				swap(posS, posE, signPos);
			else
				break;
		}
		swap(start, posE, signPos);
		fastSort(start, posE - 1, signPos);
		fastSort(posE + 1, end, signPos);
	}
}

int main()
{
	int i, j, k, from, to;
	double dist;
	string name;
	init();
	cin>>nodeNum>>roadNum>>towNum;
	for(i = 1; i <= roadNum; i++)
	{
		cin>>from>>to>>dist;
		from++, to++;
		graph[from][to] = D[0][from][to] = dist;
		graph[to][from] = D[0][to][from] =dist;
		pre[0][from][to] = from;
		pre[0][to][from] = to;
	}
	for(i = 1; i <= towNum; i++)
	{
		cin>>from>>name;
		from++;
		towns[from].name = name;
	}
	cin>>sigNum;
	for(j = 1; j <= sigNum; j++)
	{
		cin>>from>>to>>dist;
		from++, to++;
		signs[j].from = from;
		signs[j].to = to;
		signs[j].dist = dist;
	}
	//process
	for(k = 1; k <= nodeNum; k++)
	{
		for(i = 1; i <= nodeNum; i++)
		{
			for(j = 1; j <= nodeNum; j++)
			{
				if(i == j)
					continue;
				int lastPos = (k + 1) % 2;
				int curPos = k % 2;
				double curVal = D[lastPos][i][j];
				double nextVal = D[lastPos][i][k] + D[lastPos][k][j];

				if(curVal < nextVal)
				{
					if(curVal >= MAX_VAL)
						continue;
					D[curPos][i][j] = curVal;
					pre[curPos][i][j] = pre[lastPos][i][j];
				}
				else
				{
					if(nextVal >= MAX_VAL)
						continue;
					D[curPos][i][j] = nextVal;
					pre[curPos][i][j] = pre[lastPos][k][j];
				}
			}
		}
	}
	resPos = nodeNum % 2;

	for(i = 1; i <= sigNum; i++)
	{
		int from = signs[i].from;
		int to = signs[i].to;
		for(j = 1; j <= MAX_N; j++)
		{
			if(towns[j].name == " ")
				continue;
			if(byPass(from , j, to))
			{
				int num = ++signs[i].townNum;
				signs[i].townList[num] = j;
				signs[i].distToTown[num] = double(D[resPos][from][j] - signs[i].dist) + 0.5;
			}
		}
		fastSort(1, signs[i].townNum, i);
		for(j = 1; j <= signs[i].townNum; j++)
			printf("%-20s%d\n", towns[signs[i].townList[j]].name.c_str(), signs[i].distToTown[j]);
		printf("\n");
	}

	return 0;
}


