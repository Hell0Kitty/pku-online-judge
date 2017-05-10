#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 210

int n, fp, ansp;
char str[MAXN], minf[MAXN], fir[MAXN], ans[MAXN], temp[MAXN], next[MAXN],
    ret[MAXN];

inline void swap(char &a, char &b)  //交换字符
{
  char tmp;
  tmp = a, a = b, b = tmp;
}
void get_Adjacent(char t[], int x)  //得到t相邻的数
{                                   // x = -1减，x = 1加1;
  char s[MAXN];
  int i, flag = 0, len = strlen(t);
  for (i = 0; i <= len; i++) s[i] = t[i];
  if (x == -1) {
    for (i = len - 1; i >= 0 && s[i] == '0'; i--)
      ;
    if (i >= 0) s[i]--;
    if (len > 1 && s[0] == '0') flag = -1;
    for (i = i + 1; i < len; i++) s[i] = '9';
  } else {
    for (i = len - 1; i >= 0 && s[i] == '9'; i--)
      ;
    if (i >= 0)
      s[i]++;
    else
      flag = 1;
    for (i = i + 1; i < len; i++) s[i] = '0';
  }
  i = 0;
  if (flag == 1) next[i++] = '1';
  for (; i < len + flag; i++) next[i] = s[i - flag];
  next[i] = '\0';
}
bool judgment(int p, int len)  //判断是否是999991000000这种情况;
{
  int i;
  if (str[p] != '1') return false;
  for (i = 1; i < p; i++)
    if (str[i] != '9') return false;
  for (i = 1; i + p <= n && i < len; i++)
    if (str[i + p] != '0') return false;
  return true;
}
void getMin(char s[], char t[])  //取较小的,存在s中;
{
  int i, ls = strlen(s), lt = strlen(t);
  if (t[0] == '0' || lt > ls) return;
  if (lt < ls) {
    strcpy(s, t);
    ansp = fp;
    return;
  }
  for (i = 0; i < ls; i++) {
    if (s[i] > t[i])
      break;
    else if (s[i] < t[i])
      return;
  }
  strcpy(s, t);
  ansp = fp;
}
void find_FirstNumber()  //找到字符串的开始数字；
{
  int i, j, k, l, len, cnt;
  for (i = 0; i < MAXN - 2; i++) minf[i] = 'A';
  minf[MAXN - 1] = '\0';
  for (l = 1; l <= n; l++) {
    for (len = l, i = 2; i <= len + 1; i++) {
      fp = i;
      if (str[i] == '0') continue;
      if (n - i + 1 < len)  // 如果长度不够，不能分成第二个数
      {
        if (judgment(i, len + 1)) {
          for (j = 0; j < len; j++) fir[j] = '9';
          fir[j] = '\0';
          getMin(minf, fir);
          continue;
        }
        for (j = 1; j < i && str[j] == '9'; j++)
          ;
        if (j == i) {
          for (j = 0; j + i <= n; j++) temp[j] = str[i + j];
          temp[j] = '\0';
          get_Adjacent(temp, -1);
          k = j, cnt = 1;
          while (next[j - 1] == '9' && cnt < i) k--, j--, cnt++;
          for (j = 0; j < k; j++) fir[j] = next[j];
          for (j = 1; j < i; j++) fir[k + j - 1] = str[j];
          fir[k + j - 1] = '\0';
          getMin(minf, fir);
          continue;
        }
        for (j = 1; j < i; j++) fir[len - j] = str[i - j];
        fir[len] = '\0';
        for (j = 0; j <= len - i; j++) fir[j] = str[i + j];
        get_Adjacent(fir, 1);
        for (j = 0; j < len && i + j <= n; j++)
          if (next[j] != str[i + j]) break;
        if (j < len && i + j <= n)
          continue;
        else {
          getMin(minf, fir);
          continue;
        }
      }  // temp为第二个数；
      if (judgment(i, len + 1)) {
        len++;
        for (j = 1; j < len; j++) temp[j] = '0';
        temp[0] = '1';
        temp[j] = '\0';
        for (j = 0; j < len - 1; j++) fir[j] = '9';
        fir[j] = '\0';
      } else {
        for (j = 0; j < len; j++) temp[j] = str[j + i];
        temp[j] = '\0';
        get_Adjacent(temp, -1);  //得到第一个数(next)；
        for (j = 1; j < i; j++)  // 与str[1-i-1]比较；
          if (next[len - j] != str[i - j]) break;
        if (j < i) continue;
        strcpy(fir, next);
      }  //比较下一个数；
      k = i + len;
      while (k <= n) {
        get_Adjacent(temp, 1);  //得到比temp大1的数(next)；
        len = strlen(next);
        for (j = 0; k + j <= n && j < len; j++)  //从高位到低位比较；
          if (next[j] != str[k + j]) break;
        if (k + j <= n && j < len) break;  //比较失败；
        strcpy(temp, next);
        k += len;
      }
      if (k > n) getMin(minf, fir);
    }
  }
}
void bigAdd(char a[], char b[])  //大数加;
{
  int la = strlen(a), lb = strlen(b), i, j, carrt = 0, tmp, cnt = 0;
  for (i = la - 1, j = lb - 1; i >= 0 && j >= 0; i--, j--) {
    tmp = a[i] + b[j] - '0' - '0' + carrt;
    carrt = tmp / 10;
    ret[cnt++] = tmp % 10 + '0';
  }
  for (; i >= 0; i--) {
    tmp = a[i] - '0' + carrt;
    carrt = tmp / 10;
    ret[cnt++] = tmp % 10 + '0';
  }
  for (; j >= 0; j--) {
    tmp = b[j] - '0' + carrt;
    carrt = tmp / 10;
    ret[cnt++] = tmp % 10 + '0';
  }
  while (carrt) {
    ret[cnt++] = carrt % 10 + '0';
    carrt /= 10;
  }
  ret[cnt++] = '\0';
  for (i = 0; i < cnt / 2; i++) swap(ret[i], ret[cnt - i - 2]);
  strcpy(a, ret);
}
void bigMutil(char a[], int b)  //大数乘以int b
{
  int i, len = strlen(a);
  for (i = 0; i <= len; i++) next[i] = a[i];
  for (i = 1; i < b; i++) bigAdd(a, next);
}
void cal_Temp()  //计算表达式；
{
  int i, j, len = strlen(minf);
  for (i = 1; i < len && minf[i] == '0'; i++)
    ;
  if (i == len && minf[0] == '1') {
    temp[0] = '0';
    temp[1] = '\0';
    return;
  }
  j = i = 1;
  temp[0] = minf[0] - 1;
  if (temp[0] == '0') i = 0;
  for (; i <= len; i++, j++) temp[i] = minf[j];
}
void solve()  //算结果;
{
  ans[0] = '0', ans[1] = '\0';
  char a[MAXN];
  int i, j, cnt, t, len = strlen(minf);
  for (i = 1; i < len; i++) {
    t = i * 9;
    cnt = 0;
    while (t) {
      a[++cnt] = t % 10 + '0';
      t /= 10;
    }
    for (j = 0; j < cnt; j++) temp[j] = a[cnt - j];
    cnt = j;
    for (j = 0; j < i - 1; j++) temp[cnt++] = '0';
    temp[cnt] = '\0';
    bigAdd(ans, temp);
  }
  cal_Temp();
  bigMutil(temp, len);
  bigAdd(ans, temp);
  for (i = -1; i <= len - ansp; i++)  // ans - fp + 1 ;
  {
    get_Adjacent(ans, 1);
    strcpy(ans, next);
  }
}
bool special_Judge()  //特判：00000123前导0超过一半的情况；
{
  n--;
  int i, j;
  for (i = 1; i <= n && str[i] == '0'; i++)
    ;
  if (i <= n / 2 + 1) return false;
  ansp = i;
  if (i > n) {
    minf[0] = '1';
    for (j = 1; j <= n; j++) minf[j] = '0';
    minf[j] = '\0';
  } else {
    for (j = 0; i + j <= n; j++) minf[j] = str[i + j];
    for (; j < n; j++) minf[j] = '0';
    minf[j] = '\0';
  }
  return true;
}
int main() {
  int t = 0;
  str[0] = '0';
  while (~scanf("%s", str + 1)) {
    n = strlen(str);
    if (!special_Judge()) find_FirstNumber();
    solve();
    printf("%s\n", ans);
  }
  return 0;
}
