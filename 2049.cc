#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX_COORDINATE 205
#define inf 0x3f3f3f3f
#define EDGE 200

struct Grid
{
    int left, right, up, down;
}grid[MAX_COORDINATE][MAX_COORDINATE]; // using down-left coner point to present a gird

struct Point
{
    int x, y;
    int door_cnt;
    Point()
    {}
    Point(int xx, int yy, int dd):x(xx), y(yy), door_cnt(dd)
    {}
}nemo;

int wall_num, door_num;
bool vis[MAX_COORDINATE][MAX_COORDINATE];

bool operator < (const Point &a, const Point &b)
{
    return a.door_cnt > b.door_cnt;
}

void make_grids(int x, int y, int direction, int value)
{
    if (direction == 0)
    {
        grid[x][y].down = value;
        grid[x][y - 1].up = value;
    }else
    {
        grid[x][y].left = value;
        grid[x - 1][y].right = value;
    }
}            

void build_wall(int x, int y, int direction, int length)
{
    for (int i = 0; i < length; i++)
    {
        int current_x = x;
        int current_y = y;
        if (direction == 0)
            current_x += i;
        else
            current_y += i;
        make_grids(current_x, current_y, direction, inf);
    }
}

void init_grids()
{
    for (int i = 0; i < EDGE; i++)
    {
        grid[i][0].down = inf;
        grid[i][EDGE - 1].up = inf;
        grid[0][i].left = inf;
        grid[EDGE - 1][i].right = inf;
    }
}

void input()
{
    memset(grid, 0, sizeof(grid));
    init_grids();
    for (int i = 0; i < wall_num; i++)
    {
        int x, y, direction, length;
        scanf("%d%d%d%d", &x, &y, &direction, &length);
        build_wall(x, y, direction, length);
    }
    for (int i = 0; i < door_num; i++)
    {
        int x, y, direction;
        scanf("%d%d%d", &x, &y, &direction);
        make_grids(x, y, direction, 1);
    }
    double x, y;
    scanf("%lf%lf", &x, &y);
    nemo.x = floor(x);
    nemo.y = floor(y);
}

int work()
{
    if (nemo.x < 0 || nemo.x >= EDGE || nemo.y < 0 || nemo.y >= EDGE)
        return 0;
    priority_queue<Point> pq;
    pq.push(Point(0, 0, 0));
    memset(vis, 0, sizeof(vis));
    vis[0][0] = true;
    while (!pq.empty())
    {
        Point u = pq.top();
        if (u.x == nemo.x && u.y == nemo.y)
            return u.door_cnt;
        pq.pop();
        if (grid[u.x][u.y].up != inf && !vis[u.x][u.y + 1])
        {
            pq.push(Point(u.x, u.y + 1, u.door_cnt + grid[u.x][u.y].up));
            vis[u.x][u.y + 1] = true;
        }
        if (grid[u.x][u.y].down != inf && !vis[u.x][u.y - 1])
        {
            pq.push(Point(u.x, u.y - 1, u.door_cnt + grid[u.x][u.y].down));
            vis[u.x][u.y - 1] = true;
        }
        if (grid[u.x][u.y].left != inf && !vis[u.x - 1][u.y])
        {
            pq.push(Point(u.x - 1, u.y, u.door_cnt + grid[u.x][u.y].left));
            vis[u.x - 1][u.y] = true;
        }
        if (grid[u.x][u.y].right != inf && !vis[u.x + 1][u.y])
        {
            pq.push(Point(u.x + 1, u.y, u.door_cnt + grid[u.x][u.y].right));
            vis[u.x + 1][u.y] = true;
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d%d", &wall_num, &door_num), !(wall_num == -1 && door_num == -1))
    {
        input();
        printf("%d\n", work());
    }
    return 0;
}



