#include <iostream>
#include <cstring>
using namespace std;
int num[205][2];

int main(void) {
  int n, i, j, k, Count = 0, max = 0;
  cin >> n;
  for (i = 0; i < n; i++) cin >> num[i][0] >> num[i][1];
  for (i = 0; i < n - 2; i++)
    for (j = i + 1; j < n - 1; j++) {
      Count = 2;
      for (k = j + 1; k < n; k++) {
        if ((num[i][0] - num[j][0]) * (num[j][1] - num[k][1]) ==
            (num[i][1] - num[j][1]) * (num[j][0] - num[k][0]))
          Count++;
      }
      if (Count > max) max = Count;
    }
  cout << max << endl;

  return 0;
}
