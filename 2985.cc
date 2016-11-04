#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 900010;

int N,M,num;
int fa[MAXN],sz[MAXN];

struct Treap{
	int root,tcnt;
	int key[MAXN],pro[MAXN],cnt[MAXN],sz[MAXN],son[MAXN][2];
	void clear(){
		root = 0;
		tcnt = 0;
		pro[0] = INF;
		sz[0] = 0;
	}
	void Update(int x){
		sz[x] = cnt[x] + sz[son[x][0]] + sz[son[x][1]];
	}
	void Rotate(int &x,int t){
		int y = son[x][t];
		son[x][t] = son[y][1 - t];
		son[y][1 - t] = x;
		Update(x);
		Update(y);
		x = y;
	}
	void _Insert(int &x,int k){
		if(x){
			if(key[x] == k) ++cnt[x];
			else{
				int t = k > key[x];
				_Insert(son[x][t],k);
				if(pro[son[x][t]] < pro[x]) Rotate(x,t);
			}
		}
		else{
			x = ++tcnt;
			key[x] = k;
			cnt[x] = 1;
			pro[x] = rand(); //闅忔満鍖栦紭鍏堢骇
			son[x][0] = son[x][1] = 0;
		}
		Update(x);
	}
	void _Erase(int &x,int k){
		if(key[x] == k){
			if(cnt[x] > 1) cnt[x]--;
			else{
				if(son[x][0] == 0 && son[x][1] == 0){
					x = 0;
					return;
				}
				int t = pro[son[x][0]] > pro[son[x][1]];
				//娌℃湁宸﹀効瀛恡 = 1 , 娌℃湁鍙冲効瀛恡 = 0
				Rotate(x,t);
				_Erase(x,k);
			}
		}
		else	_Erase(son[x][k > key[x]],k);
		Update(x);
	}
	int _Get_kth(int &x,int k){
		if(k <= sz[son[x][0]])
			return _Get_kth(son[x][0],k);
		k -= sz[son[x][0]] + cnt[x];
		if(k <= 0) return key[x];
		return _Get_kth(son[x][1],k);
	}
	void Insert(int k){
		_Insert(root,k);
	}
	void Erase(int k){
		_Erase(root,k);
	}
	int Get_kth(int k){
		return _Get_kth(root,k);
	}
}tp;

int Find(int x){
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Union(int a,int b){
	int x = Find(a),y = Find(b);
	if(x != y){
		tp.Erase(sz[x]);
		tp.Erase(sz[y]);
		fa[x] = y;
		sz[y] += sz[x];
		tp.Insert(sz[y]);
		num--;
	}
}

int main(){
	int a,b,c,k;
	while(scanf("%d%d",&N,&M) != EOF){
		tp.clear();
		REP(i,N) fa[i] = i,sz[i] = 1,tp.Insert(1);
		num = N;
		while(M--){
			scanf("%d",&c);
			if(c == 0){
				scanf("%d%d",&a,&b);
				Union(a,b);
			}
			else{
				scanf("%d",&k);
				k = num + 1 - k;
				printf("%d\n",tp.Get_kth(k));
			}
		}
	}
	return 0;
}




