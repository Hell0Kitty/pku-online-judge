#include <math.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int map[70][70][70];
int N, M, K, L;
int dir[6][3] = {
    {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int ans;
int hash1(int x, int y, int z) { return z * N * M + y * N + x; }
void hash2(int n, int& x, int& y, int& z) {
  z = n / (N * M);
  n = n % (N * M);
  y = n / N;
  x = n % N;
}
bool is_edge(int a, int b, int c) {
  if (a == 0 || a == N - 1) return true;
  if (b == 0 || b == M - 1) return true;
  if (c == 0 || c == K - 1) return true;
  return false;
}
void bfs(int st) {
  int i, j, k;
  int a, b, c;
  int x, y, z;
  hash2(st, a, b, c);
  map[a][b][c] = 2;
  queue<int> q;
  q.push(st);
  int pre, cur;
  while (!q.empty()) {
    pre = q.front();
    q.pop();
    hash2(pre, a, b, c);
    for (i = 0; i < 6; i++) {
      x = a + dir[i][0], y = b + dir[i][1], z = c + dir[i][2];

      if (x < 0 || x >= N || y < 0 || y >= M || z < 0 || z >= K) continue;
      if (map[x][y][z] == 2) continue;
      if (map[x][y][z] == 1) {
        ans++;
        continue;
      }
      map[x][y][z] = 2;
      q.push(hash1(x, y, z));
    }
  }
}

int main() {
  int i, j, k;
  while (scanf("%d %d %d %d", &N, &M, &K, &L) == 4 && N + M + K + L) {
    memset(map, 0, sizeof(map));
    for (i = 0; i < L; i++) {
      int temp;
      scanf("%d", &temp);
      int a, b, c;
      hash2(temp, a, b, c);
      map[a][b][c] = 1;
    }
    ans = 0;
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
        for (k = 0; k < K; k++) {
          if (!is_edge(i, j, k)) continue;
          if (map[i][j][k] == 0) {
            bfs(hash1(i, j, k));
          }
        }
      }
    }
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
        if (map[i][j][0] == 1) {
          ans++;
        }
        if (map[i][j][K - 1] == 1) {
          ans++;
        }
      }
    }
    for (i = 0; i < N; i++) {
      for (j = 0; j < K; j++) {
        if (map[i][0][j] == 1) {
          ans++;
        }
        if (map[i][M - 1][j] == 1) {
          ans++;
        }
      }
    }
    for (i = 0; i < M; i++) {
      for (j = 0; j < K; j++) {
        if (map[0][i][j] == 1) {
          ans++;
        }
        if (map[N - 1][i][j] == 1) {
          ans++;
        }
      }
    }
    printf("The number of faces needing shielding is %d.\n", ans);
  }
  return 0;
}
