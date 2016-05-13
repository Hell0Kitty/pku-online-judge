#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>

#define MAXN 2005

using namespace std;

typedef long long LL;

LL positions[MAXN];
int mark[MAXN];

int main()
{
	LL N, S, F, L;
	cin >> N;
	for(int i = 0; i < N; i++ )
		cin >> positions[i];
	cin >> S >> F >> L;

	for(int i = 0; i < N; i++ ){
		LL ii = 1;
		LL jj = positions[i];
		LL startjj_S = positions[i] - (S - 1);
		LL endjj_S = positions[i] + (S - 1); 
		LL rowStart = S - 1;
		LL colStart = 0;

		if(endjj_S < F) continue; 
		if(startjj_S > F + L - 1) continue;

		LL startjj_inbound = max(F, startjj_S);
		LL endjj_inbound = min(F + L - 1, endjj_S);
		if((startjj_inbound - startjj_S) % 2) startjj_inbound++;
		if((endjj_S - endjj_inbound) % 2) endjj_inbound--;

		if(startjj_inbound > endjj_inbound) continue;

		LL diff = startjj_inbound - startjj_S;
		LL rowStart_inbound = rowStart - diff / 2;
		LL colStart_inbound = colStart + diff / 2;
		for(LL j = startjj_inbound; j <= endjj_inbound; j += 2){
			LL value = rowStart_inbound & colStart_inbound;
			if(value == 0){
				mark[j - F] ^= 1;
			}
			rowStart_inbound--;
			colStart_inbound++;
		}
	}

	for(int i = 0; i < L; i++ ){
		if(i) cout << " ";
		cout << mark[i];
	}
	cout << endl;

	return 0;
}


