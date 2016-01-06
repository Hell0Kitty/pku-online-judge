#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <list>

using namespace std;

const int MAXN = 1024;
const int N = 26 * 2 + 20;
map<char, int> var;
vector<string> vec;
vector<string> res;
int var_len = 0;
bool vist[MAXN];
struct node {
  int belong;
  node* next[N];
  node() {
    belong = -1;
    memset(next, NULL, sizeof(next));
  }
} * root;
void insert(string& s, node* root, string& c) {
  for (int i = 0; i < s.size(); ++i) {
    if (var.find(s[i]) == var.end()) var[s[i]] = var_len++;
    int l = var[s[i]];
    if (root->next[l] == NULL) root->next[l] = new node();
    root = root->next[l];
  }
  if (root->belong == -1) {
    root->belong = vec.size();
    res.push_back(s);
    vec.push_back(c);
  }
}

int find(char* s, node* root) {
  for (int i = 0; s[i]; ++i) {
    if (root->belong != -1) return root->belong;
    if (var.find(s[i]) == var.end()) return -1;
    int l = var[s[i]];
    if (root->next[l] == NULL) return -1;
    root = root->next[l];
  }
  return root->belong;
}

int main() {
  // freopen("C:/Downloads/TESTS/D.3.dat", "r", stdin);
  int a, c;
  char str[1024];
  scanf("%d%d\n", &a, &c);
  root = new node();
  int num = a + c;
  bool flag = true;
  for (int i = 0; i < num; ++i) {
    if (i == a) {
      a = vec.size();
      flag = false;
    }
    gets(str);
    // puts(str);
    int j = -1;
    while (str[++j] != '"')
      ;
    string s = "";
    while (str[++j] != '"') s += str[j];
    while (str[++j] != '"')
      ;
    string c = "";
    while (str[++j] != '"') c += str[j];
    insert(s, root, c);
    if (flag) {
      s[0] = toupper(s[0]);
      c[0] = toupper(c[0]);
      insert(s, root, c);
      for (int j = 0; j < s.size() || j < c.size(); ++j) {
        if (j < s.size()) s[j] = toupper(s[j]);
        if (j < c.size()) c[j] = toupper(c[j]);
      }
      insert(s, root, c);
    }
  }
  while (gets(str)) {
    if (str[0] == '#') memset(vist, false, sizeof(vist));
    for (int i = 0; str[i]; ++i) {
      int t = find(str + i, root);
      if (t == -1)
        putchar(str[i]);
      else if (t < a) {
        cout << vec[t];
        i += res[t].size() - 1;
      } else if (t >= a) {
        i += res[t].size() - 1;
        if (vist[t])
          cout << res[t];
        else {
          vist[t] = true;
          cout << vec[t] << " (" << res[t] << ')';
        }
      }
    }
    printf("\n");
  }
  return 0;
}
