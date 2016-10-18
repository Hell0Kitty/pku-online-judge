#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ans;
struct Trie {
  int dep;
  int next[26];
  bool init(int d) {
    dep = d;
    memset(next, -1, sizeof(next));
  }
};
char *strrev(char *str) {
  int ls, i;
  ls = strlen(str);
  char t;
  for (i = 0; i < (ls + 1) / 2; i++) {
    t = str[i];
    str[i] = str[ls - i - 1];
    str[ls - i - 1] = t;
  }
  return str;
}
Trie tree[550000];
int lt;
void init() {
  int i;
  lt = 1;
  tree[0].init(0);
}
void insert(char *word) {
  int t, i, val, lw;
  t = 0;
  lw = strlen(word);
  i = 0;
  while (word[i] != '\0') {
    val = word[i] - 'a';
    if (tree[t].next[val] == -1) {
      tree[t].next[val] = lt;
      tree[lt].init(tree[t].dep + 1);
      // printf("%d %d %d %d %c\n",t,val,lt,tree[lt].tag,word[i]);
      t = lt;
      lt++;
    } else {
      t = tree[t].next[val];
      ans = ans > (lw - tree[t].dep) ? (lw - tree[t].dep) : ans;
    }
    i++;
  }
}
int main() {
  int n, i, j, k;
  char str[110][110];
  char s[13];
  while (true) {
    scanf("%d", &n);
    ans = 9999;
    init();
    if (n == 0) break;
    for (i = 0; i < n; i++) {
      scanf("%s", str[i]);
      strcpy(str[i], strrev(str[i]));
      j = strlen(str[i]);
      ans = ans > j ? j : ans;
    }
    for (i = 0; i < n; i++) insert(str[i]);
    printf("%d\n", ans - 1);
  }
}
