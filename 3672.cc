#include <iostream>
#include <string>
using namespace std;

char unit[100005];

int main() {
  int m, t, u, f, d, i, ans = 0, sum = 0;
  cin >> m >> t >> u >> f >> d;
  for (i = 0; i < t; i++) cin >> unit[i];
  for (i = 0; i < t; i++) {
    if (unit[i] == 'u') {
      sum += u + d;
      ans++;
    } else if (unit[i] == 'f') {
      sum += f + f;
      ans++;
    } else if (unit[i] == 'd') {
      sum += d + u;
      ans++;
    }
    if (sum >= m) {
      cout << ans - 1 << endl;
      break;
    }
  }
}
