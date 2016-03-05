#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <ctime>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x, y) memset(x, y, sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x) * (x))
#define MP(x, y) make_pair(x, y)
#define EPS 1e-20

#define FOR0(i, x) for (i = 0; i < x; i++)
#define FOR1(i, x) for (i = 1; i <= x; i++)
#define FOR(i, a, b) for (i = a; i <= b; i++)
#define FORL0(i, a) for (i = a; i >= 0; i--)
#define FORL1(i, a) for (i = a; i >= 1; i--)
#define FORL(i, a, b) for (i = a; i >= b; i--)

#define rush() \
  int CC;      \
  for (scanf("%d", &CC); CC--;)
#define Rush(n) while (scanf("%d", &n) != -1)
using namespace std;

void RD(int &x) { scanf("%d", &x); }
void RD(i64 &x) { scanf("%I64d", &x); }
void RD(u32 &x) { scanf("%u", &x); }
void RD(double &x) { scanf("%lf", &x); }
void RD(int &x, int &y) { scanf("%d%d", &x, &y); }
void RD(i64 &x, i64 &y) { scanf("%I64d%I64d", &x, &y); }
void RD(u32 &x, u32 &y) { scanf("%u%u", &x, &y); }
void RD(double &x, double &y) { scanf("%lf%lf", &x, &y); }
void RD(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void RD(i64 &x, i64 &y, i64 &z) { scanf("%I64d%I64d%I64d", &x, &y, &z); }
void RD(u32 &x, u32 &y, u32 &z) { scanf("%u%u%u", &x, &y, &z); }
void RD(double &x, double &y, double &z) { scanf("%lf%lf%lf", &x, &y, &z); }
void RD(char &x) { x = getchar(); }
void RD(char *s) { scanf("%s", s); }
void RD(string &s) { cin >> s; }

void PR(int x) { printf("%d\n", x); }
void PR(int x, int y) { printf("%d %d\n", x, y); }
void PR(i64 x) { printf("%lld\n", x); }
void PR(u32 x) { printf("%u\n", x); }
void PR(u64 x) { printf("%I64u\n", x); }
void PR(double x) { printf("%.6lf\n", x); }
void PR(char x) { printf("%c\n", x); }
void PR(char *x) { printf("%s\n", x); }
void PR(string x) { cout << x << endl; }

const int mod = 1000000007;
const i64 inf = ((i64)1) << 60;
const int INF = 100000000;
const int N = 105;

char s[2][N][N];
int n, m, K, ans[26][2];
int a[26][15], b[26][15];

void deal(int x) {
  char s[20];
  RD(s);
  int L = strlen(s), i;
  for (i = 0; i < L && s[i] != '/'; i++) {
    a[x][s[i] - '0'] = 1;
  }
  for (i++; i < L && s[i] != '/'; i++) {
    b[x][s[i] - '0'] = 1;
  }
}

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int OK(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void cal(char s1[][N], char s2[][N], int x) {
  int i, j, k, cnt, xx, yy;
  char c = x + 'A';
  FOR1(i, n) FOR1(j, m) if (s2[i][j] == '.') {
    if (s1[i][j] != c) {
      cnt = 0;
      FOR0(k, 8) {
        xx = i + dx[k];
        yy = j + dy[k];
        if (OK(xx, yy) && s1[xx][yy] == c) cnt++;
      }
      if (b[x][cnt]) s2[i][j] = c;
    } else if (s1[i][j] == c) {
      cnt = 0;
      FOR0(k, 8) {
        xx = i + dx[k];
        yy = j + dy[k];
        if (OK(xx, yy) && s1[xx][yy] == c) cnt++;
      }
      if (a[x][cnt]) s2[i][j] = c;
    }
  }
  FOR1(i, n) FOR1(j, m) if (s1[i][j] == c) s1[i][j] = '.';
}

void cal(int x) {
  int i, j, k, cnt;
  FOR0(i, K) {
    cnt = 0;
    FOR1(j, n) FOR1(k, m) if (s[x][j][k] == i + 'A') { cnt++; }
    if (cnt < ans[i][0]) ans[i][0] = cnt;
    if (cnt > ans[i][1]) ans[i][1] = cnt;
  }
}

void print(char s[][N]) {
  puts("*******");
  int i;
  FOR1(i, n) {
    s[i][m + 1] = 0;
    puts(s[i] + 1);
  }
}

int main() {
  int num = 0;
  rush() {
    RD(m, n, K);
    int i;
    FOR1(i, n) RD(s[0][i] + 1);
    clr(a, 0);
    clr(b, 0);
    FOR0(i, K) deal(i);
    int cnt;
    RD(cnt);
    int pre = 0, cur = 1;
    FOR0(i, K) ans[i][0] = INF, ans[i][1] = -INF;
    cal(0);
    while (cnt--) {
      clr(s[cur], '.');
      FOR0(i, K) cal(s[pre], s[cur], i);
      cal(cur);
      swap(pre, cur);
    }
    printf("Simulation #%d\n", ++num);
    FOR0(i, K) printf("Species %c: At most %d live, at least %d live.\n",
                      i + 'A', ans[i][1], ans[i][0]);
  }
  return 0;
}
