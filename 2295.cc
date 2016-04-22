#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

string st;
int a, b, c, d;

int cal(string st) {
  int a;
  sscanf(st.c_str(), "%d", &a);
  return a;
}

void make(string st, int &a, int &b) {
  if (st == "x") {
    a++;
    return;
  }
  if (st == "-x") {
    a--;
    return;
  }
  if (st[st.length() - 1] == 'x')
    a += cal(st.substr(0, st.length() - 1));
  else
    b += cal(st);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> st;
    a = b = c = d = 0;
    int now = 1;
    int start = 0;
    while (1) {
      if (st[now] == '-' || st[now] == '+' || st[now] == '=') {
        make(st.substr(start, now - start), a, b);
        start = now;
      }
      if (st[now] == '=') break;
      now++;
    }
    now++;
    start = now;
    now++;
    while (1) {
      if (st[now] == '-' || st[now] == '+' || st[now] == '\0') {
        make(st.substr(start, now - start), c, d);
        start = now;
      }
      if (st[now] == '\0') break;
      now++;
    }
    a -= c;
    d -= b;
    if (a == 0 && d == 0)
      printf("IDENTITY\n");
    else if (a == 0 && d != 0)
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n", (int)floor(d * 1.0 / a));
  }
  return 0;
}
