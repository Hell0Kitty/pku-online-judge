#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int n;
string a[10], b[10], s, t;

bool sub(string& p, const string& a, const string& b)
{
	size_t plen = p.size(), alen = a.size(), blen = b.size(), i = p.find(a, 0);
	if(i == string::npos) return false;

	for(; i != string::npos; i = p.find(a, i+blen)){
		if(plen - alen + blen > t.size()) return false;
		p.replace(i, alen, b);
	}
	return true;
}
int bfs()
{
	if(s == t) return 0;

	queue<string> Q;
	set<string> R;

	Q.push(s);
	R.insert(s);
	int level = 0;
	while(!Q.empty()){
		++level;
		for(int cnt = Q.size(); cnt; --cnt){
			for(int i = 0; i < n; ++i){
				string p = Q.front();
				if(!sub(p, a[i], b[i]) || R.count(p)) continue;
				if(p == t) return level;
				Q.push(p);
				R.insert(p);
			}
			Q.pop();
		}
	}
	return -1;
}

int main()
{
	while(cin >> n, n){
		for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
		cin >> s >> t;
		cout << bfs() << "\n";
	}
	return 0;
}



