#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
#include <list>
#include <set>
#include <cmath>
#define INF 0x7fffffff
#define eps 1e-6
using namespace std;
void Mr_j(char *str) {
  int len = strlen(str);
  char tmp = str[len - 1];
  for (int i = len - 1; i >= 0; i--) str[i] = str[i - 1];
  str[0] = tmp;
}
void Mr_c(char *str) {
  int i;
  char tmp = str[0];
  for (i = 0; i < strlen(str) - 1; i++) str[i] = str[i + 1];
  str[i] = tmp;
}
void Mr_e(char *str) {
  int len = strlen(str);
  int i, j;
  char tmp[1001];
  for (i = 0; i < len / 2; i++) tmp[i] = str[i];
  if (len & 1) i++;
  for (j = 0; i < len; i++, j++) str[j] = str[i], str[i] = tmp[j];
}
void Mr_a(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) swap(str[i], str[len - i - 1]);
}
void Mr_p(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] > '0' && str[i] <= '9')
      str[i]--;
    else if (str[i] == '0')
      str[i] = '9';
  }
}
void Mr_m(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= '0' && str[i] < '9')
      str[i]++;
    else if (str[i] == '9')
      str[i] = '0';
  }
}
int main() {
  char str[1001];
  char order[1001];
  int m;
  scanf("%d", &m);
  while (m--) {
    scanf("%s%s", order, str);
    for (int i = strlen(order) - 1; i >= 0; i--) {
      if (order[i] == 'J')
        Mr_j(str);
      else if (order[i] == 'C')
        Mr_c(str);
      else if (order[i] == 'E')
        Mr_e(str);
      else if (order[i] == 'A')
        Mr_a(str);
      else if (order[i] == 'P')
        Mr_p(str);
      else if (order[i] == 'M')
        Mr_m(str);
    }
    puts(str);
  }
}
