#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int a[110][110], b[110][110], c[110];
int N, M, C, Q, x, y, z;
char op[2];
bool inMap(int x, int y){
	return x > 0 && x <= N && y > 0 && y <= M;
}
bool check(int x, int y, int c){
	if (!inMap(x + c, y) || a[x + c][y] != a[x][y]) return 0;
	if (!inMap(x, y + c) || a[x][y + c] != a[x][y]) return 0;
	if (!inMap(x - c, y) || a[x - c][y] != a[x][y]) return 0;
	if (!inMap(x, y - c) || a[x][y - c] != a[x][y]) return 0;
	return 1;
}
int add(int x, int y){
	int ans = 0;
	for (int i = 1; i <= 210; i++)
		if (check(x, y, i)) ans += 1;
		else break;
	return ans;
}
void change(int x, int y, int cc){
	if (a[x][y] == cc) return;
	c[a[x][y]] -= b[x][y];
	a[x][y] = cc;
	b[x][y] = add(x, y);
	c[a[x][y]] += b[x][y];
	for (int i = 1; i <= N; i++){
		if (i == x) continue;
		c[a[i][y]] -= b[i][y];
		b[i][y] = add(i, y);
		c[a[i][y]] += b[i][y];
	}
	for (int i = 1; i <= M; i++){
		if (i == y) continue;
		c[a[x][i]] -= b[x][i];
		b[x][i] = add(x, i);
		c[a[x][i]] += b[x][i];
	}
}
void init(){
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++){
			b[i][j] = add(i, j);
			c[a[i][j]] += b[i][j];
		}
}
void solve(){
	memset(c, 0, sizeof(c));
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &a[i][j]);
	init();
	while(Q--){
		scanf("%s", op);
		if (op[0] == 'C'){
			scanf("%d%d%d", &x, &y, &z);
			change(x, y, z);
		}else{
			scanf("%d", &x);
			printf("%d\n", c[x]);
		}
	}
}
int main(){
	while(scanf("%d%d%d%d", &N, &M, &C, &Q) == 4) solve();
	return 0;
}



