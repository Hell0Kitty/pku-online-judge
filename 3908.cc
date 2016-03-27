#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 2000000
int id[10005], p[N];
int n, num;
void init() {
  for (int i = 1; i <= n; i++) p[i] = i, id[i] = i;
}
int find(int k) {
  if (p[k] == k) return k;
  int t = find(p[k]);
  p[k] = t;
  return t;
}
void U(int k1, int k2) { p[k2] = k1; }
int main() {
  while (scanf("%d", &n) != EOF) {
    init();
    num = n;
    char t;
    int yes = 0, no = 0, a, b;
    while (1) {
      cin >> t;
      if (t == 'e')
        break;
      else if (t == 'c') {
        scanf("%d%d", &a, &b);
        int k1 = find(id[a]), k2 = find(id[b]);
        if (k1 != k2) U(k1, k2);
      } else if (t == 'q') {
        scanf("%d%d", &a, &b);
        int k1 = find(id[a]), k2 = find(id[b]);
        if (k1 == k2)
          yes++;
        else
          no++;
      } else {
        scanf("%d", &a);
        id[a] = ++num;
        p[id[a]] = id[a];
      }
    }
    printf("%d , %d\n", yes, no);
  }
  return 0;
}
