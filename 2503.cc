/*
trie  poj 2503 tengshengbo
*/
#include <iostream>
#include <string>
using namespace std;
int trie[200000][28];  // 27是字符串号
char str[100005][12];
int all;
int insert(char *s, int t) {
  int i, j;
  int now = 0;
  j = strlen(s);
  for (i = 0; i < j; i++) {
    int t = s[i] - 'a';
    if (trie[now][t] > 0)
      now = trie[now][t];
    else {
      all++;
      trie[now][t] = all;
      now = all;
    }
  }
  trie[now][27] = t;
  return 0;
}
int find(char *s) {
  int i, j;
  int now = 0;
  j = strlen(s);
  for (i = 0; i < j; i++) {
    int t = s[i] - 'a';
    if (trie[now][t] < 0) return -1;
    now = trie[now][t];
  }
  return trie[now][27];
}
int main() {
  char s[32];
  all = 0;
  int i, j;
  for (i = 0; i < 200000; i++)
    for (j = 0; j < 28; j++) trie[i][j] = -1;
  int total = 0;
  while ((gets(s)) && (s[0] != 0)) {
    char b[12];
    i = 0;
    while (s[i] != ' ') {
      str[total][i] = s[i];
      i++;
    }
    str[total][i] = 0;
    j = 0;
    i++;
    while (i < strlen(s)) {
      b[j] = s[i];
      j++;
      i++;
    }
    b[j] = 0;
    insert(b, total);
    total++;
  }
  while (scanf("%s", &s) != EOF) {
    i = find(s);
    if (i >= 0)
      cout << str[i] << endl;
    else
      cout << "eh" << endl;
  }
  return 0;
}
