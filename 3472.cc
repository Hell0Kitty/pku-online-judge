#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int D = 10000;

class HugeInt {
 public:
  int len;
  int a[2500];
  HugeInt();
  HugeInt operator+(const HugeInt &);
  HugeInt operator+(int);
  HugeInt operator-(const HugeInt &);
  HugeInt operator-(int);
  HugeInt operator*(const HugeInt &);
  HugeInt operator*(int);
  void output();
};

HugeInt::HugeInt() {
  len = 1;
  memset(a, 0, sizeof(a));
}

HugeInt HugeInt::operator+(int x) {
  HugeInt ret = *this;
  ret.a[0] += x;
  for (int i = 0; i < ret.len - 1 && ret.a[i] >= D; i++) {
    ret.a[i + 1] += ret.a[i] / D;
    ret.a[i] %= D;
  }

  while (ret.a[ret.len - 1] >= D) {
    ret.a[ret.len] += ret.a[ret.len - 1] / D;
    ret.a[ret.len - 1] %= D;
    ret.len++;
  }
  return ret;
}

HugeInt HugeInt::operator+(const HugeInt &x) {
  HugeInt ret = *this;
  ret.len = max(ret.len, x.len);
  for (int i = 0; i < ret.len; i++) {
    ret.a[i] += x.a[i];
    if (ret.a[i] >= D) {
      ret.a[i + 1]++;
      ret.a[i] -= D;
    }
  }
  if (ret.a[ret.len] > 0) ret.len++;
  return ret;
}

HugeInt HugeInt::operator-(int x) {
  HugeInt ret = *this;
  ret.a[0] -= x;
  for (int i = 0; i < ret.len && ret.a[i] < 0; i++) {
    ret.a[i + 1] += (ret.a[i] - D + 1) / D;  //+1是为了处理-10000等特殊情况
    ret.a[i] -= (ret.a[i] - D + 1) / D * D;
  }
  while (ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
  return ret;
}

HugeInt HugeInt::operator-(const HugeInt &x)  //保证被减数大于减数
{
  int i;
  HugeInt ret = *this;
  for (i = 0; i < x.len; i++) {
    ret.a[i] = ret.a[i] - x.a[i];
    if (ret.a[i] < 0) {
      ret.a[i + 1]--;
      ret.a[i] += D;
    }
  }
  while (ret.a[i] < 0) {
    ret.a[i] += D;
    ret.a[++i]--;
  }
  while (ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
  return ret;
}

HugeInt HugeInt::operator*(int x) {
  HugeInt ret = *this;
  ret.a[0] *= x;
  for (int i = 1; i < ret.len; i++) {
    ret.a[i] *= x;
    if (ret.a[i - 1] >= D) {
      ret.a[i] += ret.a[i - 1] / D;
      ret.a[i - 1] %= D;
    }
  }
  while (ret.a[ret.len - 1] >= D) {
    ret.a[ret.len] += ret.a[ret.len - 1] / D;
    ret.a[ret.len - 1] %= D;
    ret.len++;
  }
  while (ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
  return ret;
}

HugeInt HugeInt::operator*(const HugeInt &x) {
  HugeInt ret;
  ret.len = len + x.len - 1;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < x.len; j++) {
      ret.a[i + j] += a[i] * x.a[j];
      if (ret.a[i + j] >= D) {
        ret.a[i + j + 1] += ret.a[i + j] / D;
        ret.a[i + j] %= D;
      }
    }
  }
  if (ret.a[ret.len] > 0) ret.len++;
  while (ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
  return ret;
}

void HugeInt::output() {
  /*cout << a[len-1];
      for(int i = len - 2; i >= 0; i--)
      for(int j = 1000; j > 0; j /= 10)
          cout << a[i] / j % 10;
  cout << endl; */

  int i, j, k = 0;
  char str[10000];
  for (i = len - 1; i >= 0; i--)
    for (j = 1000; j > 0; j /= 10) str[k++] = a[i] / j % 10 + '0';

  for (i = 0; str[i] == '0'; i++)
    ;
  if (i == k)
    cout << "0" << endl;
  else if (k - i <= 3) {
    while (i < k) cout << str[i++];
    cout << endl;
  } else {
    int cnt = (k - i) % 3;
    if (cnt == 0) cnt = 3;
    for (j = i; j < i + cnt; j++) cout << str[j];
    for (; j < k; j += 3) cout << ',' << str[j] << str[j + 1] << str[j + 2];
    cout << endl;
  }
}

HugeInt fib[10002];

int main() {
  fib[1] = fib[1] + 1;
  for (int i = 2; i <= 10000; i++) fib[i] = fib[i - 1] + fib[i - 2];
  int n;
  while (cin >> n) {
    HugeInt ret;
    if (n % 2)
      ret = fib[n] * fib[n] * 2 - 1;
    else
      ret = fib[n] * fib[n] * 2 + 1;
    ret = ret * ret * 4;
    ret.output();
  }
  return 0;
}
