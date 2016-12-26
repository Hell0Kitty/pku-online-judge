#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Coin{
    int value, amount;
    bool operator < (const Coin &t)const{
        return value < t.value;
    }
}coin[22];

int need[22];

int main() {
    ios_base::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> coin[i].value >> coin[i].amount;
    sort(coin, coin + n);
    int ans = 0;
    while (1){
        int rest = c;
        memset(need, 0, sizeof need);
        for (int i = n - 1; i >= 0; --i){
            if (coin[i].amount > 0){
                int require = min(coin[i].amount, rest / coin[i].value);
                rest -= require * coin[i].value;
                need[i] = require;
            }
            if (rest == 0) break;
        }
        if (rest > 0){
            for (int i = 0; i < n; ++i){
                if (coin[i].amount > 0 && coin[i].value >= rest){
                    rest = 0;
                    ++need[i];
                    break;
                }
            }
        }
        if (rest > 0) break;
        int week = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            if (need[i])
                week = min(week, coin[i].amount / need[i]);
        for (int i = 0; i < n; ++i)
            if (need[i])
                coin[i].amount -= week * need[i];
        ans += week;
    }
    cout << ans << '\n';
    return 0;
}



