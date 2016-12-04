#include <cstdio>
#include <cstring>
using namespace std;
int sg[2005];
bool temp[2005];
int main() {
  sg[0] = 0;
  sg[1] = 1;
  sg[2] = 1;
  sg[3] = 1;
  sg[4] = 2;
  sg[5] = 2;
  for (int i = 6; i <= 2000; i++) {
    memset(temp, false, sizeof(temp));
    temp[sg[i - 3]] = temp[sg[i - 4]] = temp[sg[i - 5]] = true;
    for (int j = 1; j <= i - 5 - j; j++) temp[sg[j] ^ sg[i - 5 - j]] = true;
    for (int j = 0; j <= 2000; j++)
      if (!temp[j]) {
        sg[i] = j;
        break;
      }
  }
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", sg[n] ? 1 : 2);
  }
  return 0;
}
