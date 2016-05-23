#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1024

struct node {
    int w, h, k;
};

struct node in[MAX_N], *sort_h[MAX_N], *sort_k[MAX_N];
int A, B, C, N, ch, cw, ans, box, slash, cnt;

int cmp_h(const void *a, const void *b)
{
    return (*(struct node **)b)->h - (*(struct node **)a)->h;
}

int cmp_k(const void *a, const void *b)
{
    return (*(struct node **)b)->k - (*(struct node **)a)->k;
}

__inline void update(int h, int w)
{
    int k;

    for ( ; box < N && sort_h[box]->h >= h; box++)
        if (sort_h[box]->w >= w && sort_h[box]->w <= w + cw)
            cnt++;
    k = A * h + B * w + C;
    for ( ; slash < N && sort_k[slash]->k > k; slash++)
        if (sort_k[slash]->w >= w && sort_k[slash]->w <= w + cw)
            cnt--;
    if (cnt > ans)
        ans = cnt;
}

__inline void calc(int i)
{
    int h, w;

    box = 0;
    slash = 0;
    cnt = 0;
    h = sort_h[i]->h;
    w = sort_h[i]->w;
    for ( ; i < N && sort_h[i]->h >= h - ch; i++) 
        if (sort_h[i]->w >= w && sort_h[i]->w <= w + cw)
            update(sort_h[i]->h, w);
}

int main()
{
    int i;

    scanf("%d%d%d%d", &N, &A, &B, &C);
    cw = C/B;
    ch = C/A;
    for (i = 0; i < N; i++) {
        scanf("%d%d", &in[i].h, &in[i].w);
        in[i].k = A * in[i].h + B * in[i].w;
        sort_h[i] = &in[i];
        sort_k[i] = &in[i];
    }
    qsort(sort_h, N, sizeof(sort_h[0]), cmp_h);
    qsort(sort_k, N, sizeof(sort_k[0]), cmp_k);

    for (i = 0; i < N; i++)
        calc(i);
    printf("%d\n", ans);

    return 0;
}



