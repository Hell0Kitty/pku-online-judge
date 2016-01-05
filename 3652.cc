#include <iostream>
using namespace std;
int A, B, C, S;

int sovel() {
  int x = S;
  int state = 0;
  int n = 1;
  while ((x = (A * x + B) % C) && x != S && n <= C) {
    n++;
    state |= (x ^ S);
  }
  return state;
}
int main() {
  int i;
  int state;
  while (scanf("%d", &A) && A) {
    scanf("%d %d %d", &B, &C, &S);
    state = sovel();
    for (i = 1; i <= 16; i++) {
      if (state & (1 << (16 - i))) {
        printf("?");
      } else {
        if (S & (1 << (16 - i)))
          printf("1");
        else
          printf("0");
      }
    }
    printf("\n");
  }
  return 0;
}
