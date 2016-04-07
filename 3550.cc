#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

int len;
int next(int state, char c);
char wd[1000];
bool spc(char c) { return c == '&' || c == '#' || c == '@'; }
void output(int s, int t) {
  int i;
  for (i = s; i < t; ++i) putchar(wd[i]);
  putchar('\n');
}

int main() {
  int i, j, k, pre, state = 0;
  scanf("%s", wd + 1);
  len = strlen(wd + 1);
  if (len == 2) {
    puts("");
    return 0;
  }
  pre = 3;
  state = 2;
  for (i = 3; i <= len + 1; ++i) {
    state = next(state, wd[i]);
    if (state == 2) {
      state = next(state, wd[i]);
      output(pre, i);
      pre = i;
    }
  }
  return 0;
}

int next(int state, char c) {
  if (c == 0) return 2;
  if (state == 0) {
    if (c == 'A') return 1;
  }
  if (state == 1) {
    if (c == 'T') return 1;
  }
  if (state == 2) {
    if (isupper(c)) return 3;
    if (spc(c)) return 4;
  }
  if (state == 3) {
    if (isupper(c)) return 5;
    if (spc(c)) return 2;
    if (isdigit(c)) return 6;
    if (c == '=') return 7;
  }
  if (state == 4) {
    return 5;
  }
  if (state == 5) {
    if (isupper(c) || spc(c)) return 2;
    if (isdigit(c)) return 6;
    if (c == '=') return 7;
  }
  if (state == 6) {
    if (isdigit(c)) return 6;
    if (c == '=') return 7;
    return 2;
  }
  if (state == 7) {
    if (isdigit(c)) return 7;
    return 2;
  }
}
