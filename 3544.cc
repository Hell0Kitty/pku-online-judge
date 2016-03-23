#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long LL;
const int N = 1010;
struct pig{
	int id;
	LL weight;
}pp[N];
struct village{
	int id;
	LL price;
}vv[N];
LL dis[N],value[N];
bool cmp1(pig a,pig b){
	return a.weight > b.weight;
}
bool cmp2(village a,village b){
	return a.price > b.price;
}
int main(){
	int n;
	LL t;
	while(scanf("%d%lld",&n,&t) != EOF){
		for(int i = 0; i < n; ++i){
		  scanf("%lld",&pp[i].weight);
		  pp[i].id = i + 1;
		}
		sort(pp,pp + n,cmp1);
		for(int i = 0; i < n; ++i){
		  scanf("%lld",&dis[i]);
		}
		for(int i = 0; i < n; ++i){
		  scanf("%lld",&value[i]);
		  vv[i].price = value[i] - dis[i] * t;
		  vv[i].id = i + 1;
		}
		sort(vv,vv+n,cmp2);
		int ans[N];
		for(int i = 0; i < n; ++i){
		  ans[vv[i].id] = pp[i].id;
		}
		for(int i = 1; i < n; ++i)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}



