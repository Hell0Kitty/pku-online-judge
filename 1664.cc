
#include <iostream>
using namespace std;

int f(int i, int j, int maxVal) {
  int sum = 0;
  if (j == 1) return 1;
  if (i == 1 || i == 0) return 1;
  int k;
  for (k = min(maxVal, i); k * j >= i;
       k--)  // k值不能小于当前平均每个盘子中的苹果数
  {
    sum = sum + f(i - k, j - 1, k);
  }
  return sum;
}

int main() {
  int t, M, N;
  cin >> t;
  while (t--) {
    cin >> M >> N;
    cout << f(M, N, M + 1) << endl;
  }
  return 0;
}