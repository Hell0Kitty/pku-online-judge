#include <stdio.h>
#include <math.h>

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
  std::ios::sync_with_stdio(false);
  int64_t n, num; 
  while(scanf("%ld%ld", &n, &num)!= EOF){
    int ans = pow(num, (double)1.0/(n)) ;
    cout<< ans << endl;
  }
  return 0;
}
