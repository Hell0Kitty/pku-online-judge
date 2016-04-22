#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
vector<int> ch[1000000];
map<string, int> pp;
vector<string> rev;
int tot;
char str[1000000];

int get(string & x){
	if (pp.find(x) == pp.end()) {
		pp[x]=tot;
		rev.pb(x);
		ch[tot].clear();
		tot++;
		return tot-1;
	}
	return pp[x];
}
struct nn {
	nn * l, * r;
	int x;
};
nn* iinsert(int a, nn* x, nn* y){
	nn * tem = new nn;
	tem->x = a;
	tem->l = x; tem->r = y;
	x->r = tem; y->l = tem;
	return tem;
}

int main() {
	int w,L,n,l,i;
	scanf("%d%d%d", &w, &L, &n);
	gets(str);
	tot=0;
	string xxxxxx = "\n";
	get(xxxxxx);

	for (i=0; i<n; i++) {
		gets(str);
		string s(str), sub;
		istringstream iss(s);
		iss >> sub;

		int a = get(sub);
		while (iss >> sub) {
		 ch[a].pb(get(sub));
		}
	}
	l = 0;
	nn * head, * end, * now;
	nn tem1, tem2;

	head = & tem1;
	end = & tem2;
	now = head;

	while (gets(str)) {
		string s(str), sub;
		istringstream iss(s);

		while (iss >> sub) {
		 l += sub.length();
		 now = iinsert(get(sub), now, end);
		}
		now = iinsert(get(xxxxxx), now, end);
	}	
	bool flag = true;
	while (flag && l<L) {
		flag = false;
		nn * xxx;
		for (now = head->r; now != end; now = xxx) {
			xxx = now->r;
			int a = now->x;
			if (ch[a].size() > 0) {
				nn* tht = now->r;
				now = now->l;
				l -= rev[now->r->x].length();
				//delete now->r;
				now->r = tht;

				for (i=0; i<ch[a].size(); i++) {
					flag = true;
					now = iinsert(ch[a][i], now, xxx);
					l += rev[ch[a][i]].length();
				}
			}
		}
	}
	if (flag == false) {
		puts("No result");
		return 0;
	}
	string ans = "";
	int ww = 0;

	for (now = head->r; now != end; now = now->r) {
		if (now->x == 0) {
			ans[ans.length()-1] = '\n';
			ww=0;
			continue;
		}
		if (rev[now->x].length() + ww > w){
			ans[ans.length()-1] = '\n';
			ww = rev[now->x].length() + 1;
			ans += rev[now->x];
			ans += " ";
		}else {
			ww += rev[now->x].length() + 1;
			ans += rev[now->x];
			ans += " ";
		}
	}
	cout<<ans;
}


