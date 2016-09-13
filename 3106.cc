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

#define Maxn 330
#define M 110000

char a[Maxn][Maxn], b[Maxn][Maxn];
char ord[M];
int m, n;

void funh() {
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) b[m - i + 1][j] = a[i][j];
  memcpy(a, b, sizeof(b));
}
void funv() {
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) b[i][n - j + 1] = a[i][j];
  memcpy(a, b, sizeof(b));
}
void funa() {
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) b[j][m - i + 1] = a[i][j];
  swap(n, m);
  memcpy(a, b, sizeof(b));
}

int main() {
  while (~scanf("%d%d", &m, &n)) {
    for (int i = 1; i <= m; i++) scanf("%s", a[i] + 1);
    scanf("%s", ord);
    int hh = 0, ss = 0;
    int shu = 0, len = strlen(ord);
    int flag = 0;

    for (int i = 0; i < len; i++) {
      switch (ord[i]) {
        case '1': {
          flag ^= 1;
          if (shu) shu = (-shu + 4) % 4;
          shu = (shu + 1) % 4;
          if (hh)
            hh = 0;
          else if (ss) {
            hh = 0;
            ss = 0;
            shu = (shu + 2) % 4;
          } else
            hh++;

        } break;
        case '2': {
          flag ^= 1;  // HX
          if (shu) shu = (-shu + 4) % 4;
          shu = (shu - 1 + 4) % 4;  //最后有一个X
          if (hh)
            hh = 0;
          else if (ss) {
            hh = 0;
            ss = 0;
            shu = (shu + 2) % 4;
          } else
            hh++;
        } break;
        case 'V': {
          if (shu)  // AV=XH=HA
          {
            shu = (-(shu - 1) + 4) % 4;
            shu = (shu + 1) % 4;  //最后有一个A
            if (ss) {
              ss = 0;
              hh = 0;
              shu = (shu + 2) % 4;
            } else if (hh)
              hh = 0;
            else
              hh++;
            break;
          }
          if (ss) {
            ss = 0;
            hh = 0;
          } else if (hh) {
            ss = 0;
            hh = 0;
            shu = (shu + 2) % 4;
          } else
            ss++;  //如果一个H和V都没有，ss++

        } break;
        case 'H': {
          if (shu) shu = (4 - shu) % 4;
          if (ss) {
            ss = 0;
            hh = 0;
            shu = (shu + 2) % 4;
          } else if (hh)
            hh = 0;
          else
            hh++;
        } break;
        case 'A':
          shu = (shu + 1) % 4;
          flag ^= 1;
          break;
        case 'B':
          shu = (shu + 2) % 4;
          break;
        case 'C':
          flag ^= 1;
          shu = (shu + 3) % 4;
          break;
        case 'X':
          flag ^= 1;
          shu = (shu - 1 + 4) % 4;
          break;
        case 'Y':
          shu = (shu - 2 + 4) % 4;
          break;
        case 'Z':
          flag ^= 1;
          shu = (shu - 3 + 4) % 4;
          break;
      }
    }

    if (hh)  //注意执行顺序 H V a
      funh();
    else if (ss)
      funv();
    if (shu) {
      while (shu--) funa();
    }
    printf("%d %d\n", m, n);
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) printf("%c", a[i][j]);
      putchar('\n');
    }
  }

  return 0;
}
