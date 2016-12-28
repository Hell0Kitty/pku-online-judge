#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MAX = 60;

int main(){
    int n, i, id, ans;
    char str[MAX];
    bool vis[MAX], tan[MAX];
    while(cin >> n && n){
        memset(vis, 0, sizeof(vis));
        memset(tan, 0, sizeof(tan));
        cin >> str;
        ans = 0;
        for(i = 0; i < strlen(str); i ++){
            id = str[i] - 'A';
            if(!vis[id]){
                vis[id] = true;
                if(n > 0){
                    n --;
                    tan[id] = true;
                }else ans ++;
            }else{
                if(tan[id]) n ++;
            }
        }
        if(ans == 0)printf("All customers tanned successfully.\n");
        else printf("%d customer(s) walked away.\n", ans);
    }
    return 0;
}


