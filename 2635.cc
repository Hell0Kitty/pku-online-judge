#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000 + 100;
bool IsPrime[MAX];
int Prime[MAX], pn;

void MakePrime() {
  memset(IsPrime, true, sizeof(IsPrime));
  IsPrime[0] = IsPrime[1] = false;
  pn = 0;
  for (int i = 2; i < MAX; i++) {
    if (IsPrime[i]) Prime[pn++] = i;
    for (int j = 0; j < pn && Prime[j] * i < MAX; j++) {
      IsPrime[Prime[j] * i] = false;
      if (i % Prime[j] == 0) break;
    }
  }
}

char str[1010];
int L, num[1010];

bool Check(int len, int mod) {
  int res = 0;
  for (int i = len - 1; i >= 0; i--) res = (res * 1000 + num[i]) % mod;
  if (res) return true;
  return false;
}

int main() {
  MakePrime();
  while (scanf("%s %d", str, &L) != EOF && L) {
    int len = strlen(str);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < len; i++) {
      int id = (len + 2 - i) / 3 - 1;
      num[id] = num[id] * 10 + str[i] - '0';
    }
    int lenk = len / 3 + ((len % 3) ? 1 : 0);
    int pMin = 0, flag = 1;
    while (Prime[pMin] < L && pMin < pn) {
      if (!Check(lenk, Prime[pMin])) {
        flag = 0;
        printf("BAD %d\n", Prime[pMin]);
        break;
      }
      pMin++;
    }
    if (flag) puts("GOOD");
  }
  return 0;
}
