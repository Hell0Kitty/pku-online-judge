#include <iostream>
using namespace std;
int num[60];
int rec[10];
int val, best, best2;
int m, n;
int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int minnum() {
  int temp = 1, i;
  for (i = 1; i <= 4; i++) {
    if (temp > rec[i])
      temp = temp * rec[i] / gcd(temp, rec[i]);
    else
      temp = temp * rec[i] / gcd(rec[i], temp);
  }
  return temp;
}
void search(int a, int sum) {
  if (sum == 4) {
    int temp = minnum();
    if (val % temp == 0) {
      best = val;
      best2 = val;
    } else {
      temp = (val / minnum()) * minnum();
      if (temp <= val && temp > best) best = temp;
      temp = (val / minnum() + 1) * minnum();
      if (temp >= val && temp < best2) best2 = temp;
    }
    return;
  }
  int i;
  for (i = a; i <= n; i++) {
    if (best == val) return;
    rec[++sum] = num[i];
    search(i + 1, sum);
    sum--;
  }
}
int main() {
  int i;
  while (1) {
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    for (i = 1; i <= n; i++) scanf("%d", &num[i]);
    for (i = 1; i <= m; i++) {
      scanf("%d", &val);
      best = 0;
      best2 = 2000000000;
      search(1, 0);
      printf("%d %d\n", best, best2);
    }
  }
  return 0;
}
