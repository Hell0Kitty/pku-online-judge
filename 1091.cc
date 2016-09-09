#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int Max = 50;

struct data{
    int num, v; 

}fac[Max];

bool cmp(data a, data b){
    if(a.num < b.num) return true;
    else return false;
}

__int64 mypow(int num, int n){           //  求num^n，此时得用到__int64。
    __int64 ans = 1;
    while(n --) ans *= num;
    return ans;
}

int find_factor(int num){
    int i, j, cou = 0;
    for(i = 2; i * i < num; i ++)        //  求出num的所有因子(除去1)。
        if(num % i == 0){
            fac[cou ++].num = i;
            fac[cou ++].num = num / i;
        }
    if(i * i == num) fac[cou ++].num = i;//  补sqrt(num)。
    fac[cou ++].num = num;               //  补num。

    sort(fac, fac + cou, cmp);
    for(i = 0; i < cou; i ++){           //  求出每个因子的处理值，0为跳过，奇数为-，偶数为+。
        bool prime = true;
        int k = 0;
        for(j = 0; j < i; j ++)
            if(fac[j].v == 1 && fac[i].num % fac[j].num == 0){
                k ++;
                prime = false;
                if(fac[i].num % (fac[j].num * fac[j].num) == 0){
                    k = 0;
                    break;
                }
            }
        if(prime) fac[i].v = 1;
        else fac[i].v = k;

    }
    return cou;                          // 返回因子的个数。
}

int main(){
    int n, m, cou;
    while(scanf("%d %d", &n, &m) != EOF){
        cou = find_factor(m);
        __int64 sum = mypow(m, n);
        for(int i = 0; i < cou; i ++){
            if(fac[i].v == 0) continue;
            else if(fac[i].v % 2 == 1)
                sum -= mypow(m / fac[i].num, n);
            else
                sum += mypow(m / fac[i].num, n);
        }
        printf("%I64d\n", sum);
    }
    return 0;
}


