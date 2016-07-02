#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

#define maxn 21
#define maxl 9

struct Node
{
    int x, y, state, step;
};

struct Point
{
    int x, y;
} point[maxl];

bool map[maxn][maxn];
bool vis[maxn][maxn][16384];
bool vis1[maxn][maxn];
int n, m, l;
int maxstep, minstep;
int dir[4][2] =
{
{ -1, 0 },
{ 0, 1 },
{ 1, 0 },
{ 0, -1 } };

void input()
{
    for (int i =0; i < l; i++)
        scanf("%d%d", &point[i].x, &point[i].y);
    int t;
    scanf("%d", &t);
    memset(map, 0, sizeof(map));
    for (int i =0; i < t; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        map[x][y] =true;
    }
}

bool ok1(Node &a)
{
    if (a.x <=0|| a.x > n || a.y <=0|| a.y > m)
        return false;
    return!vis1[a.x][a.y] &&!map[a.x][a.y];
}

int bfs1()
{
    queue<Node> q;
    Node temp;
    temp.x = point[0].x;
    temp.y = point[0].y;
    temp.step =0;
    q.push(temp);
    memset(vis1, 0, sizeof(vis1));
    vis1[temp.x][temp.y] =true;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i =0; i <4; i++)
        {
            Node temp2;
            temp2.x = temp.x + dir[i][0];
            temp2.y = temp.y + dir[i][1];
            temp2.step = temp.step +1;
            if (ok1(temp2))
            {
                vis1[temp2.x][temp2.y] =true;
                if (temp2.x ==1&& temp2.y ==1)
                    return temp2.step;
                q.push(temp2);
            }
        }
    }
    return-1;
}

void setmap()
{
    for (int i =1; i < l; i++)
        map[point[i].x][point[i].y] =true;
}

void clearmap()
{
    for (int i =1; i < l; i++)
        map[point[i].x][point[i].y] =false;
}

int getmin()
{
    return bfs1();
}

int getmax()
{
    setmap();
    int ret = bfs1();
    clearmap();
    return ret;
}

int getstate()
{
    int ret =0;
    for (int i =1; i < l; i++)
    {
        for (int j =0; j <4; j++)
            if (point[i].x == point[i -1].x - dir[j][0] && point[i].y == point[i -1].y - dir[j][1])
            {
                ret <<=2;
                ret |= j;
            }
    }
    return ret;
}

void getpoint(Node &a)
{
    int state = a.state;
    point[0].x = a.x;
    point[0].y = a.y;
    for (int i =1; i < l; i++)
    {
        int d = (state >> ((l - i -1) *2)) &3;
        point[i].x = point[i -1].x - dir[d][0];
        point[i].y = point[i -1].y - dir[d][1];
    }
}

bool ok(Node &a)
{
    if (a.x <=0|| a.x > n || a.y <=0|| a.y > m)
        return false;
    return!vis[a.x][a.y][a.state] &&!map[a.x][a.y];
}

int bfs()
{
    queue<Node> q;
    int state = getstate();
    Node temp;
    temp.x = point[0].x;
    temp.y = point[0].y;
    temp.state = state;
    temp.step =0;
    q.push(temp);
    memset(vis, 0, sizeof(vis));
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        getpoint(temp);
        setmap();
        Node temp2;
        for (int i =0; i <4; i++)
        {
            temp2.x = temp.x + dir[i][0];
            temp2.y = temp.y + dir[i][1];
            temp2.step = temp.step +1;
            temp2.state = (temp.state >>2) | (i << (l -2) *2);
            if (ok(temp2))
            {
                vis[temp2.x][temp2.y][temp2.state] =true;
                if (temp2.x ==1&& temp2.y ==1)
                {
                    return temp2.step;
                }
                q.push(temp2);
            }
        }
        clearmap();
    }
    return-1;
}

int main()
{
int t =0;
    while (scanf("%d%d%d", &n, &m, &l), n | m | l)
    {
        t++;
        input();
        if (point[0].x ==1&& point[0].y ==1)
        {
            printf("Case %d: %d\n", t, 0);
            continue;
        }
        int ans1 = getmin();
        int ans2 = getmax();
        if (ans1 ==-1)
        {
            printf("Case %d: %d\n", t, -1);
            continue;
        }
        if (ans1 == ans2)
        {
            printf("Case %d: %d\n", t, ans1);
            continue;
        }
        minstep = ans1;
        if (ans2 ==-1)
            maxstep =0x3f3f3f3f;
        else
            maxstep = ans2;
        int ans = bfs();
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}


