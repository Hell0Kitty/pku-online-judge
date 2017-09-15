#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAX_LENGTH 1005
#define MAX_ASCII 205
#define MAX_CHAR_CNT 300

struct Elem {
  int pos;
  int cnt;
  Elem() {}
  Elem(int pp, int cc) : pos(pp), cnt(cc) {}
};

struct Node {
  int left_child;
  int right_child;
  int count;
} node[MAX_CHAR_CNT];

bool vis[MAX_CHAR_CNT];
char text[MAX_LENGTH];
int occurence_count[MAX_ASCII];
int node_cnt;
int original_length;
int ans;
int char_cnt;

bool operator<(const Elem &a, const Elem &b) { return a.cnt > b.cnt; }

void add_char(char ch) {
  int asc = (int)ch;
  occurence_count[asc]++;
}

void add_node(int cnt) {
  node[node_cnt].count = cnt;
  node[node_cnt].left_child = -1;
  node[node_cnt].right_child = -1;
  node_cnt++;
}

void count_char() {
  memset(occurence_count, 0, sizeof(occurence_count));
  for (int i = 0; text[i]; i++) {
    add_char(text[i]);
  }
  node_cnt = 0;
  for (int i = (int)'A'; i <= (int)'Z'; i++) {
    if (occurence_count[i]) {
      add_node(occurence_count[i]);
    }
  }
  if (occurence_count[(int)'_']) add_node(occurence_count[(int)'_']);
  original_length = strlen(text) * 8;
  char_cnt = node_cnt;
}

void build_tree() {
  priority_queue<Elem> pq;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < node_cnt; i++) pq.push(Elem(i, node[i].count));
  while (pq.size() > 1) {
    Elem a = pq.top();
    pq.pop();
    Elem b = pq.top();
    pq.pop();
    node[node_cnt].left_child = a.pos;
    node[node_cnt].right_child = b.pos;
    node[node_cnt].count = a.cnt + b.cnt;
    pq.push(Elem(node_cnt, a.cnt + b.cnt));
    node_cnt++;
    vis[a.pos] = true;
    vis[b.pos] = true;
  }
}

void dfs(int id, int depth) {
  if (node[id].left_child == -1 && node[id].right_child == -1) {
    ans += node[id].count * depth;
    return;
  }
  if (node[id].left_child != -1) dfs(node[id].left_child, depth + 1);
  if (node[id].right_child != -1) dfs(node[id].right_child, depth + 1);
}

int main() {
  while (scanf("%s", text), strcmp(text, "END")) {
    count_char();
    if (char_cnt == 1) {
      printf("%d %d 8.0\n", original_length, original_length / 8);
      continue;
    }
    build_tree();
    ans = 0;
    dfs(node_cnt - 1, 0);
    printf("%d %d %.1f\n", original_length, ans, original_length * 1.0 / ans);
  }
  return 0;
}
