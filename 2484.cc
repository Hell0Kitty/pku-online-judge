#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) break;

    if (n < 3)
      printf("Alice\n");
    else
      printf("Bob\n");
  }

  // system("PAUSE");
  return EXIT_SUCCESS;
}