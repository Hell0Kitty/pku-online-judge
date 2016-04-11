#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> Number;
string Target = "Sorcerer's Stone", Now;
char str[10005];
int n, m, i, j, k, x, tot, MagicStone, l[16];
int tag, Loop, Ans;
int Need[10005], Exist[10005];
vector<int> V[10005];

void dfs(int i);

int main() {
  while (1) {
    scanf("%d %d", &n, &m), gets(str);
    if (n == 0 && m == 0) break;
    Number.clear();
    tot = 1, Exist[1] = 0, V[1].clear();
    Number[Target] = 1;
    for (i = 1; i <= n; i++) {
      gets(str);
      Now = str;
      x = Number[Now];
      if (x == 0) x = Number[Now] = ++tot, V[tot].clear();
      Exist[x] = 1;
    }

    for (i = 1; i <= m; i++) {
      gets(str);
      l[0] = j = 0;
      while (str[j] != 0) {
        Now = "";
        for (k = j; str[k] != ',' && str[k] != ':' && str[k] != 0; k++)
          Now += str[k];
        if (str[k] == 0) {
          MagicStone = Number[Now];
          if (MagicStone == 0)
            MagicStone = Number[Now] = ++tot, V[tot].clear(), Exist[tot] = 0;
          j = k;
        }

        else {
          l[++l[0]] = Number[Now];
          if (l[l[0]] == 0)
            l[l[0]] = Number[Now] = ++tot, V[tot].clear(), Exist[tot] = 0;
          j = k + 2;
        }
      }

      for (j = 1; j <= l[0]; j++) V[MagicStone].push_back(l[j]);
    }

    if (Exist[1] == 1) {
      printf("0\n");
      continue;
    }

    tag++, Loop = Ans = 0;
    dfs(1);
    if (Loop == 1)
      printf("-1\n");
    else
      printf("%d\n", Ans);
  }

  return 0;
}

void dfs(int i) {
  if (Loop == 1) return;
  vector<int>::iterator it;
  int Now;
  if (V[i].empty()) Loop = 1;
  Need[i] = tag;
  for (it = V[i].begin(); it != V[i].end(); ++it) {
    Now = (*it);
    if (Exist[Now] == 1) continue;
    if (Need[Now] == tag) {
      Loop = 1;
      return;
    }

    dfs(Now);
  }

  Exist[i] = 1, Ans++;
  return;
}
