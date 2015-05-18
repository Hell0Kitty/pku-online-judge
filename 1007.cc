#include <iostream>
using namespace std;
int main() {
  int n, m;
  int i = 0, j = 0, k = 0;
  long min = 50000;
  int output = 0;
  char input[1000][51] = {0};
  int unsortness[100] = {0};
  cin >> n >> m;
  for (i = 0; i < m; ++i) {
    cin >> input[i];
    for (j = 0; j < n - 1; ++j)
      for (k = j + 1; k < n; ++k)
        if (input[i][j] > input[i][k]) ++unsortness[i];
  }
  for (j = 0; j < m; ++j) {
    for (i = 0; i < m; ++i)
      if ((unsortness[i] < min) && (unsortness[i] >= 0)) {
        min = unsortness[i];
        output = i;
      }
    cout << input[output] << endl;
    unsortness[output] = -1;
    min = 50000;
  }
  return 0;
}
