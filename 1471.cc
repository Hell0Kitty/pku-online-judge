#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=105;
int n, cas=1, empty[maxn][2*maxn];         //i行  j之前连续“-”数(包括j)
char str[maxn][maxn*2];

void init(){
    int i, j;
    for(i=n; i>0; i--)
        scanf("%s", str[i]);
    memset(empty, 0, sizeof(empty));
    for(i=1; i<=n; i++){
        for(j=0; j<i*2-1; j++)
        if(str[i][j]=='-'){
            empty[i][j+1]=empty[i][j]+1;
        }
    }
}

void solve(){
    int i, j, k, d, ans=0, cnt;
    for(i=1; i<=n; i++)
    for(k=1; k<=2*i-1; k++){
        if(!empty[i][k])continue;
        cnt=3;d=k+2;
        if(k%2==0){
            for(j=i-1; j>=1; j--){
                if(empty[j][k]<cnt)break;
                cnt+=2;
            }
        }
        else {
            for(j=i+1; j<=n; j++){
                if(d>2*j-1||empty[j][d]<cnt)break;
                cnt+=2;d+=2;
            }
        }
        if((cnt-1)*(cnt-1)/4>ans)
            ans=(cnt-1)*(cnt-1)/4;
    }
    printf("Triangle #%d\nThe largest triangle area is %d.\n\n", cas++, ans);
}
int main(){
    while(scanf("%d", &n)&&n){
        init();
        solve();
    }
    return 0;
}


