#include <cstdio>
#include <map>
#include <cstring>
#include <string>
using namespace std;

#define zero(x) (((x)>0?(x):-(x))<eps)
#define eps 1.0E-8
#define MAX_POINT_NUM 105
#define MAX_POLYGON_NUM 105
#define MAX_TERR_NUM 15

int double_cmp(double a)
{
    if (zero(a))
        return 0;
    return a > 0 ? 1 : -1;
}

struct Edge
{
    int v;
    int length;
    Edge()
    {}
    Edge(int v, int length):v(v), length(length)
    {}
};

struct Point
{
    double    x,y;
    Point()
    {}
    Point(double x, double y):x(x), y(y)
    {}
    Point operator - (const Point &a) const
    {
        return Point(x - a.x, y - a.y);
    }
    bool operator == (const Point &a) const
    {
        return x == a.x && y == a.y;
    }
};

double cross_product(Point a, Point b)
{
    return a.x * b.y - b.x * a.y;
}

double cross_product(Point p0, Point p1, Point p2)
{
    return cross_product(p1 - p0, p2 - p0);
}

double dot_product(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}

double dot_product(Point p0, Point p1, Point p2)
{
    return dot_product(p1 - p0, p2 - p0);
}

struct Line
{
    Point a, b;
    Line()
    {}
    Line(Point a, Point b):a(a), b(b)
    {}
    bool operator == (const Line &l) const
    {
        return l.a == a && l.b == b;
    }
};

bool points_inline(Point p1, Point p2, Point p3)
{
    return zero(cross_product(p1, p2, p3));
}

bool same_side(Point p1, Point p2, Line l)
{
    return cross_product(l.a, p1, l.b) * cross_product(l.a, p2, l.b) > eps;
}

bool point_online_in(Point p, Line l)
{
    return zero(cross_product(p, l.a, l.b)) && double_cmp(dot_product(p, l.a, l.b)) < 0;
}

bool overlap(Line u, Line v)
{
    if (u == v || (u.a == v.b && u.b == v.a))
        return true;
    if (!points_inline(u.a, u.b, v.a) || !points_inline(u.a, u.b, v.b))
        return false;
    bool ret = point_online_in(u.a, v);
    ret = ret || point_online_in(u.b, v);
    ret = ret || point_online_in(v.a, u);
    ret = ret || point_online_in(v.b, u);
    return ret;
}

struct Polygon
{
    Point point[MAX_POINT_NUM];
    int id;
    int point_num;
}polygon[MAX_POLYGON_NUM];

map<string, int> territory_id;
int polygon_num;
int territory_cnt;
int color[MAX_POLYGON_NUM];
bool graph[MAX_TERR_NUM][MAX_TERR_NUM];

void input()
{
    territory_id.clear();
    territory_cnt = 0;
    for (int i = 0; i < polygon_num; i++)
    {
        char territory_name[25];
        scanf("%s", territory_name);
        string name = string(territory_name);
        if (territory_id.find(name) == territory_id.end())
        {
            territory_id[name] = ++territory_cnt;
        }
        polygon[i].point_num = 0;
        polygon[i].id = territory_id[name];
        while (1)
        {
            int j = polygon[i].point_num;
            scanf("%lf", &polygon[i].point[j].x); 
            if (polygon[i].point[j].x == -1)
                break;
            scanf("%lf", &polygon[i].point[j].y); 
            polygon[i].point_num++;
        }
    }
}

bool neighbour(Polygon &a, Polygon &b)
{
    for (int i = 0; i < a.point_num; i++)
    {
        for (int j = 0; j < b.point_num; j++)
        {
            Line l1 = Line(a.point[i], a.point[(i + 1) % a.point_num]);
            Line l2 = Line(b.point[j], b.point[(j + 1) % b.point_num]);
            if (overlap(l1, l2))
                return true;
        }
    }
    return false;
}

void create_graph()
{
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < polygon_num - 1; i++)
    {
        for (int j = i + 1; j < polygon_num; j++)
        {
            int a = polygon[i].id;
            int b = polygon[j].id;
            a--;
            b--;
            if (a == b || graph[a][b])
                continue;
            if (neighbour(polygon[i], polygon[j]))
                graph[a][b] = graph[b][a] = true;
        }
    }
}

bool ok(int u)
{
    for (int i = 0; i < territory_cnt; i++)
        if (i != u && graph[i][u])
        {
            if (color[u] == color[i])
                return false;
        }
    return true;
}

bool dfs(int color_num, int u)
{
    if (u == territory_cnt)
    {
        return true;
    }
    for (int i = 0; i < color_num; i++)
    {
        color[u] = i;
        if (!ok(u))
            continue;
        if (dfs(color_num, u + 1))
            return true;
    }
    color[u] = -1;
    return false;
}

int main()
{
    while (scanf("%d", &polygon_num), polygon_num)
    {
        input();
        create_graph();
        int ans = 0;
        while (ans <= 10)
        {
            ans++;
            memset(color, -1, sizeof(color));
            color[0] = 0;
            if (dfs(ans, 1))
            {
                printf("%d\n", ans);
                break;
            }
        }
    }
    return 0;
}



