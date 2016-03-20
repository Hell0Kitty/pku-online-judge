#include <cstdio>

int main() {
  int f[5];
  for (int i = 0; i < 3; i++) {
    scanf("%d", &f[i]);
    if (f[i] <= 168) {
      printf("CRASH %d\n", f[i]);
      return 0;
    }
  }
  printf("NO CRASH\n");
  return 0;
}
