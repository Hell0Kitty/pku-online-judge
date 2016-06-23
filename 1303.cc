#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
int n;
int byte[5], nibble[5];
int player[20][2], n1, n2;
bool valid[20];
int toint() {
  int total = 0;
  char str[20];
  scanf("%s", str);
  for (int i = 0; str[i] != '\0'; i++) total = (total << 1) + str[i] - 48;
  return total;
}
bool win() {
  for (int i = 0; i < n; i++)
    if (valid[i] && player[i][0] + player[i][1] > n1) return false;
  return true;
}
int main() {
  // freopen("input.txt","r",stdin);
  char jud[15];
  while (scanf("%s", jud) != EOF && *jud == 'S') {
    scanf("%d", &n);
    memset(valid, true, sizeof(valid));
    n1 = toint();
    n2 = toint();
    n1 += n2;
    for (int i = 0; i < n; i++) player[i][0] = toint(), player[i][1] = 255;
    for (int i = 0; i < 4; i++) byte[i] = toint();
    for (int i = 0; i < 4; i++) nibble[i] = toint();
    scanf("%s", jud);
    printf("HAND %d\n", n);
    int total = n;
    for (int i = 0; i < n; i++)
      if (player[i][0] + player[i][1] > 510) valid[i] = false, total--;
    int limit = 0, p1 = 0, p2 = 0;
    if (!total) {
      printf("Win!");
      goto end;
    }
    while (true)
      if (n1 > 510) {
        printf("Bust!\n");
        goto end;
      } else if (win()) {
        printf("Win!\n");
        goto end;
      } else if (limit < 4 && n1 < 382) {
        n1 += byte[p1++];
        printf("Byte me!\n");
        limit++;
      } else if (limit < 4 && n1 <= 500) {
        n1 += nibble[p2++];
        printf("Nibble me!\n");
        limit++;
      } else
        break;
    for (int i = 0; i < n; i++)
      if (valid[i] && 510 - player[i][0] - player[i][1] < 510 - n1) {
        printf("Lose!\n");
        goto end;
      }
    printf("Win!\n");
  end:
    ;
  }
  return 0;
}
