#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100002
#define ll long long
#define XOR(x, y) (x == y ? '0' : '1')
using namespace std;

char s[MAX], t[MAX], e[MAX];
int next[MAX];

void get_next(char *p, int ls) {
  int k, i;
  k = -1;
  i = 0;
  memset(next, -1, sizeof(next));
  while (i <= ls - 1) {
    if (k == -1 || p[i] == p[k]) {
      k++;
      i++;
      next[i] = k;
    } else
      k = next[k];
  }
}

int kmp(int st, int ls, int lt) {
  int i, j;
  i = 0;
  j = 0;
  for (int k = 0; k < lt; k++) e[k] = XOR(s[st + k], t[k]);
  e[lt] = '\0';
  get_next(e, lt);
  while (i < ls && j < lt) {
    if (j == -1 || s[i] == e[j]) {
      i++;
      j++;
    } else
      j = next[j];
  }
  if (j >= lt) return (i - lt + 1);
  return -1;
}

int main() {
  int f, lt, ls;
  while (scanf("%s", t) != EOF) {
    scanf("%s", s);
    lt = strlen(t);
    ls = strlen(s);
    for (int i = 0; i < ls; i++) s[i + ls] = s[i];
    s[ls * 2] = '\0';
    f = -1;
    for (int i = 0; i < ls; i++) {
      f = kmp(i, ls * 2, lt);
      if (f != -1) break;
    }
    if (f != -1)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
