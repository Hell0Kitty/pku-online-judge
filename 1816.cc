
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int N = 100005;
struct node {
  char ch;
  int next[30];
  void init(char _ch) {
    ch = _ch;
    memset(next, -1, sizeof(next));
  }
} tr[N * 10];
int cnt, head[N], nc;
bool mark[N];
struct Edge {
  int to, next;
} edge[N * 2];
void add(int a, int b) {
  edge[nc].to = b;
  edge[nc].next = head[a];
  head[a] = nc++;
}
inline int change(char x) {
  if (x == '?')
    return 26;
  else if (x == '*')
    return 27;
  else
    return x - 'a';
}
void insert(char s[], int id) {
  int i, p;
  for (i = 0, p = 0; s[i] != '\0'; i++) {
    int pt = change(s[i]);
    if (tr[p].next[pt] == -1) {
      tr[p].next[pt] = cnt;
      p = cnt++;
      tr[p].init(s[i]);
    } else
      p = tr[p].next[pt];
  }
  add(p, id);
}
bool flag;
void dfs(char s[], int p) {
  if (s[0] == '\0') {
    for (int i = head[p]; i != -1; i = edge[i].next)
      flag = mark[edge[i].to] = true;
    if (tr[p].next[27] != -1) dfs(s, tr[p].next[27]);
    return;
  }
  int pt = change(s[0]);
  if (tr[p].next[pt] != -1) dfs(s + 1, tr[p].next[pt]);
  if (tr[p].next[26] != -1) dfs(s + 1, tr[p].next[26]);
  if (tr[p].next[27] != -1) dfs(s + 1, tr[p].next[27]), dfs(s, tr[p].next[27]);
  if (tr[p].ch == '*') dfs(s + 1, p);
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    tr[0].init('$');
    cnt = 1;
    memset(head, -1, sizeof(head));
    nc = 0;
    for (int i = 0; i < n; i++) {
      char s[30];
      scanf("%s", s);
      insert(s, i);
    }
    while (m--) {
      char s[30];
      scanf("%s", s);
      flag = false;
      memset(mark, false, sizeof(mark));
      dfs(s, 0);
      if (!flag) {
        printf("Not match\n");
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (mark[i]) {
          if (flag)
            flag = false;
          else
            printf(" ");
          printf("%d", i);
        }
      }
      printf("\n");
    }
  }
  return 0;
}
