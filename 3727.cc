#include <stdio.h>
#include <string.h>
#include <math.h>
double eps = 1e-6;
char s[2000];
int s1[1000];
int s2[1000];
int top;
void arr() {
  int i, tmp = 0, zhishu, xishu;
  bool fu = 0, zs = 0, xs = 0;
  for (i = 0; i < strlen(s); i++) {
    if (s[i] == '=') break;
    if (s[i] >= '0' && s[i] <= '9') tmp = tmp * 10 + s[i] - '0';
    if (s[i] == '-') fu = 1;
    if (s[i] == '^') {
      tmp = 0;
      zs = 1;
    }
    if (s[i] == 'x') {
      if (tmp == 0) tmp = 1;
      xishu = tmp;
      if (fu) xishu = -xishu;
      fu = 0;
      tmp = 0;
      xs = 1;
    }
    if (s[i] == ' ') {
      if (zs && xs) {
        zhishu = tmp;
        if (fu) zhishu = -zhishu;
      } else if (!zs && xs)
        zhishu = 1;
      else {
        xishu = tmp;
        if (fu) xishu = -xishu;
        zhishu = 0;
      }
      s1[top] = xishu;
      s2[top++] = zhishu;
      zs = 0;
      xs = 0;
      fu = 0;
      zhishu = xishu = tmp = 0;
    }
  }
}
double abs(double n) {
  if (n < 0) return -n;
  return n;
}
double f1(double x) {
  int i;
  double sum = 0;
  for (i = 0; i < top; i++) sum += pow(x, (double)s2[i]) * (double)s1[i];
  return sum;
}
double f2(double x) {
  int i;
  double sum = 0;
  for (i = 0; i < top; i++)
    if (s2[i]) sum += pow(x, (double)s2[i] - 1) * (double)s1[i] * s2[i];
  return sum;
}
int solve(double x) {
  double ff1, ff2;
  double y;
  int cnt = 0;
  while (1) {
    ff1 = f1(x), ff2 = f2(x);
    y = x - ff1 / ff2;
    if (abs(x - y) < eps || abs(ff1) < eps || cnt >= 1002) break;
    x = y;
    cnt++;
  }
  return cnt;
}
int main() {
  double n;
  int i;
  while (gets(s)) {
    top = 0;
    scanf("%lf", &n);
    arr();
    int cnt = solve(n);
    if (cnt > 1000)
      printf("Bad x0 or bad equation!\n");
    else
      printf("%d\n", cnt);
    getchar();
  }
}
