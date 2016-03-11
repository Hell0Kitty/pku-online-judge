#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_NODE_NUM 1005

struct Node
{
    int value;
    int father;
    int next;
    int child;
    int id;
    int num;
}node[MAX_NODE_NUM];

int root_id, node_num;
bool vis[MAX_NODE_NUM];
int link[MAX_NODE_NUM];
int original_value[MAX_NODE_NUM];

void add_edge(int father, int son)
{
    int temp = node[father].child;
    node[father].child = son;
    node[son].next = temp;
    node[son].father = father;
}

void input()
{
    memset(node, -1, sizeof(node));
    for (int i = 0; i < node_num; i++)
    {
        scanf("%d", &node[i].value);
        node[i].id = i;
        node[i].num = 1;
        original_value[i] = node[i].value;
    }
    for (int i = 0; i < node_num - 1; i++)
    {
        int node_a, node_b;
        scanf("%d%d", &node_a, &node_b);
        node_a--;
        node_b--;
        add_edge(node_a, node_b);
    }
}

void merge_with_father(int id)
{
    int father = node[id].father;
    node[father].value += node[id].value;
    node[father].num += node[id].num;
    node[father].id = node[id].id;
    int end = id;
    while (node[end].next != -1)
        end = node[end].next;
    node[end].next = node[id].child;
    while (node[end].next != -1)
    {
        end = node[end].next;
        node[end].father = father;
    }
    //printf("father:%d\tson:%d\n", father + 1, id + 1);
}

bool larger(int a, int b)
{
    if (a == -1)
        return true;
    return node[a].value * node[b].num < node[b].value * node[a].num;
}

void work()
{
    memset(vis, 0, sizeof(vis));
    vis[root_id] = true;
    while (1)
    {
        int p = -1;
        for (int i = 0; i < node_num; i++)
            if (!vis[i] && larger(p, i))
                p = i;
        if (p == -1)
            break;
        vis[p] = true;
        link[node[node[p].father].id] = p;
        merge_with_father(p);
    }
    int temp = root_id;
    int ans = 0;
    for (int i = 1; i <= node_num; i++)
    {
        ans += i * original_value[temp];
        temp = link[temp];    
    }
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d%d", &node_num, &root_id), node_num | root_id)
    {
        root_id--;
        input();
        work();
    }
    return 0;
}



