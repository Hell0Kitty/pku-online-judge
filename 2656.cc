#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  while (scanf("%d", &amp; n) != EOF & amp; &amp; n) {
    int a, b, maxSum = 0, pos = 0;
    for (int i = 1; i & lt; = n; i++) {
      scanf("%d%d", &amp; a, &amp; b);
      if (maxSum & lt; a + b) {
        maxSum = a + b;
        pos = i;
      } else if (maxSum == a + b & amp; &amp; i & lt; pos) {
        pos = i;
      }
    }
    if (maxSum & lt; = 8)
      printf("0\n");
    else
      printf("%d\n", pos);
  }
  return 0;
