#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 100010;
int num[maxn];
int sum[maxn];
int n, S;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &S);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &num[i]);
      sum[i] = sum[i - 1] + num[i];
    }
    if (sum[n] < S) {
      cout << 0 << endl;
      continue;
    }
    int ans = maxn;
    for (int s = 0; sum[s] + S <= sum[n];
         s++)  //从sum[s+1]开始查找，s是开始查找的数的前一个位置
    {
      int t =
          lower_bound(sum + s + 1, sum + n + 1, sum[s] + S) -
          (sum +
           s);  // sum+s是从第sum+s+1个地址开始查找的前一个地址，所以找到的地址减去这个地址即为区间长度
      ans = min(ans, t);
    }
    printf("%d\n", ans);
  }
  return 0;
}
