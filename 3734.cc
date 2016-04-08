#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 4
#define w 10007

struct Matrix
{
    int a[maxn][maxn];
    int x, y;
}ans, f;

int n;
int matrix[maxn][maxn]={{2,1,1,0},{1,2,0,1},{1,0,2,1},{0,1,1,2}};

Matrix mul(Matrix &a, const Matrix &b)
{
    Matrix ret;
    for (int i =0; i < a.x; i++)
        for (int j =0; j < b.y; j++)
        {
            int d =0;
            for (int k =0; k < a.y; k++)
                d = (d + a.a[i][k] * b.a[k][j] % w) % w;
            ret.a[i][j] = d;
        }
    ret.x = a.x;
    ret.y = b.y;
    return ret;
}

Matrix power(Matrix m, int n)
{
    Matrix ret;
    memset(ret.a, 0, sizeof(ret.a));
    for (int i =0; i <4; i++)
        ret.a[i][i] =1;
    ret.x = ret.y =4;
    for (int k =1; k <= n; k <<=1)
    {
        if (k & n)
            ret = mul(ret, m);
        m = mul(m, m);
    }
    return ret;
}

int main()
{
    f.x = f.y =4;
    for (int i =0; i <4; i++)
        for (int j =0; j <4; j++)
            f.a[i][j] = matrix[i][j];
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        f.x = f.y =4;
        memset(ans.a, 0, sizeof(ans.a));
        ans.a[0][0] =1;
        ans.x =1;
        ans.y =4;
        ans = mul(ans, power(f, n));
        printf("%d\n", ans.a[0][0]);
    }
    return 0;
}




