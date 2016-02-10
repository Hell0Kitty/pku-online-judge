nclude<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
    using namespace std;

#define maxn 20
#define maxl 30

struct Person {
  int id, x;
} person[maxn];

char st[30];
char name[maxn][maxl];
int n;

bool operator<(const Person &a, const Person &b) { return a.x > b.x; }

void input() {
  n = 0;
  while (scanf("%s", name[n]), strcmp(name[n], "END") != 0) {
    int a, b;
    scanf("%d%d", &a, &b);
    person[n].id = n;
    person[n].x = b - a;
    n++;
  }
}

void work() {
  printf("%s\n", name[person[0].id]);
  for (int i = 1; i < n; i++) printf("%s\n", name[person[i].id]);
}

int main() {
  bool first = true;
  while (scanf("%s", st) != EOF) {
    if (!first)
      putchar('\n');
    else
      first = false;
    input();
    sort(person, person + n);
    work();
  }
  return 0;
}
