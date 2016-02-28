#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);

  int ncase = 0; 
  cin >> ncase;
  if(ncase == 0) {
    cout << 0 << endl;
    return 0;
  }

  int* nums = new int[ncase];
  for (int i = 0; i < ncase; ++i)
  {
    cin >> nums[i]; 
  }

   sort(nums, nums + ncase);
   
  if( ncase & 0x1 ) cout<< nums[ncase >> 1] << endl;
  else cout<< (nums[ncase>>1] + nums[(ncase>>1) +1] ) /2 << endl;
  

  delete nums;
  return 0;
}