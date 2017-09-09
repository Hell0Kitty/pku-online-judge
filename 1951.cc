#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

char st[100];
bool vis[300];

int main() {
  bool first = true;
  memset(vis, 0, sizeof(vis));
  vis['A'] = true;
  vis['E'] = true;
  vis['I'] = true;
  vis['O'] = true;
  vis['U'] = true;
  while (scanf("%s", st) != EOF) {
    int len = strlen(st);
    bool did = false;
    for (int i = 0; i < len; i++)
      if (!vis[st[i]]) {
        if (st[i] <= 'Z' && st[i] >= 'A') vis[st[i]] = true;
        if (!did) {
          did = true;
          if (st[i] <= 'Z' && st[i] >= 'A') {
            if (first)
              first = false;
            else
              putchar(' ');
          }
        }
        putchar(st[i]);
      }
  }
  putchar('\n');
  return 0;
}
