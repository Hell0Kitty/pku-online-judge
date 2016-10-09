#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define maxn 105
#define inf 0x3f3f3f3f

struct Point
{
    int x, y;
    Point()
    {
    }
    Point(int xx, int yy) :
            x(xx), y(yy)
    {
    }
} q[maxn * maxn], point[maxn * maxn];

struct Edge
{
    Point v;
    int next, w;
} edge[maxn * maxn * maxn * 10];

struct Elem
{
    int w;
    Point v;
    Elem()
    {
    }
    Elem(int ww, Point pp) :
            w(ww), v(pp)
    {
    }
};

priority_queue<Elem> pq;

int dist[maxn * maxn][30];
char map[maxn][maxn];
int n, m;
bool vis1[maxn * maxn][30];
int head[maxn * maxn][30];
int cnt, idcnt;
int id[maxn][maxn];
int dir[4][2] =
{
{ 1, 0 },
{ 0, 1 },
{ -1, 0 },
{ 0, -1 } };

bool operator <(const Elem &a, const Elem &b)
{
    return a.w > b.w;
}

int wall(Point &a)
{
    if (map[a.x][a.y] <= '9' && map[a.x][a.y] >= '1')
        return map[a.x][a.y] - '0';
    return 0;
}

int packnum(char ch)
{
    if (ch == '#')
        return 0;
    if (isupper(ch))
        return ch - 'A' + 1;
    return -1;
}

bool ok(Point &a)
{
    if (a.x < 0 || a.y < 0 || a.x >= n || a.y >= m)
        return false;
    if (map[a.x][a.y] == '*')
        return false;
    if (packnum(map[a.x][a.y]) != -1)
        return false;
    return true;
}

void addedge1(Point a, Point b, int w)
{
    edge[cnt].v = b;
    edge[cnt].w = w;
    edge[cnt].next = head[a.x][a.y];
    head[a.x][a.y] = cnt++;
}

int getid(Point a)
{
    if (~id[a.x][a.y])
        return id[a.x][a.y];
    id[a.x][a.y] = idcnt++;
    point[id[a.x][a.y]] = a;
    return id[a.x][a.y];
}

void addedge(Point &a, Point &b)
{
    int x = getid(a);
    int y = getid(b);
    if (wall(a))
        for (int i = 0; i < 26; i++)
            addedge1(Point(x, i + 1), Point(y, i), 0);
    for (int i = 0; i <= 26; i++)
        addedge1(Point(x, i), Point(y, i), wall(a));
}

void bfs(Point a)
{
    getid(a);
    for (int i = 0; i < 4; i++)
    {
        Point b(a.x + dir[i][0], a.y + dir[i][1]);
        if (ok(b))
            addedge(a, b);
    }
}

void make_graph()
{
    memset(head, -1, sizeof(head));
    memset(id, -1, sizeof(id));
    cnt = 0;
    idcnt = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] != '*')
            {
                bfs(Point(i, j));
                if (~packnum(map[i][j]))
                    addedge1(Point(0, 0),
                            Point(getid(Point(i, j)), packnum(map[i][j])), 0);
            }
}

void dijkstra()
{
    memset(vis1, 0, sizeof(vis1));
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    pq.push(Elem(0, Point(0, 0)));
    while (!pq.empty())
    {
        Elem x;
        do
        {
            x = pq.top();
            pq.pop();
        } while (!pq.empty() && vis1[x.v.x][x.v.y]);
        if (vis1[x.v.x][x.v.y])
            break;
        Point u = x.v;
        vis1[u.x][u.y] = true;
        for (int i = head[u.x][u.y]; ~i; i = edge[i].next)
        {
            Point v = edge[i].v;
            if (vis1[v.x][v.y])
                continue;
            if (dist[v.x][v.y] == -1
                    || dist[v.x][v.y] > dist[u.x][u.y] + edge[i].w)
            {
                dist[v.x][v.y] = dist[u.x][u.y] + edge[i].w;
                pq.push(Elem(dist[v.x][v.y], v));
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == '$')
            {
                int x = id[i][j];
                for (int k = 0; k <= 26; k++)
                    if (~dist[x][k])
                        ans = min(ans, dist[x][k]);
            }
    if (ans == inf)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", ans);
}

int main()
{
    while (gets(map[0]), strcmp(map[0], "--"))
    {
        int x = 1;
        while (gets(map[x]), map[x][0])
            x++;
        n = x;
        m = strlen(map[0]);
        make_graph();
        dijkstra();
    }
    return 0;
}



