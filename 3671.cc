#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
#include <algorithm>
using namespace std;
const int MAX = 30001;
int num[MAX], tmp[MAX];

int main() {
  int i, n, ans, left, right, mid;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }

  //最长递增子序列的求解
  memset(tmp, 0, sizeof(tmp));
  tmp[0] = -1;
  ans = 0;
  for (i = 0; i < n; i++) {
    if (num[i] >= tmp[ans]) {
      tmp[++ans] = num[i];
    } else {
      left = 1, right = ans;
      while (left <= right) {
        mid = (left + right) / 2;
        if (num[i] >= tmp[mid]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      tmp[left] = num[i];
    }
  }

  cout << n - ans << endl;

  return 0;
}
