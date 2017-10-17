#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool vis[13];
int tile[13][6], ans[13][2];
int Adjacent[15][6] = { 0, 0, 0, 0, 0, 0,
                        0, 2, 3, 4, 5, 6,
                        0, 1, 6, 7 ,11, 3,
                        0, 1, 2, 11, 10, 4,
                        0, 1, 3, 10, 9, 5,
                        0, 1, 4, 9, 8, 6,
                        0, 1, 5, 8, 7, 2,
                        0, 8, 12, 11, 2, 6,
                        0, 9, 12, 7, 6, 5,
                        0, 10, 12, 8, 5, 4,
                        0, 11, 12, 9, 4, 3,
                        0, 7, 12, 10, 3, 2,
                        0, 7, 8, 9, 10, 11
                        };
int mod(int v)
{
    return (v + 5) % 5;
}
bool dfs(int cur, int mp[][13])
{
    if(cur > 12) return true;
    int mp1[13][13];
    for(int i = 1; i <= 12; i++){
        if(!vis[i]){
            for(int j = 0, k; j < 5; j++){ //枚举面=tile的5个位置
                memcpy(mp1, mp, sizeof(mp1));
                for(k = 0; k < 5; k++){
                    if(mp1[cur][Adjacent[cur][k + 1]] == -1){ //判断是否合法
                        mp1[cur][Adjacent[cur][k + 1]] = mp1[Adjacent[cur][k + 1]][cur] = tile[i][mod(j + k)];
                    }else if(mp1[cur][Adjacent[cur][k + 1]] != tile[i][mod(j + k)])
                        break;
                }
                if(k >= 5){
                    vis[i] = true;
                    ans[cur][0] = i; ans[cur][1] = Adjacent[cur][mod(5 - j) + 1]; //记录当前放的tile和参考边所对应的面
                    if(dfs(cur + 1, mp1)) return true;
                    vis[i] = false;
                }
            }
        }
    }
    return false;
}

int main()
{
    int mp[13][13];
    for(int i = 1; i <= 12; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d", &tile[i][j]);
    memset(mp, -1, sizeof(mp));
    memset(vis, 0, sizeof(vis));
    if(dfs(1, mp)){
        for(int i = 1; i <= 12; i++){
            printf("%d %d\n", ans[i][0], ans[i][1]);
        }
    }else printf("-1\n");
    return 0;
}