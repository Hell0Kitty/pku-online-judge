#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;
string input;
typedef struct Node{
    int len;
    map<int, int> imp;
}Node;
map<char, Node> mp;
int flag;
int Calculate(int i)
{
    int v;
    char c;
    if(isdigit(input[i])){
        v = 0;
        while(isdigit(input[i])){
            v = v * 10 + input[i] - '0';
            i++;
        }
        return v;
    }else if(isalpha(input[i])){
        c = input[i];
        i += 2;
        v = Calculate(i);
        if(mp.count(c)){
            if(v < mp[c].len && mp[c].imp.count(v)){
                return mp[c].imp[v];
            }else flag = 1;
        }else {
            flag = 1;
        }
    }
    return 0;
}
void Judge()
{
    int i, j, u, v, Isdec = 0;
    int len;
    char c;
    len = input.size();
    for(i = 0; i < len; i++){
        if(input[i] == '='){
            Isdec = 1;
            break;
        }
    }
    if(Isdec){
        i++;
        v = Calculate(i);
    }
    c = input[0];
    u = Calculate(2);
    if(Isdec){
        if(mp.count(c)){
            if(u < mp[c].len)
                mp[c].imp[u] = v;
            else flag = 1;
        }else flag = 1;
    }else mp[c].len = u;
}
int main()
{
    int num = 0;
    while(getline(cin, input)){
        if(input[0] == '.') break;
        num = flag = 0;
        mp.clear();
        Judge();
        if(flag) num = 1;
        for(int i = 2; ; i++){
            getline(cin, input);
            if(input[0] == '.') break;
            if(!flag){
                Judge();
                if(flag) num = i;
            }
        }
        printf("%d\n", num);
    }
    return 0;
}




