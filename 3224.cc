#include <iostream>
#include <string>
using namespace std;

int matrix[110][110];
int ans[110];

int main() {
  int n, i, j, max = 0, cur;
  cin >> n;
  memset(ans, 0, sizeof(ans));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 3) ans[i]++;
    }
  for (i = 1; i <= n; i++) {
    if (ans[i] > max) {
      max = ans[i];
      cur = i;
    }
  }
  cout << cur << endl;

  return 0;
}
