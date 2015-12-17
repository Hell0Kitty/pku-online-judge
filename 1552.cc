#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int i, j, x[20], leight, num;
  while (cin >> x[0]) {
    if (x[0] == -1)
      break;
    num = 0;
    leight = 1;
    while (cin >> x[leight]) {
      if (x[leight] == 0)
        break;
      leight++;
    }
    sort(x, x + leight + 1);
    for (i = 0; i < leight; i++)
      for (j = i + 1; j <= leight; j++)
        if (2 * x[i] == x[j])
          num++;
    cout << num << endl;
  }
  return 0;
}