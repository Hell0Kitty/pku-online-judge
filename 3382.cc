#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;

#define MAXN 5010
#define MOD 1000000000000000001LL

map<string, int> mp;

char str[MAXN], temp[MAXN];
bool can[MAXN][13];
LL dp[1010][13][13];
int pre1[1010][13][13], pre2[1010][13][13];
bool state[1010][13][13];

int part[30][30], len[30];
int arr[1010][30];

void solve(int i, int j, int k) {
	if(pre1[i][j][k] != 0) {
		if(k == 0) {
			int nj = pre2[i][j][k];
			solve(pre1[i][j][k], nj, len[nj] - 1);
		}
		else solve(pre1[i][j][k], j, k - 1);
		putchar(' ');
	}
	for(int ii = pre1[i][j][k] + 1; ii <= i; ++ii) putchar(str[ii]);
	if(k == len[j] - 1) putchar('.');
}

int main() {
	int n, m, k, maxi = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%s", str);
		string s(str);
		int l = strlen(str);
		maxi = max(l, maxi);
		mp[s] = i;
		int cnt;
		scanf("%d", &cnt);
		for(int j = 0; j < cnt; ++j) {
			int num;
			scanf("%d", &num);
			can[i][num - 1] = true;
		}
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d", len + i);
		for(int j = 0; j < len[i]; ++j) {
			scanf("%d", &part[i][j]);
			part[i][j]--;
		}
	}
	scanf("%s", str + 1);
	int l = strlen(str + 1);

	memset(arr, -1, sizeof(arr));
	for(int i = 1; i <= l; ++i)
		for(int j = i; j <= l && j - i + 1 <= maxi; ++j) {
			int pos = 0;
			for(int k = i; k <= j; ++k) temp[pos++] = str[k];
			temp[pos] = '\0';
			string t(temp);
			map<string, int>::iterator it = mp.find(t);
			if(it != mp.end()) arr[j][j - i + 1] = it->second;
		}

	for(int i = 1; i <= maxi && i <= l; ++i) {
		int v = arr[i][i];
		if(v != -1) {
			for(int j = 0; j < m; ++j)
				if(can[v][part[j][0]]) {
					dp[i][j][0]++;
					pre1[i][j][0] = 0;
					pre2[i][j][0] = -1;
				}
		}
	}
	for(int i = 1; i <= l; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < len[j]; ++k) {
				if(dp[i][j][k] || state[i][j][k]) {
					for(int h = i + 1; h <= l && h - i <= maxi; ++h) {
						int v = arr[h][h - i];
						if(v == -1) continue;
						if(k != len[j] - 1) {
							if(can[v][part[j][k + 1]]) {
								dp[h][j][k + 1] += dp[i][j][k];
								pre1[h][j][k + 1] = i;
								pre2[h][j][k + 1] = j;
								if(dp[h][j][k + 1] >= MOD) {
									state[h][j][k + 1] = true;
									dp[h][j][k + 1] -= MOD;
								}
								state[h][j][k + 1] |= state[i][j][k];
							}
						}
						else {
							for(int x = 0; x < m; ++x)
								if(can[v][part[x][0]]) {
									dp[h][x][0] += dp[i][j][k];
									pre1[h][x][0] = i;
									pre2[h][x][0] = j;
									if(dp[h][x][0] >= MOD) {
										dp[h][x][0] -= MOD;
										state[h][x][0] = true;
									}
									state[h][x][0] |= state[i][j][k];
								}
						}
					}
				}
			}
	LL res = 0;
	int pos;
	bool flag = false;
	for(int i = 0; i < m; ++i) {
		res += dp[l][i][len[i] - 1];
		if(res >= MOD) {
			flag = true;
			res -= MOD;
		}
		flag |= state[l][i][len[i] - 1];
		if(dp[l][i][len[i] - 1] != 0 || state[l][i][len[i] - 1]) pos = i;
	}
	if(flag) puts("TOO MANY");
	else printf("%lld\n", res);
	if(res != 0 || flag)
		solve(l, pos, len[pos] - 1);
	return 0;
}


