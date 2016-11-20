#include <iostream>
#include <cstring>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    char l;
    int s, e, c[1001], max = -1, min = 0xfffffff;
    memset(c, 0, sizeof(c));
    while (n--) {
      cin >> l >> s >> e;
      for (int i = s; i < e; i++) c[i]++;
      if (e > max) max = e;
      if (s < min) min = s;
    }
    for (int i = min; i <= max; i++)
      if (c[i]) cout << (char)(c[i] + 64);
    cout << endl;
  }
  return 0;
}
