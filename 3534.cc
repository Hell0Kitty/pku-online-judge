#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< i64, i64 >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

#define mx 50090

i64 dp[mx];
i64 ds[mx];

i64 x[mx],y[mx];
vector < pii > g[mx];

struct {
 int u,v,t;
 void inp() {
 scanf("%d %d %d",&u,&v,&t);
 }
}d[200090];

pii nd(int u, i64 w) {
 return pii(w,u);
}

int main() {
	int n,m,i,j,k,u,v;
	i64 t,w;
	i64 s;
	cin>>n>>m>>s;
	n++;
	for(i=1;i<n;i++) scanf("%I64d %I64d",&x[i],&y[i]);
	for(i=0;i<m;i++) d[i].inp();
	cin>>x[0]>>y[0]>>x[n]>>y[n];
	for(i=0;i<=n;i++) ds[i]=sq(x[i]-x[0])+sq(y[i]-y[0]);
	for(i=0;i<m;i++) {
	 if(ds[d[i].u]>ds[d[i].v] || d[i].u==n) g[d[i].v].PB(pii(d[i].u,d[i].t));
	 if(ds[d[i].u]<ds[d[i].v] || d[i].v==n) g[d[i].u].PB(pii(d[i].v,d[i].t));
	}
	priority_queue < pii , vector < pii >, greater < pii > > q;
	MEM(dp,63);
	dp[0]=0;
	q.push(nd(0,0));
	while(!q.empty()) {
	 u=q.top().second;
	 t=q.top().first;
	 if(u==n) break;
	 q.pop();
	 if(u && sq(dp[u]*s)>=ds[u]) continue;
	 j=g[u].size();
	 for(i=0;i<j;i++) {
	 v=g[u][i].first;
	 w=g[u][i].second+dp[u];
	 if(dp[v]>w) {
	 dp[v]=w;
	 q.push(nd(v,w));
	 }
	 }
	}
	if(q.empty()) puts("Impossible");
	else cout<<t<<'\n';
	return 0;
}


