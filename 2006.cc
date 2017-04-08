#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
  double Ka;   //平衡常数
  double ori;  //原始酸浓度
  int m;       // 1摩酸分子 完全溶解 分解出氢离子数
  int n;       // 1摩酸分子 完全溶解 分解出酸根离子数
  double H;    //最后计算Ph值的氢离子数

  while (1) {
    cin >> Ka;
    cin >> ori;
    cin >> m;
    cin >> n;

    if (Ka == 0 && ori == 0 && m == 0 && n == 0) break;

    H = (sqrt(Ka * Ka + 4 * m * n * Ka * ori) - Ka) / (2 * n);
    printf("%.3f\n", -log10(H));
  }

  return 0;
}
