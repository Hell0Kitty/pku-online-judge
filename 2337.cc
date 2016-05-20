#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Node {
  int to;
  bool vis;
  char word[20 + 1];
  Node () { to = -1; vis = false; }
  bool operator < (const Node &rhs) const {
    return strcmp(word, rhs.word) < 0;
  }
};

const int maxn = 26;
vector<Node> G[maxn];
stack<char*> s;
bool used[maxn];
int in[maxn], out[maxn], n, p[maxn], start;
char input[20 + 3];

void init() {
  for (int i = 0; i < maxn; i++) {
    G[i].clear();
    p[i] = i;
  }
  memset(in, 0, sizeof(in));
  memset(out, 0, sizeof(out));
  memset(used, 0, sizeof(used));
  while (!s.empty()) s.pop();
}

int find(int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

void Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) p[fx] = fy;
}

void add_edge(char* str) {
  int ll = strlen(str) - 1;
  int from = str[0] - 'a', to = str[ll] - 'a';
  in[to]++; out[from]++;
  used[from] = used[to] = true;
  Node e; e.to = to;
  strcpy(e.word, str);
  G[from].push_back(e);
}

bool connected() {
  int cnt = 0;
  for (int i = 0; i < 26; i++)
    if (used[i] && p[i] == i) cnt++;
  return cnt == 1;
}

bool pre_euler() {
  int ru = 0, chu = 0;
  for (int i = 0; i < 26; i++) {
    if (used[i]) {
      if (in[i] == out[i]) continue;
      if (in[i] - out[i] == 1) ru++;
      else if (out[i] - in[i] == 1) {
        chu++; start = i;
      }
      else return false;
    }
  }
  if (!ru && !chu) {
    for (int i = 0; i < 26; i++)
      if (used[i]) {
        start = i; break;
      }
    return true;
  }
  else if (ru == 1 && chu == 1) return true;
  else return false;
}

void euler(int u) {
  int bound = G[u].size();
  for (int i = 0; i < bound; i++) {
    Node &e = G[u][i];
    int v = e.to;
    if (!e.vis) {
      e.vis = true;
      euler(v);
      s.push(e.word);
    }
  }
}

int main() {
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) {
      memset(input, 0, sizeof(input));
      scanf("%s", input);
      add_edge(input);
      int a = input[0] - 'a';
      int b = input[strlen(input) - 1] - 'a';
      Union(a, b);
    }
    bool liantong = connected();
    if (!liantong) {
      printf("***\n");
      continue;
    }
    bool cunzai = pre_euler();
    if (!cunzai) {
      printf("***\n");
      continue;
    }
    for (int i = 0; i < 26; i++)
      if (used[i]) sort(G[i].begin(), G[i].end());
    euler(start);
    bool dot = false;
    while (!s.empty()) {
      if (dot) printf(".");
      printf("%s", s.top());
      s.pop();
      dot = true;
    }
    putchar('\n');
  }
  return 0;
}



