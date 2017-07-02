#include <stdio.h>

#include <string.h>

#include <vector>

#include <map>

#define N 205

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

map<int, int> hash;

vector<int> gra[N], am, cm, tm;

int vis[N], dp[N][2], n, m;

void dfs(int s)

{
  vis[s] = 1;

  for (int i = 0; i < gra[s].size(); i++)

  {
    int t = gra[s][i];

    if (vis[t]) continue;

    dfs(t);

    dp[s][0] += MAX(dp[t][0], dp[t][1]);

    dp[s][1] += dp[t][0];
  }

  dp[s][1] += am[s];
}

void re(void)

{
  int a;

  hash.clear();

  for (int i = 0; i <= n; i++) gra[i].clear();

  am.clear();
  cm.clear();

  for (int i = 1; i <= n; i++)

  {
    scanf("%d", &a);

    hash[a] = i - 1;

    am.push_back(a);
  }

  for (int i = 1; i <= m; i++) scanf("%d", &a), cm.push_back(a);
}

void run(void)

{
  for (int i = 0; i < am.size(); i++)

    for (int j = 0; j < cm.size(); j++)

    {
      int a = am[i], c = cm[j];

      if (hash.count(a + c)) gra[hash[a]].push_back(hash[a + c]);

      if (hash.count(a - c)) gra[hash[a]].push_back(hash[a - c]);
    }

  memset(vis, 0, sizeof(vis));

  memset(dp, 0, sizeof(dp));

  int ans = 0;

  for (int i = 0; i < am.size(); i++)

  {
    int s = hash[am[i]];

    if (vis[s] != 0) continue;

    dfs(s);

    ans += MAX(dp[s][0], dp[s][1]);
  }

  printf("%d\n", ans);
}

int main()

{
  while (scanf("%d%d", &n, &m), n + m)

  {
    re();

    run();
  }
}