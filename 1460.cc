#include <iostream>
using namespace std;

char str[] = "*/+-";
char s[105];
int C, ans;

int isBig(char x, char y) {
  if (x == '(') return 0;
  if (y == '*' || y == '/') return x == '*' || x == '/';
  return 1;
}

int cal(int a, char op, int b) {
  if (op == '+') return a + b;
  if (op == '-') return a - b;
  if (op == '*') return a * b;
  return a / b;
}

int OK(char s[]) {
  char s1[1005];
  int s2[1005], top1 = 0, top2 = 0;
  int i, k, a, b, len = strlen(s);
  ;
  char c;

  for (i = 0; i < len; i++) {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      while (top1 > 0) {
        if (isBig(s1[top1], s[i])) {
          c = s1[top1];
          top1--;
          a = s2[top2];
          top2--;
          b = s2[top2];
          top2--;
          if (c == '/' && a == 0) return 0;
          s2[++top2] = cal(b, c, a);
        } else
          break;
      }
      s1[++top1] = s[i];
    } else if (s[i] >= '0' && s[i] <= '9') {
      k = 0;
      while (i < len && s[i] >= '0' && s[i] <= '9')
        k = k * 10 + s[i] - '0', i++;
      i--;
      s2[++top2] = k;
    } else if (s[i] == '(')
      s1[++top1] = s[i];
    else if (s[i] == ')') {
      while (s1[top1] != '(') {
        c = s1[top1];
        top1--;
        a = s2[top2];
        top2--;
        b = s2[top2];
        top2--;
        if (c == '/' && a == 0) return 0;
        s2[++top2] = cal(b, c, a);
      }
      top1--;
    }
  }
  while (top1 > 0) {
    c = s1[top1];
    top1--;
    a = s2[top2];
    top2--;
    b = s2[top2];
    top2--;
    if (c == '/' && a == 0) return 0;
    s2[++top2] = cal(b, c, a);
  }
  return s2[top2] == ans;
}

int main() {
  for (scanf("%d", &C); C--;) {
    scanf("%s%d", s, &ans);
    int pos[15], posNum = 0;
    char temp[105];
    int len = strlen(s);
    int i, j, k, flag = 0;
    for (i = 0; i < len; i++)
      if (s[i] == '?') pos[posNum++] = i;
    for (i = 0; i < 1 << (2 * posNum); i++) {
      strcpy(temp, s);
      k = i;
      for (j = 0; j < posNum; j++) temp[pos[j]] = str[k & 3], k >>= 2;
      if (OK(temp)) {
        flag = 1;
        break;
      }
    }
    if (flag)
      puts("yes");
    else
      puts("no");
  }
  return 0;
}
