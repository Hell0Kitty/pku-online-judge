#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int Range = 1001;
inline int LowBit(int a) { return a & (-a); }
int ST[1010][1010];
void Add(int x, int y) {
  for (int i = x; i <= Range; i += LowBit(i))
    for (int j = y; j <= Range; j += LowBit(j)) ST[i][j]++;
}
int GetS(int x, int y) {
  int tmp = 0;
  for (int i = x; i > 0; i -= LowBit(i))
    for (int j = y; j > 0; j -= LowBit(j)) tmp += ST[i][j];
  return tmp;
}
int GetAr(int X, int Y, int x, int y) {
  return GetS(X, Y) - GetS(X, y - 1) - GetS(x - 1, Y) + GetS(x - 1, y - 1);
}
vector<int> PSet[2010];
int L1[1010], L2[1010];
int main() {
  int N1, N2, N3, Ans, i, j, x, y, top, butt;
  while (~scanf("%d%d%d", &N1, &N2, &N3)) {
    for (i = 0; i < N1; i++) {
      scanf("%d", &L1[i]);
      L1[i]++;
    }
    for (i = 0; i < N2; i++) {
      scanf("%d", &L2[i]);
      L2[i]++;
    }
    memset(ST, 0, sizeof(ST));
    while (N3--) {
      scanf("%d%d", &x, &y);
      x++;
      y++;
      Add(x, y);
    }
    for (i = 0; i <= 2002; i++) PSet[i].clear();
    for (i = 0; i < N1; i++)
      for (j = 0; j < N2; j++) PSet[L1[i] - L2[j] + 1001].push_back(L2[j]);
    Ans = 0;
    for (i = 0; i <= 2002; i++)
      if (PSet[i].size() > 0) {
        sort(PSet[i].begin(), PSet[i].end());
        butt = top = 0;
        while (top < PSet[i].size()) {
          if (top <= butt) top = butt + 1;
          while (top < PSet[i].size() &&
                 GetAr(PSet[i][top], i - 1001 + PSet[i][top], PSet[i][butt],
                       i - 1001 + PSet[i][butt]) == 0)
            top++;
          if (top >= PSet[i].size()) {
            break;
          }
          Ans += PSet[i].size() - top;
          butt++;
        }
      }
    printf("%d\n", Ans);
  }
}
