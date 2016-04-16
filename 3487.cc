#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct T {
  int love[26];
  int person;
  int yao;
} man[26];
struct U {
  int love[26];
  int person;
  int accept[26];
  int num;
} woman[26];
int n;
int man_num[26];
int woman_num[26];
bool check() {
  int i;
  for (i = 0; i < n; i++) {
    if (man[man_num[i]].person == -1) {
      return false;
    }
  }
  return true;
}
int main() {
  int total;
  int i, j;
  scanf("%d", &total);
  while (total--) {
    scanf("%d", &n);
    getchar();
    char ch;
    for (i = 0; i < n; i++) {
      scanf("%c", &ch);
      man_num[i] = ch - 'a';
      getchar();
    }
    for (i = 0; i < n; i++) {
      scanf("%c", &ch);
      woman_num[i] = ch - 'A';
      getchar();
    }
    char temp[100];
    int k;
    for (i = 0; i < n; i++) {
      k = 0;
      scanf("%s", temp);
      for (j = 2; j < n + 2; j++) {
        man[man_num[i]].love[k++] = temp[j] - 'A';
      }
    }
    for (i = 0; i < n; i++) {
      k = 0;
      scanf("%s", temp);
      for (j = 2; j < n + 2; j++) {
        woman[woman_num[i]].love[k++] = temp[j] - 'a';
      }
    }

    for (i = 0; i < n; i++) {
      man[man_num[i]].person = -1;
      man[man_num[i]].yao = 0;
      woman[woman_num[i]].person = -1;
    }
    for (;;) {
      for (j = 0; j < n; j++) {
        woman[woman_num[j]].num = 0;
      }
      for (j = 0; j < n; j++) {
        if (man[man_num[j]].person != -1) {
          continue;
        }
        woman[man[man_num[j]].love[man[man_num[j]].yao]]
            .accept[woman[man[man_num[j]].love[man[man_num[j]].yao]].num++] =
            man_num[j];
        man[man_num[j]].yao++;
      }
      int l;
      for (j = 0; j < n; j++) {
        int max = woman[woman_num[j]].person;
        if (max != -1) {
          for (k = 0; k < n; k++) {
            if (woman[woman_num[j]].love[k] == max) {
              max = k;
              break;
            }
          }
        }
        if (max == -1) {
          max = 26;
        }

        for (k = 0; k < woman[woman_num[j]].num; k++) {
          int tem = woman[woman_num[j]].accept[k];
          for (l = 0; l < n; l++) {
            if (woman[woman_num[j]].love[l] == tem) {
              tem = l;
              break;
            }
          }
          if (tem < max) {
            if (max != 26) {
              man[woman[woman_num[j]].person].person = -1;
            }
            woman[woman_num[j]].person = woman[woman_num[j]].love[tem];
            man[woman[woman_num[j]].person].person = woman_num[j];
            max = tem;
          }
        }
      }
      if (check()) {
        break;
      }
    }
    for (i = 0; i < n; i++) {
      printf("%c %c\n", man_num[i] + 'a', man[man_num[i]].person + 'A');
    }
    printf("\n");
  }
  return 0;
}
