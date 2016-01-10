#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int MaxLen = 2010000;
char str[MaxLen];
int N, A, B, Len, cnt;
int Arr[100000];
typedef struct re { int num, len, time; } re;
bool operator<(const re& a, const re& b) {
  if (a.time > b.time) return true;
  if (a.time == b.time) {
    if (a.len > b.len)
      return true;
    else if (a.len == b.len) {
      if (a.num > b.num)
        return true;
      else
        return false;
    } else
      return false;
  } else
    return false;
}
re R[100000];
int input() {
  scanf("%d%d", &A, &B);
  scanf("%d", &N);
  getchar();
  char tmp;
  int i = 0;
  while (tmp = getchar()) {
    if (tmp == '2')
      break;
    else
      str[i++] = tmp;
  }
  return i;
}
int Insert(char* s, int len) {
  int i = 1;
  for (int j = 0; j < len; ++j) {
    if (s[j] == '0')
      i <<= 1;
    else
      i = (i << 1) + 1;
  }
  ++Arr[i];
}
void work() {
  for (int i = A; i <= B; ++i)
    for (int j = 0; j <= Len - i; ++j) Insert(str + j, i);
}
void print(int num, int len) {
  char tmp[20];
  int t = 0;
  while (t < len) {
    if (num & 1)
      tmp[len - t - 1] = '1';
    else
      tmp[len - t - 1] = '0';
    ++t;
    num >>= 1;
  }
  for (int i = 0; i < len; ++i) putchar(tmp[i]);
  putchar(' ');
}
void calc() {
  int down = (1 << A);
  int up = (1 << (B + 1));
  for (int len = A; len <= B; ++len) {
    for (int i = (1 << len); i < (1 << (len + 1)); ++i) {
      if (Arr[i] != 0) {
        R[cnt].num = i;
        R[cnt].len = len;
        R[cnt].time = Arr[i];
        ++cnt;
      }
    }
  }
}
int main() {
  Len = input();
  work();
  calc();
  sort(R, R + cnt);
  int ccc = 0;
  int i = 0;
  while (i < cnt && ccc < N) {
    int ttt = R[i].time;
    printf("%d ", R[i].time);
    while (R[i].time == ttt) {
      print(R[i].num, R[i].len);
      ++i;
    }
    putchar('\n');
    ++ccc;
  }
  return 0;
}
