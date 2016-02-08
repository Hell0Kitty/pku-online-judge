#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int n, a[26], ans, tag;
char ex2[500];
char ex[500];
bool vis[26];

int main() {
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    gets(ex2);
    strcpy(ex, ex2);
    for (int j = 0; j < strlen(ex); j++) {
      if (ex[j] == ' ') {
        int p = j;
        for (; ex[p] != '\0'; p++) ex[p] = ex[p + 1];
        j--;
      }
    }
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < 26; j++) a[j] = j + 1;
    int label = 1;
    ans = 0;
    for (int j = 0; j < strlen(ex); j++) {
      if (ex[j] == '-' || ex[j] == '+') {
        if ((ex[j + 1] == '-' && ex[j] == '-' ||
             ex[j + 1] == '+' && ex[j] == '+') &&
            (ex[j + 2] <= 'z' && ex[j + 2] >= 'a')) {
          a[ex[j + 2] - 'a'] += ex[j] == '+' ? 1 : -1, j += 1;
          vis[ex[j + 1] - 'a'] = 1;
        } else
          label = ex[j] == '+' ? 1 : -1;
      } else if (ex[j] <= 'z' && ex[j] >= 'a') {
        int flag = 0;

        ans += label * a[ex[j] - 'a'];
        if (!vis[ex[j] - 'a']) flag = 1, vis[ex[j] - 'a'] = 1;
        if (flag && (ex[j + 1] == '-' && ex[j + 2] == '-' ||
                     ex[j + 1] == '+' && ex[j + 2] == '+')) {
          a[ex[j] - 'a'] += ex[j + 1] == '+' ? 1 : -1, j += 2;
        }
      }
    }
    printf("Expression: %s\n", ex2);
    printf("value = %d\n", ans);
    for (int j = 0; j < 26; j++) {
      if (vis[j]) printf("%c = %d\n", j + 'a', a[j]);
    }
  }

  return 0;
}
