#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stack>
#include <queue>

using namespace std; 


int roman_to_int(string s){
  
  return 0; 
}


    
    
    
int main(){
  std::ios::sync_with_stdio(false);

  string inputbuff;
  while(cin >> inputbuff){
    if( inputbuff[0] == '='){
      cout<< "[dbg]print the result; " << endl;

    }else if (inputbuff[0] == '+'){
      cout<< "[dbg]add operator ; " << endl;
      
    }else if (inputbuff[0] == '-'){
      cout<< "[dbg]minus operator ; " << endl;
      
    }else if (inputbuff[0] == '*'){
      cout<< "[dbg]multiple operator ; " << endl;
      
    }else if (inputbuff[0] == '/'){
      cout<< "[dbg]divide operator ; " << endl;
      
    }
    
  }

  return 0; 
}