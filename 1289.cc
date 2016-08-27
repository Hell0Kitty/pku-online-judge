#include <iostream>
using namespace std;

int main() {
  int init_hei, work_num;
  while (cin >> init_hei >> work_num && init_hei != 0) {
    int n = 0, v1, v2, x;
    bool flag = false;
    while (!flag) {  //  模拟解方程(n+1)^x = init_hei, n^x = work_num。
      n++;
      x = 0;
      v1 = v2 = 1;
      while (1) {
        if (v1 > init_hei || v2 > work_num) break;
        if (v1 == init_hei && v2 == work_num) {
          flag = true;
          break;
        }
        v1 *= n + 1;
        v2 *= n;
        x++;
      }
    }

    int nowork_num, hei, num, height_sum;
    if (n == 1)
      nowork_num = 0;  //  切记比为1的情况应单独考虑。
    else
      nowork_num = (work_num - 1) / (n - 1);
    hei = 1;
    num = work_num;
    height_sum = 0;
    for (int i = 0; i <= x; i++) {  //  逐项乘积相加。
      height_sum += num * hei;
      hei *= n + 1;
      num /= n;
    }
    cout << nowork_num << ' ' << height_sum << endl;
  }
  return 0;
}
