#include <iostream>
#include <cmath>
#include <queue>
#include <memory.h>
using namespace std;
const int Max = 10005;
bool prime[Max], visit[Max];


void funprime(){
    for(int num = 1000; num < 10000; num ++){
        prime[num] = true;
        for(int i = 2; i <= sqrt((float)num); i ++)
            if(num % i == 0){
                prime[num] = false;
                break;
            }
        }
}       //  先打出一张素数表。

int izero(int num, int n){
    int m[5], i;     //  运用数组m[5]存放各位数，解决了许多繁琐，自认为很巧妙。
    for(i = 1; i <= 4; i ++){
        m[i] = num % 10;
        num = num / 10;
    }
    m[n] = 0;
    for(i = 1; i <= 4; i ++)
        num += m[i] * pow(10.0, i - 1);
    return num;
}       //  对num的从右算起第n位置0，如num=8792,n=3，则返回8092。

int main(){
    int n, sta, end;
    funprime();
    cin >> n;
    while(n --){
        cin >> sta >> end;
        if(sta == end){
            cout << '0' << endl;
            continue;
        }

        bool fine = false;
        int steps = 0;
        queue<int> pri;
        pri.push(sta);
        memset(visit, false, sizeof(visit));
        visit[sta] = true;

        while(!pri.empty() && !fine){
            int t = pri.size();
            steps ++;
            while(t --){
                int num = pri.front();
                pri.pop();
                for(int i = 1; i <= 4; i ++){
                    int n = izero(num, i);
                    for(int j = 0; j <= 9; j ++){
                        int now = n + j * pow(10.0, i - 1);
                        if(now == end){
                            fine = true;  // 一开始写成fine == true,调了很久。
                            break;
                        }
                        else if(prime[now] && !visit[now]){
                            pri.push(now);
                            visit[now] = true;
                        }
                    }
                }
            }
        }
        if(fine) cout << steps << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}
