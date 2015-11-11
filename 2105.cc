#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n;
  char a[35];
  cin >> n;
  getchar();
  while (n--) {
    int i;
    gets(a);
    for (i = 0; i < 32; i++) {
      if ((i + 1) % 8 == 0) {
        int j, sum = 0;
        for (j = i - 7; i - j >= 0; j++) {
          if (a[j] != '0') sum = sum + pow(2.0, (i - j));
        }
        cout << sum;
        if (i != 31) cout << ".";
      }
    }
    cout << endl;
  }

  return 0;
}