
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int number[1000000];
class Solution {
 public:
  int lengthOfLIS(int *nums, int num_size) {
    if (num_size == 0) return 0;
    int *d = new int[num_size];
    for (int i = 0; i < num_size; ++i) {
      d[i] = nums[i];
    }
    int len = LISSEx(d, num_size);  //, int result[])
    delete d;
    return len;
  }
  unsigned int LISSEx(const int array[], size_t length)  //, int result[])
  {
    unsigned int i, j, k, l, max;
    unsigned int liss[length];
    unsigned int pre[length];
    liss[0] = 0;
    for (i = 0; i < length; ++i) {
      pre[i] = i;
    }

    for (i = 1, max = 1; i < length; ++i) {
      j = 0, k = max - 1;
      while (k - j > 1) {
        l = (j + k) / 2;
        if (array[liss[l]] < array[i]) {
          j = l;
        } else {
          k = l;
        }
      }

      if (array[liss[j]] < array[i]) {
        j = k;
      }
      if (j == 0) {
        if (array[liss[0]] >= array[i]) {
          liss[0] = i;
          continue;
        }
      }
      if (j == max - 1) {
        if (array[liss[j]] < array[i]) {
          pre[i] = liss[j];
          liss[max++] = i;
          continue;
        }
      }

      pre[i] = liss[j - 1];
      liss[j] = i;
    }

    i = max - 1;
    k = liss[max - 1];

    return max;
  }
};

Solution s;

int main(int argc, char const *argv[]) {
  /* code */
  std::ios::sync_with_stdio(false);
  int cur_case = 1;
  while (true) {
    int arraylen = 0;
    while (true) {
      int tmp;
      cin >> tmp;
      if (tmp < 0) break;
      number[arraylen++] = tmp;
    }

    if (arraylen == 0) break;
    // cout <<"[dbg] the array length is: " << arraylen << endl;
    // for (int i = 0; i < arraylen; ++i)
    //  {
    //   cout << number[i] << endl;
    //  }
    reverse(number, number + arraylen);
    int answer = s.lengthOfLIS(number, arraylen);
    cout << "Test #" << cur_case++ << ":" << endl;
    cout << "  maximum possible interceptions: " << answer << endl
         << endl;
  }
  return 0;
}