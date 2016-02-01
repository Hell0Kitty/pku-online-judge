#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

struct Player {
  string name;
  double speed;
  int weight, strength;
  Player() {}
  Player(string name, double speed, int weight, int strength)
      : name(name), speed(speed), weight(weight), strength(strength) {}
} player[5];

int weight, strength;
double speed;

void init() {
  player[0] = Player(string("Wide Receiver"), 4.5, 150, 200);
  player[1] = Player(string("Lineman"), 6.0, 300, 500);
  player[2] = Player(string("Quarterback"), 5.0, 200, 300);
}

void work() {
  bool did = false;
  for (int i = 0; i < 3; i++)
    if (speed <= player[i].speed && weight >= player[i].weight &&
        strength >= player[i].strength) {
      if (did)
        putchar(' ');
      else
        did = true;
      printf("%s", player[i].name.c_str());
    }
  if (!did)
    puts("No positions");
  else
    puts("");
}

int main() {
  init();
  while (scanf("%lf%d%d", &speed, &weight, &strength) != EOF) {
    if (speed == 0 && weight == 0 && strength == 0) break;
    work();
  }
  return 0;
}
