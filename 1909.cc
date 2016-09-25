#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

const int M = 10005;
vector<int>que[M];
int num[M];
int rd[M];
int n, ans;

void init() {

    for(int i = 0; i <= n; i++){

        que[i].clear();
        num[i] = 0;
        rd[i] = 0;
    }
}

void dfs(int u){

     int v;
    for(int i = 0; i < (int)que[u].size(); i++) {

        v = que[u][i];
        dfs(v);
        num[u] += num[v];
        ans += fabs(num[v]);
    }
    num[u] -= 1;
}

int main()
{
    int a, b, q;

    while(scanf("%d", &n) != EOF) {

        if(!n)
            break;
         init();
         ans = 0;
        for(int i = 0; i< n; i++){

            scanf("%d%d%d", &a, &b, &q);
            num[a] = b;
            for(int j = 0; j < q; j++){

                scanf("%d", &b);
                que[a].push_back(b);
                rd[b]++;
            }

        }
        for(int i = 1; i <= n; i++){

            if(!rd[i]){

                dfs(i);
                break;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}



