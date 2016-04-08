#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#define F(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

int n, cons;

int a[21], alpha[21], pos[128], con[51][2];
bool mk[21];

void dfs(int x) {
  if (x == n + 1) {
    F(i, 1, n)
    printf("%c", a[i]);
    printf("\n");
    return;
  }

  F(i, 1, n) {
    if (!mk[i]) {
      a[x] = alpha[i];
      pos[a[x]] = x;
      mk[i] = true;
      bool ok = true;
      for (int j = 1; j <= cons && ok; j++) {
        int b = con[j][0], c = con[j][1];
        if (pos[b] == 0 || pos[c] == 0 || pos[b] < pos[c])
          ;
        else
          ok = false;
      }
      if (ok) dfs(x + 1);
      pos[a[x]] = 0;
      mk[i] = false;
    }
  }
}

int main() {
  string line;
  istringstream ss;
  char chra, chrb, chr;

  while (getline(cin, line)) {
    memset(mk, 0, sizeof(mk));
    memset(pos, 0, sizeof(pos));

    n = 0, cons = 0;
    ss.clear();
    ss.str(line);
    while (ss >> chr) alpha[++n] = chr;

    sort(&alpha[1], &alpha[n + 1]);

    getline(cin, line);
    ss.clear();
    ss.str(line);

    while (ss >> chra >> chrb) {
      con[++cons][0] = chra;
      con[cons][1] = chrb;
    }

    dfs(1);
    printf("\n");
  }

  return 0;
}
