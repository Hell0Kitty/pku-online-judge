#include <iostream>  
#include <string>  
#include <ctype.h>  
using namespace std;  

struct Map {  
    int v;  
    int flag;  
};  

Map map[256];  
int len;  
//初始化  
void init() {  
    for(int i = 0; i < 26; i++) {  
        map[i + 'a'].v = i+1;  
        map[i + 'a'].flag = 0;   
    }  
}  

void solve(string tmp,int pos,int &sum) {  

    int i = pos-1; //查找字母前一个字符  

    if( i >= 0 && tmp[i] == tmp[i-1]) { //前缀为--或者++  
        if(tmp[i] == '-') //前缀先做自增加或自减  
            --map[tmp[pos]].v;  
        else  
            ++map[tmp[pos]].v;  

        i -= 2; //将位置向前移动两位，查找前缀之前的符号，如果是减法就减去相应的值，否则增加  
        if(tmp[i] == '-') {  
            sum -= map[tmp[pos]].v;  
        }  
        else {  
            sum += map[tmp[pos]].v;  
        }  
    }  
    else { //判断中缀  
        if(tmp[i] == '-') {  
            sum -= map[tmp[pos]].v;  
        }  
        else {  
            sum += map[tmp[pos]].v;  
        }  
    }  
    i = pos+1; //判断后缀，如果是后缀就先自增加再运算  
    if( i+1 < len && tmp[i] == tmp[i+1]) {  
        if(tmp[i] == '-') {  
            --map[tmp[pos]].v;  
        }  
        else {  
            ++map[tmp[pos]].v;  
        }  
    }  
}  

int main() {  
    string str;   
    while(getline(cin,str)) {  
        cout << "Expression: " <<str<<endl;  

        string tmp;  
        init();   
        len = str.size();  
        //去掉多余的括号  
        for (int i = 0; i < len; i++) {  
            if(str[i] != ' ') {  
                tmp += str[i];  
            }  
        }  

        int sum = 0; //保存最后的总值  
        len = tmp.size();  
        for(int i = 0; i < len; i++) {  
            if( isalpha(tmp[i]) ) {  
                map[tmp[i]].flag = 1; //标记该字母已经被使用过  
                solve(tmp,i,sum);   //解决函数  
            }  
        }  

        cout<<"    value = "<<sum<<endl; //输出sum的值  
        for(int i = 0; i < 26; i++) { //输出每个元素的值  
            if(map[i + 'a'].flag != 0) {  
                cout<<"    "<<(char)(i + 'a') << " = "<<map[i + 'a'].v <<endl;  
            }  
        }  
    }  
    return 0;  
}


