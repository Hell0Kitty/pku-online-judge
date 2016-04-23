#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

set<string> wait, pau, run;
pair<string, int> psi[100003];
const string ans[]={
		"finished",
		"waiting",
		"paused",
		"downloading"
};

int main() {

	int ds, n, m;
	string op, key;
	cin >> ds;
	while (ds--) {
		wait.clear();
		pau.clear();
		run.clear();

		int sz=0;
		cin >> n >> m;
		bool asc=true;
		while (m--) {
			cin >> op >> key;

			if(op=="New") {
				wait.insert(key);
			} else if(op=="Pause") {
				pau.insert(key);
				if(run.find(key)!=run.end()) {
					run.erase(key);
				} else if(wait.find(key)!=wait.end()) {
					wait.erase(key);
				}
			} else if(op=="Sort") {
				asc=(key=="asc");
			} else if(op=="Continue") {
				if(pau.find(key)!=pau.end()) {
					pau.erase(key);
					wait.insert(key);
				}
			} else if(op=="Finish") {
				run.erase(key);
				psi[sz++]=make_pair(key, 0);
			}

			while(run.size()<n && !wait.empty()) {
				if(asc)
					key=*wait.begin();
				else
					key=*wait.rbegin();
				wait.erase(key);
				run.insert(key);
			}
		}

		for(set<string>::iterator sit=wait.begin(); sit!=wait.end(); ++sit) {
			psi[sz++]=make_pair(*sit, 1);
		}

		for(set<string>::iterator sit=pau.begin(); sit!=pau.end(); ++sit) {
			psi[sz++]=make_pair(*sit, 2);
		}

		for(set<string>::iterator sit=run.begin(); sit!=run.end(); ++sit) {
			psi[sz++]=make_pair(*sit, 3);
		}

		sort(psi, psi+sz);

		if(asc) {
			for(int i=0; i<sz; ++i) {
				cout<<psi[i].first<<" "<<ans[ psi[i].second ]<<endl;
			}
		} else {
			for(int i=sz-1; i>=0; --i) {
				cout<<psi[i].first<<" "<<ans[ psi[i].second ]<<endl;
			}
		}
		cout<<endl;
	}

	return 0;
}


