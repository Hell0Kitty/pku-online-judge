#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
class T {
 public:
  int p;  //价值
  int d;  // deadline
} loan[10010];
int counter[10010];
bool cmp(T a, T b) { return a.p > b.p; }
int main() {
  int n, L;
  while (~scanf("%d%d", &n, &L)) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &loan[i].p, &loan[i].d);
    }
    memset(counter, 0, sizeof(counter));
    sort(loan, loan + n, cmp);
    int ant = 0;
    for (int i = 0; i < n; i++) {
      while (counter[loan[i].d] == L) {
        loan[i].d--;
      }
      if (loan[i].d < 0) {
        continue;
      }
      counter[loan[i].d]++;
      ant += loan[i].p;
    }
    printf("%d\n", ant);
  }
  return 0;
}
