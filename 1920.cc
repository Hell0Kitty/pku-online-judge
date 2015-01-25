#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <iostream>
#include <map>
using namespace std;
#define inf 0x3f3f3f3f
#define Max 110
#define mod 1000000
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int two[100100], n, s1, s2, s3;
int flag[100100], num[3], id;
inline void init() {
  int i;
  two[0] = 1;
  for (i = 1; i <= 100010; i++) two[i] = (two[i - 1] << 1) % mod;
}
int main() {
  int i, j;
  init();
  while (scanf("%d", &n) != EOF) {
    scanf("%d%d%d", &num[0], &num[1], &num[2]);
    for (i = 0; i < 3; i++)
      for (j = 0; j < num[i]; j++) {
        scanf("%d", &id);
        flag[id] = i;
      }
    int pos1 = flag[n];
    int ans = 0;
    for (i = n; i >= 1; i--) {
      if (flag[i] != pos1) {
        pos1 = 3 - pos1 - flag[i];
        ans = (ans + two[i - 1]) % mod;
        //   printf("%d\n",i);
      }
    }
    printf("%d\n%d\n", flag[n] + 1, (ans + mod) % mod);
  }
}
