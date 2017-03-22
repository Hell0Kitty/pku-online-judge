#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 24;

struct node {
  char a, b, aa;
  int c, d, val;
} p[5], temp;

struct node2 {
  node tt[5];
  int most;
} ans[122];

int cmp(node a, node b) { return a.val < b.val; }

int cmp2(node2 a, node2 b) { return a.most < b.most; }

int cnt;

int value(char ch) {
  if (ch == 'C')
    return 1;
  else if (ch == 'D')
    return 2;
  else if (ch == 'H')
    return 3;
  else if (ch == 'S')
    return 4;
  if (ch == 'A')
    return 1;
  else if (ch >= '2' && ch <= '9')
    return (ch - '0');
  else if (ch == 'J')
    return 11;
  else if (ch == 'Q')
    return 12;
  else if (ch == 'K')
    return 13;
}

bool judge() {
  if (p[0].b != p[1].b) return false;

  if (p[2].val <= p[3].val && p[2].val <= p[4].val) {
    if (p[3].val >= p[4].val) {  // pos = 4
      if (p[1].aa != '#') {      // 10
        if (p[0].a == 'A')
          return true;
        else
          return false;
      } else if (p[1].a == 'A') {  // 1
        if (p[0].a == '5')
          return true;
        else
          return false;
      } else if (p[1].a == '2') {  // 2
        if (p[0].a == '6')
          return true;
        else
          return false;
      } else if (p[1].a == '3') {  // 3
        if (p[0].a == '7')
          return true;
        else
          return false;
      } else if (p[1].a == '4') {  // 4
        if (p[0].a == '8')
          return true;
        else
          return false;
      } else if (p[1].a == '5') {  // 5
        if (p[0].a == '9')
          return true;
        else
          return false;
      } else if (p[1].a == '6') {  // 6
        if (p[0].a == '1')
          return true;
        else
          return false;
      } else if (p[1].a == '7') {  // 7
        if (p[0].a == 'J')
          return true;
        else
          return false;
      } else if (p[1].a == '8') {  // 8
        if (p[0].a == 'Q')
          return true;
        else
          return false;
      } else if (p[1].a == '9') {  // 9
        if (p[0].a == 'K')
          return true;
        else
          return false;
      } else if (p[1].a == 'J') {  // J
        if (p[0].a == '2')
          return true;
        else
          return false;
      } else if (p[1].a == 'Q') {  // Q
        if (p[0].a == '3')
          return true;
        else
          return false;
      } else if (p[1].a == 'K') {  // K
        if (p[0].a == '4')
          return true;
        else
          return false;
      }
    } else {                 // pos = 1
      if (p[1].aa != '#') {  // 10
        if (p[0].a == 'J')
          return true;
        else
          return false;
      } else if (p[1].a == 'A') {  // 1
        if (p[0].a == '2')
          return true;
        else
          return false;
      } else if (p[1].a == '2') {  // 2
        if (p[0].a == '3')
          return true;
        else
          return false;
      } else if (p[1].a == '3') {  // 3
        if (p[0].a == '4')
          return true;
        else
          return false;
      } else if (p[1].a == '4') {  // 4
        if (p[0].a == '5')
          return true;
        else
          return false;
      } else if (p[1].a == '5') {  // 5
        if (p[0].a == '6')
          return true;
        else
          return false;
      } else if (p[1].a == '6') {  // 6
        if (p[0].a == '7')
          return true;
        else
          return false;
      } else if (p[1].a == '7') {  // 7
        if (p[0].a == '8')
          return true;
        else
          return false;
      } else if (p[1].a == '8') {  // 8
        if (p[0].a == '9')
          return true;
        else
          return false;
      } else if (p[1].a == '9') {  // 9
        if (p[0].a == '1')
          return true;
        else
          return false;
      } else if (p[1].a == 'J') {  // J
        if (p[0].a == 'Q')
          return true;
        else
          return false;
      } else if (p[1].a == 'Q') {  // Q
        if (p[0].a == 'K')
          return true;
        else
          return false;
      } else if (p[1].a == 'K') {  // K
        if (p[0].a == 'A')
          return true;
        else
          return false;
      }
    }
  }

  if (p[4].val <= p[3].val && p[4].val <= p[2].val) {
    if (p[2].val >= p[3].val) {  // pos = 6
      if (p[1].aa != '#') {      // 10
        if (p[0].a == '3')
          return true;
        else
          return false;
      } else if (p[1].a == 'A') {  // 1
        if (p[0].a == '7')
          return true;
        else
          return false;
      } else if (p[1].a == '2') {  // 2
        if (p[0].a == '8')
          return true;
        else
          return false;
      } else if (p[1].a == '3') {  // 3
        if (p[0].a == '9')
          return true;
        else
          return false;
      } else if (p[1].a == '4') {  // 4
        if (p[0].a == '1')
          return true;
        else
          return false;
      } else if (p[1].a == '5') {  // 5
        if (p[0].a == 'J')
          return true;
        else
          return false;
      } else if (p[1].a == '6') {  // 6
        if (p[0].a == 'Q')
          return true;
        else
          return false;
      } else if (p[1].a == '7') {  // 7
        if (p[0].a == 'K')
          return true;
        else
          return false;
      } else if (p[1].a == '8') {  // 8
        if (p[0].a == 'A')
          return true;
        else
          return false;
      } else if (p[1].a == '9') {  // 9
        if (p[0].a == '2')
          return true;
        else
          return false;
      } else if (p[1].a == 'J') {  // J
        if (p[0].a == '4')
          return true;
        else
          return false;
      } else if (p[1].a == 'Q') {  // Q
        if (p[0].a == '5')
          return true;
        else
          return false;
      } else if (p[1].a == 'K') {  // K
        if (p[0].a == '6')
          return true;
        else
          return false;
      }
    } else {                 // pos = 3
      if (p[1].aa != '#') {  // 10
        if (p[0].a == 'K')
          return true;
        else
          return false;
      } else if (p[1].a == 'A') {  // 1
        if (p[0].a == '4')
          return true;
        else
          return false;
      } else if (p[1].a == '2') {  // 2
        if (p[0].a == '5')
          return true;
        else
          return false;
      } else if (p[1].a == '3') {  // 3
        if (p[0].a == '6')
          return true;
        else
          return false;
      } else if (p[1].a == '4') {  // 4
        if (p[0].a == '7')
          return true;
        else
          return false;
      } else if (p[1].a == '5') {  // 5
        if (p[0].a == '8')
          return true;
        else
          return false;
      } else if (p[1].a == '6') {  // 6
        if (p[0].a == '9')
          return true;
        else
          return false;
      } else if (p[1].a == '7') {  // 7
        if (p[0].a == '1')
          return true;
        else
          return false;
      } else if (p[1].a == '8') {  // 8
        if (p[0].a == 'J')
          return true;
        else
          return false;
      } else if (p[1].a == '9') {  // 9
        if (p[0].a == 'Q')
          return true;
        else
          return false;
      } else if (p[1].a == 'J') {  // J
        if (p[0].a == 'A')
          return true;
        else
          return false;
      } else if (p[1].a == 'Q') {  // Q
        if (p[0].a == '2')
          return true;
        else
          return false;
      } else if (p[1].a == 'K') {  // K
        if (p[0].a == '3')
          return true;
        else
          return false;
      }
    }
  }

  if (p[3].val <= p[2].val && p[3].val <= p[4].val) {
    if (p[2].val >= p[4].val) {  // pos = 5
      if (p[1].aa != '#') {      // 10
        if (p[0].a == '2')
          return true;
        else
          return false;
      } else if (p[1].a == 'A') {  // 1
        if (p[0].a == '6')
          return true;
        else
          return false;
      } else if (p[1].a == '2') {  // 2
        if (p[0].a == '7')
          return true;
        else
          return false;
      } else if (p[1].a == '3') {  // 3
        if (p[0].a == '8')
          return true;
        else
          return false;
      } else if (p[1].a == '4') {  // 4
        if (p[0].a == '9')
          return true;
        else
          return false;
      } else if (p[1].a == '5') {  // 5
        if (p[0].a == '1')
          return true;
        else
          return false;
      } else if (p[1].a == '6') {  // 6
        if (p[0].a == 'J')
          return true;
        else
          return false;
      } else if (p[1].a == '7') {  // 7
        if (p[0].a == 'Q')
          return true;
        else
          return false;
      } else if (p[1].a == '8') {  // 8
        if (p[0].a == 'K')
          return true;
        else
          return false;
      } else if (p[1].a == '9') {  // 9
        if (p[0].a == 'A')
          return true;
        else
          return false;
      } else if (p[1].a == 'J') {  // J
        if (p[0].a == '3')
          return true;
        else
          return false;
      } else if (p[1].a == 'Q') {  // Q
        if (p[0].a == '4')
          return true;
        else
          return false;
      } else if (p[1].a == 'K') {  // K
        if (p[0].a == '5')
          return true;
        else
          return false;
      }
    } else {                 // pos = 2
      if (p[1].aa != '#') {  // 10
        if (p[0].a == 'Q')
          return true;
        else
          return false;
      } else if (p[1].a == 'A') {  // 1
        if (p[0].a == '3')
          return true;
        else
          return false;
      } else if (p[1].a == '2') {  // 2
        if (p[0].a == '4')
          return true;
        else
          return false;
      } else if (p[1].a == '3') {  // 3
        if (p[0].a == '5')
          return true;
        else
          return false;
      } else if (p[1].a == '4') {  // 4
        if (p[0].a == '6')
          return true;
        else
          return false;
      } else if (p[1].a == '5') {  // 5
        if (p[0].a == '7')
          return true;
        else
          return false;
      } else if (p[1].a == '6') {  // 6
        if (p[0].a == '8')
          return true;
        else
          return false;
      } else if (p[1].a == '7') {  // 7
        if (p[0].a == '9')
          return true;
        else
          return false;
      } else if (p[1].a == '8') {  // 8
        if (p[0].a == '1')
          return true;
        else
          return false;
      } else if (p[1].a == '9') {  // 9
        if (p[0].a == 'J')
          return true;
        else
          return false;
      } else if (p[1].a == 'J') {  // J
        if (p[0].a == 'K')
          return true;
        else
          return false;
      } else if (p[1].a == 'Q') {  // Q
        if (p[0].a == 'A')
          return true;
        else
          return false;
      } else if (p[1].a == 'K') {  // K
        if (p[0].a == '2')
          return true;
        else
          return false;
      }
    }
  }
}

