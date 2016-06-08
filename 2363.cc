

#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int T, V;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &V);
    int l = ceil(pow(V, 1.0 / 3));
    bool flag = 0;
    int i, j, k;
    int minn = 2 * (1 + V + V);
    for (i = l; i > 0; i--)
      for (j = l; j <= V; j++) {
        if (V % (i * j) == 0) {
          k = V / (i * j);
          minn = 2 * (i * j + i * k + j * k) < minn
                     ? 2 * (i * j + i * k + j * k)
                     : minn;
        }
      }
    printf("%d\n", minn);
  }
}
