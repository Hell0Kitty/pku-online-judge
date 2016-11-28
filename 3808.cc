#include <cstdio>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
} A, B, C, I;

double get_dis(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    while(~scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y)) {
        if(A.x == 0 && A.y == 0 && B.x == 0 && B.y == 0 && C.x == 0 && C.y == 0) break;
        double a = get_dis(B, C);
        double b = get_dis(A, C);
        double c = get_dis(A, B);
        double s = (a + b + c) / 2;  // 半周长
        I.x = (a * A.x + b * B.x + c * C.x) / (a + b + c);
        I.y = (a * A.y + b * B.y + c * C.y) / (a + b + c); // 内切圆圆心坐标
        double r = sqrt((s - a) * (s - b) * (s - c) / s); // 内切圆半径
        double IA = get_dis(A, I);
        double IB = get_dis(B, I);
        double IC = get_dis(C, I);
        double r1 = r / (2 * (s - a)) * (s - r + IA - IB - IC);
        double r2 = r / (2 * (s - b)) * (s - r + IB - IA - IC);
        double r3 = r / (2 * (s - c)) * (s - r + IC - IA - IB);
        printf("%.6lf %.6lf %.6lf\n", r1, r2, r3);
    }
    return 0;
}



