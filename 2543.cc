#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int const maxn = 300;
int const inf = 1000000;
char opt[maxn];
int pt;
int num[maxn];
int pn;
char expr[maxn];
int pe;
char expression[26][10][300];
int result[26][10];
inline char isdigit(char const c) {
  if (c >= '0' && c <= '9') return 1;
  return 0;
}
inline char isletter(char const c)  // A...Z
{
  if (c >= 'A' && c <= 'Z') return 1;
  return 0;
}
void cal() {
  pn--;
  switch (opt[--pt]) {
    case '+':
      if (pt > 0 && opt[pt - 1] == '-')
        num[pn - 1] -= num[pn];
      else
        num[pn - 1] += num[pn];
      break;
    case '-':
      if (pt > 0 && opt[pt - 1] == '-')
        num[pn - 1] += num[pn];
      else
        num[pn - 1] -= num[pn];
      break;
    case '*':
      num[pn - 1] *= num[pn];
      break;
    case '/':
      if (num[pn])
        num[pn - 1] /= num[pn];
      else
        num[pn - 1] = 0;
      break;
    default:  // error or add your extention
      break;
  }
}

int deal_expression(char *s) {
  int spn = pn, spt = pt;
  int ps = 0;
  char minus;
  if (s[0] == '(') s[0] = '(';
  while (s[ps]) {
    switch (s[ps]) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '(':
        opt[pt++] = s[ps++];
        break;
      case ')':
        ps++;
        while (pt > spt && opt[pt - 1] != '(') cal();
        if (pt > spt) pt--;
        while (pt > spt && (opt[pt - 1] == '*' || opt[pt - 1] == '/')) cal();
        break;
      default:
        if (isdigit(s[ps])) {
          minus = 0;
          if (ps - 1 >= 0 && s[ps - 1] == '-' &&
              (ps - 2 < 0 || s[ps - 2] == '('))
            minus = 1, pt--;
          int tmp = s[ps++] - '0';
          while (isdigit(s[ps])) tmp = tmp * 10 + s[ps++] - '0';
          if (minus) tmp = -tmp;
          num[pn++] = tmp;
        } else if (isletter(s[ps])) {
          int x = s[ps++] - 'A', y = s[ps++] - '0';
          if (result[x][y] == inf)
            return inf;
          else if (result[x][y] == -1) {
            result[x][y] = inf;
            result[x][y] = deal_expression(expression[x][y]);
            if (result[x][y] == inf) return inf;
          } else
            num[pn++] = result[x][y];
        } else {
        }  // error
        while (pt > spt && (opt[pt - 1] == '*' || opt[pt - 1] == '/')) cal();
        break;
    }
  }
  while (pt > spt) cal();
  return num[spn];
}

int n;
char buf1[maxn], buf2[maxn];
int p1, p2;
int main() {
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 10; j++) result[i][j] = 0;
  scanf("%d\n", &n);
  while (n--) {
    gets(buf1);
    for (p1 = 0, p2 = 0; buf1[p1]; p1++)
      if (buf1[p1] != ' ') buf2[p2++] = buf1[p1];
    buf2[p2] = 0;
    if (buf2[0] == 0) continue;
    int x = buf2[0] - 'A', y = buf2[1] - '0';
    result[x][y] = -1;
    strcpy(expression[x][y], buf2 + 3);
  }
  pt = pn = 0;
  int ans = deal_expression(expression[0][1]);
  printf("%d\n", ans);
  scanf("\n");
  return 0;
}
