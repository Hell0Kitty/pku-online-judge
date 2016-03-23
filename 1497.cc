#include<iostream>
#include<sstream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define pb push_back
#define all(c) c.begin(), c.end()
#define start(side   ) s[id[side]][p[side]    ]
#define end(side, len) s[id[side]][p[side]+len]
// 13C
#define DBG 1
#define sz(c) ((int)(c).size())
#define    forl(i, a, b) for(int i = (a); i <  (b); ++i)
#define   forle(i, a, b) for(int i = (a); i <= (b); ++i)
#define    forg(i, a, b) for(int i = (a); i >  (b); --i)
#define   forge(i, a, b) for(int i = (a); i >= (b); --i)
#define   forlc(i, a, b) for(int i##_b = (b), i = (a); i <  i##_b; ++i)
#define  forlec(i, a, b) for(int i##_b = (b), i = (a); i <= i##_b; ++i)
#define   forgc(i, a, b) for(int i##_b = (b), i = (a); i >  i##_b; --i)
#define  forgec(i, a, b) for(int i##_b = (b), i = (a); i >= i##_b; --i)
#define  forall(i, v   )  forl(i, 0, sz(v))
#define forallc(i, v   ) forlc(i, 0, sz(v))
#define  forlla(i, v   ) forge(i, sz(v)-1, 0)
#define   forls(i, n, a, b) for(int i = a; i != b; i = n[i])
#define rep(n)  for(int               repp = 0; repp <    (n); ++repp)
#define repc(n) for(int repp_b = (n), repp = 0; repp < repp_b; ++repp)
#define rst(a, v) memset(a, v, sizeof a)
#define cpy(a, b) memcpy(a, b, sizeof a)
#define rstn(a, v, n) memset(a, v, (n)*sizeof((a)[0]))
#define cpyn(a, b, n) memcpy(a, b, (n)*sizeof((a)[0]))
#define ast(b) if(DBG && !(b)) { printf("%d!!|\n", __LINE__); while(1) getchar(); }
#define dout DBG && cout << __LINE__ << ">>| "
#define pr(x) #x"=" << (x) << " | "
#define mk(x) DBG && cout << __LINE__ << "**| "#x << endl
#define pra(arr, a, b) if(DBG) { \
    dout<<#arr"[] | "; \
    forlec(i, a, b) cout<<"["<<i<<"]="<<arr[i]<<" |"<<((i-(a)+1)%13?" ":"\n"); \
    if(((b)-(a)+1)%13) puts(""); \
  }
#define rd(type, x) type x; cin >> x
inline int     rdi() { int d; scanf("%d", &d); return d; }
inline char    rdc() { scanf(" "); return getchar(); }
inline string  rds() { rd(string, s); return s; }
inline double rddb() { double d; scanf("%lf", &d); return d; }
template<class T> inline bool updateMin(T& a, T b) { return a>b? a=b, true: false; }
template<class T> inline bool updateMax(T& a, T b) { return a<b? a=b, true: false; }

const int N = 12;

enum {U, L, D, R};

char s[4][N+1];
int id[4], p[4];

int main() {
  while(scanf("%s", s[0])==1 && s[0][0]!='Q') {
    forl(i, 1, 4) scanf("%s", s[i]);
    forl(i, 0, 4) id[i] = i;
    int area = 0;
    do {
      for(p[U] = 1; p[U] < N-1; ++p[U])
      for(p[L] = 1; p[L] < N-1; ++p[L]) if(start(U) == start(L))
        for(int l1 = 2; p[U]+l1 < N-1; ++l1) 
        for(int l2 = 2; p[L]+l2 < N-1; ++l2)
          for(p[D] = 1; p[D]+l1 < N-1; ++p[D]) if(start(D) == end(L, l2))
          for(p[R] = 1; p[R]+l2 < N-1; ++p[R])
            if(start(R)==end(U, l1) && end(R, l2)==end(D, l1))
              updateMax(area, (l1-1)*(l2-1));
    } while(next_permutation(id, id+4));
    printf("%d\n", area);
  }
  return 0;
}



