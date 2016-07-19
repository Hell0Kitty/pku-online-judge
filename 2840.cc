#include <cstdio>
using namespace std;

int T, h, m;

int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d:%d", &h, &m);
    if (!m)
      printf("%d\n", (h + 11) % 24 + 1);
    else
      putchar('0'), putchar('\n');
  }
  return 0;
}
