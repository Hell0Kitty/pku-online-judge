#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cctype>
#include <map>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;

const int MAXN = 1010;

map<string, int> mymap;
char s[20000][MAXN];
bool ans[20000][10000];
int n, page, row, cur, cnt;

string to_str(char *&st) {
    while(!isalpha(*st) && *st != 0) ++st;
    string ret;
    while(isalpha(*st) && *st != 0) {
        if(islower(*st)) *st += 'A' - 'a';
        ret += *st, ++st;
    }
    return ret;
}

void to_map(char *s) {
    string tmp;
    while(true) {
        tmp = to_str(s);
        if(tmp == "") break;
        int now;
        if(mymap.find(tmp) != mymap.end()) now = mymap[tmp];
        else mymap[tmp] = now = ++cnt;
        //cout<<tmp<<endl;
        ans[now][page] = true;
    }
}

void output() {
    map<string, int>::iterator it;
    for(it = mymap.begin(); it != mymap.end(); ++it) {
        bool flag = false;
        int now = it->second;
        cout<<it->first;
        for(int i = 1; i <= page; ++i) {
            if(!ans[now][i]) continue;
            if(!flag) putchar(' '), flag = true;
            else putchar(',');
            printf("%d", i);
            int j = i;
            while(ans[now][j + 1]) ++j;
            if(j >= i + 2) {
                printf("-%d", j);
                i = j;
            }
        }
        puts("");
    }
}

int main() {
    scanf("%d", &n); getchar();
    page = 1, row = 1;
    cur = 1; cnt = 0;
    bool flag = true;
    mymap.clear();
    while(flag && gets(s[0])) {
        cur = 1;
        while((flag = gets(s[cur])) && s[cur][0] != 0) ++cur;
        if(cur == 1) {
            to_map(s[0]);
            ++row;
            if(++row > n) row = 1, ++page;
            continue;
        }
        if(cur == 2) {
            if(row == n) row = 1, ++page;
            to_map(s[0]);
            to_map(s[1]);
            row += 2;
            if(++row > n) row = 1, ++page;
            continue;
        }
        if(cur == 3) {
            if(row + 1 == n || row == n) row = 1, ++page;
            to_map(s[0]);
            to_map(s[1]);
            to_map(s[2]);
            row += 3;
            if(++row > n) row = 1, ++page;
            continue;
        }
        if(row == n) row = 1, ++page;//cur >= 4
        for(int i = 0; i < cur; ++i) {
            if(row == n && i == cur - 2) row = 1, ++page;
            to_map(s[i]);
            ++row;
            if(row > n) row = 1, ++page;
        }
        if(row == 1) continue;
        if(++row > n) row = 1, ++page;
    }
    output();
}



