#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

int test_cnt, l[6], x1, y1, x2, y2;

const int enough_x = 20;
std::vector<std::pair<int, int> > adj[enough_x * 96];

int hash(int x, int y, int top, int front) {
  int front_id = -1;
  for (int i = 0; i < 6; ++i) {
    if (i != top && i != 5 - top) {
      front_id++;
    }
    if (i == front) {
      return x * 96 + y * 24 + top * 4 + front_id;
    }
  }
  return -1;
}

//(top,front)->left
const int help[6][6] = {{-1, 2, 4, 1, 3, -1},
                        {3, -1, 0, 5, -1, 2},
                        {1, 5, -1, -1, 0, 4},
                        {4, 0, -1, -1, 5, 1},
                        {2, -1, 5, 0, -1, 3},
                        {-1, 3, 1, 4, 2, -1}};
/*
 const int help[6][6] = { { -1, 3, 1, 4, 2, -1 }, { 2, -1, 5, 0, -1, 3 }, { 4,
 0,
 -1, -1, 5, 1 }, { 1, 5, -1, -1, 0, 4 }, { 3, -1, 0, 5, -1, 2 }, { -1, 2,
 4, 1, 3, -1 } };
 */
void generate() {
  for (int x = 0; x < enough_x; ++x) {
    for (int y = 0; y < 4; ++y) {
      for (int top = 0; top < 6; ++top) {
        for (int front = 0; front < 6; ++front) {
          if (front == top || front == 5 - top) {
            continue;
          }
          int left = help[top][front], u = hash(x, y, top, front);
          int _x, _y, _top, _front, v;

          // go left
          if (x - 1 >= 0) {
            _x = x - 1, _y = y;
            _top = 5 - left, _front = front;
            v = hash(_x, _y, _top, _front);
            adj[u].push_back(std::make_pair(v, _top));
          }

          // go right
          if (x + 1 < enough_x) {
            _x = x + 1, _y = y;
            _top = left, _front = front;
            v = hash(_x, _y, _top, _front);
            adj[u].push_back(std::make_pair(v, _top));
          }

          // go up
          if (y + 1 < 4) {
            _x = x, _y = y + 1;
            _top = front, _front = 5 - top;
            v = hash(_x, _y, _top, _front);
            adj[u].push_back(std::make_pair(v, _top));
          }

          // go down
          if (y - 1 >= 0) {
            _x = x, _y = y - 1;
            _top = 5 - front, _front = top;
            v = hash(_x, _y, _top, _front);
            adj[u].push_back(std::make_pair(v, _top));
          }
        }
      }
    }
  }
}

#define foreach \
  (i, v) for (__typeof((v).begin()) i = (v).begin(); i != ((v).end()); ++i)
typedef long long int64;
int64 dist[enough_x * 96];
const int64 inf = (int64)(1e16);

std::priority_queue<std::pair<int64, int> > q;

void dijkstra(int source) {
  std::fill(dist, dist + enough_x * 96, inf);
  while (!q.empty()) {
    q.pop();
  }
  dist[source] = 0, q.push(std::make_pair(0, source));
  while (!q.empty()) {
    int u = q.top().second, cost = -q.top().first;
    q.pop();
    if (dist[u] < cost) {
      continue;
    }
    foreach (iter, adj[u]) {
      int v = iter->first, top = iter->second;
      if (dist[v] > cost + l[top]) {
        dist[v] = cost + l[top], q.push(std::make_pair(-dist[v], v));
      }
    }
  }
}

const int N = 96;
struct matrix_st {
  int64 a[N][N];
};

matrix_st mul(matrix_st &lhs, matrix_st &rhs) {
  matrix_st ans;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      ans.a[i][j] = inf;
    }
  }
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ans.a[i][j] = std::min(ans.a[i][j], lhs.a[i][k] + rhs.a[k][j]);
      }
    }
  }
  return ans;
}

matrix_st exp(matrix_st a, int b) {
  matrix_st ans;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      ans.a[i][j] = (i == j ? 0LL : inf);
    }
  }
  for (; b; b /= 2, a = mul(a, a)) {
    if (b & 1) {
      ans = mul(ans, a);
    }
  }
  return ans;
}

int64 f[96], g[96][96];

void record(int x, int64 *f) {
  for (int y = 0; y < 4; ++y) {
    for (int top = 0; top < 6; ++top) {
      for (int front = 0; front < 6; ++front) {
        if (front == top || front == 5 - top) {
          continue;
        }
        int hash_val = hash(x, y, top, front);
        f[hash_val % 96] = dist[hash_val];
      }
    }
  }
}

int64 solve() {
  int diff = std::abs(x1 - x2), x = enough_x / 2;
  int source = hash(x, y1, 0, 1);
  dijkstra(source);
  if (diff == 0) {
    int64 ans = inf;
    for (int top = 0; top < 6; ++top) {
      for (int front = 0; front < 6; ++front) {
        if (front == top || front == 5 - top) {
          continue;
        }
        ans = std::min(ans, dist[hash(x, y2, top, front)]);
      }
    }
  }
  record(x, f);
  for (int y = 0; y < 4; ++y) {
    for (int top = 0; top < 6; ++top) {
      for (int front = 0; front < 6; ++front) {
        if (front == top || front == 5 - top) {
          continue;
        }
        source = hash(x, y, top, front);
        dijkstra(source);
        record(x + 1, g[source % 96]);
      }
    }
  }
  matrix_st a;
  for (int i = 0; i < 96; ++i) {
    for (int j = 0; j < 96; ++j) {
      a.a[i][j] = g[i][j];
    }
  }
  matrix_st b = exp(a, diff);
  int64 ans = inf;
  for (int i = 0; i < 96; ++i) {
    for (int j = 0; j < 96; ++j) {
      if (j / 24 == y2) {
        ans = std::min(ans, f[i] + b.a[i][j]);
      }
    }
  }
  return ans;
}

int main() {
  generate();

  for (int i = 0; i < 6; ++i) {
    scanf("%d", &l[i]);
  }
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  --y1, --y2;
  if (x1 > x2) {
    std::swap(l[2], l[3]);
  }
  printf("%lld\n", solve());

  return 0;
}
