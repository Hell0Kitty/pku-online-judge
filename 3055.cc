#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 500

char a[MAXN], b[MAXN];
int visa[15], visb[15];

bool checkEqual() {
  for (int i = 0; i <= 10; i++) {
    if (visa[i] == 0 && visb[i] != 0 || visa[i] != 0 && visb[i] == 0)
      return false;
  }
  return true;
}

int main() {
  int i, j, n, T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", a, b);
    int na = strlen(a);
    int nb = strlen(b);
    memset(visa, 0, sizeof(visa));
    memset(visb, 0, sizeof(visb));
    for (i = 0; i < na; i++) {
      visa[a[i] - '0']++;
    }
    for (i = 0; i < nb; i++) {
      visb[b[i] - '0']++;
    }
    if (checkEqual()) {
      printf("friends\n");
      continue;
    }
    for (i = 0; i < na - 1; i++) {
      if (a[i] - '0' > 0) {
        visa[a[i] - '0']--;
        visa[a[i] - '0' - 1]++;
        visa[a[i + 1] - '0']--;
        visa[a[i + 1] - '0' + 1]++;
        if (checkEqual() && (i != 0 || a[i] != '1')) break;
        visa[a[i] - '0']++;
        visa[a[i] - '0' - 1]--;
        visa[a[i + 1] - '0']++;
        visa[a[i + 1] - '0' + 1]--;
      }
      if (a[i + 1] - '0' > 0) {
        visa[a[i] - '0']--;
        visa[a[i] - '0' + 1]++;
        visa[a[i + 1] - '0']--;
        visa[a[i + 1] - '0' - 1]++;
        if (checkEqual()) break;
        visa[a[i] - '0']++;
        visa[a[i] - '0' + 1]--;
        visa[a[i + 1] - '0']++;
        visa[a[i + 1] - '0' - 1]--;
      }
    }
    if (i < na - 1) {
      printf("almost friends\n");
      continue;
    }
    for (i = 0; i < nb - 1; i++) {
      if (b[i] - '0' > 0) {
        visb[b[i] - '0']--;
        visb[b[i] - '0' - 1]++;
        visb[b[i + 1] - '0']--;
        visb[b[i + 1] - '0' + 1]++;
        if (checkEqual() && (i != 0 || b[i] != '1')) break;
        visb[b[i] - '0']++;
        visb[b[i] - '0' - 1]--;
        visb[b[i + 1] - '0']++;
        visb[b[i + 1] - '0' + 1]--;
      }
      if (b[i + 1] - '0' > 0) {
        visb[b[i] - '0']--;
        visb[b[i] - '0' + 1]++;
        visb[b[i + 1] - '0']--;
        visb[b[i + 1] - '0' - 1]++;
        if (checkEqual()) break;
        visb[b[i] - '0']++;
        visb[b[i] - '0' + 1]--;
        visb[b[i + 1] - '0']++;
        visb[b[i + 1] - '0' - 1]--;
      }
    }
    if (i < nb - 1) {
      printf("almost friends\n");
      continue;
    }
    printf("nothing\n");
  }
  return 0;
}
