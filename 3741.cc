#include <iostream>
#include <string>
using namespace std;

int p, q;
string str;

int cal1(char x) {
  if (x <= '9') return x - '0';
  return x - 'a' + 10;
}

char cal2(int x) {
  if (x <= 9) return x + '0';
  return x - 10 + 'a';
}

int main() {
  while (scanf("%d%d", &p, &q) != -1) {
    cin >> str;
    int i, temp = -q, k;
    char c;
    for (i = str.length() - 1, k = 1; i >= 0; i--, k *= p) {
      temp += k * cal1(str[i]);
      if (temp >= 0) temp %= (q - p), k %= (q - p);
    }
    if (temp < 0)
      temp += q;
    else
      temp += p;
    str = "";
    while (temp) str += cal2(temp % q), temp /= q;
    for (i = 0; i < str.length() / 2; i++) {
      c = str[i];
      str[i] = str[str.length() - 1 - i];
      str[str.length() - 1 - i] = c;
    }
    if (str.length() == 0) str += '0';
    printf("%s\n", &str[0]);
  }
  return 0;
}
