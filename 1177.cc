#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_REC_NUM 5005
#define MAX_INTERVAL MAX_REC_NUM * 2

struct Node
{
    int    l, r;
    Node    *pleft, *pright;
    int    num;
    bool    to_left, to_right;    
    int    edge_num;
};

int    node_cnt;
Node    tree[MAX_INTERVAL * 3];

struct Interval
{
    int start, end;
    int pos;
    int value;
    Interval()
    {}
    Interval(int start, int end, int pos, int value):start(start), end(end), pos(pos), value(value)
    {}
    bool operator < (const Interval &a)const
    {
        if (pos != a.pos)
            return pos < a.pos;
        return value > a.value;
    }
}interval[MAX_REC_NUM * 2];

struct Rectangle
{
    int l, d, u, r;
}rec[MAX_REC_NUM];

int discrete[MAX_REC_NUM * 2];
int discrete_num;
int rec_num;
int interval_num;

int get_index(int a)
{
    return lower_bound(discrete, discrete + discrete_num, a) - discrete;
}

void discretization(int discrete[], int &discrete_num)
{
    sort(discrete, discrete + discrete_num);
    discrete_num = unique(discrete, discrete + discrete_num) - discrete;
}

void input()
{
    scanf("%d", &rec_num);
    for (int i = 0; i < rec_num; i++)
    {
        int l, d, r, u;
        scanf("%d%d%d%d", &l, &d, &r, &u);
        rec[i].l = l;
        rec[i].r = r;
        rec[i].u = u;
        rec[i].d = d;
    }
}

void make_xscan()
{
    discrete_num = 0;
    interval_num = 0;
    for (int i = 0; i < rec_num; i++)
    {
        int l, d, r, u;
        l = rec[i].l;
        r = rec[i].r;
        u = rec[i].u;
        d = rec[i].d;
        interval[interval_num++] = Interval(d, u, l, 1);
        interval[interval_num++] = Interval(d, u, r, -1);
        discrete[discrete_num++] = u;
        discrete[discrete_num++] = d;
    }
}

void make_yscan()
{
    discrete_num = 0;
    interval_num = 0;
    for (int i = 0; i < rec_num; i++)
    {
        int l, d, r, u;
        l = rec[i].l;
        r = rec[i].r;
        u = rec[i].u;
        d = rec[i].d;
        interval[interval_num++] = Interval(l, r, d, 1);
        interval[interval_num++] = Interval(l, r, u, -1);
        discrete[discrete_num++] = l;
        discrete[discrete_num++] = r;
    }
}

void buildtree(Node *proot, int s, int e)
{
    proot->l = s;
    proot->r = e;
    proot->to_left = false;
    proot->to_right = false;
    proot->num = 0;
    proot->edge_num = 0;
    if (s == e)
    {
        proot->pleft = proot->pright = NULL;
        return;
    }
    node_cnt++;
    proot->pleft = tree + node_cnt;
    node_cnt++;
    proot->pright = tree + node_cnt;
    buildtree(proot->pleft, s, (s + e) / 2);
    buildtree(proot->pright, (s + e) / 2 + 1, e);
}

void recount(Node *p)
{
    if (p->num > 0)
    {
        p->edge_num = 0;
        p->to_right = p->to_left = true;
        return;
    }
    if (p->pleft == NULL || p->pright == NULL)
    {
        p->edge_num = 0;
        p->to_right = p->to_left = false;
        return;
    }
    p->to_left = p->pleft->to_left;
    p->to_right = p->pright->to_right;
    p->edge_num = p->pleft->edge_num + p->pright->edge_num;
    if (p->pleft->to_right != p->pright->to_left)
        p->edge_num++;
}

void insert(Node *proot, int s, int e, int value)
{
    if (s > proot->r || e < proot->l)
        return;
    s = max(s, proot->l);
    e = min(e, proot->r);
    if (s == proot->l && e == proot->r)
    {
        proot->num += value;
        recount(proot);
        return;
    }
    insert(proot->pleft, s, e, value);
    insert(proot->pright, s, e, value);
    recount(proot);
}

long long work()
{
    long long ans = 0;
    for (int i = 0; i < interval_num; i++)
    {
        int s = get_index(interval[i].start);
        int e = get_index(interval[i].end) - 1;
        insert(tree, s, e, interval[i].value);
        long long line_num = tree->edge_num;
        if (tree->to_left)
            line_num++;
        if (tree->to_right)
            line_num++;
        if (i != interval_num - 1)
            ans += (interval[i + 1].pos - interval[i].pos) * line_num;
    }
    return ans;
}

int main()
{
    input();
    long long ans = 0;
    make_xscan();
    sort(interval, interval + interval_num);
    discretization(discrete, discrete_num);
    buildtree(tree, 0, discrete_num);
    ans += work();

    make_yscan();
    sort(interval, interval + interval_num);
    discretization(discrete, discrete_num);
    buildtree(tree, 0, discrete_num);
    ans += work();

    printf("%lld\n", ans);
    return 0;
}


