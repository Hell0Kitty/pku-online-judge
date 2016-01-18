#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
const int N = 1000;
char comp(char a, char b) {
  if (b == '\0') {
    if (a == '\0')
      return '=';
    else
      return '>';
  } else if (a == '\0')
    return '<';
  else if (b == '(')
    return '<';
  else if (b == ')') {
    if (a == '(')
      return '=';
    else
      return '>';
  } else if (a == '(')
    return '<';
  else
    return '>';
}
bool cac(bool a, bool b, char op) {
  if (op == '|')
    return a || b;
  else if (op == '&')
    return a && b;
}
bool solve(char s[]) {
  int len = strlen(s), optop = 0, botop = 0, i = 0;
  char opstk[N];
  bool bostk[N];
  opstk[optop++] = '\0';
  while (s[i] != '\0' || opstk[optop - 1] != '\0') {
    if (s[i] == ' ' || s[i] == '\t') {
      i++;
      continue;
    } else if (s[i] == '!' || s[i] == '(')
      opstk[optop++] = s[i++];
    else if (s[i] == 'V' || s[i] == 'F')
      bostk[botop++] = (s[i] == 'V'), i++;
    else {
      switch (comp(opstk[optop - 1], s[i])) {
        case '>':
          if (opstk[optop - 1] == '!') {
            optop--;
            bostk[botop - 1] ^= true;
          } else {
            bool b = bostk[--botop], a = bostk[--botop];
            char ch = opstk[--optop];
            bostk[botop++] = cac(a, b, ch);
          }
          break;
        case '<':
          opstk[optop++] = s[i++];
          break;
        case '=':
          optop--;
          i++;
          break;
      }
    }
  }
  return bostk[0];
}
int main() {
  char s[200];
  int ca = 0;
  while (gets(s)) printf("Expression %d: %c\n", ++ca, solve(s) ? 'V' : 'F');
  return 0;
}
