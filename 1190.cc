#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_LAYER_NUM 25
#define INF 0x3f3f3f3f

int layer_num;
int total_volume;
int min_vol[MAX_LAYER_NUM];
int min_area[MAX_LAYER_NUM];
int ans;

void init() {
  min_area[0] = min_vol[0] = 0;
  for (int i = 1; i <= 20; i++) {
    min_vol[i] = min_vol[i - 1] + i * i * i;
    min_area[i] = min_area[i - 1] + 2 * i * i;
  }
}

void DFS(int r_limit, int h_limit, int layer, int area, int volume) {
  if (layer == 0) {
    if (volume != total_volume) return;
    ans = min(ans, area);
    return;
  }
  if (total_volume - volume < min_vol[layer]) return;
  if (ans - area < min_area[layer]) return;
  if (layer < layer_num && area + 2 * (total_volume - volume) / r_limit > ans)
    return;
  for (int i = r_limit; i >= layer; i--) {
    if (layer == layer_num) {
      area = i * i;
    }
    int max_h = (total_volume - min_vol[layer - 1] - volume) / (i * i);
    for (int j = min(max_h, h_limit); j >= layer; j--) {
      DFS(i - 1, j - 1, layer - 1, area + 2 * i * j, volume + i * i * j);
    }
  }
}

int main() {
  scanf("%d%d", &total_volume, &layer_num);
  ans = INF;
  init();
  DFS((int)sqrt(total_volume), total_volume, layer_num, 0, 0);
  printf("%d\n", ans);
  return 0;
}
