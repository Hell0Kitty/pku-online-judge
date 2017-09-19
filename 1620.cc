#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 12;

class Tower {
 public:
  double x, y;
  void set() { cin >> x >> y; }
  bool near(const Tower& t) const {
    return ((x - t.x) * (x - t.x) + (y - t.y) * (y - t.y)) <= 20 * 20;
  }
};

int n, no = 0, color[MAX];
bool map[MAX][MAX];
Tower tower[MAX];

void init() { memset(map, false, sizeof(map)); }

bool check(int v) {
  for (int i = 0; i < n; i++) {
    if (map[v][i] && color[v] == color[i]) {
      return false;
    }
  }
  return true;
}

bool DFS(int v, int c) {
  if (c == 4 || v >= n) {
    return true;
  }
  for (int i = 1; i <= c; i++) {
    color[v] = i;
    if (check(v)) {
      if (DFS(v + 1, c)) {
        return true;
      }
    }
    color[v] = 0;
  }
  return false;
}

int main() {
  while (cin >> n && n) {
    init();
    for (int i = 0; i < n; i++) {
      tower[i].set();
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (tower[i].near(tower[j])) {
          map[i][j] = map[j][i] = true;
        }
      }
    }
    for (int i = 1; i <= 4; i++) {
      memset(color, 0, sizeof(color));
      if (DFS(0, i)) {
        cout << "The towers in case " << ++no << " can be covered in " << i
             << " frequencies." << endl;
        break;
      }
    }
  }
  return 0;
}
