#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

int dp[1005][1005];

__int64 f(int n,int m){
    if(dp[n][m])
        return dp[n][m];
    if(n==1||m==1) return dp[n][m]=1;
    if(m>n)
        return dp[n][m]=f(n,n);
    else if(m==n)
        return dp[n][m]=f(n,m-1)+1;
    else if(m<n)
        return dp[n][m]=f(n,m-1)+f(n-m,m);
}

int n;
int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0)
            break;
        memset(dp,0,sizeof(dp));
        //因为f中没有含有0的参数，这里将res设为1，表示本身那种划分 
        __int64 res=1;
        int y;
        for(int i=1;i<n;i++){
            if((n-i)%2==0){
                //剩下元素的和 
                y=(n-i)>>1;
                res+=f(y,i); 
            }
        }
        if(n%2==0)
            res+=f(n/2,n/2);
        printf("%d %I64d\n",n,res);
    }
    return 0;
}


