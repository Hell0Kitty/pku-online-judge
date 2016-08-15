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

#define MAXN 55

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

int id[MAXN];
vector<int> adj[MAXN];
int parent[MAXN];
int n;

void parse(string &s, int nodeu) {
  n++;
  string temp = s.substr(1, s.size() - 2);
  stringstream iss(temp);
  int token2;
  iss >> token2;
  id[nodeu] = token2;
  int l, r, numparen = 1;
  int i = 0;
  while (temp[i] != '(' && i < temp.size()) i++;
  if (i == temp.size()) return;
  l = i++;
  for (; i < temp.size(); i++) {
    if (temp[i] == '(')
      numparen++;
    else if (temp[i] == ')') {
      numparen--;
    }
    if (numparen == 0) {
      r = i;
      string t2 = temp.substr(l, r - l + 1);
      i++;
      l = i + 1;
      int c = n;
      parse(t2, n);
      adj[nodeu].push_back(c);
      parent[c] = nodeu;
    }
  }
}

/*
void preorder(int x){
    cout << id[x] << endl;
    for(int i = 0; i < adj[x].size(); i++ ){
        preorder(adj[x][i]);
    }
}
*/

int smallestID, at;

void removeSmallestHelper(int x) {
  if (adj[x].size() == 0) {
    if (id[x] < smallestID) {
      smallestID = id[x];
      at = x;
    }
  }
  for (int i = 0; i < adj[x].size(); i++) {
    removeSmallestHelper(adj[x][i]);
  }
}

int root;

void removeSmallest() {
  smallestID = MAXN;
  removeSmallestHelper(root);
  int pa;
  if (adj[root].size() == 1 && id[root] < smallestID) {
    smallestID = id[root];
    at = root;
    pa = adj[root][0];
    cout << id[pa];
    root = pa;
  } else {
    pa = parent[at];
    cout << id[pa];
    for (vector<int>::iterator it = adj[pa].begin(); it != adj[pa].end();
         it++) {
      if (*it == at) {
        adj[pa].erase(it);
        break;
      }
    }
  }
}

int main() {
  string s;
  while (getline(cin, s)) {
    n = 0;
    root = 0;
    for (int i = 0; i < MAXN; i++) {
      adj[i].clear();
      parent[i] = i;
    }
    parse(s, 0);
    for (int i = 0; i < n - 1; i++) {
      if (i) cout << " ";
      removeSmallest();
    }
    cout << endl;
  }
  return 0;
}
