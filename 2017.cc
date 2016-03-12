#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
  std::ios::sync_with_stdio(false);
  while(true){
    int nline; 
    cin >> nline;
    if(nline <0) break;
    int speed, hour; 
    int prehour = 0;
    long sum = 0;
    while(nline--){
      cin >> speed >> hour;
      sum += speed * (hour - prehour);
      prehour = hour;
    }

    cout<< sum <<  " miles" << endl;


  }


  return 0;
}