#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include<math.h>
using namespace std;

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int maxn= 1000000+4000;
int sum[maxn<<2];
void up(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt)
{
	if (l == r){
		sum[rt] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	up(rt);
}

void update(int key, int add, int l, int r, int rt)
{
	if (l == r){
		sum[rt] = add; return;
	}
	int mid = (l + r) >> 1;
	if (key <= mid) update(key, add, lson);
	else update(key, add, rson);
	up(rt);
}

int ask(int key, int l, int r, int rt)
{
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (key <= sum[rt << 1]) return ask(key, lson);
	else return ask(key-sum[rt<<1], rson);
}

char str[maxn];
char str1[maxn];
char cha[4000];
int pos[4000],spos[4000],cnt[4000];
char gg[4000][20];
int main()
{
    int t;
    memset(str1,0,sizeof(str1));
	scanf("%s", str);
	int len = strlen(str);
	scanf("%d", &t);
	cnt[0]=len;
	for (int i = 1; i <=t; i++){
		scanf("%s", gg[i]);
		getchar();
		if (gg[i][0] == 'I'){
			scanf("%c %d", &cha[i], &pos[i]);
			cnt[i] = cnt[i - 1] + 1;
		}
		else{
			scanf("%d", &pos[i]);
			cnt[i] = cnt[i - 1];
		}
	}
	int n = cnt[t];
	build(1,n,1);
	for (int i = t; i >=1 ; i--){
        pos[i]=min(pos[i],cnt[i]);
		if (gg[i][0] == 'I'){
			int kk = ask(pos[i], 1, n, 1);
			spos[i]= kk;
			update(kk, 0, 1, n, 1);
			str1[kk] = cha[i];
			//printf("%d %d %c\n",pos[i],kk,str1[kk]);
		}
	}
	int ret = 0; int ret1 = 1;
	while (ret < len){
		if (str1[ret1] == 0){
			str1[ret1] = str[ret++];
		}
		ret1++;
	}
	for (int i = 1; i <= t; i++){
        int kk=ask(pos[i],1,n,1);
		if (gg[i][0] == 'I'){
			update(spos[i], 1, 1, n, 1);
		}
		else{
			printf("%c\n", str1[kk]);
		}
	}
	return 0;
}


