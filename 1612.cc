#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
using namespace std;

#define maxn 40+10
#define inf 0x3fffffff
int n;
char s[100];
int I[maxn];
int cnt;
int dis[maxn][maxn];
long long f[maxn][maxn];

void init(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = inf;
        }
    }
    memset(f,0,sizeof(f));
}
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("##%d %d: %d\n",i,j,dis[i][j]);
        }
    }
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[k][j]==dis[i][j]){
                    f[i][j] |=(1LL<<(k-1));
                }
            }
        }
    }
}

bool solve(){
    long long ans = 0;
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            ans |= f[I[i]][I[j]];
        }
    }
    int res = 0;
    while(ans>0){
        if(ans&1) res++;
        ans = ans>>1;
    }
    return res == n;
}

int main(){
    init();
    scanf("%d\n",&n);
    int temp,t;
    for(int i=1;i<=n;i++){
        gets(s);
        stringstream ss(s);
        while(ss>>temp) dis[i][temp] = 1;
    }
    floyd();
    scanf("%d\n",&t);
    while(t--){
        cnt = 0;
        gets(s);
        stringstream ss(s);
        while(ss>>temp) I[cnt++] = temp;
        if(solve()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}



