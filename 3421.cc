#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = (1 << 20) + 2;
bool ispri[maxn];
int n, pri[maxn], cnt, ans;
long long fact[21];
void Init() {
  cnt = 0;
  ispri[1] = 1;
  for (int i = 2; i < maxn; i++)
    if (!ispri[i]) {
      pri[cnt++] = i;
      for (int j = 2; i * j < maxn; j++) ispri[i * j] = 1;
    }
  fact[0] = 1;
  for (int i = 1; i <= 20; i++) fact[i] = fact[i - 1] * i;
}
int main() {
  Init();
  while (scanf("%d", &n) != EOF) {
    ans = 0;
    int m = n, index = 0;
    long long divs = 1;
    while (m > 1) {
      if (m % pri[index] == 0) {
        int dcnt = 0;
        while (m % pri[index] == 0) {
          m /= pri[index];
          dcnt++;
        }
        divs = divs * fact[dcnt];
        ans += dcnt;
      }
      index++;
      if (!ispri[m]) {
        ans++;
        break;
      }
    }
    long long s = fact[ans];
    s /= divs;
    printf("%d %I64d\n", ans, s);
  }
  return 0;
}
