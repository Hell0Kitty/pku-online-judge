#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double PI = 3.141592653;
const double EPS = 1e-6;
#define LL long long

const int Max=1000009;
int in[Max],cube[109][109][109];

int lowbit(int t){
	return t & (-t);
}

int sum(int x){
	int t=0;
	while(x>0){
		t+=in[x];
		x-=lowbit(x);
	}
	return t;
}

void insert(int x,int num){
	while(x<=Max){
		in[x]+=num;
		x+=lowbit(x);
	}
}

struct node {
	int x,y,z;
}pos;
int n;

void gao(node p) {
	for(int x = p.x; x < n; x++) {
		swap(cube[x][p.y][p.z],cube[x+1][p.y][p.z]);
	}
	for(int y = p.y; y < n; y++) {
		swap(cube[n][y][p.z],cube[n][y+1][p.z]);
	}
	for(int z = p.z; z < n; z++) {
		swap(cube[n][n][z],cube[n][n][z+1]);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		memset(in,0,sizeof(in));
		for(int z = 1; z <= n; z++) {
			for(int y = 1; y <= n; y++) {
				for(int x = 1; x <= n; x++) {
					scanf("%d",&cube[x][y][z]);
					if(cube[x][y][z] == 0)
						pos.x = x, pos.y = y, pos.z = z;
				}
			}
		}
		gao(pos);
		int ans = 0;
		int s = 0;
		for(int z = 1; z <= n; z++) {
			for(int y = 1; y <= n; y++) {
				for(int x = 1; x <= n; x++) {
					if(x == n && y == n && z == n)
						continue;
					int cnt = s - sum(cube[x][y][z]);
					s++;
					insert(cube[x][y][z],1);
					ans = (ans + cnt) % 2;
				}
			}
		}
		if(ans % 2)
			printf("Puzzle is unsolvable.\n");
		else
			printf("Puzzle can be solved.\n");
	}
	return 0;
}



