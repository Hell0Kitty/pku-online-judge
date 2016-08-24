#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 35

int f[maxn][maxn];
int g[maxn][maxn];
int x[maxn];
int dir[5][2] =
{
{ 0, 0 },
{ 0, 1 },
{ 1, 0 },
{ -1, 0 },
{ 0, -1 } };

void debug()
{
    for (int i =0; i <30; i++)
    {
        for (int j =0; j <31; j++)
            cout <<""<< g[i][j];
        cout << endl;
    }
    cout << endl;
}

void input()
{
    for (int i =0; i <5; i++)
        for (int j =0; j <6; j++)
            scanf("%d", &g[i *6+ j][30]);
}

void work()
{
    int k;
    int row, col;
    for (row =0, col =0; row <30&& col <30; row++, col++)
    {
        for (k = row; k <30; k++)
            if (g[k][col] !=0)
                break;
        if (k ==30)
        {
            row--;
            continue;
        }
        if (k != row)
            for (int i = col; i <=30; i++)
                swap(g[row][i], g[k][i]);
        for (int i = row +1; i <30; i++)
            if (g[i][col])
                for (int j = col; j <=30; j++)
                    g[i][j] ^= g[row][j];
    }
    for (int i = row; i >=0; i--)
    {
        x[i] = g[i][30];
        for (int j =29; j > i; j--)
            x[i] ^= (g[i][j] && x[j]);
    }
}

void print()
{
    for (int i =0; i <5; i++)
    {
        printf("%d", x[i *6]);
        for (int j =1; j <6; j++)
            printf(" %d", x[i *6+ j]);
        putchar('\n');
    }
}

int main()
{

    for (int i =0; i <5; i++)
        for (int j =0; j <6; j++)
            for (int k =0; k <5; k++)
            {
                int a = i + dir[k][0];
                int b = j + dir[k][1];
                if (a >=0&& b >=0&& a <5&& b <6)
                    f[i *6+ j][a *6+ b] =1;
            }
    int t;
    scanf("%d", &t);
    for (int i =0; i < t; i++)
    {
        printf("PUZZLE #%d\n", i +1);
        memcpy(g, f, sizeof(g));
        input();
        work();
        print();
    }
    return 0;
}


