#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define VEC(l) (l.b-l.a)
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

const int N = 1024;

const int di[4] = {-1,1,0,0};
const int dj[4] = {0,0,-1,1};
const char* ds[4] = {"dolu", "nahoru", "doprava", "doleva"};

int r, c;
int oi, oj;
int a[N][N];

bool in_bounds(int i, int j) {
  return 0<=i&&i<r && 0<=j&&j<c;
}

void mov(int num) {
  int dir;
  for(dir = 0; dir < 4; ++dir) {
    int ni = oi+di[dir];
    int nj = oj+dj[dir];
    if(in_bounds(ni, nj) && a[ni][nj]==num) {
      printf("Kamen %d presunut %s.\n", num, ds[dir]);
      swap(a[oi][oj], a[ni][nj]);
      oi = ni;
      oj = nj;
      break;
    }
  }
  if(dir == 4) printf("Neplatny tah kamenem %d.\n", num);
}

void print_a() {
  forl(i, 0, r)
    forl(j, 0, c)
      printf("%d%c", a[i][j], j<c-1?' ':'\n');
}

int main() {
  repc(rdi()) {
    scanf("%d %d", &r, &c);
    forl(i, 0, r)
      forl(j, 0, c) {
        scanf("%d", a[i]+j);
        if(a[i][j] == 0) oi = i, oj = j;
      }
    static int cas;
    printf("Skladacka cislo %d:\n", ++cas);
    for(int num; scanf("%d", &num)==1 && num; mov(num)) {}
    print_a();
    puts("");
  }
  return 0;
}



