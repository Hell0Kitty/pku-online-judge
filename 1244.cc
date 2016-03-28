#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 0x7ffffff
#define MAXN 110
#define eps 1e-7
#define ghs 1.7320508075

struct line{
    int num;
    double x[3],y[3];
}p[27];

bool judge(line & q){
    double ans = (q.x[0] - q.x[1]) * (q.x[0] - q.x[1]) + (q.y[0] - q.y[1]) * (q.y[0] - q.y[1]);
    for(int i = 1; i < 3; i++){
        if(fabs(ans - ((q.x[i] - q.x[(i+1)%3]) * (q.x[i] - q.x[(i+1)%3]) + (q.y[i] - q.y[(i+1)%3]) * (q.y[i] - q.y[(i+1)%3]))) > eps)return 0;
    }
    return 1;
}

int main(){

    int n,i,j;
    double t, a, b;
    char c;
    while(scanf("%d",&n),n){
        for(i = 0; i < 27; i++){
            p[i].num = 0;
        }
        a = 10000.0;
        b = 10000.0;
        getchar();
        for(i = 1; i <= n; i++){
            t = a ;
            for(j = 1; j <= i; j++){
                c = getchar();
                p[c - 'a'].x[p[c-'a'].num] = t;
                p[c - 'a'].y[p[c-'a'].num] = b;
                p[c - 'a'].num ++;
                t = t + 2*ghs;
            }
            a = a - ghs;
            b = b - 3.0;
        }

        int flag = 0;
        for(i = 0; i < 26; i++){
            if(p[i].num != 3)continue;
            if(judge(p[i])){printf("%c",'a'+i);flag = 1;}
        }
        if(!flag){
            printf("LOOOOOOOOSER!");
        }
        putchar('\n');
    }
    return 0;
}


