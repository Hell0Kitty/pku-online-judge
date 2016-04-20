#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 105;

class Disjoint_Set {
 public:
  int father[MAX];
  int rank[MAX];

  void Init(int n) {
    for (int i = 0; i <= n; i++) Make_Set(i);
  }

  void Make_Set(int x) {
    father[x] = x;
    rank[x] = 1;
  }

  int Find_Set(int x) {
    if (x != father[x]) father[x] = Find_Set(father[x]);
    return father[x];
  }

  bool Union(int x, int y) {
    int a = Find_Set(x);
    int b = Find_Set(y);
    if (a == b) return false;
    if (rank[a] >= rank[b]) {
      father[b] = a;
      rank[a] += rank[b];
    } else {
      father[a] = b;
      rank[b] += rank[a];
    }
    return true;
  }
} ob;

vector<int> graphs[MAX];
int predeg[MAX];
int degree[MAX];
int n, m;

bool Deal() {
  int i;
  for (i = 1; i <= n; i++)
    if (predeg[i] == 1)
      for (int j = 0; j < graphs[i].size(); j++) degree[graphs[i][j]]--;

  int cnt = 0;
  for (i = 1; i <= n; i++)
    if (predeg[i] > 1 && degree[i] == 1) cnt++;
  if (cnt > 2) return false;
  return true;
}

int main() {
  int Cas = 1;
  while (~scanf("%d%d", &n, &m), n) {
    ob.Init(MAX);
    memset(predeg, 0, sizeof(predeg));
    memset(degree, 0, sizeof(degree));
    int cnt = 0;
    bool flag = true;
    if (n != m + 1) flag = false;
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      predeg[a]++, degree[a]++;
      predeg[b]++, degree[b]++;
      graphs[a].push_back(b);
      graphs[b].push_back(a);
      if (ob.Union(a, b) == false) flag = false;
    }
    if (flag) {
      if (Deal())
        printf("Graph %d is a caterpillar.\n", Cas++);
      else
        printf("Graph %d is not a caterpillar.\n", Cas++);
    } else
      printf("Graph %d is not a caterpillar.\n", Cas++);
  }
  return 0;
}
