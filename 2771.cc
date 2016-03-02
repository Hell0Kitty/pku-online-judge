#include"cstdio"
#include"string"
#include"iostream"
#include"algorithm"
using namespace std;
#define FOR(a,b,c) for(int a=b;a<c;a++)
const int N = 510;

int H[N]; char S[N]; string X[N],Y[N];
bool a[N][N],V[N]; int L[N];
int n;
bool can(int k) {
	FOR(i, 1, n + 1) if(!V[i] && a[k][i] && !L[i]) { L[i] = k; return 1; }
	FOR(i, 1, n + 1) if(!V[i] && a[k][i] &&  L[i]) {
		V[i] = 1; if(can(L[i])) { L[i] = k; return 1; } }
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--) {
		cin>>n;
		FOR(i, 1, n + 1) cin>>H[i]>>S[i]>>X[i]>>Y[i];
		FOR(i, 1, n + 1) FOR(j, i, n + 1) 
			a[j][i] = a[i][j] = abs(H[i]-H[j])<=40 && S[i]!=S[j] && X[i]==X[j] && Y[i]!=Y[j];
		int ans = n;
		FOR(i, 1, n + 1) L[i] = 0;
		FOR(i, 1, n + 1) if(S[i] == 'M') {
			FOR(j, 1, n + 1) V[j] = 0;
			ans -= can(i); }
		cout<<ans<<endl; }
	return 0;
}



