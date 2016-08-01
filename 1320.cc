#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int f[10][2];
    f[0][0] = 6;
    f[0][1] = 8;
    f[1][0] = 35;
    f[1][1] = 49;
    f[2][0] = 204;
    f[2][1] = 288;
    f[3][0] = 1189;
    f[3][1] = 1681;
    f[4][0] = 6930;
    f[4][1] = 9800;
    f[5][0] = 40391;
    f[5][1] = 57121;
    f[6][0] = 235416;
    f[6][1] = 332928;
    f[7][0] = 1372105;
    f[7][1] = 1940449;
    f[8][0] = 7997214;
    f[8][1] = 11309768;
    f[9][0] = 46611179;
    f[9][1] = 65918161;
    for (int i = 0; i < 10; i++)
        printf("%10d%10d\n", f[i][0], f[i][1]);
}


