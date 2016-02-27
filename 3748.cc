#include <iostream>
#include <string>
using namespace std;
int main() {
  int a, x, y, i;
  char s[32];
  cin >> a;
  getchar();
  cin >> x;
  getchar();
  cin >> y;
  for (i = 0; i <= 31; i++) s[i] = 0;
  i = 31;
  int j;
  while (a != 0) {
    int t = a % 10;
    j = i;
    while (t != 0) {
      s[i] = t % 2;
      t = t / 2;
      i--;
    }
    i = j - 4;
    a = a / 10;
  }
  s[31 - x] = 0;
  s[31 - y] = 1;
  s[31 - y + 1] = 1;
  s[31 - y + 2] = 0;
  int sum = 0;
  for (i = 0; i <= 31; i++) sum = sum * 2 + s[i];
  printf("%x\n", sum);
  return 0;
}
