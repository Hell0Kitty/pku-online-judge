#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <iostream>

using namespace std;

int func(int number){
  int sum = 1;
  for(int i = 2; i < sqrt((double)number); i++){
    if(number %i ==0 ) {sum += i; sum += number /i;}
  }
  int reg = sqrt((double)number);
  if( reg * reg == number){
    sum += reg;
  }
  if( sum == number) return 0 ;
  if (sum > number) return 2;

  return 1;

}

int main(){
  //15 28 6 56 60000 22 496 0
  puts("PERFECTION OUTPUT");
  while(true){
    int number;
    scanf("%d", &number);
    if(number == 0) break;
    if(number == 1 ) {printf( "%5d  ", number); puts("DEFICIENT"); continue;}
    int result = func(number);
    if(result == 0 ) {printf( "%5d  ", number); puts("PERFECT");}
    else if (result == 1) {printf( "%5d  ", number); puts("DEFICIENT");}
   else if (result == 2) {printf( "%5d  ", number); puts("ABUNDANT");}
  }
  puts("END OF OUTPUT");



  return 0;
}