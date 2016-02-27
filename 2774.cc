#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
#define ULL unsigned long long
#define LL long long
#define INF 1LL << 60
#define maxn 200200
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

char s[maxn];
int wa[maxn], wb[maxn], wv[maxn], ws[maxn], rank[maxn], height[maxn], sa[maxn], r[maxn];

inline bool cmp(int rr[], int a, int b, int l) {
	return rr[a] == rr[b] && rr[a+l] == rr[b+l];
}

void da(int n, int m = 128) {
	int *x = wa, *y = wb, *t;
	rep(i,m) ws[i] = 0;
	rep(i,n) ++ws[x[i]=r[i]];
	for(int i = 1; i < m; ++i) ws[i] += ws[i-1];
	for(int i = n-1; i >= 0; --i) sa[--ws[x[i]]] = i;
	for(int j = 1, p = 1; p < n; j <<= 1, m = p) {
		p = 0;
		for(int i = n-j; i < n; ++i) y[p++] = i;
		rep(i,n) if(sa[i] >= j) y[p++] = sa[i] - j;
		rep(i,n) wv[i] = x[y[i]];
		rep(i,m) ws[i] = 0;
		rep(i,n) ++ws[wv[i]];
		for(int i = 1; i < m; ++i) ws[i] += ws[i-1];
		for(int i = n-1; i >= 0; --i) sa[--ws[wv[i]]] = y[i];
		t = x; x = y; y = t; x[sa[0]] = 0; p = 1;
		for(int i = 1; i < n; ++i)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
	}
}

void cal(int n) {
	Rep(i,n) rank[sa[i]] = i;
	for(int i = 0, k = 0; i < n; height[rank[i++]] = k) {
		if(k) --k;
		for(int j = sa[rank[i]-1]; r[i+k] == r[j+k]; ++k);
	}
}

int main()
{
	int n;
	scanf("%s",s);
	n = strlen(s);
	s[n] = 1;
	scanf("%s",s+n+1);
	int len = n + strlen(s+n);
	rep(i,len) r[i] = s[i];
	r[len] = 0;
	da(len+1);
	cal(len);
	int ans = 0;
	Rep(i, len)
		if(height[i] > ans && (sa[i-1] < n && sa[i] > n || sa[i-1] > n && sa[i] < n))
			ans = height[i];
	printf("%d\n", ans);
	return 0;
}



