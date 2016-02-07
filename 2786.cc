#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define maxn 800005
typedef pair<int, int> par;
par data[maxn];
struct node{
	int idx;
	friend bool operator < (node a, node b){
		return data[a.idx].first < data[b.idx].first;
	}
	node (int a){
		idx = a;
	}
	node(){}
};
int ans, n;
priority_queue<node> que;
bool cmp(par a, par b){
	return a.second  < b.second;
}
void solve(){
	int i;
	int sum;
	node now;
	while (!que.empty()){
		que.pop();
	}
	sum = 0;
	for (i = 1; i <= n; i ++){
		if (sum + data[i].first <= data[i].second){
			ans ++;
			sum += data[i].first;
			que.push(node(i));
		}
		else {
			if (que.empty()){
				continue;
			}
			now = que.top();
			que.pop();
			if (data[i].first < data[now.idx].first){
				que.push(node(i));
				sum = sum - data[now.idx].first + data[i].first;
			}
			else {
				que.push(now);
			}
		}
	}
}
int main(){
	int i, j;
	int textnum;
	while (scanf("%d", &n) == 1){
		for (i = 1; i <= n; i ++){
			scanf("%d%d", &data[i].first, &data[i].second);
		}
		sort(data + 1, data + n + 1, cmp);
		ans = 0;
		solve();
		printf("%d\n", ans);
	}
	return 0;
}



