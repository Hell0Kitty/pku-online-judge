#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=1440;
const int NIG=360;

struct Street {
	string name;
	int len, min;
	Street(){}
	Street(string n, int l, int m):name(n), len(l), min(m){}
};

int totlen, totmin, fare;

int cost_drive(int len, int cc) {
	int ret=0, c1=cc*100, c2=cc*25, c3=cc*10;
	while (len) {
		if (totlen>=30) {
			totlen+=len; ret+=len*c3; len=0;
		}
		else if (totlen>=10) {
			int tmp=min(30-totlen, len);
			totlen+=tmp; len-=tmp; ret+=tmp*c2;
		}
		else {
			int tmp=min(10-totlen, len);
			totlen+=tmp; len-=tmp; ret+=tmp*c1;
		}
	}
	return ret;
}

void calc_cost(int m, int cm, int &curt, int &need, int tag) {
	int len=(tag==1)?((cm-1)/m+1):(cm/m);
	if (tag<2) fare+=cost_drive(len, 12);
	else fare+=cost_drive(len, 10);
	need-=len*m; curt+=len*m;
	curt%=MAX;
}

int solve(vector<Street> &S, string src, string des, int curt) {
	bool flag=false;
	fare=0, totlen=0, totmin=0;
	for (int i=0; i<(int)S.size(); ++i) {
		if (S[i].name==src) flag=true;
		if (flag) {
			int need=S[i].len*S[i].min, m=S[i].min;
			totmin+=need;
			while (need) {
				if (curt<NIG) {
					int tmp=NIG-curt;
					if (tmp>=need) calc_cost(m, need, curt, need, 0);
					else calc_cost(m, tmp, curt, need, 1);
				}
				else {
					int tmp=MAX-curt;
					if (tmp>=need) calc_cost(m, need, curt, need, 2);
					else {
						calc_cost(m, tmp, curt, need, 3);
						curt=(curt+m)%MAX; need-=m; fare+=cost_drive(1, 12);
					}
				}
			}
		}
		if (S[i].name==des) break;
	}
	assert(fare%10==0);
	if (totmin>2*totlen) fare=fare*11/10;
	return fare;
}

int main() {
	vector<Street> S;
	Street t;
	while (cin >> t.name) {
		if (t.name=="--") break;
		S.clear();
		do {
			cin >> t.len >> t.min;
			S.push_back(t);
			cin >> t.name;
		}while (t.name!="$");
		string src, des;
		int h, m;
		cin >> src >> des;
		scanf("%d:%d", &h, &m);
		printf("%d\n", solve(S, src, des, h*60+m));
		cin >> t.name;
	}
	return 0;
}



