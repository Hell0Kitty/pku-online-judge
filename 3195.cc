#include <iostream>
#include <stack>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN = 20000;
int nNum = 0;
stack<int> nS;
int nSize[MAXN], nFlag[MAXN];
bool isMatri(int n);
int main() {
  int n;
  char ch;
  nNum = 0;
  while (2 == scanf("%d%c", &n, &ch)) {
    nSize[nNum++] = n;
    if (ch == '\n') {
      if (isMatri(nNum))
        printf(":-) Matrioshka!\n");
      else
        printf(":-( Try again.\n");
      nNum = 0;
    }
  }
  return 0;
}
bool isMatri(int n) {
  if (n & 1) return false;
  if (nSize[0] >= 0) return false;

  int k = 0;
  memset(nFlag, 0, sizeof(nFlag));
  nFlag[k++] = -nSize[0];
  nS.push(nSize[0]);
  for (int i = 1; i != nNum; ++i) {
    if (nSize[i] < 0) {
      if (-nSize[i] >= nFlag[k - 1]) {
        return false;
      } else {
        nS.push(nSize[i]);
        nFlag[k - 1] += nSize[i];
        nFlag[k++] = -nSize[i];
      }
    } else {
      int tmp = -nS.top();
      if (tmp != nSize[i]) {
        return false;
      } else {
        nS.pop();
        nFlag[k - 1] = 0;
        k -= 1;
      }
    }
  }
  return true;
}
