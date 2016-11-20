#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int getid(char *st)
{
    if (strcmp(st, "T") == 0)
        return 0;
    if (strcmp(st, "D") == 0)
        return 1;
    return 2;
}

void calt(double &t, double &d, double &h)
{
    double e, hh;
    e = 6.11 * exp((5417.7530 * ((1 / 273.16) - (1 / (d + 273.16)))));
    hh = (0.5555) * (e - 10.0);
    t = h - hh;
}

void cald(double &t, double &d, double &h)
{
    double e, hh;
    hh = h - t;
    e = hh / 0.5555 + 10.0;
    d = 1 / (1 / 273.16 - log(e / 6.11) / 5417.7530) - 273.16;
}

void calh(double &t, double &d, double &h)
{
    double e, hh;
    e = 6.11 * exp((5417.7530 * ((1 / 273.16) - (1 / (d + 273.16)))));
    hh = (0.5555) * (e - 10.0);
    h = t + hh;
}

int main()
{
    char st[100];
    double data[3];
    while (scanf("%s", st) != EOF && !(strcmp(st, "E") == 0))
    {
        data[0] = data[1] = data[2] = 0;
        double a;
        scanf("%lf", &a);
        data[getid(st)] = a;
        scanf("%s", st);
        scanf("%lf", &a);
        data[getid(st)] = a;
        getchar();
        if (data[0] == 0)
            calt(data[0], data[1], data[2]);
        if (data[1] == 0)
            cald(data[0], data[1], data[2]);
        if (data[2] == 0)
            calh(data[0], data[1], data[2]);
        printf("T %.1f D %.1f H %.1f\n", data[0], data[1], data[2]);
    }
    return 0;
}


