#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define DOR(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define CLR(a) memset((a), 0, sizeof((a)))
#define pb push_back
#define mp make_pair
#define ins insert
#define F first
#define S second
#define bug puts("Oh Here!");

#define nMax 10010
#define oo 0x7fffffff
#define eps 1e-8

#define LL long long
#define Vec vector<int>
#define Pai pair<int, int>

char s[nMax];
int b[nMax], l[nMax];
int g[3];
class Sur_Number {
 public:
  LL sn;
  void make(int*, int);
  friend Sur_Number operator+(const Sur_Number&, const Sur_Number&);
  friend bool operator<(const Sur_Number&, const Sur_Number&);
};
void Sur_Number::make(int* b, int l) {
  sn = 0LL;
  LL k = 1LL << 52;
  // printf("k = %lld \n",k);
  int i = 1;
  b[0] = b[1];
  while (i <= l) {
    if (b[i] == b[i - 1]) {
      if (b[i] == 0)
        sn += k;
      else
        sn -= k;
    } else
      break;
    i++;
  }
  k >>= 1;
  while (i <= l) {
    if (b[i] == 0)
      sn += k;
    else
      sn -= k;
    i++;
    k >>= 1;
  }
}

Sur_Number operator+(const Sur_Number& a, const Sur_Number& b) {
  Sur_Number c;
  c.sn = a.sn + b.sn;
  return c;
}

bool operator<(const Sur_Number& a, const Sur_Number& b) { return a.sn < b.sn; }

int main() {
  int t, cas;
  scanf("%d", &t);
  Sur_Number p[2], r;
  while (t--) {
    scanf("%s %d\n", s, &cas);
    for (int k = 0; k < 2; k++) {
      p[k].sn = 0;
      for (int i = 0; i < 3; i++) scanf("%d", &l[i]);
      for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= l[j]; i++) {
          scanf("%s", s);
          b[i] = s[0] == 'W' ? 0 : 1;
        }
        r.make(b, l[j]);
        // printf("---%lld\n",r.sn);
        p[k] = p[k] + r;
      }
    }
    printf("Test %d: %s\n", cas, p[0] < p[1] ? "No" : "Yes");
  }
  return 0;
}
