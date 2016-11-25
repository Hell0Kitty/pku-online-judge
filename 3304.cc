#include <iostream>
#include <math.h>
using namespace std;
#define MAXM 110
#define EPS 1e-8

typedef struct { double x1, y1, x2, y2; } Segment;

Segment segment[MAXM];
int n;

double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double corss(double x1, double y1, double x2, double y2, double x, double y) {
  return (x2 - x1) * (y - y1) - (x - x1) * (y2 - y1);
}

bool judge(double x1, double y1, double x2, double y2) {
  int i;
  if (distance(x1, y1, x2, y2) < EPS) return 0;
  for (i = 0; i < n; i++) {
    if (corss(x1, y1, x2, y2, segment[i].x1, segment[i].y1) *
            corss(x1, y1, x2, y2, segment[i].x2, segment[i].y2) >
        EPS)
      return 0;
  }
  return 1;
}

int main() {
  int t, i, j, ans;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &segment[i].x1, &segment[i].y1, &segment[i].x2,
            &segment[i].y2);
    if (n == 1) {
      printf("Yes!\n");
      continue;
    }

    ans = 0;
    for (i = 0; i < n && !ans; i++)
      for (j = i + 1; j < n && !ans; j++) {
        if (judge(segment[i].x1, segment[i].y1, segment[j].x1, segment[j].y1) ||
            judge(segment[i].x1, segment[i].y1, segment[j].x2, segment[j].y2) ||
            judge(segment[i].x2, segment[i].y2, segment[j].x1, segment[j].y1) ||
            judge(segment[i].x2, segment[i].y2, segment[j].x2, segment[j].y2))
          ans = 1;
      }
    if (ans)
      printf("Yes!\n");
    else
      printf("No!\n");
  }
  return 0;
}
