#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int ch[10010];
char str[10010];
int n;
int solve(int i)  //递归求从0变1需要的至少次数
{
  if (2 * i + 1 >= n - 1) {
    if (ch[i] == 0)
      return 1;
    else
      return 2;
  }
  if (ch[i] == 1)
    return solve(2 * i + 1) + solve(2 * i + 2);
  else
    return min(solve(2 * i + 1), solve(2 * i + 2));
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", &str);
    for (int i = 0; i < n - 1; i++) {
      scanf("%d", &ch[i]);
    }
    int m = solve(0);
    int res;
    if (str[0] == '0')
      res = 0;
    else
      res = 1;
    int len = strlen(str);
    for (int i = 1; i < len; i++)  //找变化的次数，1变0，0变1
    {
      if (str[i] != str[i - 1]) res++;
    }
    if (res) res += m - 1;
    printf("%d\n", res);
  }
  return 0;
}
