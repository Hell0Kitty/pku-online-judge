#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 105, maxl = 45;

int text1[maxn], text2[maxn], len1, len2;
char dic[maxn * 2][maxl];
int tot;
char first[maxl];
int f[maxn][maxn], from[maxn][maxn];
int stk[maxn];

int getid(char *word) {
  for (int i = 0; i < tot; i++)
    if (strcmp(dic[i], word) == 0) return i;
  strcpy(dic[tot++], word);
  return tot - 1;
}

void input(int text[], int &len) {
  char word[maxl];
  int i = 1;

  strcpy(word, first);
  while (strcmp(word, "#")) {
    text[i++] = getid(word);
    scanf("%s", word);
  }
  len = i - 1;
}

void work() {
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (f[i - 1][j] > f[i][j - 1]) {
        from[i][j] = 0;
        f[i][j] = f[i - 1][j];
      } else {
        from[i][j] = 1;
        f[i][j] = f[i][j - 1];
      }
      if (text1[i] == text2[j] && f[i][j] < f[i - 1][j - 1] + 1) {
        f[i][j] = f[i - 1][j - 1] + 1;
        from[i][j] = 2;
      }
    }
  }

  int a = len1, b = len2;
  int rear = 0;
  while (a && b) {
    if (from[a][b] == 0)
      a--;
    else if (from[a][b] == 1)
      b--;
    else {
      stk[rear++] = text1[a];
      a--;
      b--;
    }
  }
  printf("%s", dic[stk[rear - 1]]);
  for (int i = rear - 2; i >= 0; i--) printf(" %s", dic[stk[i]]);
  printf("\n");
}

int main() {
  while (~scanf("%s", first)) {
    memset(f, 0, sizeof(f));
    tot = 0;
    input(text1, len1);
    scanf("%s", first);
    input(text2, len2);
    work();
  }
  return 0;
}
