#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define pi 3.1415927

int revolution;
double travel_time, diameter;

int main() {
  int t = 0;
  while (scanf("%lf%d%lf", &diameter, &revolution, &travel_time), revolution) {
    t++;
    double distance = revolution * pi * diameter / 12 / 5280;
    double mph = distance * 3600 / travel_time;
    printf("Trip #%d: %.2f %.2f\n", t, distance, mph);
  }
  return 0;
}
