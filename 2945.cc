#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long LL;
#define clr(x, y) memset(x, y, sizeof(x))
#define disc(x, y) memcpy(x, y, sizeof(y))
#define Dc(x) fixed << setprecision(x)
#define sf scanf
#define pf printf
const double pi = 4.0 * atan(1.0);
const double eps = 1e-8;
const int INF = 1<<29;
const int maxn = 20005;

typedef struct Node {
    int nxt[26], sum;
}Node;
Node tree[maxn * 16];
int ans[maxn];
int N, M, top;

void init() {
    clr(tree, 0), clr(ans, 0);
	top = 0;
}
void update(char str[]) {
    int node = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
	    int tmp = str[i] - 'A';
		if (!tree[node].nxt[tmp]) {
		    tree[node].nxt[tmp] = ++top;
			node = top;
		}else {
		    node = tree[node].nxt[tmp];
		}
	}
	ans[tree[node].sum++]--;
	ans[tree[node].sum]++;
}
int main() {
	while (~sf("%d%d",&N,&M) && N+M) {
	    init();char name[25];
		for (int i = 1; i <= N; i++) {
		    sf("%s",&name);
			update(name);
		}
		for (int i = 1; i <= N; i++) {
		    pf("%d\n",ans[i]);
		}
	}
    return 0;
}



