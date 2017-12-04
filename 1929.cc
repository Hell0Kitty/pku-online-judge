#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
  char temp, f1, p1, su1, st1, a1;
  double f, p, su, st, a, sum = 0, fat = 0;
  int flag = 0, flag2;
  while (cin >> temp) {
    if (temp == '-') {
      flag++;
      if (flag == 1) {
        cout << fixed << setprecision(0) << fat / sum * 100 << "%" << endl;
        fat = sum = 0;
        continue;
      }
      if (flag == 2) break;
    }
    flag = 0;
    flag2 = 0;
    cin.putback(temp);
    cin >> f >> f1 >> p >> p1 >> su >> su1 >> st >> st1 >> a >> a1;
    if (f1 == '%') {
      f /= 100.0;
      flag2 = 1;
    } else if (f1 == 'g')
      f *= 9;
    if (p1 == '%') {
      p /= 100.0;
      flag2 = 1;
    } else if (p1 == 'g')
      p *= 4;
    if (su1 == '%') {
      su /= 100.0;
      flag2 = 1;
    } else if (su1 == 'g')
      su *= 4;
    if (st1 == '%') {
      st /= 100.0;
      flag2 = 1;
    } else if (st1 == 'g')
      st *= 4;
    if (a1 == '%') {
      a /= 100.0;
      flag2 = 1;
    } else if (a1 == 'g')
      a *= 7;
    if (flag2 == 1) {
      double sum1 = 0, sum2 = 0;
      if (f >= 1)
        sum1 += f;
      else
        sum2 += f;
      if (p >= 1)
        sum1 += p;
      else
        sum2 += p;
      if (su >= 1)
        sum1 += su;
      else
        sum2 += su;
      if (st >= 1)
        sum1 += st;
      else
        sum2 += st;
      if (a >= 1)
        sum1 += a;
      else
        sum2 += a;
      sum += sum1 / (1 - sum2);
      if (f < 1)
        fat += f * (sum1 / (1 - sum2));
      else
        fat += f;
    } else {
      sum += f + p + su + st + a;
      fat += f;
    }
  }
  return 0;
}
