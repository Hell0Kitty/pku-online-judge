#include <iostream>
using namespace std;
#define Max 21
int map[Max][Max];
void floyd() {
  for (int m = 1; m <= 20; m++)  // m代表mid,即中间的点
    for (int b = 1; b <= 20; b++)  // b代表begin,即开始的点
      for (int e = 1; e <= 20; e++)  // e代表end,即结束的点
        if (map[b][e] > map[b][m] + map[m][e])
          map[b][e] = map[b][m] + map[m][e];
}
int main() {
  int n, num, end, i, j, start, count = 1;
  while (cin >> num) {
    memset(map, 21, sizeof(map));  //这个松驰操作关键的第一步，也是关键的一步
    while (num--) {
      cin >> end;
      map[1][end] = map[end][1] = 1;  //初始化map,注意初始时的双向性
    }
    for (i = 2; i <= 19; i++) {
      cin >> num;
      while (num--) {
        cin >> end;
        map[i][end] = map[end][i] = 1;  //初始化map,注意初始时的双向性
      }
    }
    floyd();
    cin >> n;
    cout << "Test Set #" << count++ << endl;
    while (n--) {
      cin >> start >> end;
      cout << start << " to " << end << ": " << map[start][end] << endl;
    }
    cout << endl;
  }
  return 0;
}
