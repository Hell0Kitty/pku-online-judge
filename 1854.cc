#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#define REP(i, x, v) for (int i = x; i <= v; i++)
#define REPD(i, x, v) for (int i = x; i >= v; i--)
#define FOR(i, v) for (int i = 0; i < v; i++)
#define CLR(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define cz(x) scanf("%d", &(x))
#define cz2(x, y) scanf("%d%d", &(x), &(y))
#define cz3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define MAXN 8000 + 50
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

char str[MAXN];
int digit[26], len;
int cnt;
int ans = 0;
int main() {
  int num;
  cz(num);
  while (num--) {
    cnt = 0;
    ans = 0;
    CLR(digit, 0);
    scanf("%s", str);
    int len = strlen(str);
    FOR(i, len) { digit[str[i] - 'a']++; }
    FOR(i, 26) {
      if (digit[i] & 0x1) {
        cnt++;
      }
    }
    if (cnt >= 2) {
      printf("Impossible\n");
    } else {
      FOR(i, len / 2) {
        char value = str[i];
        bool flag = false;
        for (int j = len - 1 - i; j > i; --j) {
          if (str[i] == str[j]) {
            flag = true;
            for (int k = j; k < len - i - 1; ++k) {
              str[k] = str[k + 1];
              ans++;
            }
            str[len - i - 1] = value;
            break;
          }
        }
        if (!flag) {
          char tmp;
          tmp = str[i];
          str[i] = str[i + 1];
          str[i + 1] = tmp;
          ans++;
          --i;
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
