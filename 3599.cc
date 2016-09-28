#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct Edge {
  int t;
  char c;
  Edge *ne;
  void clear(int tt, char cc, Edge *&nee) {
    t = tt;
    c = cc;
    ne = nee;
    nee = this;
  }
};

string startx[1001];
string endz[1001];
bool st[1001] = {0};
bool fin[1001] = {0};
Edge b[52000], *bp;
Edge *fe[1001] = {0};
Edge *rfe[1001] = {0};
int from[1001];
char cf[1001];
int que[1001];
int n, s, p, q;
char str[1001];

void bfs(Edge **fe, bool opt = true) {
  int i;
  for (i = 0; i <= n; i++) from[i] = -1;
  if (opt)
    for (i = p; i < q; i++) from[que[i]] = -2;
  while (p != q) {
    i = que[p++];
    for (Edge *j = fe[i]; j; j = j->ne) {
      int t = j->t;
      if (from[t] == -1) {
        from[t] = i;
        cf[t] = j->c;
        que[q++] = t;
      }
    }
  }
}
string getS(int j, bool opt = true) {
  int ss = 0;
  while (from[j] != -2) {
    str[ss++] = cf[j];
    j = from[j];
  }
  if (opt) {
    for (int i = 0; i + i < ss; i++) {
      char c = str[i];
      str[i] = str[ss - i - 1];
      str[ss - i - 1] = c;
    }
  }
  str[ss] = '\0';
  return string(str);
}
string getY(int j) {
  int ss = 0, f = j;
  do {
    str[ss++] = cf[j];
    j = from[j];
  } while (j != f);
  for (int i = 0; i + i < ss; i++) {
    char c = str[i];
    str[i] = str[ss - i - 1];
    str[ss - i - 1] = c;
  }
  str[ss] = '\0';
  return string(str);
}
bool canFindAns() {
  for (int i = 0; i <= n; i++) {
    if (st[i] && fin[i]) {
      p = q = 0;
      que[q++] = i;
      bfs(fe, false);
      if (from[i] != -1) {
        printf("%s(%s)%s\n", startx[i].c_str(), getY(i).c_str(),
               endz[i].c_str());
        return true;
      }
    }
  }
  return false;
}
void calEndZ() {
  p = q = 0;
  for (int i = 0; i <= n; i++)
    if (fin[i]) que[q++] = i;
  bfs(rfe);
  for (int i = 0; i <= n; i++) {
    if (from[i] != -1) {
      fin[i] = true;
      endz[i] = getS(i, false);
    }
  }
}
void calStartX() {
  p = q = 0;
  que[q++] = s;
  bfs(fe);
  for (int i = 0; i <= n; i++) {
    if (from[i] != -1) {
      st[i] = true;
      startx[i] = getS(i);
    }
  }
}

int main() {
  int i, m, k;
  scanf("%d%d", &n, &s);
  scanf("%d", &m);
  bp = b;
  for (i = 0; i < m; i++) {
    int x, y;
    char c;
    scanf("%d %c%d", &x, &c, &y);
    (bp++)->clear(y, c, fe[x]);
    (bp++)->clear(x, c, rfe[y]);
  }
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    fin[x] = true;
  }
  st[s] = true;
  calStartX();
  calEndZ();
  if (!canFindAns()) printf("*\n");
  return 0;
}
