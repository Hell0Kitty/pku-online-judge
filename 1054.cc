#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int r, c, n;
class PLANT {
 public:
  PLANT(){};
  virtual ~PLANT(){};
  int x;
  int y;
};
PLANT plants[5001];
PLANT plant;
int myCompare(const void* ele1, const void* ele2) {
  PLANT* p1, *p2;
  p1 = (PLANT*)ele1;
  p2 = (PLANT*)ele2;
  if (p1->x == p2->x) return (p1->y - p2->y);
  return (p1->x - p2->x);
}
int searchPath(PLANT secPlant, int dx, int dy) {
  PLANT plant;
  int steps;

  plant.x = secPlant.x + dx;
  plant.y = secPlant.y + dy;
  steps = 2;
  while (plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1) {
    if (!bsearch(&plant, plants, n, sizeof(PLANT), myCompare)) {
      steps = 0;
      break;
    }
    plant.x += dx;
    plant.y += dy;
    steps++;
  }
  return (steps);
}

int main() {
  int i, j, dx, dy, px, py, steps, max = 2;
  scanf("%d%d", &r, &c);
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d %d", &plants[i].x, &plants[i].y);
  qsort(plants, n, sizeof(PLANT), myCompare);
  for (i = 0; i < n - 2; i++)
    for (j = i + 1; j < n - 1; j++) {
      dx = plants[j].x - plants[i].x;
      dy = plants[j].y - plants[i].y;
      px = plants[i].x - dx;
      py = plants[i].y - dy;
      if (px <= r && px >= 1 && py <= c && py >= 1) continue;
      if (plants[i].x + max * dx > r) break;
      py = plants[i].y + max * dy;
      if (py > c || py < 1) continue;
      steps = searchPath(plants[j], dx, dy);
      if (steps > max) max = steps;
    }

  if (max == 2) max = 0;
  printf("%d\n", max);
  return 0;
}
