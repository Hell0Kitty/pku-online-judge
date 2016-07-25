#include <iostream>
#include <algorithm>
#define maxv(a, b) ((a)&am p; gt; = (b) ? (a) : (b))
#define minv(a, b) ((a) <= (b) ? (a) : (b))
#define MAX_N 505
#define MAX_VAL 99999999
using namespace std;
struct room {
  int cap, price;
} rooms[MAX_N + 1];
int dp[MAX_N][MAX_N][2];
int mn, fn, rn, cn, casen;
int minCost;
void set() {
  for (int i = 0; i <= mn; i++)
    for (int j = 0; j <= fn; j++)
      for (int k = 0; k <= 1; k++) dp[i][j][k] = MAX_VAL;
  dp[0][0][0] = 0;
  minCost = MAX_VAL;
}
int main() {
  int i;
  scanf("%d", &casen);
  while (casen--) {
    scanf("%d%d%d%d", &mn, &fn, &rn, &cn);
    for (i = 1; i <= rn; i++) scanf("%d%d", &rooms[i].cap, &rooms[i].price);
    set();
    int rp, mp, fp, cp;
    for (rp = 1; rp <= rn; rp++) {
      for (mp = mn; mp >= 0; mp--) {
        for (fp = fn; fp >= 0; fp--) {
          for (cp = 1; cp >= 0; cp--) {
            if (mp + fp + cp == 0) continue;
            if (mp >= 1)
              dp[mp][fp][cp] = minv(
                  dp[mp][fp][cp],
                  dp[mp - minv(mp, rooms[rp].cap)][fp][cp] + rooms[rp].price);
            if (fp >= 1)
              dp[mp][fp][cp] = minv(
                  dp[mp][fp][cp],
                  dp[mp][fp - minv(fp, rooms[rp].cap)][cp] + rooms[rp].price);
            if (cp >= 1 && rooms[rp].cap >= 2)
              dp[mp][fp][cp] =
                  minv(dp[mp][fp][cp], dp[mp][fp][0] + rooms[rp].price);
          }
        }
      }
      if (dp[mn][fn][0] < minCost) minCost = dp[mn][fn][0];
      if (dp[mn - 1][fn - 1][1] < minCost) minCost = dp[mn - 1][fn - 1][1];
    }
    if (minCost == MAX_VAL)
      cout << "Impossible" << endl;
    else
      cout << minCost << endl;
  }
  return 0;
}
