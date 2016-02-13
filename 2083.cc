#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 800

char map[maxn][maxn];

void make(int n)
{
    int each = pow(double(3), n - 2);
    for (int i = 0; i < each; i++)
        for (int j = 0; j < each; j++)
            map[i + each * 2][j] = map[i + each * 2][j + each * 2] = map[i][j + each * 2] = map[i + each][j + each] = map[i][j];
}

int findlast(int n, int size)
{
    int ret = size;
    while (map[n][ret - 1] == 0)
        ret--;
    return ret;
}

void print(int n)
{
    int size = pow(double(3), n - 1);
    for (int i = 0; i < size; i++)
    {
        int temp = findlast(i, size);
        for (int j = 0; j < temp; j++)
            if (map[i][j])
                printf("X");
            else
                printf(" ");
        printf("\n");
    }
    printf("-\n");
}

int main()
{
    memset(map, 0, sizeof(map));
    map[0][0] = 'X';
    for (int i = 2; i <= 7; i++)
        make(i);
    int n;
    while (scanf("%d", &n), n != -1)
        print(n);
    return 0;
}



