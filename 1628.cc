#include <iostream>
using namespace std;
struct Node {
  char s1[200], s2[200];
} decl[250];
bool more, ur[128], visit[250];
int n, m, l, k;
char s[200], res[200];
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++) scanf("%s => %s", &decl[i].s1, &decl[i].s2);
    for (int i = 0; i < m; i++) {
      scanf("%s", &s);
      l = strlen(s);
      memset(ur, false, sizeof(ur));
      for (int j = 0; j < l; j++) ur[s[j]] = true;
      more = true;
      memset(visit, false, sizeof(visit));
      while (more) {
        more = false;
        for (int j = 0; j < n; j++) {
          if (visit[j]) continue;
          l = strlen(decl[j].s1);
          for (k = 0; k < l; k++)
            if (!ur[decl[j].s1[k]]) break;
          if (k == l) {
            visit[j] = true;
            more = true;
            l = strlen(decl[j].s2);
            for (k = 0; k < l; k++) ur[decl[j].s2[k]] = true;
          }
        }
      }
      for (char c = 'a'; c <= 'z'; c++)
        if (ur[c]) printf("%c", c);
      for (char c = 'A'; c <= 'Z'; c++)
        if (ur[c]) printf("%c", c);
      puts("");
    }
  }
  return 0;
}
