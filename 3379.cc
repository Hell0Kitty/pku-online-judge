#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 10000 + 10;
int n, m, k;
char a[maxn];

int main() {
  while (scanf("%d%d%d", &n, &k, &m) != EOF) {
    scanf("%s", a + 1);
    m += n;
    int sum = 0;
    int x = 1;
    while (m > n) {
      if (x == 1) sum++;
      int s = min(m - n, (m - x) / (k + 1) + 1);
      x += s * (k + 1);
      if (x > m)
        x -= m;
      else
        x -= s;
      m -= s;
      x %= m;
      if (!x) x = m;
    }
    sum %= 26;
    a[x] = (a[x] - 'A' + sum) % 26 + 'A';
    cout << a[x] << endl;
  }
}
