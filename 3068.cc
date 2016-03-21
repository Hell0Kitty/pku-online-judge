#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100;
const int INF = 1e9 + 7;
int N, M, s, t;
vector <int> G[MAX];
struct Edge {int from, to, cap, flow, cost;};
vector <Edge> edges;
int a[MAX], p[MAX], d[MAX];
bool inq[MAX];

void add_edge(int from, int to, int cap, int cost) {
    edges.push_back((Edge) {from, to, cap, 0, cost});
    edges.push_back((Edge) {to, from, 0, 0, -cost});
    int m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}

bool BellmanFord(int &flow, int &cost) {
    for (int i = 0; i <= t; ++i) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; a[s] = INF; p[s] = 0; inq[s] = 1;
    queue <int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge &e = edges[ G[u][i] ];
            if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                p[e.to] = G[u][i];
                a[e.to] = min(a[u], e.cap - e.flow);
                if (!inq[e.to]) {q.push(e.to); inq[e.to] = 1;}
            }
        }
    }

    if (d[t] == INF) return false;
    flow += a[t];
    cost += a[t] * d[t];
    int u = t;
    while (u != s) {
        edges[ p[u] ].flow += a[t];
        edges[ p[u] ^ 1].flow -= a[t];
        u = edges[ p[u] ].from;
    }

    return true;
}

int Mincost() {
    int flow = 0, cost = 0;
    while (BellmanFord(flow, cost) && flow < 2);

    if (flow < 2) return -1;
    return cost;
}

int main()
{

    int ca = 1;
    while (scanf("%d%d", &N, &M) != EOF) {
        if (N == 0 && M == 0) break;
        s = 0, t = N - 1;
        for (int i = 0; i <= t; ++i) G[i].clear();
        edges.clear();

        for (int i = 1; i <= M; ++i) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, 1, c);
        }

        printf("Instance #%d: ", ca++);
        int ans = Mincost();
        if (ans == -1) {
            printf("Not possible\n");
        } else {
            printf("%d\n", ans);
        }

    }
    return 0;
}



