#include <iostream>
#include <queue>
using namespace std;
#define MAXV 110

typedef struct Node {
  int aa, bb, type, cout;
  int i;
  int pa, pb, ca, cb;
} VNode;

VNode map[MAXV][MAXV], v, temp;
bool dis[MAXV][MAXV];

void write(int first, int last) {
  int ft, lt;
  printf("%d\n", map[first][last].cout);

  map[first][last].ca = -1, map[first][last].cb = -1;

  while (map[first][last].pa != -1 && map[first][last].pb != -1) {
    ft = first, lt = last;
    v = map[map[first][last].pa][map[first][last].pb];
    map[map[first][last].pa][map[first][last].pb].ca = first,
    map[map[first][last].pa][map[first][last].pb].cb = last;
    first = v.aa, last = v.bb;
  }
  while (map[first][last].ca != -1 && map[first][last].cb != -1) {
    ft = first, lt = last;
    switch (map[map[first][last].ca][map[first][last].cb].type) {
      case 1:
        printf("FILL(%d)\n", map[map[first][last].ca][map[first][last].cb].i);
        break;
      case 2:
        printf("POUR(%d,%d)\n",
               map[map[first][last].ca][map[first][last].cb].i ^ 3,
               map[map[first][last].ca][map[first][last].cb].i);
        break;
      case 3:
        printf("DROP(%d)\n", map[map[first][last].ca][map[first][last].cb].i);
        break;
    }

    first = map[ft][lt].ca, last = map[ft][lt].cb;
  }
}

int bfs(int a, int b, int c) {
  queue<VNode> q;
  memset(dis, false, sizeof(dis));
  memset(map, 0, sizeof(map));

  dis[0][0] = true;
  map[0][0].pa = -1, map[0][0].pb = -1;
  q.push(map[0][0]);

  while (!q.empty()) {
    temp = v = q.front();
    q.pop();

    v.aa = a;
    if (!dis[v.aa][v.bb]) {
      dis[v.aa][v.bb] = true;
      v.cout = temp.cout + 1;
      v.pa = temp.aa, v.pb = temp.bb;
      v.type = 1;
      v.i = 1;
      map[v.aa][v.bb] = v;
      if (v.aa == c || v.bb == c) {
        write(v.aa, v.bb);
        return 0;
      }
      q.push(v);
    }
    v = temp;
    v.bb = b;
    if (!dis[v.aa][v.bb]) {
      dis[v.aa][v.bb] = true;
      v.cout = temp.cout + 1;
      v.pa = temp.aa, v.pb = temp.bb;
      v.type = 1;
      v.i = 2;
      map[v.aa][v.bb] = v;
      if (v.aa == c || v.bb == c) {
        write(v.aa, v.bb);
        return 0;
      }
      q.push(v);
    }
    v = temp;
    v.aa = v.bb + v.aa;
    if (v.aa > a) {
      v.bb = v.aa - a;
      v.aa = a;
    } else
      v.bb = 0;
    if (!dis[v.aa][v.bb]) {
      dis[v.aa][v.bb] = true;
      v.cout = temp.cout + 1;
      v.pa = temp.aa, v.pb = temp.bb;
      v.type = 2;
      v.i = 1;
      map[v.aa][v.bb] = v;
      if (v.aa == c || v.bb == c) {
        write(v.aa, v.bb);
        return 0;
      }
      q.push(v);
    }
    v = temp;
    v.bb = v.bb + v.aa;
    if (v.bb > b) {
      v.aa = v.bb - b;
      v.bb = b;
    } else
      v.aa = 0;
    if (!dis[v.aa][v.bb]) {
      dis[v.aa][v.bb] = true;
      v.cout = temp.cout + 1;
      v.pa = temp.aa, v.pb = temp.bb;
      v.type = 2;
      v.i = 2;
      map[v.aa][v.bb] = v;
      if (v.aa == c || v.bb == c) {
        write(v.aa, v.bb);
        return 0;
      }
      q.push(v);
    }
    v = temp;
    v.aa = 0;
    if (!dis[v.aa][v.bb]) {
      dis[v.aa][v.bb] = true;
      v.cout = temp.cout + 1;
      v.pa = temp.aa, v.pb = temp.bb;
      v.type = 3;
      v.i = 1;
      map[v.aa][v.bb] = v;
      if (v.aa == c || v.bb == c) {
        write(v.aa, v.bb);
        return 0;
      }
      q.push(v);
    }
    v = temp;
    v.bb = 0;
    if (!dis[v.aa][v.bb]) {
      dis[v.aa][v.bb] = true;
      v.cout = temp.cout + 1;
      v.pa = temp.aa, v.pb = temp.bb;
      v.type = 3;
      v.i = 2;
      map[v.aa][v.bb] = v;
      if (v.aa == c || v.bb == c) {
        write(v.aa, v.bb);
        return 0;
      }
      q.push(v);
    }
  }
  return -1;
}

int main() {
  int a, b, c;
  while (scanf("%d%d%d", &a, &b, &c) != EOF) {
    a = bfs(a, b, c);
    if (a == -1) printf("impossible\n");
  }
  return 0;
}
