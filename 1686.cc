#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
const int N = 1000;
char op[8] = {'+', '-', '*', '/', '(', ')', '\0'};
char cp[7][7] = {{'>', '>', '<', '<', '<', '>', '>'},
                 {'>', '>', '<', '<', '<', '>', '>'},
                 {'>', '>', '>', '>', '<', '>', '>'},
                 {'>', '>', '>', '>', '<', '>', '>'},
                 {'<', '<', '<', '<', '<', '=', '@'},
                 {'>', '>', '>', '>', '@', '>', '>'},
                 {'<', '<', '<', '<', '<', '@', '='}};
char st_char[N];
int st_int[N], top_char, top_int;
int cal(int a, char op, int b) {
  switch (op) {
    case '+':
      return a + b;
      break;
    case '-':
      return a - b;
      break;
    case '*':
      return a * b;
      break;
    case '/':
      return a / b;
      break;
    default:
      while (1) puts("You Will Output Limit Exceeded\n");
  }
}
char comp(char a, char b) {
  int i, j;
  for (i = 0; i < 7; i++)
    if (a == op[i]) break;
  for (j = 0; j < 7; j++)
    if (b == op[j]) break;
  return cp[i][j];
}
char comp10(char x, char ch) {
  if (x == '+' || x == '-')
    if (ch == '+' || ch == '-' || ch == ')' || ch == '\0')
      return ('>');
    else
      return ('<');
  if (x == '*' || x == '/')
    if (ch == '(')
      return ('<');
    else
      return ('>');
  if (x == '(')
    if (ch == ')')
      return ('=');
    else
      return ('<');
  if (x == ')')
    if (ch != '(') return ('>');
  if (x == '\0')
    if (ch == '\0')
      return ('=');
    else
      return ('<');
}
int cac(char s[]) {
  top_char = top_int = 0;
  st_char[top_char++] = '\0';
  int i = 0, v, a, b;
  char ch;
  bool flag = true;
  while (s[i] != '\0' || st_char[top_char - 1] != '\0') {
    if (s[i] == ' ' || s[i] == '\t') {
      i++;
      continue;
    } else if (isdigit(s[i])) {
      v = 0;
      while (isdigit(s[i])) {
        v = v * 10 + s[i] - '0';
        i++;
      }
      st_int[top_int++] = v;
    } else if (isalpha(s[i])) {
      st_int[top_int++] = (int)s[i++];
    } else {
      switch (comp(st_char[top_char - 1], s[i])) {
        case '<':
          st_char[top_char++] = s[i++];
          break;
        case '=':
          top_char--;
          i++;
          break;
        case '>':
          ch = st_char[--top_char];
          b = st_int[--top_int];
          a = st_int[--top_int];
          v = cal(a, ch, b);
          st_int[top_int++] = v;
          break;
      }
    }
  }
  return st_int[0];
}
int main() {
  int T;
  for (scanf("%d ", &T); T; T--) {
    char s1[1000], s2[1000];
    gets(s1);
    gets(s2);
    if (cac(s1) == cac(s2))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
