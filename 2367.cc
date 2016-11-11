#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 101
using namespace std;

int n, m;
int DU_C[MAX], DU_R[MAX];
vector<int> f[MAX];
bool b[MAX];

void readin();
void work();

int main() {
  readin();
  work();
  return 0;
}

void readin() {
  int x;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    while (x) {
      DU_C[i]++;
      f[i].push_back(x);
      DU_R[x]++;
      scanf("%d", &x);
    }
  }
}
void work() {
  for (int k = 1; k <= n; k++) {
    for (int x = 1; x <= n; x++) {
      if (b[x]) continue;
      if (DU_R[x] != 0) continue;
      printf("%d", x);
      b[x] = true;
      if (k != n) putchar(' ');
      for (int i = 0; i < DU_C[x]; i++) DU_R[f[x][i]]--;
      break;
    }
  }
}
