#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);
  int i, j, k, status;
  char ch;
  int step[17][2];
  int change[4][4] = {{63624, 62532, 61986, 61713},
                      {36744, 20292, 12066, 7953},
                      {35064, 17652, 8946, 4593},
                      {34959, 17487, 8751, 4383}};
  status = 0;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++) {
      cin >> ch;
      if (ch == '+')
        status ^= change[i][j];
    }
  k = 0;
  status *= 2;
  i = j = 4;
  while (status >>= 1) {
    if ((status & 1) == 1) {
      step[k][0] = i;
      step[k][1] = j;
      k++;
    }
    if (j == 1) {
      i--;
      j = 4;
    } else
      j--;
  }
  cout << k << endl;
  for (i = k - 1; i >= 0; i--)
    cout << step[i][0] << " " << step[i][1] << endl;
  // system("pause");
  return 0;
}