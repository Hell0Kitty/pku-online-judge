#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
char s[300];
int pos;
char A, B;
char D_H(int x) {
  if (x < 10)
    return x + '0';
  else
    return x - 10 + 'A';
}
int H_D(char x) {
  if (isdigit(x))
    return x - '0';
  else
    return x - 'A' + 10;
}
void LD() {
  int w = H_D(s[++pos]);
  w = w * 16 + H_D(s[++pos]);
  pos++;
  A = s[w];
}
void ST() {
  int w = H_D(s[++pos]);
  w = w * 16 + H_D(s[++pos]);
  pos++;
  s[w] = A;
}
void SWP() {
  pos++;
  swap(A, B);
}
void ADD() {
  pos++;
  int a, b, c;
  a = H_D(A);
  b = H_D(B);
  c = a + b;
  A = D_H(c % 16);
  B = D_H(c / 16);
}
void INC() {
  pos++;
  A = D_H((H_D(A) + 1) % 16);
}
void DEC() {
  pos++;
  A = D_H((H_D(A) + 15) % 16);
}
void BR();
void BZ() {
  if (A != '0')
    pos += 3;
  else {
    int w = H_D(s[++pos]);
    w = w * 16 + H_D(s[++pos]);
    pos = w;
  }
}
void BR() {
  int w = H_D(s[++pos]);
  w = w * 16 + H_D(s[++pos]);
  pos = w;
}
int main() {
  while (gets(s), s[0] != '8') {
    pos = 0;
    A = B = '0';
    while (s[pos] != '8' && pos < 256) {
      switch (s[pos]) {
        case '0':
          LD();
          break;
        case '1':
          ST();
          break;
        case '2':
          SWP();
          break;
        case '3':
          ADD();
          break;
        case '4':
          INC();
          break;
        case '5':
          DEC();
          break;
        case '6':
          BZ();
          break;
        case '7':
          BR();
          break;
      }
    }
    puts(s);
  }
  return 0;
}
