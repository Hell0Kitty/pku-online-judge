#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <cmath>
using namespace std;
const double pi = 3.141592653589793;
const double r = 6378.0;

struct node {
    double j, w;
    node() {}
    node(double _x, double _y): j(_x), w(_y) {}
};
map<string, node> g;

inline double dist(double j1, double w1, double j2, double w2) {
    return r*acos(cos(w1)*cos(w2)*cos(j2-j1) + sin(w1)*sin(w2));
}
int main() {
    g.clear();

    char s1[33], s2[33];
    double j, w;
    while (scanf(" %s", s1) == 1 && s1[0] != '#') {
        scanf(" %lf %lf", &w, &j);
        w = w*pi/180.0;
        j = j*pi/180.0;
        g[s1] = node(j, w);
    }
    node a, b;
    while (scanf(" %s %s", s1, s2) == 2) {
        if (s1[0] == '#' && s2[0] == '#')
            break;
        printf("%s - %s\n", s1, s2);
        if (g.find(s1) != g.end() && g.find(s2) != g.end())
            a = g[s1], b = g[s2];
        else {
            printf("Unknown\n\n");
            continue;
        }
        double d = dist(a.j, a.w, b.j, b.w);
        printf("%.0lf km\n\n", d);
    }
    return 0;
}



