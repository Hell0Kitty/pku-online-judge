#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int N = 100000;
bool Num[N];
int main(void) {
  int n;

  while (cin >> n) {
    printf((n & n - 1) ? "NO\n" : "YES\n");
  }

  return 0;
}
