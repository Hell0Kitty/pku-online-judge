#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N = 50005;
struct Treap_Node {
  int left, right;
  int value, pri, id;
} Tnode[N];
int ans[N][3];
void dfs(int now) {
  if (now == -1) return;
  int id = Tnode[now].id, ll = Tnode[now].left, rr = Tnode[now].right;
  if (ll != -1) {
    ans[id][1] = Tnode[ll].id;
    ans[Tnode[ll].id][0] = id;
    dfs(ll);
  }
  if (rr != -1) {
    ans[id][2] = Tnode[rr].id;
    ans[Tnode[rr].id][0] = id;
    dfs(rr);
  }
}
struct data {
  int v, p, id;
  bool operator<(const data &ne) const { return v < ne.v; }
} po[N];
int stk[N], top;
int main() {
  int n;
  scanf("%d", &n);
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &po[i].v, &po[i].p);
    po[i].id = i;
  }
  sort(po + 1, po + n + 1);
  Tnode[0].left = Tnode[0].right = -1;
  Tnode[0].pri = -10000000;
  top = 1;
  stk[0] = 0;
  for (int i = 1; i <= n; i++) {
    int v = po[i].v, p = po[i].p, d = po[i].id;
    while (top > 0 && Tnode[stk[top - 1]].pri > p) top--;
    Tnode[i].left = Tnode[stk[top - 1]].right;
    Tnode[stk[top - 1]].right = i;
    Tnode[i].right = -1;
    Tnode[i].value = v;
    Tnode[i].pri = p;
    Tnode[i].id = d;
    stk[top++] = i;
  }
  dfs(0);
  printf("YES\n");
  for (int i = 1; i <= n; i++)
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  return 0;
}
