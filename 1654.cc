#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    long long ans = 0;
    int x = 0;
    int y = 0;
    char ch;
    while (ch = getchar(), ch != '5') {
      switch (ch) {
        case '1':
          ans -= y * 2 - 1;
          x--;
          y--;
          break;
        case '2':
          y--;
          break;
        case '3':
          ans += y * 2 - 1;
          x++;
          y--;
          break;
        case '4':
          ans -= y * 2;
          x--;
          break;
        case '6':
          ans += y * 2;
          x++;
          break;
        case '7':
          ans -= y * 2 + 1;
          x--;
          y++;
          break;
        case '8':
          y++;
          break;
        case '9':
          ans += y * 2 + 1;
          x++;
          y++;
          break;
      }
    }
    getchar();
    if (ans < 0) ans = -ans;
    if (ans & 1)
      cout << ans / 2 << ".5" << endl;
    else
      cout << ans / 2 << endl;
  }
  return 0;
}
