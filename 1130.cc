#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <vector>

#define MAXINT 99999999

using namespace std;

// int data[1000][1000];

int prev[300];
int vis[300];
// int path[1000];

int countn = 0;
vector<int> vt[300];

int bfs(int n, int et) {
  int i;

  queue<int> q;
  for (i = 0; i < n; i++) {
    vis[i] = 0;
    prev[i] = -1;
  }

  vis[0] = 1;
  q.push(0);

  while (q.size()) {
    int tmp = q.front();
    q.pop();

    vector<int>::iterator it;
    for (it = vt[tmp].begin(); it != vt[tmp].end(); it++) {
      if (vis[*it] == 0) {
        vis[*it] = 1;
        q.push(*it);
        prev[*it] = tmp;
        if (*it == et) break;
      }
    }
  }

  return 0;
}

int bfs2(int beginv, int n, int et) {
  int i;

  queue<int> q;

  q.push(beginv);
  vis[beginv] = 1;

  while (q.size()) {
    int tmp = q.front();
    q.pop();

    /*for(i=0;i<n;i++)
    {
                    if((vis[i]==0)&&(data[tmp][i]==1))
                    {vis[i]=1;
                     q.push(i);
                     if(i==et)
                     return 1;
                    }
    }*/

    vector<int>::iterator it;
    for (it = vt[tmp].begin(); it != vt[tmp].end(); it++) {
      if (vis[*it] == 0) {
        vis[*it] = 1;
        q.push(*it);
        if (*it == et) return 1;
      }
    }
  }
  return 0;
}

int dfs(int beginv, int n, int et) {
  if (beginv == et) return 1;

  vis[beginv] = 1;

  vector<int>::iterator it;
  for (it = vt[beginv].begin(); it != vt[beginv].end(); it++) {
    if (vis[*it] == 0) {
      if (dfs(*it, n, et)) return 1;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int n, et;
  scanf("%d%d", &n, &et);
  int a, b;
  int i, j, k;
  /*for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  data[i][j]=0;
  */

  while (scanf("%d%d", &a, &b) != EOF) {
    // data[a][b]=1;
    vt[a].insert(vt[a].end(), b);
  }

  bfs(n, et);

  int w = prev[et];

  while (w > -1) {
    for (i = 0; i < n; i++) vis[i] = 0;

    vis[w] = 1;

    if (w == 0) {
      printf("Put guards in room %d.\n", w);
      break;
    }

    int tag = bfs2(0, n, et);

    if (tag == 0) {
      printf("Put guards in room %d.\n", w);
      break;
    }

    w = prev[w];
  }

  return EXIT_SUCCESS;
}