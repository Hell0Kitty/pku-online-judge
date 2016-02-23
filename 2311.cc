#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int M = 210;
int g[M][M];

int main () {
	memset(g, 0, sizeof(g));
	for(int i = 2; i <= 200; i++){
		for(int j = 2; j <= 200; j++){
			bool vis[M] = {};
			for(int k = 2; i - k >= 2; k++) vis[ g[k][j]^g[i-k][j] ] = 1;
			for(int k = 2; j - k >= 2; k++) vis[ g[i][k]^g[i][j-k] ] = 1;
			int cnt = 0;
			while(vis[cnt]) cnt++;
			g[i][j] = cnt;
		}
	}
	int h, w;
	while(~scanf("%d%d", &h, &w)){
		printf("%s\n", g[h][w]?"WIN" : "LOSE");
	} 
}



