#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int a[6];
map<int, int> h;

int main() {
  for (int i = 1; i < 6; i++) scanf("%d", &a[i]);
  for (int i = -50; i <= 50; i++)
    for (int j = -50; j <= 50; j++) {
      if (i == 0 || j == 0) continue;
      int temp = i * i * i * a[1] + j * j * j * a[2];
      if (h.find(temp) == h.end())
        h[temp] = 1;
      else
        h[temp]++;
    }
  int ans = 0;
  for (int i = -50; i <= 50; i++)
    for (int j = -50; j <= 50; j++)
      for (int k = -50; k <= 50; k++) {
        if (i == 0 || j == 0 || k == 0) continue;
        int temp = i * i * i * a[3] + j * j * j * a[4] + k * k * k * a[5];
        if (h.find(0 - temp) == h.end()) continue;
        ans += h[0 - temp];
      }
  printf("%d\n", ans);
  return 0;
}
