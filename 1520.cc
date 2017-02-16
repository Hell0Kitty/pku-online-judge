#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 1005
#define maxl 55

struct Word {
  char name[maxl];
} word[maxn];

int word_num, int_num;
bool is_word[maxn];
int number[maxn];

void uni_case(char *st) {
  int len = strlen(st);
  for (int i = 0; i < len; i++)
    if (isupper(st[i])) st[i] -= 'A' - 'a';
}

bool operator<(const Word &a, const Word &b) {
  char aa[maxl];
  char bb[maxl];
  strcpy(aa, a.name);
  strcpy(bb, b.name);
  uni_case(aa);
  uni_case(bb);
  return strcmp(aa, bb) < 0;
}

void init() {
  word_num = 0;
  int_num = 0;
  memset(is_word, 0, sizeof(is_word));
}

bool is_number(char *temp) {
  int len = strlen(temp);
  for (int i = 0; i < len - 1; i++)
    if (!((temp[i] >= '0' && temp[i] <= '9') || temp[i] == '-')) return false;
  return true;
}

void insert(char *temp, int a) {
  if (is_number(temp)) {
    sscanf(temp, "%d", &number[int_num]);
    int_num++;
  } else {
    is_word[a] = true;
    strcpy(word[word_num].name, temp);
    word[word_num].name[strlen(word[word_num].name) - 1] = 0;
    word_num++;
  }
}

void output(int n) {
  int a = 0, b = 0;

  for (int i = 0; i < n; i++) {
    if (is_word[i])
      printf("%s", word[a++].name);
    else
      printf("%d", number[b++]);
    if (i != n - 1)
      printf(", ");
    else
      printf(".\n");
  }
}

int main() {
  char st[maxl];
  while (scanf("%s", st), strcmp(st, ".")) {
    init();
    int a = 0;
    while (st[strlen(st) - 1] != '.') {
      insert(st, a++);
      scanf("%s", st);
    }
    insert(st, a++);
    sort(number, number + int_num);
    sort(word, word + word_num);
    output(a);
  }
  return 0;
}
