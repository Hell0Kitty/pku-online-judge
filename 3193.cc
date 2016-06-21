#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1010;
char sentence[MAX][65];
int main() {
  int N, M, i, j, ans, k;
  char str[65];
  scanf("%d%d", &M, &N);
  getchar();
  for (i = 0; i < M; ++i) {
    gets(sentence[i]);
  }
  int len;
  ans = 0;
  for (i = 0; i < N; ++i) {
    gets(str);
    len = strlen(str);
    for (j = 0; j < M; ++j) {
      for (k = 0; k < len; ++k) {
        if (str[k] != sentence[j][k]) {
          break;
        }
      }
      if (k == len) {
        ans++;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
