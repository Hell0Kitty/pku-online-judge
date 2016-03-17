#include <iostream>
#include <string>
using namespace std;
#define MAX 151
int sov[MAX][MAX], rig[MAX];
bool tag[MAX];
bool search(int low, int up) {
  if (sov[low][up] != -1) return sov[low][up] == 0 ? false : true;
  if (low > up) return true;
  if (tag[low]) {  //情况1
    sov[low + 1][up] = search(low + 1, up);
    if (sov[low + 1][up]) return true;
  }
  int i, j;
  i = rig[low];
  while (i != -1 && i < up)  //情况2
  {
    sov[low][i] = search(low, i);
    sov[i + 1][up] = search(i + 1, up);
    if (sov[low][i] && sov[i + 1][up]) return true;
    i = rig[i];
  }
  if (i == -1 || i > up) return false;
  if (i == up)  //情况3
  {
    sov[low + 1][up - 1] = search(low + 1, up - 1);
    if (sov[low + 1][up - 1]) return true;
    for (j = rig[low]; j < up; j = rig[j]) {
      sov[low + 1][j - 1] = search(low + 1, j - 1);
      sov[j + 1][up - 1] = search(j + 1, up - 1);
      if (sov[low + 1][j - 1] && sov[j + 1][up - 1]) return true;
    }
  }
  return false;
}
int main() {
  char s[MAX];
  int i, j, n, vis[30];
  while (scanf("%s", &s) != EOF) {
    memset(tag, 0, sizeof(tag));
    j = 0;
    for (i = 1; i < strlen(s); i++) {
      if (s[i] == s[j])
        tag[j] = true;
      else
        s[++j] = s[i];
    }
    n = j + 1;
    memset(rig, -1, sizeof(rig));
    memset(vis, -1, sizeof(vis));
    for (i = 0; i < n; i++) {
      if (vis[s[i] - 'A'] == -1)
        vis[s[i] - 'A'] = i;
      else {
        rig[vis[s[i] - 'A']] = i;
        vis[s[i] - 'A'] = i;
      }
    }
    memset(sov, -1, sizeof(sov));
    for (i = 0; i < n; i++) sov[i][i] = tag[i];
    if (search(0, n - 1))
      printf("solvable\n");
    else
      printf("unsolvable\n");
  }
  return 0;
}
