#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define maxn 16000000

char s[maxn];
int a[10000];
int hash[maxn];

int main() {
  int N, NC, num = 0, len, i, cnt = 0, sum = 0, j;
  scanf("%d%d", &N, &NC);
  scanf("%s", &s);

  len = strlen(s);

  for (i = 0; i < len; i++)  // ascll码作为下标
  {
    if (!a[s[i]]) a[s[i]] = ++num;
  }

  for (i = 0; i < len - N + 1; i++) {
    sum = 0;
    for (j = i; j < i + N; j++) sum += sum * NC + a[s[j]];

    if (!hash[sum]) {  // hash表
      cnt++;
      hash[sum] = 1;
    }
  }

  printf("%d\n", cnt);
  return 0;
}
