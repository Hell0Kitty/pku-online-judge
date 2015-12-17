#include <stdio.h>
#include <string.h>

int map[16];
int bit_cnt[256];

__inline int calc_cnt(unsigned short val)
{
    return bit_cnt[val & 0xff] + 
           bit_cnt[(val >> 8)];
}

struct {
    int a, b, c;
} stat[20] = {
    {0, 1, 2},
    {0, 1, 3},
    {0, 1, 4},
    {0, 1, 5},

    {0, 2, 3},
    {0, 2, 4},
    {0, 2, 5},

    {0, 3, 4},
    {0, 3, 5},

    {0, 4, 5},

    {1, 2, 3},
    {1, 2, 4},
    {1, 2, 5},

    {1, 3, 4},
    {1, 3, 5},

    {1, 4, 5},

    {2, 3, 4},
    {2, 3, 5},

    {2, 4, 5},

    {3, 4, 5},
};

char input[1024];
char ans[32];

int dfs(int, int);

__inline int can(int a, int b, int c, int d, int used, int step)
{
    int sa, sb, sc, sd, mask;

    mask = (1 << a) | (1 << b) | (1 << c) | (1 << d);
    if (used & mask)
        return 0;
    if ((map[a] & mask) != (1 << a))
        return 0;
    if ((map[b] & mask) != (1 << b))
        return 0;
    if ((map[c] & mask) != (1 << c))
        return 0;
    sa = map[a];
    sb = map[b];
    sc = map[c];
    sd = map[d];
    map[a] |= mask;
    map[b] |= mask;
    map[c] |= mask;
    map[d] |= mask;
    ans[step] = a + 'A';
    ans[step + 1] = b + 'A';
    ans[step + 2] = c + 'A';
    ans[step + 3] = d + 'A';
    if (dfs(used | mask, step + 4))
        return 1;
    map[a] = sa;
    map[b] = sb;
    map[c] = sc;
    map[d] = sd;
    return 0;
}

int dfs(int used, int step)
{
    int i, j, d, arr[6];

    if (step == 32) {
        for (i = 0; i < 12; i++) {
            printf("%.4s ", &input[i*4]);
            if ((i&3) == 3)
                printf("\n");
        }
        for (i = 0; i < 8; i++) {
            printf("%.4s ", &ans[i*4]);
            if ((i&3) == 3)
                printf("\n");
        }
        return 1;
    }

    if (used == 0xffff) 
        return dfs(0, step);

    for (d = 0; d < 16; d++)
        if (!(used & (1 << d)))
            break;
    j = 0;
    for (i = 0; i < 16; i++)
        if (!(map[d] & (1 << i)))
            arr[j++] = i;

    if (j == 6) {
        for (i = 0; i < 20; i++) 
            if (can(arr[stat[i].a], arr[stat[i].b], arr[stat[i].c], d, used, step))
                return 1;        
    } else if (j == 3) {
        if (can(arr[0], arr[1], arr[2], d, used, step))
            return 1;
    } else
        *(int *)NULL = 0;

    return 0;
}

int solve()
{
    int i;

    for (i = 0; i < 16; i++) {
        if (calc_cnt(map[i]) < 10)
            return 0;
    }

    return dfs(0, 0);
}

int main()
{
    int i, j, k, mask;
    char *str;

    //freopen("e:\\test\\in.txt", "r", stdin);

    for (i = 0; i < 256; i++) {
        k = 0;
        for (j = i; j; j &= j - 1)
            k++;
        bit_cnt[i] = k;
    }

    while (1) {
        memset(map, 0, sizeof(map));
        str = input;
        for (i = 0; i < 12; i++) {
            if (scanf("%s", str) == EOF)
                return 0;
            mask = 0;
            for (j = 0; j < 4; j++)
                mask |= 1 << (str[j] - 'A');
            for (j = 0; j < 4; j++)
                map[str[j] - 'A'] |= mask;
            str += 4;
        }

        if (!solve())
            printf("It is not possible to complete this schedule.\n");
        printf("\n");
    }

    return 0;
}
