nclude <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 25
#define maxw 10005

int n, m;
int hook[maxn], weight[maxn];
int f[maxn][maxw];

int main()
{

    scanf("%d%d", &n, &m);
    for (int i =0; i < n; i++)
        scanf("%d", &hook[i]);
    for (int i =0; i < m; i++)
        scanf("%d", &weight[i]);
    f[0][5000] =1;
    for (int i =0; i < m; i++)
        for (int j =0; j < maxw; j++)
            if (f[i][j])
                for (int k =0; k < n; k++)
                    f[i +1][j + hook[k] * weight[i]] += f[i][j];
    printf("%d\n", f[m][5000]);
    return 0;
}



