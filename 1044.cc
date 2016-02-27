#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct NODE { int year, dic; } Node[20];
int main() {
  int n, i, j, m = 1;
  while (cin >> n && n) {
    Node N;
    int x, y;
    for (i = 0; i < n; i++) {
      cin >> N[i].year >> x >> y;
      N[i].dic = y - x;
    }
    printf("Case #%d:\n", m++);
    while (N[0].year < 10000) {
      for (i = 1; i < n; i++)
        if ((N[0].year - N[i].year) % N[i].dic != 0) break;
      if (i == n) {
        for (j = 1; j < n; j++)
          if (N[j].year > N[0].year) break;
        if (j == n) {
          printf("The actual year is %d.\n", N[0].year);
          break;
        }
      }

      N[0].year += N[0].dic;
    }
    if (N[0].year >= 10000) cout << "Unknown bugs detected." << endl;
    cout << endl;
  }
  return 0;
}
