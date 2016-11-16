#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct Edge
{
    int v, next;
}edge[50];

struct Node
{
    int f[7];
    int s;
}q[1000000], node;

int head[10];
int ecount = 0;
bool vis[1000000];
int step[1000000];

void addedge(int a, int b)
{
    edge[ecount].v = b;
    edge[ecount].next = head[a];
    head[a] = ecount++;
}

int hash(Node &a)
{
    int x = 1;
    int ret = 0;
    for (int i = 0; i < 7; i++)
    {
        ret += a.f[i] * x;
        x *= 7;
    }
    return ret;
}

void bfs()
{
    int front = 0;
    int rear = 1;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 7; i++)
        q[0].f[i] = i;
    int h = hash(q[0]);
    step[h] = q[0].s = 0;
    vis[h] = true;
    while (front < rear)
    {
        int a;
        for (int i = 0; i < 7; i++)
            if (q[front].f[i] == 0)
            {
                a = i;
                break;
            }
        for (int i = head[a]; i != -1; i = edge[i].next)
        {
            int b = edge[i].v;
            swap(q[front].f[a], q[front].f[b]);
            h = hash(q[front]);
            if (!vis[h])
            {
                vis[h] = true;
                q[rear] = q[front];
                step[h] = q[rear++].s = q[front].s + 1;
            }
            swap(q[front].f[a], q[front].f[b]);
        }
        front++;
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(step, -1, sizeof(step));
    addedge(0, 2);
    addedge(0, 4);
    addedge(0, 6);
    addedge(1, 6);
    addedge(1, 2);
    addedge(2, 1);
    addedge(2, 0);
    addedge(2, 3);
    addedge(3, 2);
    addedge(3, 4);
    addedge(4, 3);
    addedge(4, 0);
    addedge(4, 5);
    addedge(5, 4);
    addedge(5, 6);
    addedge(6, 1);
    addedge(6, 0);
    addedge(6, 5);
    bfs();
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        for (int i = 0; i < 7; i++)
        {
            char ch = getchar();
            node.f[i] = ch - '0';
        }
        getchar();
        printf("%d\n", step[hash(node)]);
    }
    return 0;
}


