#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int kind = 26;
struct node {
  node *fail;  //失败指针
  node *next[kind];  // Tire每个节点的26个子节点（最多26个字母）
  int id;   //是否为该单词的最后一个节点
  node() {  //构造函数初始化
    fail = NULL;
    id = -1;
    memset(next, (int)NULL, sizeof(next));
  }
} * q[500001], *root;  //队列，方便用于bfs构造失败指针
char str[1005];        //模式串

#define maxn 1005
#define maxl 305

int l, c, w;
char map[maxn][maxn];
char word[maxn][maxl];
int dir[8][2] = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int ans[maxn][3];
bool vis[maxn];
int nowx, nowy, nowd;
int len[maxn];

void insert(char *str, node *root, int id) {
  node *p = root;
  int i = 0, index;
  while (str[i]) {
    index = str[i] - 'A';
    if (p->next[index] == NULL) p->next[index] = new node();
    p = p->next[index];
    i++;
  }
  p->id = id;
}
void build_ac_automation(node *root) {
  int i;
  int head, tail;  //队列的头尾指针
  head = tail = 0;
  root->fail = NULL;
  q[head++] = root;
  while (head != tail) {
    node *temp = q[tail++];
    node *p = NULL;
    for (i = 0; i < 26; i++) {
      if (temp->next[i] != NULL) {
        p = temp->fail;
        while (p != NULL && p->next[i] == NULL) p = p->fail;
        if (p == NULL)
          temp->next[i]->fail = root;
        else
          temp->next[i]->fail = p->next[i];
        q[head++] = temp->next[i];
      }
    }
  }
}

void makeans(int id, int pos) {
  vis[id] = true;
  ans[id][0] = nowx + dir[nowd][0] * (pos - len[id] + 1);
  ans[id][1] = nowy + dir[nowd][1] * (pos - len[id] + 1);
  ans[id][2] = nowd;
}

int query(node *root, char *str) {
  int i = 0, cnt = 0, index;
  node *p = root;
  while (str[i]) {
    index = str[i] - 'A';
    while (p->next[index] == NULL && p != root) p = p->fail;
    p = p->next[index];
    p = (p == NULL) ? root : p;
    node *temp = p;
    while (temp != root) {
      if (temp->id != -1 && !vis[temp->id]) makeans(temp->id, i);
      temp = temp->fail;
    }
    i++;
  }
  return cnt;
}

void input() {
  scanf("%d%d%d", &l, &c, &w);
  for (int i = 0; i < l; i++) scanf("%s", map[i]);
  for (int i = 0; i < w; i++) {
    scanf("%s", word[i]);
    insert(word[i], root, i);
    len[i] = strlen(word[i]);
  }
}

bool ok(int x, int y) { return x >= 0 && y >= 0 && x < l && y < c; }

void make(int x, int y, int d) {
  int i = 0;
  nowx = x;
  nowy = y;
  nowd = d;
  while (ok(x, y)) {
    str[i++] = map[x][y];
    x += dir[d][0];
    y += dir[d][1];
  }
  str[i] = 0;
  query(root, str);
}

void work() {
  build_ac_automation(root);
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < l; i++)
    for (int j = 0; j < 8; j++) {
      make(i, 0, j);
      make(i, c - 1, j);
    }
  for (int i = 0; i < c; i++)
    for (int j = 0; j < 8; j++) {
      make(0, i, j);
      make(l - 1, i, j);
    }
  for (int i = 0; i < w; i++)
    printf("%d %d %c\n", ans[i][0], ans[i][1], (char)(ans[i][2] + 'A'));
}

int main() {
  root = new node();
  input();
  work();
  return 0;
}
