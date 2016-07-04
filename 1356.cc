#include <iostream>
using namespace std;
struct pis {  //点的位置
  int x;
  int y;
};
pis* p;
int work(pis*, int, int, int);  //核心算法
int main() {
  int n;
  cin >> n;
  while (n--) {
    int m, a;
    cin >> m >> a;
    p = new pis[m];
    int i = 0;
    while (i < m) {
      cin >> p[i].x >> p[i].y;
      i++;
    }
    int max = 0;
    i = 0;
    while (i < m) {
      int temp = work(p, i, m, a);
      if (temp > max) max = temp;
      i++;
    }
    cout << max << endl;
    delete p;
  }
  return 0;
}
int work(pis* p, int i, int m, int a) {
  int max = 0;
  int dec = 0;
  pis fix;
  fix.x = p[i].x;
  fix.y = p[i].y;
  while (dec < 4) {
    int count = 0;
    if (dec == 0) {
      for (int j = 0; j < m; j++) {
        if (p[j].x >= fix.x && p[j].y >= fix.y && p[j].x <= fix.x + a &&
            p[j].y <= fix.y + a)
          count++;
      }
    }
    if (dec == 1) {
      for (int j = 0; j < m; j++) {
        if (p[j].x >= fix.x && p[j].y <= fix.y && p[j].x <= fix.x + a &&
            p[j].y >= fix.y - a)
          count++;
      }
    }
    if (dec == 2) {
      for (int j = 0; j < m; j++) {
        if (p[j].x <= fix.x && p[j].y <= fix.y && p[j].x >= fix.x - a &&
            p[j].y >= fix.y - a)
          count++;
      }
    }
    if (dec == 3) {
      for (int j = 0; j < m; j++) {
        if (p[j].x <= fix.x && p[j].y >= fix.y && p[j].x >= fix.x - a &&
            p[j].y <= fix.y + a)
          count++;
      }
    }
    if (count > max) max = count;
    dec++;
  }
  return max;
}
