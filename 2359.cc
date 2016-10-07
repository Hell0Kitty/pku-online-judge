#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

const int N=1999;
const int maxn=30010;
char ch[maxn];

int main(){

    string s;
    int res=0;
    while(gets(ch)){     
        s+=ch;
    }
    int len=s.length();
    for(int i=2;i<=len;i++)
        res=(res+N)%i;
    if(s[res]=='?')
        printf("Yes\n");
    else if(s[res]==' ')
        printf("No\n");
    else
        printf("No comments\n");
    return 0;
}


