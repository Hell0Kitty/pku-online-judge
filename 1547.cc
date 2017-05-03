#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 15

struct Student {
  int v;
  char name[10];
} stu[maxn];

int n;

bool operator<(const Student &a, const Student &b) { return a.v < b.v; }

void input() {
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    stu[i].v = a * b * c;
    scanf("%s", stu[i].name);
  }
}

int main() {
  while (scanf("%d", &n), ~n) {
    input();
    sort(stu, stu + n);
    printf("%s took clay from %s.\n", stu[n - 1].name, stu[0].name);
  }
  return 0;
}
