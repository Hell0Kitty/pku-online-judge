#include <iostream>
using namespace std;

#define MAX_size 2005
int cow[MAX_size];
int main() {
  int c, f1, f2, d;
  int i, j;
  int a, b;
  cin >> c >> f1 >> f2 >> d;
  memset(cow, 0, sizeof(cow));
  for (i = 0; i < c; i++) {
    cin >> a >> b;
    for (j = a; j <= b; j++) {
      cow[j]++;
    }
  }
  j = d;
  int pay = f1 - f2;
  while (pay != 0) pay -= cow[j--];
  cout << j + 1 << endl;
  return 0;
}
