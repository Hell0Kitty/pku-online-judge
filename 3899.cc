#include <stdio.h>
#include <string.h>

long long dp[500][3][3][3][3];

char sa[200], sb[200];
int lena, lenb;
int geta1(int now, int sta, int k) {
  if (sta) return sta;
  if (k > sa[now - 1] - '0') return 2;
  if (k < sa[now - 1] - '0') return 1;
  return 0;
}
int geta2(int now, int sta, int k) {
  if (k > sa[lena - now] - '0') return 2;
  if (k < sa[lena - now] - '0') return 1;
  return sta;
}
int getb1(int now, int sta, int k) {
  if (sta) return sta;
  if (k > sb[now - 1] - '0') return 2;
  if (k < sb[now - 1] - '0') return 1;
  return 0;
}
int getb2(int now, int sta, int k) {
  if (k > sb[lenb - now] - '0') return 2;
  if (k < sb[lenb - now] - '0') return 1;
  return sta;
}
long long cal() {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0][0] = 1;
  int len, a1, a2, b1, b2, aa1, bb1, aa2, bb2;

  long long ans;
  ans = 0;
  for (len = 0; len < lenb; len++)
    for (a1 = 0; a1 < 3; a1++)
      for (b1 = 0; b1 < 3; b1++)
        for (a2 = 0; a2 < 3; a2++)
          for (b2 = 0; b2 < 3; b2++) {
            aa1 = geta1(len + 1, a1, 4);
            aa2 = geta2(len + 1, a2, 4);
            bb1 = getb1(len + 1, b1, 4);
            bb2 = getb2(len + 1, b2, 4);
            dp[len + 1][aa1][bb1][aa2][bb2] =
                dp[len + 1][aa1][bb1][aa2][bb2] + dp[len][a1][b1][a2][b2];

            aa1 = geta1(len + 1, a1, 7);
            aa2 = geta2(len + 1, a2, 7);
            bb1 = getb1(len + 1, b1, 7);
            bb2 = getb2(len + 1, b2, 7);
            dp[len + 1][aa1][bb1][aa2][bb2] =
                dp[len + 1][aa1][bb1][aa2][bb2] + dp[len][a1][b1][a2][b2];
          }
  for (len = 0; len < lenb; len++)
    for (a1 = 0; a1 < 3; a1++)
      for (b1 = 0; b1 < 3; b1++)
        for (a2 = 0; a2 < 3; a2++)
          for (b2 = 0; b2 < 3; b2++) {
            if (len + 1 >= lena && len + 1 <= lenb) {
              if ((len + 1 > lena || (len + 1 == lena && a1 - 1)) &&
                  (len + 1 < lenb || (len + 1 == lenb && b1 - 2)))
                ans = ans + dp[len + 1][a1][b1][a2][b2];
              else if ((len + 1 > lena || (len + 1 == lena && a2 - 1)) &&
                       (len + 1 < lenb || (len + 1 == lenb && b2 - 2)))
                ans = ans + dp[len + 1][a1][b1][a2][b2];
            }
          }

  return ans;
}
int main() {
  int t;

  scanf("%d", &t);
  while (t--) {
    scanf("%s%s", sa, sb);
    lena = strlen(sa);
    lenb = strlen(sb);

    printf("%I64d\n", cal());
  }
}
