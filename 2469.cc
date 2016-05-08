#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
using namespace std;
int sa[105][100];
int card[100], _card[100];
char val[15][10] = {"2", "3",  "4",    "5",     "6",    "7",  "8",
                    "9", "10", "Jack", "Queen", "King", "Ace"};
char suit[5][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};
int Getdig(char str[]) {
  int i, len = strlen(str);
  int tot = 0;
  for (i = 0; i < len; i++) {
    if (isdigit(str[i])) tot = tot * 10 + str[i] - '0';
  }
  return tot;
}
int main() {
  int T, n, j, i;
  char num[100];
  while (scanf("%d", &n) != EOF) {
    int tmp;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= 52; j++) {
        scanf("%d", &sa[i][j]);
      }
    }
    for (i = 1; i <= 52; i++) card[i] = i - 1;
    while (scanf("%d", &tmp) != EOF) {
      // tmp=Getdig(num);
      if (tmp == 0) break;
      for (i = 1; i <= 52; i++) {
        int a = sa[tmp][i];
        _card[i] = card[a];
      }
      for (i = 1; i <= 52; i++) card[i] = _card[i];
      for (i = 1; i <= 52; i++) {
        int d = card[i] % 13;
        int c = card[i] / 13;
        printf("%s of %s\n", val[d], suit[c]);
      }
      printf("\n");
    }
  }
}
