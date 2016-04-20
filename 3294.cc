#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 100500;
const int nMAX = 105;
const int mMAX = 1005;

int n, sum[nMAX];
char str[nMAX][mMAX];
int m, num[MAX];
int sa[MAX], rank[MAX], height[MAX];
int wa[MAX], wb[MAX], wv[MAX], wd[MAX];

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int *r, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++)
        {
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1 : p ++;
        }
    }
}

void calHeight(int *r, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i ++]] = k)
    {
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}

int getId(int k)                         
{
    int low = 0, high = n - 1, mid;
    while(low < high)
    {
        mid = (low+high) / 2;
        if(sum[mid] < k) {
            low = mid + 1;
        }else {
            high = mid;
        }
    }
    return low;
}

bool valid(int len, int out = 0)
{
    int i = n + 1, j, k, id, cnt;
    bool f[nMAX];
    while(1)
    {
        while(i <= m && height[i] < len) i ++;
        if(i > m) break;
        memset(f, 0, sizeof(f));
        id = getId(sa[i-1]);
        f[id] = true;
        cnt = 1;
        while(i <= m && height[i] >= len)
        {
            id = getId(sa[i]);
            if(!f[id]) {
                f[id] = true;
                cnt ++;
            }
            i ++;
        }
        if(out == 0) {
            if(2 * cnt > n) return true;
        }else {
            if(2 * cnt > n) {
                for(k = sa[i-1], j = 0; j < len; k ++, j ++)
                {
                    printf("%c", num[k] + 'a' - 100);
                }
                printf("\n");
            }
        }
    }
    return false;
}

int main()
{
    int i, j, k;
    while(scanf("%d", &n) && n != 0)
    {
        scanf("%s", str[0]);
        if(n == 1) {
            printf("%s\n\n", str[0]);
            continue;
        }
        sum[0] = strlen(str[0]);
        for(i = 1; i < n; i ++)
        {
            scanf("%s", str[i]);
            sum[i] = sum[i-1] + strlen(str[i]) + 1;
        }
        for(k = i = 0; i < n; i ++)
        {
            for(j = 0; j < strlen(str[i]); j ++)
            {
                num[k ++] = str[i][j] - 'a' + 100;
            }
            num[k ++] = i;
        }
        m = k - 1;
        da(num, m + 1, 130);
        calHeight(num, m);
        int low = 0, high = m, mid;
        while(low < high)                
        {
            mid = (low+high+1) / 2;
            if(valid(mid)) {
                low = mid;
            }else {
                high = mid - 1;
            }
        }
        if(low == 0) {
            printf("?\n\n");
        }else {                          
            valid(low, 1);
            printf("\n");
        }
    }
    return 0;

}



