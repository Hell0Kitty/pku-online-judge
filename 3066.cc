#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define  esp 1e-6
#define  pi acos(-1.0)
#define  inf 0x0f0f0f0f
#define  pb push_back
#define  lson l, m, rt<<1
#define  rson m+1, r, rt<<1|1
#define  mp(a, b) make_pair((a), (b))
#define  in  freopen("solve_in.txt", "r", stdin);
#define  out freopen("solve_out.txt", "w", stdout);
#define  bug puts("********))))))");
#define  inout in out
#define  stop  system("pause");
#define  PRD(a) printf("%d\n",(a))
#define  PRU(a) printf("%u\n", (a))
#define  PRID(a) printf("%I64d\n", (a))
#define  PRIU(a) printf("%I64u\n", (a))

#define  PRLU(a) printf("%llu\n", (a))
#define  PRLD(a) printf("%lld\n", (a))

#define  SET(a, v) memset(a, (v), sizeof(a))
#define  READ(a, n) {REP(i, n) cin>>(a)[i];}
#define  REP(i, n) for(int i = 0; i < (n); i++)
#define  Rep(i, base, n) for(int i = base; i < n; i++)
#define  REPS(s, i) for(int i = 0; s[i]; i++)
#define  pf(x) ((x)*(x))
#define  Log(a, b) (log((double)b)/log((double)a))
#define Srand() srand((int)time(0))
#define random(number) (rand()%number)
#define random_range(a, b) (int)(((double)rand()/RAND_MAX)*(b-a) + a)

using namespace std;
typedef long long  LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
typedef vector<pii> VII;
typedef vector<pii, int> VIII;
typedef VI:: iterator IT;
typedef map<string, int> Mps;
typedef map<int, int> Mpi;
typedef map<int, pii> Mpii;
typedef map<pii, int> Mpiii;

int main(){

    int m, p, a, b;
    while(scanf("%d%d%d%d", &m, &p, &a, &b) == 4){
        double ans = 0;
        double down = -1.0/sqrt((double)a), up = sqrt((double)a);
        double sum = b*up;
        for(int i = 1; i < m; i++)
             if(sum - up < down)
               ans += pow(down, p), sum -= down;
             else
                ans += pow(up, p), sum -= up;
        ans += pow(sum, p);
        printf("%.0f\n", ans);
    }
    return 0;
}



