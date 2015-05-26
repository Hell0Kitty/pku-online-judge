#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define INF 0x7fffffff
using namespace std;

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }

void exgcd(LL a, LL b, LL& x, LL& y) {
  if (b == 0) {
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
  }
}

int main() {
  LL A, B, C, k;
  while (scanf("%I64d %I64d %I64d %I64d", &A, &B, &C, &k) != EOF) {
    if (A == 0 && B == 0 && C == 0 && k == 0) break;

    if (A == B) {
      printf("0\n");
      continue;
    }

    LL a = C;
    LL b = (1LL << k);
    LL c = gcd(a, b);
    LL d = B - A;

    if (d % c != 0) {
      printf("FOREVER\n");
      continue;
    }

    a /= c;  //这里要进行简化，因为可能产生多余的次数
    b /= c;
    d /= c;

    LL p, q;
    exgcd(a, b, p, q);  //这里求的是最简ax+by=gcd(a,b)的一组x,y的解

    printf("%I64d\n", (p * (d / gcd(a, b)) % b + b) % b);
  }
  return 0;
}
