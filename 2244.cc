#include <iostream>
#include <stdio.h>
using namespace std;
#define _MAX_ 150

int ans[_MAX_];

void init(){
  int i,j,m;
  for(i = 3;i < _MAX_;i++){
    m = 1;
    while(1){
      int tmp = 1;
      for(j = 2;j < i;j++){
        tmp = (tmp + m)%j;
        if(tmp == 0){
          tmp = j;
        }
      }
      if(tmp == 1){
        ans[i] = m;
        break;
      }
      m++;
    }
  }
}

int main(){
  int n;
  init();
  while(scanf("%d",&n)){
    if(!n) break;
    printf("%d\n",ans[n]);
  }
  return 0;
}
