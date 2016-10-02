#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX 1001
using namespace std;
char str[MAX], sub[3][10];
int a[3], num[3][10], len[3], ans = 0;
bool use[30], vis[10];
int GetNumber(char op) {
  switch (op) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
  }
}
void DFS() {
  int flag = 0, pos = -1;
  if (ans == 2) return;
  for (int i = 0; i < 27; i++) {
    if (use[i]) {
      pos = i;
      break;
    }
  }
  if (pos != -1) {
    use[pos] = 0;
    for (int i = 0; i < 10; i++) {
      bool zero = 0;
      if (vis[i]) continue;
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < len[j]; k++) {
          if (sub[j][k] == pos + 'A') {
            if (i == 0 && k == 0 && len[j] > 1) {
              zero = 1;
              break;
            }
            num[j][k] = i;
          }
        }
        if (zero) break;
      }
      if (!zero) {
        vis[i] = 1;
        DFS();
        vis[i] = 0;
      }
      if (ans == 2) return;
    }
    use[pos] = 1;
  } else {
    int a[3];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 3; i++) {
      int ita = 0;
      for (int j = 0; j < len[i]; j++) a[i] = a[i] * 10 + num[i][j];
    }
    // printf("A %d %d %d\n",a[0],a[1],a[2]);
    if (a[0] + a[1] == a[2]) ans++;
  }
}
int main() {
  while (scanf("%s", str) && str[0] != '#') {
    int ita = 0, cou = 0;
    ans = 0;
    memset(len, 0, sizeof(len));
    memset(use, 0, sizeof(use));
    memset(vis, 0, sizeof(vis));
    int l = strlen(str);
    for (int i = 0; i < l - 1; i++) {
      if (str[i] == '+' || str[i] == '=') {
        a[cou++] = ita;
        ita = 0;
        continue;
      }
      use[str[i] - 'A'] = 1;
      sub[cou][len[cou]++] = str[i];
      if (str[i + 1] != '+' && str[i + 1] != '=')
        ita += GetNumber(str[i]) < GetNumber(str[i + 1]) ? (-GetNumber(str[i]))
                                                         : GetNumber(str[i]);
      else
        ita += GetNumber(str[i]);
    }
    ita += GetNumber(str[l - 1]);
    a[cou] = ita;
    use[str[l - 1] - 'A'] = 1;
    sub[cou][len[cou]++] = str[l - 1];
    if (a[0] + a[1] == a[2])
      printf("Correct");
    else
      printf("Incorrect");
    if (max(len[0], len[1]) <= len[2]) DFS();
    if (!ans)
      printf(" impossible\n");
    else if (ans == 1)
      printf(" valid\n");
    else
      printf(" ambiguous\n");
  }
  return 0;
}
