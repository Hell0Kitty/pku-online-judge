#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
using namespace std;
const int nMax = 55;
const int mMax = 105;
const int inf = 0xffffff;

struct{
    int r, c;
}que[2500];
int row, col, n, ans;
int maze[nMax][nMax];
bool vis[nMax][nMax];
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
int map[mMax][mMax], dis[mMax];

void bfs(int fir_r, int fir_c){  //  枚举顶点，用bfs构造顶点(fir_r,fir_c)d的所有边，加入邻接矩阵。
    int i, j;
    for(i = 1; i <= row; i ++)
        for(j = 1; j <= col; j ++)
            vis[i][j] = false;
    vis[fir_r][fir_c] = true;
    que[0].r = fir_r;
    que[0].c = fir_c;
    int num = n - 1, step = 0, head = 0, tail = 1;  // num表示未加入邻接矩阵的个数，step表示步数。
    while(tail - head > 0){
        step ++;
        int count = tail - head;
        while(count --){
            for(i = 0 ; i < 4; i ++){
                int r = que[head].r + dr[i];
                int c = que[head].c + dc[i];
                if(maze[r][c] != -1 && !vis[r][c]){
                    vis[r][c] = true;
                    if(maze[r][c] > 0){
                        int u = maze[fir_r][fir_c];
                        int v = maze[r][c];
                        map[u][v] = step;
                        num --;
                        if(num == 0) return;  //  当所有顶点加入了邻接矩阵，即可退出。
                    }
                    que[tail].r = r;
                    que[tail].c = c;
                    tail ++;
                }
            }
            head ++;
        }
    }
}

int min(int a, int b){
     return a < b ? a : b;
}

void prim(){   //  自己的prim模板。
    int i, j, now, min_node, min_edge;
    for(i = 1; i <= n; i ++)
        dis[i] = inf;
    now = 1;
    ans = 0;
    for(i = 1; i < n; i ++){
        dis[now] = -1;
        min_edge = inf;
        for(j = 1; j <= n; j ++)
            if(j != now && dis[j] >= 0){
                 dis[j] = min(dis[j], map[now][j]);
                 if(dis[j] < min_edge){
                     min_edge = dis[j];
                     min_node = j;
                 }
             }
         now = min_node;
         ans += min_edge;
    }
}

int main(){
    int t, i, j;
    char str[nMax];
    scanf("%d", &t);
    while(t --){
        scanf("%d %d", &col, &row);
        gets(str);   //  输入可能出现的“6 5     ”的情况应注意。
        n = 0;
        for(i = 1; i <= row; i ++){
            for(j = 1; j <= col; j ++){
                char c;
                scanf("%c", &c);
                if(c == '#')  maze[i][j] = -1;
                else if(c == ' ')  maze[i][j] = 0;
                else maze[i][j] = ++ n;    //  n表示第几个顶点。最后的n值即为顶点数（1 ~ 101）。
            }
            getchar();   //  读入每行迷宫最后的回车号。
        }
        for(i = 1; i <= row; i ++)
            for(j = 1; j <= col; j ++)
                if(maze[i][j] > 0)   //  枚举顶点。
                    bfs(i, j);
        prim();
        printf("%d\n", ans);
    }
    return 0;
}
