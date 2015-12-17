
#include <stdio.h>
#include <string.h>
char str[1000000];
bool hash[16000000] = {false};
int ansi[256] = {0};

int main() {
  int N, NC, ans = 0;
  scanf("%d%d%s", &N, &NC, str);
  for (char *s = str; *s; ++s) {  //*s 不是 s
    ansi[*s] = 1;                 //如果字母出现过，赋值为1
  }
  int cnt = 0;
  for (int i = 0; i < 256; ++i) {
    if (ansi[i]) ansi[i] = cnt++;  //从0开始编号
  }
  int len = strlen(str);
  for (int i = 0; i < len - N + 1; ++i) {
    int key = 0;
    for (int j = 0; j < N; ++j) {
      key = key * NC + ansi[str[i + j]];  //转换成NC进制
      // printf("%d\n",ansi[str[i + j]]);
    }
    // printf("key=%d\n",key);
    if (!hash[key]) {
      ans++;
      hash[key] = true;
    }
    }
    printf("%d\n",ans);
    return 0;
}