#include<iostream>
#include<cstring>
#include<cstdio> 
using namespace std;  
int main(){  
    char str[256];  
    long sum=0;  
    while (gets(str)){
        if(str[0] == '#') break;  
        for (int i=0;i<strlen(str);i++){
            if (str[i] == ' ')
                continue;
            sum += (i+1)*(str[i] - 'A' + 1);  
        }
        cout << sum << endl;
        sum = 0;  
    }
    return 0;  
}



