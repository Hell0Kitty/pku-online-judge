#include "stdio.h"
#include "string.h"
int main() {
  int pot;
  int bet;
  int fpot;
  while (scanf("%d%d%d", &pot, &bet, &fpot) != -1, pot + bet + fpot) {
    if (pot > fpot)
      pot -= fpot;
    else
      pot = fpot - pot;
    if (pot % bet != 0)
      printf("No accounting tablet\n");
    else {
      pot = pot / bet;
      int ans;
      ans = 0;
      ans += pot / 3;
      pot %= 3;
      ans += pot / 2, pot %= 2;
      ans += pot;
      printf("%d\n", ans);
    }
  }
  return 0;
}
