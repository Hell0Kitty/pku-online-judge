#include <string.h>

#include <stdio.h>
#include <map> 
#include <string> 
#include <iostream> 
using namespace std; 

map<string, int> dict;

char c_convert(char inChar){
    
    if(inChar == 'A' || inChar == 'B' || inChar == 'C' ) return '2';
    if(inChar == 'D' || inChar == 'E' || inChar == 'F' ) return '3';
    if(inChar == 'G' || inChar == 'H' || inChar == 'I' ) return '4';
    if(inChar == 'J' || inChar == 'K' || inChar == 'L' ) return '5';
    if(inChar == 'M' || inChar == 'N' || inChar == 'O' ) return '6';
    if(inChar == 'P' || inChar == 'R' || inChar == 'S' ) return '7';
    if(inChar == 'T' || inChar == 'U' || inChar == 'V' ) return '8';
    if(inChar == 'W' || inChar == 'X' || inChar == 'Y' ) return '9';

    return inChar;
}

int main(){
    int n;
    scanf("%d",&n);
    char input[100];
    int i;
    for (i = 0;i < n; i ++)
    {
        scanf("%s", input);
        int j;
        for(j=0;j< strlen(input);j++){
            input[j] = c_convert(input[j]);
        }
        char input_trim[100];
        int input_trim_len = 0;
        for(j=0;j< strlen(input);j++){
            if(input[j] == '-')
                continue;
            input_trim[input_trim_len++] = input[j];
        }
        input_trim[input_trim_len] = '\0';
        //printf("The input trim is %s\n", input_trim);
        string value(input_trim,0, input_trim_len);
    //  cout<<"The input string is :"<<value<<endl;
        dict[value] ++;     
    }
    //output the dict
    bool Noduplicates = true;
    map < string, int >::iterator iter;  
    for (iter = dict.begin(); iter!= dict.end(); iter++)
    {
        if(iter-> second < 2) continue;
        printf("%s-%s %d\n", iter->first.substr(0,3).c_str(),
                             iter->first.substr(3, iter->first.length()-3).c_str(),
                             iter->second);
        Noduplicates = false;
        //
        //printf("%s %d\n", iter->first.c_str(), iter->second);
    }
    if(Noduplicates)
        puts("No duplicates.");
    return 0;
}
