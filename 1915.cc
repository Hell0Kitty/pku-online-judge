#include<iostream>
using namespace std;
const int Max = 305;
 
struct{
    int r, c;
}sta, end, queue[Max * Max];
int len;

bool vis[Max][Max];
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
 
bool inmap(int r, int c){
    if(r >= 0 && r < len && c >= 0 && c < len)
        return true;
    return false;
}
 
int main(){
    int n;
    cin >> n;
    while(n --){
        cin >> len;
        cin >> sta.r >> sta.c >> end.r >> end.c;
        if(sta.r == end.r && sta.c == end.c){   //  记得加起点等于终点的判断。
            cout << '0' << endl;
            continue;
        }
        memset(vis, false, sizeof(vis));
        vis[sta.r][sta.c] = true;
        queue[0].r = sta.r;
        queue[0].c = sta.c;
        int head = 0, tail = 1, steps = 0;
        bool find = false;
        while(!find){
            steps ++;
            int count = tail - head;
            while(!find && count --){
                for(int i = 0; i < 8; i ++){
                    int r = queue[head].r + dr[i];
                    int c = queue[head].c + dc[i];
                    if(r == end.r && c == end.c){
                        find = true;
                        break;
                    }
                    if(inmap(r, c) && !vis[r][c]){
                        vis[r][c] = true;
                        queue[tail].r = r;
                        queue[tail].c = c;
                        tail ++;
                    }
                }
                head ++;   //  一开始把head++写到外面，卡了很久，以后要小心。
            }
        }
        cout << steps << endl;
    }
    return 0;
}
