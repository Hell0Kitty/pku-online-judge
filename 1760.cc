#include <string>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

#define MAXNODE 20000  //输入文本每行最多40个结点，40*500
#define MAXLEN 85
#define MAXWORD 45

map<string, int> m[MAXNODE];

void preOder_traversal(int midx, int indentation) {
  for (map<string, int>::iterator i = m[midx].begin(); i != m[midx].end();
       ++i) {
    for (int i = 0; i < indentation; ++i) printf(" ");
    printf("%s\n", (i->first).c_str());

    preOder_traversal(i->second, indentation + 1);
  }
}

int main() {
  int n, i, j, midx, midx_counter = 0;
  char str[MAXLEN];
  int word_init[MAXWORD];
  string current_str;

  scanf("%d", &n);

  while (n--) {
    scanf("%s", str);
    word_init[0] = 0;
    j = 1;
    for (i = 0; str[i]; ++i) {
      if (str[i] == '\\') {
        str[i] = 0;
        word_init[j++] = i + 1;  //第j个单词从str[i+1]开始
      }
    }

    midx = 0;
    for (i = 0; i < j; ++i) {
      current_str = str + word_init[i];

      if (!m[midx].count(current_str))  //新结点
      {
        m[midx][current_str] = (++midx_counter);
      }

      midx = m[midx][current_str];
    }
  }

  preOder_traversal(0, 0);

  return 0;
}
