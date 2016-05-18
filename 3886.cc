#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <ctime>

using namespace std;

#define MAXN 30
long long fact[MAXN], f[MAXN];
char line[MAXN];
int i, j, k, N, T;
long long res;

int main() {
  fact[0] = 1;
  for (i = 1; i <= 20; i++) fact[i] = fact[i - 1] * i;

  scanf("%d\n", &T);
  while (T--) {
    fgets(line, sizeof(line), stdin);
    N = strlen(line);
    while (!isalpha(line[N - 1])) {
      line[N - 1] = '\0';
      N--;
    }

    memset(f, 0, sizeof(f));
    for (i = 0; i < N; i++) f[line[i] - 'A']++;

    res = 0;
    for (i = 0; i < N - 1; i++) {
      for (j = 0; j < line[i] - 'A'; j++) {
        if (f[j] == 0) continue;

        long long identical = 1;
        for (k = 0; k <= 'Z' - 'A'; k++)
          if (k != j)
            identical *= fact[f[k]];
          else
            identical *= fact[f[k] - 1];

        res += fact[N - 1 - i] / identical;
      }
      f[line[i] - 'A']--;
    }

    printf("%I64d\n", res);
  }

  return 0;
}
