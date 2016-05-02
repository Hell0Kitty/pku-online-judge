#include <iostream>
#include <cmath>
#define Max 1000000
using namespace std;

struct Node {
  double x, y, r;
} * data;

bool *visit;
short Queuen[Max];
int N, f, l;

void readdata() {
  int i;

  data = new Node[N + 1];

  for (i = 1; i <= N; i++) {
    cin >> data[i].x >> data[i].y >> data[i].r;
  }
  f = l = 0;
}

bool connect(short id1, short id2) {
  double dis;
  dis = (double)sqrt((data[id1].x - data[id2].x) * (data[id1].x - data[id2].x) +
                     (data[id1].y - data[id2].y) * (data[id1].y - data[id2].y));

  if (dis < (data[id1].r + data[id2].r) &&
      dis > (double)fabs(data[id1].r - data[id2].r))
    return true;
  else if ((double)fabs(data[id1].x - data[id2].x) <= 0.00000001 &&
           (double)fabs(data[id1].y - data[id2].y) <= 0.00000001 &&
           (double)fabs(data[id1].r - data[id2].r) <= 0.00000001)
    return true;
  return false;
}

int BFS() {
  visit = new bool[N + 1];
  int Count = 1, i;
  short Id;
  for (i = 1; i <= N; i++) visit[i] = false;

  while (f < l && l < Max) {
    Id = Queuen[f++];
    visit[Id] = true;

    for (i = 1; i <= N; i++) {
      if (!visit[i]) {
        if (connect(Id, i)) {
          visit[i] = true;
          Queuen[l++] = i;
          Count++;
        }
      }
    }
  }
  delete visit;
  return Count;
}

int main() {
  while (cin >> N) {
    if (N == -1) break;

    readdata();
    int best = 0, tmp;
    for (int i = 1; i <= N; i++) {
      f = l = 0;
      Queuen[l++] = i;
      tmp = BFS();
      if (tmp > best) best = tmp;
    }

    cout << "The largest component contains " << best << " rings" << endl;
  }
  return 0;
}
