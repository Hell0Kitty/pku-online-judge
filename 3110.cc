#include <iostream>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <ctime>
#include <bitset>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll __int64
#define LL long long
#define lson l, m, (rt << 1)
#define rson m + 1, r, (rt << 1) | 1
#define M 1000000007
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define Maxn 55000
int n;
int yd[2] = {365, 366};

int days[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                   0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct DD {
  int m, d, y;
};
struct Sub {
  int cur, ea;
  char save[25];
  int dd;
} sub[Maxn];
bool cmp1(struct Sub a, struct Sub b)  //按考试日期从晚到前排序
{
  return a.cur > b.cur;
}

int isleap(int y)  //是否是润年
{
  if ((y % 4 == 0 && y % 100) || (y % 400 == 0)) return 1;
  return 0;
}

int dtoi(int y, int m, int d)  //将日期转化成距0000年00月00日的天数
{
  int res = 0, yy = isleap(y);

  res += y * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;  //从第0年开始
  for (int i = 1; i < m; i++) res += days[yy][i];
  return res + d - 1;
}

DD itod(int cur) {
  DD res;
  int i;

  res.y = cur / 182621 * 500;

  for (cur = cur % 182621; cur >= yd[isleap(res.y)]; res.y++)
    cur -= yd[isleap(res.y)];
  for (i = 1; cur >= days[isleap(res.y)][i]; i++) cur -= days[isleap(res.y)][i];
  res.m = i;
  res.d = cur + 1;

  return res;
}
struct Inf {
  int d;

  friend bool operator<(struct Inf a, struct Inf b) { return a.d < b.d; }
};
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%s", sub[i].save);
      int y, m, d;
      scanf("%2d.%2d.%4d", &d, &m, &y);
      sub[i].cur = dtoi(y, m, d);
      scanf("%d", &sub[i].dd);
      sub[i].ea = sub[i].cur - sub[i].dd;
    }
    sort(sub + 1, sub + 1 + n, cmp1);

    priority_queue<struct Inf> myq;

    int la = sub[1].cur, s = 1, e = n, le = n;
    bool ans = false;

    while (la) {
      bool ha = false;

      if (sub[s].cur == la) {
        struct Inf temp;
        temp.d = sub[s].ea;
        myq.push(temp);
        ha = true;
        s++;
      }

      if (!ha) {
        if (!myq.empty()) {
          struct Inf temp = myq.top();
          myq.pop();
          if (temp.d <= la)
            le--;
          else {
            ans = true;
            printf("Impossible\n");
            break;
          }
        }
      }
      if (!le) {
        DD tt = itod(la);
        ans = true;
        printf("%02d.%02d.%04d\n", tt.d, tt.m, tt.y);
        break;
      }
      la--;
    }
    if (!ans) printf("Impossible\n");
  }
  return 0;
}
