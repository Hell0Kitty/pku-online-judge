#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double g[100][100], dist[100];
bool visit[100];
int n, t_id; //n为墙数，t_id为终点在图中的编号

const double eps = 1e-8;
const double inf = 999999999;

/*door[i][j][k]表示第i堵墙的j扇门的第k端点
  s为起点，t为终点
*/
struct Point {
    double x, y;
} door[20][2][2], s, t;

//叉积
double multi(Point p1, Point p2, Point p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

//判断线段ab与直线cd是否相交，过端点也算相交
bool cross(Point a, Point b, Point c, Point d) {
    if (multi(a, d, c) * multi(b, d, c) > eps) return false;
    return true;
}

//求两点距离
double dis(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//判断两点是否能够直接相连不撞墙
bool judge(int i, int j, Point a, Point b) {
     for (; i <= j; i++)
         if (cross(door[i][0][0], door[i][0][1], a, b) == false && cross(door[i][1][0], door[i][1][1], a, b) == false)
            return false;
     return true;
}

//构图：将不同墙上的门之间的距离构造进图
void make_map() {
     int i, j, k, l, p, q, x, y;

     for (i = 0; i < n-1; i++)
         for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++) {
                x = 4*i+2*j+k+1;
                for (l = i + 1; l < n; l++)
                    for (p = 0; p < 2; p++)
                        for (q = 0; q < 2; q++) {
                            y = 4*l+2*p+q+1;
                            if (judge(i+1, l-1, door[i][j][k], door[l][p][q]))
                                g[x][y] = dis(door[i][j][k], door[l][p][q]);
                        }
            }
}

//求最短距
double Dikstra() {
    int i, j, cur;
    double tmp;

    memset(visit, false, sizeof (visit));
    for (i = 1; i <= t_id; i++) dist[i] = inf;
    dist[0] = 0;
    for (i = 0; i <= t_id; i++) {
        tmp = inf;
        cur = -1;
        for (j = 0; j <= t_id; j++)
            if (!visit[j] && dist[j] < tmp) {
                tmp = dist[j];
                cur = j;
            }
        visit[cur] = true;
        if (cur == t_id) break;
        for (j = 0; j <= t_id; j++) {
            if (!visit[j] && g[cur][j] > eps && dist[cur] + g[cur][j] + eps < dist[j])
                dist[j] = dist[cur] + g[cur][j];
        }
    }
    return dist[t_id];
}

int main()
{
    double x, y1, y2, y3, y4;
    int i, j, k;

    //初始化起点终点坐标
    s.x = 0; s.y = 5;
    t.x = 10; t.y = 5;
    while (scanf ("%d", &n) && n != -1) {
        for (i = 0; i < n; i++) {
            scanf ("%lf%lf%lf%lf%lf", &x, &y1, &y2, &y3, &y4);
            door[i][0][0].x = door[i][0][1].x = door[i][1][0].x = door[i][1][1].x = x;
            door[i][0][0].y = y1; door[i][0][1].y = y2;
            door[i][1][0].y = y3; door[i][1][1].y = y4;
        }
        memset(g, 0, sizeof (g));
        t_id = 4 * n + 1; //求出终点在图中的编号
        if (judge(0, n-1, s, t)) { //r若起点终点可以直接相连，则这两点距离即为答案
            printf ("%.2lf\n", dis(s, t));
            continue;
        }
        int id;
        //将起点和终点与中间的墙上的门的距离构造进图
        for (i = 0; i < n; i++) {
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 2; k++) {
                    id = 4*i+2*j+k+1; //求出门上的点在图中的编号
                    if (judge(0, i-1, s, door[i][j][k])) g[0][id] = dis(s, door[i][j][k]);
                    if (judge(i+1, n-1, door[i][j][k], t)) g[id][t_id] = dis(door[i][j][k], t);
                }
            }
        }
        make_map();
        printf ("%.2lf\n", Dikstra());
    }
    return 0;
}


