#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[101], b[101];
int f[101][101] = {0};

bool enough(int T)
{
	memset(f, -1, sizeof(f));	//f[i][j] = -1，表示i个人在时间T内不可能做j个任务
	f[0][0] = 0;				//0个人自然是能做0个A类任务和0个B类任务的
	for(int i = 1; i <= n; ++i){//前i个都不做A类任务
		f[i][0] = f[i-1][0] + T / b[i];
	}
	for(int j = min(m, T/a[1]); j; --j){//第1个人选择做j个A类任务
		f[1][j] = (T - j*a[1]) / b[1];
	}
	for(int i = 2; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			for(int k = min(T/a[i], j); k > -1; --k){
				//第i个人做k个A类任务，则需要前i-1个人做j-k个A类任务
				if(f[i-1][j-k] != -1) f[i][j] = max(f[i][j], f[i-1][j-k] + (T-k*a[i]) / b[i]);
			}
		}
	}
	return f[n][m] >= m;
}

int main()
{
	int test, ans;
	for(scanf("%d", &test); test--; ){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) scanf("%d%d", a + i, b + i);
		int l = 0, r = m * (*max_element(a+1, a+n+1) + *max_element(b+1, b+n+1));
		while(l <= r){
			int m = (l+r) >> 1;
			if(enough(m)){
				ans = m;
				r = m-1;
			}
			else l = m+1;
		}
		printf("%d\n", ans);
	}
	return 0;
}



