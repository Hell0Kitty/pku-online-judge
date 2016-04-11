#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<iomanip>
using namespace std;
map<string, int> mm;
int main(){
	string name; int cnt = 0;
	while (getline(cin, name)){
		mm[name]++;
		cnt++;
	}
	map<string, int>::iterator iter;
	for (iter = mm.begin(); iter != mm.end(); iter++)
		cout << iter->first << ' ' << fixed << setprecision(4) << (100.0*mm[iter->first])/cnt<< endl;
	return 0;
}



