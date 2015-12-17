#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int lengthOfLIS(int *nums, int size) {
    if (size == 0)
      return 0;
    int *d = new int[size];
    for (int i = 0; i < size; ++i) {
      d[i] = nums[i];
    }
    int len = LISSEx(d, size); //, int result[])
    delete d;
    return len;
  }
  unsigned int LISSEx(const int array[], size_t length) //, int result[])
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

    /*while(pre[k] != k)
    {
        result[i--] = array[k];
        k = pre[k];
    }
    result[i] = array[k];  */
    return max;
  }
};

int data[100000];
int main(int argc, char const *argv[]) {
  /* code */
  std::ios::sync_with_stdio(false);
  int ncase;

  int arraylen;
  cin >> arraylen;
  for (int i = 0; i < arraylen; ++i) {
    cin >> data[i];
  }
  Solution s;
  int result = s.lengthOfLIS(data, arraylen);
  cout << result << endl;

  return 0;
}