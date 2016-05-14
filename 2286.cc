#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int INF = 1 << 30;
const int MAXN = 7500 + 10;
int maxh, c;
int num[30];
int res[10];
int A[8][7] = {1,  3,  7,  12, 16, 21, 23, 2,  4,  9,  13, 18, 22, 24,
               11, 10, 9,  8,  7,  6,  5,  20, 19, 18, 17, 16, 15, 14,
               24, 22, 18, 13, 9,  4,  2,  23, 21, 16, 12, 7,  3,  1,
               14, 15, 16, 17, 18, 19, 20, 5,  6,  7,  8,  9,  10, 11};

bool judge(int *a) {
  int t = a[7];
  if (a[8] != t || a[9] != t || a[12] != t || a[13] != t || a[16] != t ||
      a[17] != t || a[18] != t)
    return 0;
  return 1;
}

int cal(int *a) {
  int b[5] = {0};
  b[a[7]]++;
  b[a[8]]++;
  b[a[9]]++;
  b[a[12]]++;
  b[a[13]]++;
  b[a[16]]++;
  b[a[17]]++;
  b[a[18]]++;
  b[0] = b[1] > b[2] ? b[1] : b[2];
  b[0] = b[0] > b[3] ? b[0] : b[3];
  return 8 - b[0];
}

bool dfs(int deep) {
  int n = cal(num);
  if (n == 0) return true;
  if (n > maxh - deep) return false;
  for (int i = 0; i < 8; i++) {
    res[c++] = i;
    int tmp = num[A[i][0]];
    for (int j = 1; j < 7; j++) {
      num[A[i][j - 1]] = num[A[i][j]];
    }
    num[A[i][6]] = tmp;
    if (dfs(deep + 1)) return true;
    c--;
    tmp = num[A[i][6]];
    for (int j = 6; j > 0; j--) {
      num[A[i][j]] = num[A[i][j - 1]];
    }
    num[A[i][0]] = tmp;
  }
  return false;
}

int main() {
  int x;
  while (scanf("%d", &x), x) {
    num[1] = x;
    int i;
    for (i = 2; i <= 24; i++) {
      scanf("%d", &x);
      num[i] = x;
    }
    if (judge(num)) {
      printf("No moves needed\n");
      printf("%d\n", num[7]);
      continue;
    }
    maxh = 1;
    c = 0;
    while (!dfs(0)) {
      maxh++;
    }
    for (i = 0; i < c; i++) {
      printf("%c", res[i] + 'A');
    }
    printf("\n%d\n", num[7]);
  }
  return 0;
}
