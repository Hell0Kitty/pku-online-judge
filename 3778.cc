#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

const int MAXN = 25 + 10;
const double ESP = 10e-8;
const double Pi = atan(1.0) * 4;
const int INF = 0xffffff;
const int MOD = 10000007;

using namespace std;
struct People{
  int s;
  string n;
};
People a[MAXN];
string str[MAXN];
int main(){
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            cin >> a[i].n >> a[i].s;
        }
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j)
                    continue;
                for(int k = 0;k < n;k++){
                    if(k == i || k == j)
                        continue;
                    if(a[i].s == a[j].s + a[k].s){
                        str[cnt++] = a[i].n;
                        k = n;
                        j = n;
                        break;
                    }
                    for(int l = 0;l < n;l++){
                        if(l == k || l == i || l == j){
                            continue;
                        }
                        if(a[i].s == a[j].s+a[k].s+a[l].s){
                            str[cnt++] = a[i].n;
                            k = n;
                            j = n;
                            l = n;
                            break;
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
        sort(str,str+cnt);
        for(int i = 0;i < cnt;i++){
            cout << str[i] << endl;
        }
    }
    return 0;
}



