#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

unsigned long long u[5050],t[5050];

int main(){
    u[0]=u[1]=u[2]=1;
    t[0]=t[1]=t[2]=1;
    for (int i=3; i<=5000; i++){
        u[i]=0;
        for (int j=2; j<=i-1; j++){
            u[i]+=t[j]*t[i-j+1];
        }
        t[i]=u[i];
        for (int j=2; j<=i-2; j++){
           t[i]+=t[j]*u[i-j+1];
        }
    }
    for (int i=3; i<=5000; i++)cout << t[i] << endl;
}



