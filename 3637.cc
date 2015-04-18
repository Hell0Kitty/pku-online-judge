#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int money[150010];

int main(int argc, char const *argv[]) {
  int ncase;
  cin >> ncase;
  while (ncase--) {
    int nitems;
    cin >> nitems;
    for (int i = 0; i < nitems; ++i) {
      cin >> money[i];
    }
    sort(money, money + nitems);
    reverse(money, money + nitems);
    int sum = 0;
    for (int i = 2; i < nitems; i += 3) sum += money[i];
    printf("%d\n", sum);
  }
  return 0;
}