#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const int Maxn = 400010;

string pattern;
int plen;

int nxt[Maxn];

inline void getNxt() {
  memset(nxt, 0, sizeof(nxt));
  int i = 0, j = -1;
  nxt[0] = -1;
  while (i < plen) {
    if (j == -1 || pattern[i] == pattern[j]) {
      i++;
      j++;
      nxt[i] = j;
    } else {
      j = nxt[j];
    }
  }
}

vector<int> Ans;
int main() {
  while (cin >> pattern) {
    plen = pattern.length();
    getNxt();
    Ans.clear();
    int k = plen;
    while (k > 0) {
      Ans.push_back(k);
      k = nxt[k];
    }
    sort(Ans.begin(), Ans.end());
    for (int i = 0; i < Ans.size(); i++) printf("%d ", Ans[i]);
    printf("\n");
  }
  return 0;
}
