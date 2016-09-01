#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define MP make_pair
#define OP begin()
#define ED end()
#define SZ size()

string solve(int p, int q) {
  string ret;
  int v[55], i, j;
  for (i = 0; i < p; i++) v[i] = -1;
  v[p] = 0;
  for (i = p + 1; i <= p + q; i++) v[i] = 1;
  int m = p + q + 1;
  int st = 0;
  int vis[2];
  vis[0] = vis[1] = 0;
  while (1) {
    int add = 0;
    if (!st) {
      for (i = 0; i + 1 < m; i++)
        if (v[i] == -1 && !v[i + 1]) {
          swap(v[i], v[i + 1]);
          ret += "S";
          add = 1;
          break;
        }
      for (i = 2; i < m; i++)
        if (v[i] == 1 && !v[i - 2] && v[i - 1] == -1) {
          swap(v[i], v[i - 2]);
          ret += "h";
          add = 1;
        }
    } else {
      for (i = 1; i < m; i++)
        if (v[i] == 1 && !v[i - 1]) {
          swap(v[i], v[i - 1]);
          ret += "s";
          add = 1;
          break;
        }
      for (i = m - 3; i >= 0; i--)
        if (v[i] == -1 && !v[i + 2] && v[i + 1] == 1) {
          swap(v[i], v[i + 2]);
          ret += "H";
          add = 1;
        }
    }
    //		for(i=0;i<m;i++){
    //			if(v[i]==0)cout<<"_";
    //			if(v[i]==1)cout<<"+";
    //			if(v[i]==-1)cout<<"-";
    //		}cout<<"~"<<endl;
    if (!add && vis[0] && vis[1])
      break;
    else if (!add)
      vis[st] = 1;
    else
      vis[0] = 0, vis[1] = 0;
    st ^= 1;
  }
  return ret;
}
void gao(string s) {
  int i, j;
  for (j = 0; j < s.SZ; j += 50) {
    for (i = 0; i < 50 && i + j < s.SZ; i++) putchar(s[i + j]);
    putchar('\n');
  }
  putchar('\n');
}
int main() {
  int p, q;
  int T;
  cin >> T;
  for (int CA = 1; CA <= T; CA++) {
    int p, q, r;
    cin >> r >> p >> q;
    string s = solve(p, q);
    printf("%d %d\n", CA, s.SZ);
    gao(solve(p, q));
  }
  return 0;
}