void solve(int l, int r) {
  if (l > r && cnt == 0) {
    if (judge() == true) {
      ans[cnt].tt[0] = p[0];
      ans[cnt].tt[1] = p[1];
      ans[cnt].tt[2] = p[2];
      ans[cnt].tt[3] = p[3];
      ans[cnt].tt[4] = p[4];
      ans[cnt].most = p[0].val + 10 * p[1].val + 100 * p[2].val +
                      1000 * p[3].val + 10000 * p[4].val;
      cnt++;
    }
    return;
  }
  for (int i = l; i <= r && cnt == 0; i++) {
    temp = p[i];
    p[i] = p[l];
    p[l] = temp;
    solve(l + 1, r);
    if (cnt > 0) return;
    temp = p[i];
    p[i] = p[l];
    p[l] = temp;
  }
}

int main() {
  int ca = 1;
  int T;
  scanf("%d", &T);
  while (T--) {
    printf("Problem %d: ", ca++);
    char s[4];
    cnt = 0;
    for (int i = 0; i < 5; i++) {
      scanf("%s", s);
      if (strlen(s) == 3) {
        p[i].a = '1';
        p[i].aa = '0';
        p[i].b = s[2];
        p[i].c = 10;
        p[i].d = value(s[2]);
        p[i].val = 10 * p[i].c + p[i].d;
      } else {
        p[i].a = s[0];
        p[i].b = s[1];
        p[i].aa = '#';
        p[i].c = value(s[0]);
        p[i].d = value(s[1]);
        p[i].val = 10 * p[i].c + p[i].d;
      }
    }
    sort(p, p + 5, cmp);
    solve(0, 4);
    for (int i = 0; i < 5; i++) {
      if (i == 0) {
        if (p[i].aa == '#')
          printf("%c%c", p[i].a, p[i].b);
        else
          printf("10%c", p[i].b);
      } else {
        if (p[i].aa == '#')
          printf(" %c%c", p[i].a, p[i].b);
        else
          printf(" 10%c", p[i].b);
      }
    }
    printf("\n");
  }
  return 0;
}
