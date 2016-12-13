#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int sum, fir;
const int MAX = 100000;
const int SQRT = 318;
bool v[MAX] = {1,1};
bool n[11][11][11][11][11] = {0};
int a[5];
int pri[MAX];
int priLen = 0;
int maze[5][5];
bool vis[5][5];
struct ANS
{
	short ma[5][5];
}ans[1000];
int ansLen = 0;
bool operator<(const ANS& a1, const ANS& a2)
{
	for (int i = 0; i < 5; ++ i) {
		for (int j = 0; j < 5; ++ j) {
			if (a1.ma[i][j] < a2.ma[i][j]) {
				return 1;
			}
			else if (a1.ma[i][j] > a2.ma[i][j]) {
				return 0;
			}
		}
	}
	return 0;
}
#define FOR(i) for(ii[i]=0;ii[i]<2;++ii[i]){if(ii[i]==0)aa[i]=a[i];else aa[i]=10;
inline void deal(int k)
{
	int tmp = 0;
	for (int j = 4; j >= 0; -- j) {
		tmp += a[j] = k%10;
		k /= 10;
	}
	if (tmp != sum) {
		return;
	}
	int ii[5];
	int aa[5];
	FOR(0)
		FOR(1)
			FOR(2)
				FOR(3)
					FOR(4)
						n[aa[0]][aa[1]][aa[2]][aa[3]][aa[4]]=1;
					}
				}
			}
		}
	}
}
void init()
{
	scanf("%d%d",&sum,&fir);
	n[10][10][10][10][10]=1;
	for (int i = 0; i < 5; ++ i) {
		for (int j = 0; j < 5; ++ j) {
			maze[i][j] = 10;
		}
	}
	maze[0][0] = fir;
	priLen = 0;
	ansLen = 0;
	for (int i = 2; i < SQRT; ++ i) {
		if (!v[i]) {
			for (int j = i*i; j < MAX; j += i) {
				v[j] = 1;
			}
		}
	}
	for (int i = 10001; i < MAX; ++ i) {
		if (!v[i]) {
			pri[priLen++] = i;
			deal(i);
		}
	}
}
inline bool is_prime()
{
	return n[a[0]][a[1]][a[2]][a[3]][a[4]];
}
int dir[25][2] = {{0,0},{0,1},{0,2},{0,3},{0,4},{1,0},{2,0},{3,0},{4,0},{1,1},{2,2},{3,3},{4,4},{1,2},{1,3},{1,4},{3,2},{4,2},{2,3},{4,3},{4,1},{2,1},{2,4},{3,1},{3,4}};
inline bool ok()
{
	for (int i = 0; i < 5; ++ i) {
		for (int j = 0; j < 5; ++ j) {
			a[j] = maze[i][j];
		}
		if (!is_prime()) {
			return 0;
		}
	}
	for (int j = 0; j < 5; ++ j) {
		for (int i = 0; i < 5; ++ i) {
			a[i] = maze[i][j];
		}
		if (!is_prime()) {
			return 0;
		}
	}
	for (int i = 0; i < 5; ++ i) {
		a[i] = maze[i][i];
	}
	if (!is_prime()) {
		return 0;
	}
	for (int i = 4, j = 0; j < 5; -- i, ++ j) {
		a[j] = maze[i][j];
	}
	if (!is_prime()) {
		return 0;
	}
	else {
		return 1;
	}

}
void print()
{
	for (int i = 0; i < 5; ++ i) {
		for (int j = 0; j < 5; ++ j) {
			if (maze[i][j] == 10) printf(" ");
			else printf("%d",maze[i][j]);
		}
		printf("\n");
	}
	printf("# # # # # # # # #\n");
}
void dfs(int id)
{
	if (id == 25) {
		for (int i = 0; i < 5; ++ i) {
			for (int j = 0; j < 5; ++ j) {
				ans[ansLen].ma[i][j] = maze[i][j];
			}
		}
		++ ansLen;
		return;
	}
	int x=dir[id][0],y=dir[id][1];
	for (int i = 0; i < 10; ++ i) {
		maze[x][y] = i;
		if (ok()) {
			dfs(id+1);
		}
	}
	maze[x][y] = 10;
}
int main()
{
	init();
	dfs(1);
	sort(ans, ans+ansLen);
	for (int k = 0; k < ansLen; ++ k) {
		for (int i = 0; i < 5; ++ i) {
			for (int j = 0; j < 5; ++ j) {
				printf("%d",ans[k].ma[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}


