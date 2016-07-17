#include <iostream>

#include <cstdio>

#include <cstring>

#include <cstdlib>

using namespace std;

#define maxn 100000

struct Snow

    {
  int arm[6];

  Snow *next;
};

Snow *snow[maxn];

bool same(Snow &a, Snow &b)

{
  for (int i = 0; i < 6; i++)

  {
    bool ok = true;

    for (int j = 0; j < 6; j++)

      if (a.arm[j] != b.arm[(j + i) % 6])

      {
        ok = false;

        break;
      }

    if (ok) return true;
  }

  for (int i = 0; i < 6; i++)

  {
    bool ok = true;

    for (int j = 0; j < 6; j++)

      if (a.arm[j] != b.arm[(i + 6 - j) % 6])

      {
        ok = false;

        break;
      }

    if (ok) return true;
  }

  return false;
}

bool ins(Snow &a, int index)

{
  if (snow[index] == 0)

  {
    a.next = snow[index];

    snow[index] = &a;

    return true;
  }

  Snow *p = snow[index];

  while (p != 0)

  {
    if (same(*p, a)) return false;

    p = (*p).next;
  }

  a.next = snow[index];

  snow[index] = &a;

  return true;
}

int main()

{
  memset(snow, 0, sizeof(snow));

  int n;

  scanf("%d", &n);

  while (n--)

  {
    Snow *temp = new Snow;

    int sum = 0;

    for (int i = 0; i < 6; i++)

    {
      scanf("%d", &(*temp).arm[i]);

      sum += (*temp).arm[i];
    }

    if (!ins((*temp), sum % maxn))

    {
      printf("Twin snowflakes found.\n");

      return 0;
    }
  }

  printf("No two snowflakes are alike.\n");

  return 0;
}
