#include <iostream>
using namespace std;
const int maxN = 1000024;
int vis[maxN];

int main() {
  int n;
  memset(vis, 0, sizeof(vis));
  int q, a, x, sum = 0, correct_num = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d%d", &q, &a, &x);
    if (a == 0)
      sum += 10;
    else {
      sum += 20;
      if (vis[q] == 1)
        sum += 10 * correct_num;
      else {
        vis[q] = 1;
        ++correct_num;
      }
      if (x == 1) sum += 20;
    }
  }
  printf("%d", sum);
  return 0;
}
