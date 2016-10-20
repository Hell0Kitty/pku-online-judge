#include <iostream>

#include <string.h>

#include <vector>

#include <stack>

using namespace std;

vector<int> map[101];

stack<int> S;

int low[101], pre[101], post[101], indegree[101], outdegree[101], ss[101], cnt,
    time, in, out;

int tarjan(int s)

{
  int i, k, e;

  pre[s] = cnt++;
  low[s] = pre[s];

  post[s] = 1;
  S.push(s);

  for (i = 0; i < map[s].size(); i++)

  {
    k = map[s][i];

    if (!pre[k])

    {
      tarjan(k);

      low[s] = (low[s] < low[k]) ? low[s] : low[k];

    }

    else if (post[k] && low[s] > pre[k])

    {
      low[s] = pre[k];
    }
  }

  if (pre[s] == low[s])

  {
    time++;

    for (e = S.top(), S.pop(); e != s; e = S.top(), S.pop())

    {
      ss[e] = time;
      post[e] = 0;
    }

    ss[e] = time;
    post[e] = 0;
  }

  return 0;
}

int solve(int n)

{
  int i, j, k;

  if (time == 1)

  {
    in = 1;
    return 0;
  }

  memset(indegree, 0, sizeof(indegree));

  memset(outdegree, 0, sizeof(outdegree));

  for (i = 1; i <= n; i++)

    for (j = 0; j < map[i].size(); j++)

    {
      k = map[i][j];

      if (ss[i] != ss[k])

      {
        indegree[ss[k]]++;
        outdegree[ss[i]]++;
      }
    }

  for (out = in = 0, i = 1; i <= time; i++)

  {
    if (indegree[i] == 0) in++;

    if (outdegree[i] == 0) out++;
  }

  return in > out ? in : out;
}

int main()

{
  int i, m, n, k;

  while (cin >> n)

  {
    for (i = 1; i <= n; i++)

      while (cin >> m && m)

        if (m != i) map[i].push_back(m);

    memset(low, 0, sizeof(low));

    memset(pre, 0, sizeof(pre));

    memset(post, 0, sizeof(post));

    memset(ss, 0, sizeof(ss));

    for (cnt = 1, time = 0, i = 1; i <= n; i++)

      if (!pre[i]) tarjan(i);

    k = solve(n);

    cout << in << endl
         << k << endl;

    for (i = 0; i <= n; i++) map[i].clear();
  }

  return 0;
}
