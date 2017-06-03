#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, S, T;
string str;

struct Edge {
    int v, ct, next;
    int ti[20][2], ways;
}e[505];
int idx, head[55];

void insert() {
    int a[40];
    char *s = new char [str.size()+1];
    strcpy(s, str.c_str());
    int i = 0;
    for (char * p = strtok(s, " "); p != NULL; ++i) {
        a[i] = atoi(p);
        p = strtok(NULL, " ");
    }
    ++idx;
    e[idx].v = a[1], e[idx].ct = a[2];
    e[idx].next = head[a[0]];
    head[a[0]] = idx;
    a[2] = 0;
    int j, k;
    for (j = 3, k = 0; j < i; j+=2, ++k) { // 读取通道的关闭和开始时间 
        e[idx].ti[k][0] = a[j-1];    // 开启时间 
        e[idx].ti[k][1] = a[j];        // 关闭时间 
    }
    if (j == i) { // 这个区间是一直开启的
        e[idx].ti[k][0] = a[j-1];
        e[idx].ti[k][1] = INF;
        ++k;
    }
    e[idx].ways = k-1;

    ++idx;
    e[idx] = e[idx-1];
    e[idx].v = a[0], e[idx].next = head[a[1]];
    head[a[1]] = idx;
/*    for (j = 0; j <= e[idx].ways; ++j) {
        printf("%d %d\n", e[idx].ti[j][0], e[idx].ti[j][1]);    
    }*/
    delete [] s;
}

int dis[55];
bool vis[55];

void spfa() {
    memset(vis, 0, sizeof (vis));
    memset(dis, 0x3f, sizeof (dis));
    queue<int>q;
    q.push(S);
    dis[S] = 0;
    vis[S] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        vis[v] = false;
        for (int i = head[v]; i != -1; i = e[i].next) {
            for (int j = 0; j <= e[i].ways; ++j) {
                // 如果从v出发能够通过该通道，则允许通过 
                if (dis[v] + e[i].ct <= e[i].ti[j][1] && e[i].ct + e[i].ti[j][0] <= e[i].ti[j][1]) {
                    int temp = max(dis[v], e[i].ti[j][0]) + e[i].ct;
                    if (temp < dis[e[i].v]) {
                        dis[e[i].v] = temp;
                        if (!vis[e[i].v]) {
                            q.push(e[i].v);
                            vis[e[i].v] = true;
                        }
                    }
                    break;
                }
            }    
        }
    }
}

int main() {
    while (scanf("%d", &N), N) {
        memset(head, 0xff, sizeof (head));
        idx = -1;
        scanf("%d %d %d", &M, &S, &T);
        char c;
        while ((c = getchar()) != '\n') ;
        for (int i = 0; i < M; ++i) {
            getline(cin, str);
            insert();
        }
        spfa();
        printf(dis[T]==INF ? "*\n" : "%d\n", dis[T]);
    }
    return 0;    
}



