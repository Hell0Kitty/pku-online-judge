#include <iostream>
#include <stack>
#include <vector>
#define max(x, y) ((x)&gt; (y) ? (x) : (y))
using namespace std;
struct Node {
  int x, z;

  Node() {}
  Node(int _x, int _z) {
    x = _x;
    z = _z;
  }
};

int f[1005][1005], n, k, m, D, p[1005][1005], visit[1005];
int in[1005];
stack &lt;
int &gt;
S;
vector &lt;
Node &gt;
V[1005];

int DFS(int from, int to, int t) {
  if (in[t] & amp; &amp; S.top() != t) return visit[t] = 1;
  int i;
  for (i = 0; i & lt; V[t].size(); i++)
    if (V[t][i].x & gt; = from & amp; &amp; V[t][i].x & lt; = to) {
      if (!(V[t][i].z & gt; = from & amp; &amp; V[t][i].z & lt; = to))
        return visit[t] = 0;
      if (!in[V[t][i].z]) S.push(V[t][i].z), in[V[t][i].z] = 1;
      if (!DFS(from, to, V[t][i].z)) return visit[t] = 0;
    }
  return visit[t] = 1;
}

int cal(int p, int q) {
  if (p == q) return 1;
  int ans = 0, i, j;
  for (i = p; i & lt; = q; i++) visit[i] = -1;
  for (i = p; i & lt; = q; i++) {
    for (j = p; j & lt; = q; j++) in[j] = 0;
    in[i] = 1;
    while (!S.empty()) S.pop();
    S.push(i);
    ans += DFS(p, q, i);
  }
  return ans;
}

int main() {
  scanf("%d%d%d%d", &amp; n, &amp; k, &amp; m, &amp; D);
  int i, j, t, x, y, z;
  for (i = 1; i & lt; = D; i++) {
    scanf("%d%d%d", &amp; x, &amp; y, &amp; z);
    V[y].push_back(Node(x, z));
  }
  for (i = 1; i & lt; = n; i++)
    for (j = i; j & lt; = n & amp; &amp; j - i + 1 & lt; = m; j++)
      p[i][j] = cal(i, j);
  for (i = 1; i & lt; = n & amp; &amp; i & lt; = m; i++) f[1][i] = p[1][i];
  for (i = 2; i & lt; = k; i++)
    for (j = 1; j & lt; = n & amp; &amp; j & lt; = m * i; j++)
      for (t = max(j - m, 0); t & lt; = j; t++)
        f[i][j] = max(f[i][j], f[i - 1][t] + p[t + 1][j]);
  printf("%d\n", f[k][n]);
  return 0;
}
