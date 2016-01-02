#include <stdio.h>
#include <string.h>

#define inf 1000000000

struct Node {
  int Y, M;
} node[55555];

int h[55555][22];

bool operator<(const Node a, const Node b) { return a.Y < b.Y; }

int n, m;

void pre() {
  int i, j, l;
  for (j = 1, l = 1; l * 2 <= n; j++, l *= 2)
    for (i = 0; i <= n - l * 2; i++)
      h[i][j] = (h[i][j - 1] > h[i + l][j - 1]) ? h[i][j - 1] : h[i + l][j - 1];
}

int query(int be, int ed) {
  int j = 0, l = 1;
  while (2 * l <= ed - be + 1) {
    j++;
    l *= 2;
  }
  return (h[be][j] > h[ed + 1 - l][j]) ? h[be][j] : h[ed + 1 - l][j];
}

int main() {
  // freopen("in.txt","r",stdin);
  bool ok = false;
  while (scanf("%d", &n)) {
    int i, j, k;
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &node[i].Y, &node[i].M);
    }
    // sort(node,node+n);
    scanf("%d", &m);
    if ((n + m) == 0) {
      break;
    }
    if (ok) printf("\n");
    ok = true;
    node[0].Y = node[0].M = -1000000001;
    for (i = 0; i <= n; i++) {
      h[i][0] = node[i].M;
    }
    pre();
    int be, ed;
    while (m--) {
      scanf("%d %d", &be, &ed);
      int k1, k2, l = 0, r = n, mid;
      while (l <= r) {
        mid = (l + r) >> 1;
        if (node[mid].Y <= be) {
          k1 = mid;
          l = mid + 1;
        } else
          r = mid - 1;
      }
      l = 0;
      r = n;
      while (l <= r) {
        mid = (l + r) >> 1;
        if (node[mid].Y <= ed) {
          k2 = mid;
          l = mid + 1;
        } else
          r = mid - 1;
      }
      bool ok1, ok2;
      if (node[k1].Y == be)
        ok1 = true;
      else
        ok1 = false;
      if (node[k2].Y == ed)
        ok2 = true;
      else
        ok2 = false;
      if (ok1 == true && ok2 == true) {
        if (node[k1].M < node[k2].M) {
          printf("false\n");
          continue;
        }
        if (k1 + 1 == k2) {
          if (node[k1].Y + 1 == node[k2].Y)
            printf("true\n");
          else
            printf("maybe\n");
          continue;
        }
        int mx = query(k1 + 1, k2 - 1);
        if (mx < node[k2].M) {
          if (k2 - k1 == node[k2].Y - node[k1].Y)
            printf("true\n");
          else
            printf("maybe\n");
        } else
          printf("false\n");
      } else if (ok1 == false && ok2 == false) {
        if (k1 == k2) {
          printf("maybe\n");
          continue;
        }
        printf("maybe\n");
      } else if (ok1 == true && ok2 == false) {
        if (k1 == k2) {
          printf("maybe\n");
          continue;
        }
        int mx = query(k1 + 1, k2);
        if (mx < node[k1].M) {
          printf("maybe\n");
          continue;
        } else
          printf("false\n");
      } else {
        if (k1 + 1 == k2) {
          printf("maybe\n");
          continue;
        }
        int mx = query(k1 + 1, k2 - 1);
        if (mx < node[k2].M) {
          printf("maybe\n");
        } else
          printf("false\n");
      }
    }
  }
  return 0;
}
