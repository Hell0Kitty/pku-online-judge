#include <cstdio>

using namespace std;

int main(){
	long long int k, n;
	while(~scanf("%lld%lld", &n, &k)){
		long long int x = 0;
		for(int i = 1; i <= n; i++)	x += k % i;
		//printf("check : %lld\n", x);
		long long int ans = 0;
		if(n > k)	 { ans = (n - k) * k; n = k; }
		long long int p;
		for(int i = 1; ; i++)	 if(k / i <= k / ( i + 1) + 2)	{ p = i; break; }
		if(n <= k / (p + 1)){
			for(int i = 1; i <= n; i++)    ans += k % i;
			printf("%lld\n", ans);
			continue;
		}
		for(int i = p; i >= 1; i--){
			int cnt = k / i - k / (i + 1);
			int t = k % (k / i) + (cnt - 1) * i;
			if(n < k / (i + 1) + 1)	break;
			if(n < k / i)    cnt = n - k / (i + 1);
			ans += cnt * (2 * t + (1 - cnt) * i) / 2;
		}
		for(int i = 1; i <= k / (1 + p); i++)	ans += k % i;
		printf("%lld\n", ans);
	}
	return 0;
}

