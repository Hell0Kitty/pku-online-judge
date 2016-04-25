#include <cstdio>

#include <algorithm>

#include <cstring>

using namespace std;

int x[50005], y[50005], left[50005], right[50005];

int main()

{
  int n;

  while (scanf("%d", &n) && n != -1)

  {
    x[0] = y[0] = 0;

    y[n + 1] = 0;

    left[0] = 0;
    right[n + 1] = n + 1;

    for (int i = 1; i <= n; i++)

    {
      scanf("%d%d", x + i, y + i);

      x[i] += x[i - 1];

      left[i] = right[i] = i;

      while (y[i] && y[left[i] - 1] >= y[i]) left[i] = left[left[i] - 1];
    }

    int ans = 0;

    for (int i = n; i >= 1; i--)

    {
      while (y[i] && y[right[i] + 1] >= y[i]) right[i] = right[right[i] + 1];

      ans = max(ans, (x[right[i]] - x[left[i] - 1]) * y[i]);
    }

    printf("%d\n", ans);
  }

  return 0;
}
