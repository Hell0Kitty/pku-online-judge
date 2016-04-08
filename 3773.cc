#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define KIND 26
#define MAXN 1001
#define MAXNODE 260100

int n, N, L, C;
int child[MAXNODE][KIND], suffix[MAXNODE], q[MAXNODE];
char s[MAXN];

int change(char ch) { return ch - 'a'; }

void Trie() {
  memset(child, 0, sizeof(child));
  N = 1;
  int p = 1;
  for (int j = 0; s[j]; ++j) {
    int ch = change(s[j]);
    if (!child[p][ch]) child[p][ch] = ++N;
    p = child[p][ch];
  }
}

void AC() {
  int ql = 0, qr = 0;
  for (int i = 0; i < KIND; ++i)
    if (child[1][i]) {
      suffix[child[1][i]] = 1;
      q[qr++] = child[1][i];
    } else
      child[1][i] = 1;
  while (ql < qr) {
    int u = q[ql++];
    for (int i = 0; i < KIND; ++i)
      if (child[u][i]) {
        suffix[child[u][i]] = child[suffix[u]][i];
        q[qr++] = child[u][i];
      } else
        child[u][i] = child[suffix[u]][i];
  }
}

int main() {
  scanf("%s", s);
  while (s[0] != '0') {
    Trie();
    AC();
    for (int i = 1; i <= N; i++) {
      printf("%d ", i - 1);
      for (int j = 0; j < KIND - 1; j++) printf("%d ", child[i][j] - 1);
      printf("%d\n", child[i][KIND - 1] - 1);
    }
    scanf("%s", s);
  }
  return 0;
}
