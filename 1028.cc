#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>


using namespace std; 


std::stack<string> stack_1;
std::stack<string> stack_2;

int main(int argc, char const *argv[])
{

   // stack_1.push("http://www.acm.org/");
  string cur = "http://www.acm.org/";
  while(true){
    string ins; 
    string website; 
    cin >> ins; 
    if( ins == "QUIT") break; 
    else if ( ins == "VISIT") {
      cin >> website;
      cout << website << endl;
      stack_1.push( cur );
      while(!stack_2.empty()) stack_2.pop();
      cur = website;


    } else if ( ins == "BACK" ) {

      if(stack_1.empty()) cout<<"Ignored" << endl;
      else {
        stack_2.push( cur );
        string _top = stack_1.top();
        stack_1.pop(); 
        cur = _top;

        cout << cur << endl;
              
      }
      
    } else if ( ins == "FORWARD" ){
      if(stack_2.empty()) cout<<"Ignored" << endl;
      else {
        stack_1.push( cur );
        string _top = stack_2.top();
        stack_2.pop(); 
        cur = _top;

        cout << cur << endl;
      }

    }
    

  }

  return 0;
}