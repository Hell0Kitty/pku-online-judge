#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[40], b[40], c[40];
int num[10];
char s[10];
int main() {
  int n, i, j, k;
  a[1] = b[1] = c[1] = 1;
  for (i = 2; i <= 30; i++) {
    a[i] = a[i - 1] * 2 + 1;
    c[i] = c[i - 1] * 3 + 2;
    b[i] = b[i - 1] + c[i - 1] + 1;
  }
  scanf("%d", &n);
  for (i = 1; i <= 6; i++) {
    scanf("%s", s);
    k = (s[0] - 'A') * 4 + s[1] - 'A';
    num[k] = i;
  }
  if (num[1] < num[2]) {
    if (num[4] < num[6])
      printf("%I64d\n", c[n]);
    else if (num[9] < num[8])
      printf("%I64d\n", b[n]);
    else
      printf("%I64d\n", a[n]);
  } else {
    if (num[8] < num[9])
      printf("%I64d\n", c[n]);
    else if (num[6] < num[4])
      printf("%I64d\n", b[n]);
    else
      printf("%I64d\n", a[n]);
  }
}
