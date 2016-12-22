#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define maxn 205
#define maxm 20005
#define maxl 50

struct Edge
{
    int v, w, next;
}edge[maxm * 2];

int city_num, road_num;
int head[maxn];
map<string, int> city_name;
int city_cnt;
int edge_cnt;
int start_pos, end_pos;
int dist[maxn];
bool vis[maxn];

void addedge(int a, int b, int weight)
{
    edge[edge_cnt].v = b;
    edge[edge_cnt].w = weight;
    edge[edge_cnt].next = head[a];
    head[a] = edge_cnt++;
}

int city_id(char *st)
{
    string a;
    a.assign(st);
    if (city_name.find(a) == city_name.end())
    {
        city_name[a] = city_cnt++;
        return city_cnt - 1;
    }
    return city_name[a];
}

void input()
{
    memset(head, -1, sizeof(head));
    edge_cnt = 0;
    city_cnt = 0;
    city_name.clear();
    char a[maxl], b[maxl];
    int weight;
    for (int i = 0; i < road_num; i++)
    {
        scanf("%s%s%d", a, b, &weight);
        int id_a = city_id(a);
        int id_b = city_id(b);
        addedge(id_a, id_b, weight);
        addedge(id_b, id_a, weight);
    }
    scanf("%s%s", a, b);
    start_pos = city_id(a);
    end_pos = city_id(b);
}

int dijkstra(int s, int e)
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    dist[s] = 10000;
    while (1)
    {
        int p = -1;
        int temp = -1;
        for (int i = 0; i < city_num; i++)
            if (!vis[i] && dist[i] > temp)
            {
                p = i;
                temp = dist[i];
            }
        if (p == -1)
            break;
        vis[p] = true;
        for (int i = head[p]; i != -1; i = edge[i].next)
            dist[edge[i].v] = max(dist[edge[i].v], min(dist[p], edge[i].w));
    }
    return dist[e];
}

int main()
{
    int t = 0;
    while (scanf("%d%d", &city_num, &road_num), city_num | road_num)
    {
        t++;
        input();
        printf("Scenario #%d\n%d tons\n\n", t, dijkstra(start_pos, end_pos));
    }
    return 0;
}


