#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
  char s[600];
  int len;
  bool operator<(const node& a) const {
    if (len != a.len) return len < a.len;
    for (int i = 0; i < len; i++)
      if (s[i] != a.s[i]) return s[i] < a.s[i];
    return 0;
  }
};

char s[600];
int n;
node f[600], now;

void maxconvert(int x, int y, node z) {
  int i, j;
  if (y + 2 < n && y - x + 1 > z.len) return;
  node tmp;
  tmp.len = 0;
  if (y + 2 >= n || y - x + 1 < z.len) {
    for (i = x; i <= y; i++) {
      tmp.s[tmp.len++] = s[i] == '?' ? '9' : s[i];
    }
    if (tmp.s[0] != '0') f[x] = tmp;
    return;
  }
  int id = -1;
  for (i = x; i <= y; i++)
    if (s[i] != z.s[i - x]) {
      if (s[i] != '?' && s[i] > z.s[i - x]) {
        if (id != -1) break;
        return;
      }
      if (s[i] == '?' && z.s[i - x] == '0') continue;
      if (s[i] == '?' && z.s[i - x] == '1' && i == x) continue;
      id = i;
      if (s[i] != '?' && s[i] < z.s[i - x]) break;
    }
  if (id == -1) return;
  i = id;
  for (j = x; j < i; j++) {
    tmp.s[tmp.len++] = z.s[j - x];
  }

  if (s[i] == '?')
    tmp.s[tmp.len++] = z.s[i - x] - 1;
  else
    tmp.s[tmp.len++] = s[i];

  for (j = i + 1; j <= y; j++) {
    tmp.s[tmp.len++] = s[j] == '?' ? '9' : s[j];
  }
  if (tmp.s[0] != '0') f[x] = tmp;
}

bool minconvert(int x, int y, node z) {
  int i, j;
  if (y - x + 1 < now.len) return false;
  node tmp;
  tmp.len = 0;
  if (y - x + 1 > now.len) {
    tmp.s[tmp.len++] = s[x] == '?' ? '1' : s[x];
    for (i = x + 1; i <= y; i++) {
      tmp.s[tmp.len++] = s[i] == '?' ? '0' : s[i];
    }
    if (tmp.s[0] != '0' && (y + 1 >= n || tmp < z)) {
      for (i = x; i <= y; i++) {
        s[i] = tmp.s[i - x];
      }
      now = tmp;
      return true;
    }
    return false;
  }
  int id = -1;
  for (i = x; i <= y; i++)
    if (now.s[i - x] != s[i]) {
      if (s[i] != '?' && s[i] < now.s[i - x]) {
        if (id != -1) break;
        return false;
      }
      if (s[i] == '?' && now.s[i - x] == '9') continue;
      id = i;
      if (s[i] != '?' && s[i] > now.s[i - x]) break;
    }
  if (id == -1) return false;

  i = id;
  for (j = x; j < i; j++) {
    tmp.s[tmp.len++] = now.s[j - x];
  }
  if (s[i] == '?')
    tmp.s[tmp.len++] = now.s[i - x] + 1;
  else
    tmp.s[tmp.len++] = s[i];

  for (j = i + 1; j <= y; j++) tmp.s[tmp.len++] = s[j] == '?' ? '0' : s[j];
  if (tmp.s[0] != '0' && (y + 1 >= n || tmp < z)) {
    for (i = x; i <= y; i++) s[i] = tmp.s[i - x];
    now = tmp;
    return true;
  }
  return false;
}

int main() {
  int i, j;
  while (scanf("%s", s) != EOF) {
    n = strlen(s);
    for (i = 0; i <= n + 10; i++) f[i].len = 0;
    for (i = n - 1; i >= 0; i--)
      if (s[i] != ',') {
        for (j = i; j < n; j++)
          if (j + 1 >= n || s[j + 1] == ',' ||
              (s[j + 1] == '?' && j + 2 < n && s[j + 2] != ',')) {
            maxconvert(i, j, f[j + 2]);
            if (s[j + 1] == ',') break;
          }
      }

    now.len = 0;
    int x = 0;
    bool fid = 1;
    for (i = 0; i < n; i++) {
      if (s[i] == ',') continue;
      int j;
      bool succ = false;
      for (j = i; j < n; j++)
        if (j + 1 >= n || s[j + 1] == ',' ||
            (s[j + 1] == '?' && j + 2 < n && s[j + 2] != ',')) {
          if (minconvert(i, j, f[j + 2])) {
            succ = true;
            if (s[j + 1] == '?') s[j + 1] = ',';
            i = j;
            break;
          }
          if (s[j + 1] == ',') break;
        }
      if (!succ) {
        fid = 0;
        break;
      }
    }
    now.len = 0;
    for (i = 0; i < n; i++)
      if (s[i] != ',') {
        if (s[i] == '?') {
          fid = 0;
          break;
        }
        node tmp;
        tmp.len = 0;
        for (j = i; j < n; j++) {
          if (s[j] == ',' || s[j] == '?') break;
          tmp.s[tmp.len++] = s[j];
        }
        if (!(now < tmp)) fid = 0;
        now = tmp;
        i = j - 1;
      }
    if (!fid)
      printf("impossible\n");
    else
      printf("%s\n", s);
  }
  return 0;
}
