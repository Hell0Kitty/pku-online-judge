#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
using namespace std;
const int MAXN = 53;
stack<string> nCard[MAXN];
int nIndex;
void funcInput();
void procMove();
void funcOutput();
bool isMatch(string str1, string str2);
int main() {
  string nStr;

  while (cin >> nStr, nStr != "#") {
    nCard[0].push(nStr);
    funcInput();
    procMove();
    funcOutput();
  }
  return 0;
}
void funcInput() {
  string nStr;
  for (nIndex = 1; nIndex != 52; ++nIndex) {
    cin >> nStr;
    nCard[nIndex].push(nStr);
  }
}
void procMove() {
  while (1) {
    int pos;
    for (pos = 0; pos != nIndex; ++pos) {
      if (pos > 2 && isMatch(nCard[pos - 3].top(), nCard[pos].top())) {
        nCard[pos - 3].push(nCard[pos].top());
        break;
      }
      if (pos > 0 && isMatch(nCard[pos - 1].top(), nCard[pos].top())) {
        nCard[pos - 1].push(nCard[pos].top());
        break;
      }
    }
    if (pos == nIndex) break;
    nCard[pos].pop();
    if (nCard[pos].empty()) {
      for (int i = pos; i != nIndex - 1; ++i) {
        nCard[i] = nCard[i + 1];
      }
      while (!nCard[nIndex - 1].empty()) nCard[nIndex - 1].pop();
      --nIndex;
    }
  }
}
void funcOutput() {
  cout << nIndex << " piles remaining:";
  for (int i = 0; i != nIndex; ++i) {
    cout << ' ' << nCard[i].size();
    while (!nCard[i].empty()) nCard[i].pop();
  }
  cout << endl;
}
bool isMatch(string str1, string str2) {
  if (str1[0] == str2[0] || str1[1] == str2[1]) return true;
  return false;
}
