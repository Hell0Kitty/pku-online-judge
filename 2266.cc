#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}

//#define DEBUGGER // show debugging message
#ifdef DEBUGGER  // require C11 (g++ -O2 -std=gnu++0x -Wall -Wshadow)
template <class T>
void _printcoll(T const& coll) {
  int first = 1;
  cout << "[";
  for (auto a : coll) {
    if (!first) printf(", ");
    cout << a;
    first = false;
  }
  cout << "]" << endl;
}
template <class T>
void _printcoll(T const& coll, int len) {
  int first = 1;
  cout << "[";
  for (auto a : coll) {
    if (!first) printf(", ");
    cout << a;
    first = false;
    len--;
    if (!len) break;
  }
  cout << "]" << endl;
}
#define DBG(vari) cout << #vari << " = " << (vari) << endl;
#define DBGC(vari)        \
  cout << #vari << " = "; \
  _printcoll(vari);
#define DBGCN(vari, len)  \
  cout << #vari << " = "; \
  _printcoll(vari, len);
#else
#define DBG(vari)
#define DBGC(vari)
#define DBGCN(vari, len)
#endif

#define MAXN (555)

int N;
string S;

char board[MAXN][MAXN];
int start;
void solve(int ii, int jj, int len) {
  if (len == 1) {
    board[ii][jj] = S[start++];
  } else if (S[start] != 'Q') {
    for (int i = ii; i < ii + len; i++) {
      for (int j = jj; j < jj + len; j++) {
        board[i][j] = S[start];
      }
    }
    start++;
  } else {
    start++;
    solve(ii, jj, len / 2);
    solve(ii, jj + len / 2, len / 2);
    solve(ii + len / 2, jj, len / 2);
    solve(ii + len / 2, jj + len / 2, len / 2);
  }
}

void print(int r, int c) {
  int ret = 0;
  for (int i = c + 7; i >= c; i--) {
    ret <<= 1;
    if (board[r][i] == 'B') ret += 1;
  }
  printf("0x%02x,", ret);
}

int main() {
  cin >> N >> S;
  start = 0;
  solve(0, 0, N);

  printf("#define quadtree_width %d\n", N);
  printf("#define quadtree_height %d\n", N);
  printf("static char quadtree_bits[] = {\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N / 8; j++) {
      print(i, j * 8);
    }
    printf("\n");
  }
  printf("};");
  return 0;
}
