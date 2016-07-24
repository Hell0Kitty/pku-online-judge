#include <iostream>

#include <cstdio>

#include <cstring>

#include <queue>

using namespace std;

#define MAX_INT 1234567890

struct node

    {
  int v;

  int value;

  int next;
};

node edge1[1000001], edge2[1000001];

int head1[1000001], head2[1000001], dist[1000001], visit[1000001];

queue<int> Q;

int spfa1(int n)

{
  int i, j, e;

  for (i = 1; i <= n; i++) dist[i] = MAX_INT;

  memset(visit, 0, sizeof(visit));

  Q.push(1);

  visit[1] = 1;
  dist[1] = 0;

  while (!Q.empty())

  {
    e = Q.front(), Q.pop();
    visit[e] = 0;

    for (j = head1[e]; j; j = edge1[j].next)

      if (dist[edge1[j].v] > dist[e] + edge1[j].value)

      {
        dist[edge1[j].v] = dist[e] + edge1[j].value;

        if (!visit[edge1[j].v])

        {
          Q.push(edge1[j].v);

          visit[edge1[j].v] = 1;
        }
      }
  }

  return 0;
}

int spfa2(int n)

{
  int i, j, e;

  for (i = 1; i <= n; i++) dist[i] = MAX_INT;

  memset(visit, 0, sizeof(visit));

  Q.push(1);

  visit[1] = 1;
  dist[1] = 0;

  while (!Q.empty())

  {
    e = Q.front(), Q.pop();
    visit[e] = 0;

    for (j = head2[e]; j; j = edge2[j].next)

      if (dist[edge2[j].v] > dist[e] + edge2[j].value)

      {
        dist[edge2[j].v] = dist[e] + edge2[j].value;

        if (!visit[edge2[j].v])

        {
          Q.push(edge2[j].v);

          visit[edge2[j].v] = 1;
        }
      }
  }

  return 0;
}

int main()

{
  int i, k, m, n, s, t, N, cost;

  __int64 sum;

  cin >> m;

  while (m--)

  {
    scanf("%d%d", &n, &k);

    memset(head1, 0, sizeof(head1));

    memset(head2, 0, sizeof(head2));

    for (N = 1, i = 0; i < k; i++)

    {
      scanf("%d%d%d", &s, &t, &cost);

      node e = {t, cost, 0};

      edge1[N] = e;

      edge1[N].next = head1[s];

      head1[s] = N;

      e.v = s;

      edge2[N] = e;

      edge2[N].next = head2[t];

      head2[t] = N;

      N++;
    }

    sum = 0;

    spfa1(n);

    for (i = 1; i <= n; i++) sum += dist[i];

    spfa2(n);

    for (i = 1; i <= n; i++) sum += dist[i];

    printf("%I64d\n", sum);
  }

  return 0;
}
