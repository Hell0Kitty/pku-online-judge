#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct node {
  char name[100], paty[100];
  int cast;
} people[21];
bool cmp(node x, node y) { return x.cast > y.cast; }
int main() {
  char win[100];
  int n, m;
  while (cin >> n) {
    cin.get();
    for (int i = 0; i < n; i++) {
      cin.getline(people[i].name, 100);
      cin.getline(people[i].paty, 100);
      people[i].cast = 0;
    };
    cin >> m;
    cin.get();
    for (int i = 0; i < m; i++) {
      cin.getline(win, 100);
      for (int j = 0; j < n; j++) {
        if (strcmp(win, people[j].name) == 0) people[j].cast++;
      }
    }
    sort(people, people + n, cmp);
    strcpy(win, "independent");
    int i = 0;
    while (strcmp(people[i].paty, win) == 0) i++;
    if (people[i].cast == people[i + 1].cast)
      cout << "tie" << endl;
    else
      cout << people[i].paty << endl;
  }
  return 0;
}
