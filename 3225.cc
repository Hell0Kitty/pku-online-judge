#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
const int maxn = 66000 * 2;
const int N = maxn * 4;
struct Line {
  int left, right;
  int tag;
  bool rev;
} line[N];
void build(int now, int left, int right) {
  line[now].left = left;
  line[now].right = right;
  line[now].tag = 0;
  line[now].rev = false;
  if (left == right) return;
  int mid = (left + right) >> 1;
  build(now * 2, left, mid);
  build(now * 2 + 1, mid + 1, right);
}
void pushdown(int now) {
  if (line[now].left == line[now].right) {
    if (line[now].rev) {
      line[now].tag ^= 1;
      line[now].rev = false;
    }
    return;
  }
  if (line[now].tag != -1) {
    if (line[now].rev) line[now].tag ^= 1;
    line[now * 2].tag = line[now * 2 + 1].tag = line[now].tag;
    line[now].tag = -1;
    line[now].rev = line[now * 2].rev = line[now * 2 + 1].rev = false;
  }
  if (line[now].rev) {
    line[now].rev = false;
    if (line[now * 2].tag == -1)
      line[now * 2].rev ^= true;
    else
      line[now * 2].tag ^= 1;
    if (line[now * 2 + 1].tag == -1)
      line[now * 2 + 1].rev ^= true;
    else
      line[now * 2 + 1].tag ^= 1;
  }
}
void solve(int now, int left, int right, int op) {
  if (left > right) return;
  int ll = line[now].left, rr = line[now].right;
  if (ll == left && rr == right) {
    if (op < 2) {
      line[now].rev = false;
      line[now].tag = op;
    } else if (line[now].tag != -1) {
      line[now].tag ^= 1;
    } else {
      line[now].rev ^= 1;
    }
    return;
  }
  int mid = (ll + rr) >> 1;
  pushdown(now);
  if (mid < left) {
    solve(now * 2 + 1, left, right, op);
  } else if (right <= mid) {
    solve(now * 2, left, right, op);
  } else {
    solve(now * 2, left, mid, op);
    solve(now * 2 + 1, mid + 1, right, op);
  }
}
bool vis[N];
void findinter(int now) {
  if (line[now].tag != -1) {
    if (line[now].tag == 1) {
      int ll = line[now].left, rr = line[now].right;
      for (int i = ll; i <= rr; i++) vis[i] = true;
    }
    return;
  }
  pushdown(now);
  findinter(now * 2);
  findinter(now * 2 + 1);
}
int main() {
  build(1, 0, maxn);
  char s[100];
  while (gets(s)) {
    int len = strlen(s), i, op, a = 0, b = 0;
    for (i = 3; i < len; i++) {
      if (!isdigit(s[i])) break;
      a = a * 10 + s[i] - '0';
    }
    for (i++; i < len; i++) {
      if (!isdigit(s[i])) break;
      b = b * 10 + s[i] - '0';
    }
    if (s[i] == ']')
      b = b * 2;
    else
      b = b * 2 - 1;
    if (s[2] == '[')
      a = a * 2;
    else
      a = a * 2 + 1;
    switch (s[0]) {
      case 'U':
        solve(1, a, b, 1);
        break;
      case 'I':
        solve(1, 0, a - 1, 0);
        solve(1, b + 1, maxn, 0);
        break;
      case 'D':
        solve(1, a, b, 0);
        break;
      case 'C':
        solve(1, 0, a - 1, 0);
        solve(1, b + 1, maxn, 0);
        solve(1, a, b, 2);
        break;
      case 'S':
        solve(1, a, b, 2);
        break;
    }
  }
  memset(vis, false, sizeof(vis));
  findinter(1);
  bool first = true;
  for (int i = 0; i <= maxn; i++) {
    if (!vis[i]) continue;
    int a = i, b;
    while (vis[i] && i <= maxn) i++;
    b = --i;
    if (first)
      first = false;
    else
      printf(" ");
    if (a & 1)
      printf("(%d,", a / 2);
    else
      printf("[%d,", a / 2);
    if (b & 1)
      printf("%d)", (b + 1) / 2);
    else
      printf("%d]", b / 2);
  }
  if (first) printf("empty set");
  printf("\n");
  return 0;
}
