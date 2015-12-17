
#include <stdio.h>
#include <string.h>
const int strl = 15;
struct color_type {
  int degree, n, cl;
  char c[strl];
  inline void set(const int &id, const int &l, const char *s) {
    degree = 1, n = id, cl = l;
    strcpy(c, s);
  }
};
color_type color[1000001];
int trie[1000000][27];
int root, ptr(1), loc(1), i(0), num(0);
int locate(char *s, int &i, int len) {
  root = 0;
  for (i = 0; i < len && trie[root][s[i] - 'a'] > 0; i++)
    root = trie[root][s[i] - 'a'];
  return root;
}
int insert(char *s) {
  int len = strlen(s);
  root = locate(s, i, len);
  int pos = 0;
  if (i == len)
    pos = 26;
  else if (trie[root][s[i] - 'a'] == 0)
    pos = s[i] - 'a';
  else {
    int tmp = -trie[root][s[i] - 'a'];
    if (strcmp(color[tmp].c, s)) {
      while (i < len && i < color[tmp].cl && color[tmp].c[i] == s[i]) {
        trie[root][s[i++] - 'a'] = ptr;
        root = ptr++;
      }
      if (i == len)
        pos = 26;
      else
        pos = s[i] - 'a';
      if (i == color[tmp].cl)
        trie[root][26] = -tmp;
      else
        trie[root][color[tmp].c[i] - 'a'] = -tmp;
    } else
      pos = s[i] - 'a';
  }
  if (trie[root][pos] == 0) {
    trie[root][pos] = -loc;
    color[loc].set(loc, len, s);
    loc++, num++;
  } else
    color[-trie[root][pos]].degree++;
  return color[-trie[root][pos]].n;
}
// union_find is used to judge whether the graph is connected.
int uset[510001];
int get_root(const int &v) {
  if (uset[v] == v)
    return v;
  return uset[v] = get_root(uset[v]);
}
inline void Unite(const int &a, const int &b) { uset[uset[b]] = uset[a]; }

int main() {
  char s[80];
  int i, len, pos, a, b;
  for (i = 0; i < 510000; i++)
    uset[i] = i;
  while (gets(s)) {
    i = 0;
    while (s[i] != ' ')
      i++;
    s[i] = 0;
    a = insert(s);
    b = insert(s + i + 1);
    if (get_root(a) != get_root(b)) {
      Unite(a, b);
      num--;
    }
  }
  if (num > 1) {
    printf("Impossible\n");
    return 0;
  }
  int odd = 0;
  bool im = false;
  for (i = 1; i < loc; i++)
    if (color[i].degree % 2 == 1)
      if ((++odd) > 2) {
        im = true;
        break;
      }
  if (!im && (odd == 0 || odd == 2))
    printf("Possible\n");
  else
    printf("Impossible\n");
  scanf("\n");
  return 0;
}
