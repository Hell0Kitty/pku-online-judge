#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    int a[110][110];
    int t, s, c;
    scanf("%d",&t);
    while(t --){
        memset(a, 0, sizeof(a));
        scanf("%d%d",&s, &c);
        for (int i = 0; i < s; i ++){
            scanf("%d", &a[0][i]);
        }
        for (int i = 1; i < s; i ++){
            for (int j = 0; j < s - i; j ++){
                a[i][j] = a[i-1][j+1] - a[i-1][j];
            }
        }
        for (int i = 1; i <= c; i ++)
            a[s-1][i] = a[s-1][0];
        for (int i = s - 2; i >= 0; i --){
            for (int j = 0; j < c; j ++){
                a[i][s-i+j] = a[i+1][s-i+j-1] + a[i][s-i+j-1];
            }
        }
        for (int i = 0; i < c - 1; i ++){
            printf("%d ", a[0][s+i]);
        }
        printf("%d\n",a[0][s+c-1]);
    }
    return 0;
}


