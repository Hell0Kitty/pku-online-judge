#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

const int maxn = 10000 + 10;

stack<bool> S;
char s[maxn];
bool hash[200], ans;

void check(char pos) {
  if (s[pos] == 'N') {
    bool x = S.top();
    S.pop();
    S.push(!x);
  } else if (s[pos] >= 'p' && s[pos] <= 't') {
    S.push(hash[s[pos]]);
  } else {
    bool x, y;
    x = S.top();
    S.pop();
    y = S.top();
    S.pop();

    if (s[pos] == 'K')
      S.push(x & y);
    else if (s[pos] == 'A')
      S.push(x | y);
    else if (s[pos] == 'C')
      S.push(!x | y);  //即蕴含
    else if (s[pos] == 'E')
      S.push(!(x ^ y));
  }
}

int main() {
  while (scanf("%s", s) == 1) {
    if (s[0] == '0') break;
    ans = true;
    int i;

    for (i = 0; i < (1 << 5); i++) {
      hash['p'] = i & 1;
      hash['q'] = i & (1 << 1);
      hash['r'] = i & (1 << 2);
      hash['s'] = i & (1 << 3);
      hash['t'] = i & (1 << 4);

      int pos = strlen(s) - 1;

      while (pos >= 0) {
        check(pos);
        pos--;
      }

      ans = S.top();
      S.pop();

      if (ans == false) {
        printf("not\n");
        break;
      }
    }

    if (i >= (1 << 5)) printf("tautology\n");
  }

  return 0;
}
