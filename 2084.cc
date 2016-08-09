#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 9999
#define DLEN 4

class BigNum {
 private:
  int a[50];  //可以控制大数的位数
  int len;    //大数长度
 public:
  BigNum() {
    len = 1;
    memset(a, 0, sizeof(a));
  }                        //构造函数
  BigNum(const int);       //将一个int类型的变量转化为大数
  BigNum(const BigNum &);  //拷贝构造函数
  BigNum &operator=(const BigNum &);  //重载赋值运算符，大数之间进行赋值运算

  friend ostream &operator<<(ostream &, BigNum &);  //重载输出运算符

  BigNum operator+(
      const BigNum &) const;  //重载加法运算符，两个大数之间的相加运算
  BigNum operator*(
      const BigNum &) const;  //重载乘法运算符，两个大数之间的相乘运算

  bool operator>(const int &t) const;  //大数和一个int类型的变量的大小比较
  bool operator>(const BigNum &T) const;  //大数和另一个大数的大小比较
};

BigNum dp[220][220];

BigNum d(int x, int y) {
  if (x == y) return 1;
  if (x > y) return 1;

  if (dp[x][y] > 0) return dp[x][y];
  if (y - x == 1) return (dp[x][y] = 1);

  BigNum ans = 0;
  for (int i = x + 1; i <= y; i += 2) {
    ans = ans + d(x + 1, i - 1) * d(i + 1, y);
  }

  return (dp[x][y] = ans);
}

int main() {
  int n;

  while (scanf("%d", &n) == 1 && n != -1) {
    BigNum ans = d(1, 2 * n);
    cout << ans << endl;
  }

  return 0;
}

BigNum::BigNum(const int b)  //将一个int类型的变量转化为大数
{
  int c, d = b;
  len = 0;
  memset(a, 0, sizeof(a));
  while (d > MAXN) {
    c = d - (d / (MAXN + 1)) * (MAXN + 1);
    d = d / (MAXN + 1);
    a[len++] = c;
  }
  a[len++] = d;
}
BigNum::BigNum(const BigNum &T)
    : len(T.len)  //拷贝构造函数
{
  int i;
  memset(a, 0, sizeof(a));
  for (i = 0; i < len; i++) a[i] = T.a[i];
}
BigNum &BigNum::operator=(
    const BigNum &n)  //重载赋值运算符，大数之间进行赋值运算
{
  int i;
  len = n.len;
  memset(a, 0, sizeof(a));
  for (i = 0; i < len; i++) a[i] = n.a[i];
  return *this;
}

ostream &operator<<(ostream &out, BigNum &b)  //重载输出运算符
{
  int i;
  cout << b.a[b.len - 1];
  for (i = b.len - 2; i >= 0; i--) {
    cout.width(DLEN);
    cout.fill('0');
    cout << b.a[i];
  }
  return out;
}

BigNum BigNum::operator+(const BigNum &T) const  //两个大数之间的相加运算
{
  BigNum t(*this);
  int i, big;  //位数
  big = T.len > len ? T.len : len;
  for (i = 0; i < big; i++) {
    t.a[i] += T.a[i];
    if (t.a[i] > MAXN) {
      t.a[i + 1]++;
      t.a[i] -= MAXN + 1;
    }
  }
  if (t.a[big] != 0)
    t.len = big + 1;
  else
    t.len = big;
  return t;
}

BigNum BigNum::operator*(const BigNum &T) const  //两个大数之间的相乘运算
{
  BigNum ret;
  int i, j, up;
  int temp, temp1;
  for (i = 0; i < len; i++) {
    up = 0;
    for (j = 0; j < T.len; j++) {
      temp = a[i] * T.a[j] + ret.a[i + j] + up;
      if (temp > MAXN) {
        temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
        up = temp / (MAXN + 1);
        ret.a[i + j] = temp1;
      } else {
        up = 0;
        ret.a[i + j] = temp;
      }
    }
    if (up != 0) ret.a[i + j] = up;
  }
  ret.len = i + j;
  while (ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--;
  return ret;
}
bool BigNum::operator>(const int &t) const  //大数和一个int类型的变量的大小比较
{
  BigNum b(t);
  return *this > b;
}

bool BigNum::operator>(const BigNum &T) const  //大数和另一个大数的大小比较
{
  int ln;
  if (len > T.len)
    return true;
  else if (len == T.len) {
    ln = len - 1;
    while (a[ln] == T.a[ln] && ln >= 0) ln--;
    if (ln >= 0 && a[ln] > T.a[ln])
      return true;
    else
      return false;
  } else
    return false;
}
