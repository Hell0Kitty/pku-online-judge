#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct _Line {
  char word[100][85];
  int cc_word;
  void Init() {
    cc_word = 0;
    for (int i = 0; i < 100; i++) memset(word[i], 0, sizeof(word[i]));
  }
} Line;

Line line[1010];

inline bool judge(char ch) {
  if (ch >= 33 && ch <= 126) return true;
  return false;
}

int main() {
  int cases;
  char str[190];

  memset(str, 0, sizeof(str));
  int cc_line = 0;
  while (gets(str) != NULL) {
    int len = strlen(str);

    int cc = 0;
    bool flag = false;
    for (int i = 0; i <= len; i++) {
      if (flag && !judge(str[i])) {
        line[cc_line].word[line[cc_line].cc_word][cc] = 0;
        cc = 0;
        line[cc_line].cc_word++;
        flag = false;
      } else if (!flag && !judge(str[i]))
        continue;
      else {
        line[cc_line].word[line[cc_line].cc_word][cc++] = str[i];
        flag = true;
      }
    }
    cc_line++;
  }
  int max_word = 0;
  for (int i = 0; i < cc_line; i++)
    if (line[i].cc_word > max_word) max_word = line[i].cc_word;

  for (int j = 0; j < max_word; j++) {
    int max_width = 0;
    for (int i = 0; i < cc_line; i++) {
      if (line[i].cc_word <= j) continue;
      int len_line = strlen(line[i].word[j]);
      if (len_line > max_width) max_width = len_line;
    }
    for (int i = 0; i < cc_line; i++) {
      if (line[i].cc_word <= j || line[i].cc_word - 1 == j) continue;
      int len_line = strlen(line[i].word[j]);
      for (int k = len_line; k < max_width; k++) line[i].word[j][k] = ' ';
      line[i].word[j][max_width] = 0;
    }
  }
  for (int i = 0; i < cc_line; i++) {
    printf("%s", line[i].word[0]);
    for (int j = 1; j < line[i].cc_word; j++) printf(" %s", line[i].word[j]);
    puts("");
  }
  return 0;
}
