
#include <stdio.h>
#include <memory.h>
#include <math.h>

#define maxBound 20005
#define kBound 205
int array[maxBound];
int ncase, k;
bool dp[maxBound][kBound];

int modfunc(int i, int j) {
  if (i >= 0) return i % j;

  return abs(i) % j;
}

void answer() {
  memset(dp, 0, sizeof(dp));
  dp[1][array[1]] = true;
  for (int i = 1; i <= ncase - 1; i++) {
    for (int j = 0; j <= k - 1; j++) {
      if (dp[i][j]) {
        int temp = modfunc(j + array[i + 1], k);
        dp[i + 1][temp] = true;
        dp[i + 1][modfunc(j - array[i + 1], k)] = true;
      }
    }
  }

  if (dp[ncase][0]) {
    printf("Divisible\n");
  } else {
    printf("Not divisible\n");
  }
  //  for (int i = 1 ;i <= ncase;i++)
  //  {
  //    for (int j = 1; j<= k;j++)
  //    {
  //      printf("%d ", dp[i][j]);
  //    }
  //    puts("");
  //  }
}
int main() {
  scanf("%d%d", &ncase, &k);
  for (int i = 1; i <= ncase; i++) {
    int temp;
    scanf("%d", &temp);
    array[i] = modfunc(temp, k);
  }
  //  for (int i = 1; i<= ncase;i++)
  //  {
  //    printf("%d ", array[i]);
  //  }
  //  puts("");
  answer();

  return 0;
}