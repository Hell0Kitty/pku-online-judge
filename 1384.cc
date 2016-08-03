#include <stdio.h>
#define MAX_COINS_KIND 510
#define MAX_WEIGH 10010
#define INF 1000000
int get_min(int, int);
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int wgh_epty, wgh_total, n, i, j, wgh_coins[MAX_COINS_KIND],
        val_coins[MAX_COINS_KIND], dp[MAX_WEIGH];
    scanf("%d%d", &wgh_epty, &wgh_total);
    scanf("%d", &n);
    dp[0] = 0;
    for (i = 1; i < MAX_WEIGH; i++) {
      dp[i] = INF;
    }
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &val_coins[i], &wgh_coins[i]);
    }
    for (i = 1; i <= n; i++) {
      for (j = wgh_coins[i]; j <= wgh_total - wgh_epty; j++) {
        dp[j] = get_min(dp[j], dp[j - wgh_coins[i]] + val_coins[i]);
      }
    }
    if (dp[wgh_total - wgh_epty] != INF) {
      printf("The minimum amount of money in the piggy-bank is %d.\n",
             dp[wgh_total - wgh_epty]);
    } else {
      printf("This is impossible.\n");
    }
  }
  return 0;
}
int get_min(int x, int y) { return x <= y ? x : y; }
