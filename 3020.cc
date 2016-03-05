#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int N, M;
int g[45], dp[45][1 << 10];
#define B2(m,i) (((m)>>2*(i))&3)
#define B(m,i) (((m)>>(i))&1)

VI mscost[1 << 10], msnext[1 << 10];
int main(){
	REP(m, 0, 1 << (2 * 10)){
		bool ok = 1;
		REP(j, 0, 10) if (B2(m, j) == 3) { ok = 0; break; }
		if (!ok) continue;
		int cover = 0, next = 0, cost = 0;
		REP(j, 0, 10){
			int b = B2(m, j);
			if (b == 2) {
				cover += 1 << j;
				next += 1 << j;
			}
			else if (b == 1){
				cover += (1 << j) + (1 << j + 1);
			}
			if (b) cost++;
		}
		REP(gm, 0, 1 << 10){
			if ((gm & cover) != gm) continue; // not cover
			bool ok = 1;
			REP(j, 0, 10){
				int b = B2(m, j);
				if (b && !B(gm, j)) ok = 0;	// cover empty
				if (b == 1 && !B(gm, j + 1)) ok = 0;	// horizontal cover empty
				if (!ok) break;
			}
			if (!ok) continue;
			msnext[gm].push_back(next);
			mscost[gm].push_back(cost);
		}
	}

	int T;
	cin >> T;
	while (T--){
		scanf("%d%d", &N, &M);
		REP(i, 1, N + 1){
			char buf[11];
			scanf("%s", buf);
			g[i] = 0;
			REP(j, 0, M) if (buf[j] == '*') g[i] += 1 << j;
		}

		REP(i, 0, 1 << M) dp[0][i] = INF;
		dp[0][0] = 0;
		REP(i, 1, N + 1){
			REP(m, 0, 1 << M) dp[i][m] = INF;
			REP(m, 0, 1 << M){
				if (dp[i - 1][m] == INF) continue;
				int gm = g[i] ^ (g[i] & m);
				int sz = msnext[gm].size();
				REP(msi, 0, sz){
					int m2 = msnext[gm][msi], cost = mscost[gm][msi];
					dp[i][m2] = min(dp[i][m2], dp[i - 1][m] + cost);
				}
			}
		}
		int ans = INF;
		REP(m, 0, 1 << M){
			if (dp[N][m] != INF) ans = min(ans, dp[N][m]);
		}
		printf("%d\n", ans);

	}
	return 0;
}



