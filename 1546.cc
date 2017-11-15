#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int n, m;
char c[10], c1[10];
void read() {
  int i, j, k;
  while (cin >> c >> n >> m) {
    j = 0;

    for (i = 0; i < strlen(c); i++)

    {
      if (c[i] >= '0' && c[i] <= '9') j = j * n + c[i] - '0';

      if (c[i] >= 'A' && c[i] <= 'Z') j = j * n + c[i] - 'A' + 10;
    }

    k = 0;

    if (j >= pow(1. * m, 7))

    {
      cout << "  ERROR" << endl;

      continue;
    }

    if (j == 0)

    {
      cout << 0 << endl;

      continue;
    }

    while (j != 0)

    {
      int s = j % m;

      if (s <= 9)

        c1[k++] = s + '0';

      else

        c1[k++] = s - 10 + 'A';

      j /= m;
    }

    for (i = 6; i >= k; i--) cout << ' ';

    for (i = k - 1; i >= 0; i--) cout << c1[i];

    cout << endl;
  }
}

int main() {
  read();

  return 0;
}
