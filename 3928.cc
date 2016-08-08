#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

#define MAXN 22000

int n;
int c[MAXN];

int lowbit(int t) { return t & (-t); }

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += c[i];
    i -= lowbit(i);
  }
  return s;
}

void modify(int i, int x) {
  while (i <= n) {
    c[i] += x;
    i += lowbit(i);
  }
}

struct node {
  int id, level;
} data[MAXN];

long long ans;
bool cmp(node a, node b) { return a.level < b.level; }

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &data[i].level);
      data[i].id = i;
    }
    sort(data + 1, data + 1 + n, cmp);
    memset(c, 0, sizeof(c));
    ans = 0;
    long long l, r;
    for (int i = 1; i <= n; i++) {
      l = sum(data[i].id);
      r = sum(n) - l;
      ans += (l * (n - data[i].id - r) + r * (data[i].id - 1 - l));
      modify(data[i].id, 1);
    }
    cout << ans << endl;
  }
  return 0;
}
