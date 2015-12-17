

#include <stdio.h>
#include <string.h>

#define maxBound 250
#define max(a, b) (((a) > (b)) ? (a) : (b))
int StrALen;
int StrBLen;
char a[maxBound];
char b[maxBound];
int dp[maxBound][maxBound];

int answer(int alen, int blen) {
  for (int i = 0; i < alen; i++) {
    for (int j = 0; j < blen; j++) {
      if (a[i] == b[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
        // printf("The sample character is:%c\n",a[i]);
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  return dp[alen][blen];
}

int main() {
  while (scanf("%s%s", &a, &b) != EOF) {
    // printf("The a is:%s\n",a);
    // printf("The b is:%s\n",b);
    memset(dp, 0, sizeof(dp));

    int result = answer(strlen(a), strlen(b));
    printf("%d\n", result);
  }

  return 0;
}