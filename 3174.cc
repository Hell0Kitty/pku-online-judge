#include <stdio.h>
#include <stdlib.h>

#define MAX_N 780

struct frac {
    int up, down;
};
struct point {
    int x, y;
};
struct slash_node {
    int from, to;
    struct frac k;
};
struct ans_node {
    int id[MAX_N], len;
};
struct seg_node {
    int start, end;
};
struct slash_node slash[MAX_N * MAX_N];
struct point in[MAX_N];
struct ans_node ans[MAX_N];
char visited[MAX_N][MAX_N];
int N, ans_cnt, slash_cnt;

__inline int gcd(int a, int b)
{
    int r;

    if (a < b) {
        r = a;
        a = b;
        b = r;
    }

    while (1) {
        r = a % b;
        if (!r)
            return b;
        a = b;
        b = r;
    }
}

__inline struct frac frac_init(int up, int down)
{
    int r, s;
    struct frac f;

    if (!down) {
        f.down = 1;
        f.up = 200000;
        return f;
    }
    if (!up) {
        f.down = 1;
        f.up = 0;
        return f;
    }

    if (up < 0) {
        up = -up;
        s = -1;
    } else
        s = 1;
    r = gcd(up, down);
    f.up = up / r;
    f.up *= s;
    f.down = down / r;
    return f;
}

__inline int frac_cmp(struct frac fa, struct frac fb)
{
    return fa.up * fb.down - fa.down * fb.up;
}

int cmp_slash(const void *a, const void *b)
{
    struct slash_node *p, *q;
    int r;

    p = (struct slash_node *)a;
    q = (struct slash_node *)b;
    if (p->from != q->from)
        return p->from - q->from;
    r = frac_cmp(p->k, q->k);
    if (!r)
        return p->to - q->to;
    return r;
}

__inline void add_slash(int from, int to)
{
    struct slash_node *s;

    if (visited[from][to])
        return ;

    s = &slash[slash_cnt++];
    s->from = from;
    s->to = to;
    if (in[from].x < in[to].x)
        s->k = frac_init(in[to].y - in[from].y, in[to].x - in[from].x);
    else
        s->k = frac_init(in[from].y - in[to].y, in[from].x - in[to].x);
}

__inline void update(int start, int end)
{
    int i;
    struct ans_node *a;

    a = &ans[ans_cnt++];
    a->len = 0;
    a->id[a->len++] = slash[start].from;
    for (i = start; i <= end; i++)
        a->id[a->len++] = slash[i].to;

    for ( ; start <= end - 1; start++)
        for (i = start + 1; i <= end; i++)
            visited[slash[start].to][slash[i].to] = 1;
}

__inline int cmp_seg(struct seg_node *a, struct seg_node *b)
{
    return slash[a->start].to - slash[b->start].to;
}

__inline void swap_seg(struct seg_node *a, struct seg_node *b)
{
    struct seg_node t = *a;
    *a = *b;
    *b = t;
}

__inline void bsort(struct seg_node *arr, int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++) 
        for (j = i; j < len - 1; j++)
            if (cmp_seg(&arr[j], &arr[j + 1]) > 0)
                swap_seg(&arr[j], &arr[j + 1]); 
}

__inline int calc(int i)
{
    int from, start, cnt, j;
    static struct seg_node arr[MAX_N];

    cnt = 0;
    for (from = slash[i].from; slash[i].from == from; i++) {
        start = i;
        while (i + 1 < slash_cnt && 
               slash[i + 1].from == from && 
               !frac_cmp(slash[i + 1].k, slash[i].k)
               )
               i++;
        if (i - start >= 1) {
            arr[cnt].start = start;
            arr[cnt].end = i;
            cnt++;
        }
    }
    if (cnt) {
        bsort(arr, cnt);
        for (j = 0; j < cnt; j++)
            update(arr[j].start, arr[j].end);
    }

    return i;
}

__inline void dump_ans(struct ans_node *a)
{
    int i, j, k;

    for (i = 0; i < a->len - 2; i++) 
        for (j = i + 1; j < a->len - 1; j++)
            for (k = j + 1; k < a->len; k++)
                printf("%d %d %d\n", a->id[i], a->id[j], a->id[k]);
}

int main()
{
    int i, j, cnt;

    scanf("%d", &N);
    for (i = 1; i <= N; i++) 
        scanf("%d%d", &in[i].x, &in[i].y);
    slash_cnt = 0;
    for (i = 1; i <= N; i++) 
        for (j = i + 1; j <= N; j++) 
            add_slash(i, j);
    qsort(slash, slash_cnt, sizeof(slash[0]), cmp_slash);
    for (i = 0; i < slash_cnt; i++)
        i = calc(i);

    cnt = 0;
    for (i = 0; i < ans_cnt; i++) 
        cnt += (ans[i].len) * (ans[i].len - 1) * (ans[i].len - 2) / 6;
    printf("%d\n", cnt);
    for (i = 0; i < ans_cnt; i++)
        dump_ans(&ans[i]);

    return 0;
}



