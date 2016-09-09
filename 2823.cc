#include <cstdio>
#include <queue>
using namespace std;

int a[1000010];

deque<int> q1, q2;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < k; ++i) {
    if (q1.empty())
      q1.push_back(i);
    else {
      while (!q1.empty() && a[q1.back()] > a[i]) q1.pop_back();
      q1.push_back(i);
    }
    if (q2.empty())
      q2.push_back(i);
    else {
      while (!q2.empty() && a[q2.back()] < a[i]) q2.pop_back();
      q2.push_back(i);
    }
  }
  printf("%d", a[q1.front()]);
  for (int i = k; i < n; ++i) {
    if (q1.front() < i - k + 1) q1.pop_front();
    while (!q1.empty() && a[q1.back()] > a[i]) q1.pop_back();
    q1.push_back(i);
    printf(" %d", a[q1.front()]);
  }
  printf("\n");
  printf("%d", a[q2.front()]);
  for (int i = k; i < n; ++i) {
    if (q2.front() < i - k + 1) q2.pop_front();
    while (!q2.empty() && a[q2.back()] < a[i]) q2.pop_back();
    q2.push_back(i);
    printf(" %d", a[q2.front()]);
  }
  printf("\n");
  return 0;
}
