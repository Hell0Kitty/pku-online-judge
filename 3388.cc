#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <functional>
#include <string.h>
#include <iostream>
#include <numeric>
#include <list>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> data(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &data[i]);
  }
  int low = 1;
  int high = n + 1;
  while (high - low > 1) {
    int mid = (high + low) / 2;
    int cols = 0;
    for (int i = 0; i < k; ++i) {
      cols += data[i] / mid;
    }
    if (cols >= n) {
      low = mid;
    } else {
      high = mid;
    }
  }
  printf("%d\n", low);
  for (int i = 0; i < k; ++i) {
    for (int j = data[i] / low; j > 0; --j) {
      if (n-- > 0) {
        printf("%d\n", i + 1);
      } else {
        break;
      }
    }
  }
}
