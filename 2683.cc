#include <iostream>
using namespace std;

int main() {
  int cases;
  scanf("%d", &cases);
  while (cases--) {
    int fund, year, op, ans = -1;
    scanf("%d%d%d", &fund, &year, &op);
    while (op--) {
      int A, B, flag, charge;
      double rate;
      scanf("%d%lf%d", &flag, &rate, &charge);
      A = fund;
      if (flag == 1) {
        for (int i = 0; i < year; ++i) {
          B = (int)A * rate;
          A = A + B - charge;
        }
      } else {
        int cumulative = 0;
        for (int i = 0; i < year; ++i) {
          B = (int)A * rate;
          A -= charge;
          cumulative += B;
        }
        A += cumulative;
      }
      ans = max(ans, A);
    }
    printf("%d\n", ans);
  }
  return 0;
}
